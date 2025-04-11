#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// AFFICHER
void MainWindow::on_pushButton_afficher_clicked()
{
    resultat res;
    QSqlQueryModel *model = res.afficher();

    ui->aff_res->setRowCount(model->rowCount());
    ui->aff_res->setColumnCount(model->columnCount());

    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < model->columnCount(); ++j) {
            QString value = model->data(model->index(i, j)).toString();
            ui->aff_res->setItem(i, j, new QTableWidgetItem(value));
        }
    }
}

void MainWindow::on_sortCriteriaChanged()
{
    QString sortOption = ui->Ctri_res->currentText();
    QString orderBy = "";
    QString orderDirection = "";

    if (sortOption == "Note >") {
        orderBy = "NOTE";
        orderDirection = "ASC";
    } else if (sortOption == "Note <") {
        orderBy = "NOTE";
        orderDirection = "DESC";
    } else if (sortOption == "Date >") {
        orderBy = "DATE_RES";
        orderDirection = "ASC";
    } else if (sortOption == "Date <") {
        orderBy = "DATE_RES";
        orderDirection = "DESC";
    }

    // Update the table with the new sorted data
    resultat res;
    QSqlQueryModel *model = res.trier(orderBy, orderDirection == "ASC" ? Qt::AscendingOrder : Qt::DescendingOrder);

    ui->aff_res->setRowCount(model->rowCount());
    ui->aff_res->setColumnCount(model->columnCount());

    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < model->columnCount(); ++j) {
            QString value = model->data(model->index(i, j)).toString();
            ui->aff_res->setItem(i, j, new QTableWidgetItem(value));
        }
    }
}

// AJOUTER
void MainWindow::on_ajout_res_clicked()
{
    int ID_ETUDIANT = ui->idl_res->text().toInt();
    QString NOM = ui->noml_res->text();
    QString MATIERE = ui->matl_res->text();
    QDate DATE_RES = ui->datel_res->date();
    double NOTE = ui->notel_res->text().toDouble();
    QString STATUT = ui->statutl_res->text();
    QDate currentDate = QDate::currentDate(); // Date actuelle du système

    // Vérification de l'ID (doit être un entier positif)
    if (ui->idl_res->text().isEmpty() || ID_ETUDIANT <= 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'ID doit être un entier positif."), QMessageBox::Cancel);
        return;
    }

    // Vérification du nom (doit contenir uniquement des lettres)


    // Vérification de la note (doit être entre 0 et 20)
    if (NOTE < 0 || NOTE > 20) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("La note doit être comprise entre 0 et 20."), QMessageBox::Cancel);
        return;
    }

    // Vérification de la date (doit être après la date du système)
    if (DATE_RES <= currentDate) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("La date du résultat doit être après la date actuelle."), QMessageBox::Cancel);
        return;
    }

    // Vérification que les champs ne sont pas vides
    if (NOM.isEmpty() || MATIERE.isEmpty() || STATUT.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez remplir tous les champs."), QMessageBox::Cancel);
        return;
    }

    // Vérification si l'ID existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM RESULTAT WHERE ID_ETUDIANT = :ID_ETUDIANT");
    checkQuery.bindValue(":ID_ETUDIANT", ID_ETUDIANT);
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Cet ID existe déjà dans la base de données."), QMessageBox::Cancel);
        return;
    }

    // Création de l'objet et tentative d'ajout
    resultat re(ID_ETUDIANT, NOM, MATIERE, STATUT, DATE_RES, NOTE);
    bool test = re.ajouter();
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Ajout réussi."), QMessageBox::Ok);
        on_pushButton_afficher_clicked(); // Actualiser l'affichage

        // Réinitialiser les champs après l'ajout
        ui->idl_res->clear();
        ui->noml_res->clear();
        ui->matl_res->clear();
        ui->datel_res->setDate(QDate::currentDate());
        ui->notel_res->clear();
        ui->statutl_res->clear();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec"), QObject::tr("Erreur lors de l'ajout."), QMessageBox::Cancel);
    }
}

// MODIFIER
void MainWindow::on_mod_res_clicked()
{
    int ID_ETUDIANT = ui->idl_res->text().toInt();
    QString NOM = ui->noml_res->text();
    QString MATIERE = ui->matl_res->text();
    QDate DATE_RES = ui->datel_res->date();
    double NOTE = ui->notel_res->text().toDouble();
    QString STATUT = ui->statutl_res->text();

    resultat re(ID_ETUDIANT, NOM, MATIERE, STATUT, DATE_RES, NOTE);
    bool test = re.modifier(ID_ETUDIANT);
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Modification réussie."), QMessageBox::Ok);
        on_pushButton_afficher_clicked();
        ui->idl_res->clear();
        ui->noml_res->clear();
        ui->matl_res->clear();
        ui->datel_res->setDate(QDate::currentDate()); // Remettre la date du jour
        ui->notel_res->clear();
        ui->statutl_res->clear();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec"), QObject::tr("Erreur lors de la modification."), QMessageBox::Cancel);
    }
}

// SUPPRIMER
void MainWindow::on_supp_res_clicked()
{
    int ID_ETUDIANT = ui->idl_res->text().toInt();

    if (ID_ETUDIANT == 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un ID valide."), QMessageBox::Cancel);
        return;
    }

    resultat re;
    bool test = re.supprimer(ID_ETUDIANT);
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Suppression réussie."), QMessageBox::Ok);
        on_pushButton_afficher_clicked();

        ui->idl_res->clear();
        ui->noml_res->clear();
        ui->matl_res->clear();
        ui->datel_res->setDate(QDate::currentDate()); // Remettre la date du jour
        ui->notel_res->clear();
        ui->statutl_res->clear();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec"), QObject::tr("Erreur lors de la suppression."), QMessageBox::Cancel);
    }
}


void MainWindow::on_aff_res_cellClicked(int row, int column)
{
    // Récupérer les valeurs de la ligne sélectionnée
    QString ID_ETUDIANT = ui->aff_res->item(row, 0)->text();
    QString NOM = ui->aff_res->item(row, 1)->text();
    QString MATIERE = ui->aff_res->item(row, 2)->text();
    QString STATUT = ui->aff_res->item(row, 3)->text();
    QString DATE_RES = ui->aff_res->item(row, 4)->text();
    QString NOTE = ui->aff_res->item(row, 5)->text();

    // Remplir les QLineEdit avec les valeurs sélectionnées
    ui->idl_res->setText(ID_ETUDIANT);
    ui->noml_res->setText(NOM);
    ui->matl_res->setText(MATIERE);
    ui->statutl_res->setText(STATUT);
    ui->datel_res->setDate(QDate::fromString(DATE_RES, "yyyy-MM-dd")); // Adapter le format si nécessaire
    ui->notel_res->setText(NOTE);
}


// RECHERCHE
void MainWindow::on_rech_res_clicked()
{
    QString rech = ui->rechl_res->text();
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT * FROM RESULTAT WHERE NOM LIKE :rech OR MATIERE LIKE :rech");
    query.bindValue(":rech", "%" + rech + "%");

    query.exec();
    model->setQuery(query);

    ui->aff_res->setRowCount(model->rowCount());
    ui->aff_res->setColumnCount(model->columnCount());

    for (int i = 0; i < model->rowCount(); ++i)
        for (int j = 0; j < model->columnCount(); ++j)
            ui->aff_res->setItem(i, j, new QTableWidgetItem(model->data(model->index(i, j)).toString()));
}

// TRIER PAR NOTE
void MainWindow::on_tri_res_clicked()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT * FROM RESULTAT ORDER BY NOTE DESC");
    query.exec();
    model->setQuery(query);

    ui->aff_res->setRowCount(model->rowCount());
    ui->aff_res->setColumnCount(model->columnCount());

    for (int i = 0; i < model->rowCount(); ++i)
        for (int j = 0; j < model->columnCount(); ++j)
            ui->aff_res->setItem(i, j, new QTableWidgetItem(model->data(model->index(i, j)).toString()));
}

//EXPORTER EN PDF

void MainWindow::on_exp_res_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF files (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdf(filePath);
    QPainter painter(&pdf);
    int x = 100, y = 100;
    int lineSpacing = 30;

    painter.setFont(QFont("Arial", 12));
    painter.drawText(x, y, "Liste des résultats étudiants");
    y += 2 * lineSpacing;

    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_ETUDIANT, NOM, MATIERE, STATUT, DATE_RES, NOTE FROM RESULTAT");
    query.exec();
    model->setQuery(query);

    // Écrire l'en-tête
    QStringList headers = {"ID", "Nom", "Matière", "Statut", "Date Résultat", "Note"};
    QString headerLine = headers.join(" | ");
    painter.drawText(x, y, headerLine);
    y += lineSpacing;

    // Écrire les données
    for (int row = 0; row < model->rowCount(); ++row) {
        QString line;
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            line += data + " | ";
        }
        painter.drawText(x, y, line);
        y += lineSpacing;

        // Sauter à la page suivante si nécessaire
        if (y > pdf.height() - 100) {
            pdf.newPage();
            y = 100;
        }
    }

    painter.end();
    QMessageBox::information(this, "Exportation", "PDF généré avec succès.");
}

