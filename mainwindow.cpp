#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QIntValidator>
/*#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_center->setModel(C.afficherCenter());

    ui->lineEdit_capacite->setValidator(new QIntValidator(0, 99, this));
    ui->lineEdit_nom->setMaxLength(10);
    ui->lineEdit_adresse->setMaxLength(10);
    ui->lineEdit_disponibilite->setMaxLength(1); // On limite la saisie à 1 caractère
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_afficher_clicked()
{
    ui->tableView_center->setModel(C.afficherCenter());
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    QString nom = ui->lineEdit_nom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QDate datec = ui->dateEdit->date();
    int capacite = ui->lineEdit_capacite->text().toInt();
    int disponibilite = ui->lineEdit_disponibilite->text().toInt();

    if (nom.isEmpty() || adresse.isEmpty() || capacite <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "Veuillez remplir tous les champs correctement !");
        return;
    }

    if (disponibilite != 0 && disponibilite != 1) {
        QMessageBox::critical(this, "Erreur de saisie", "La disponibilité doit être 1 (disponible) ou 0 (non disponible).");
        return;
    }

    center C(nom, adresse, datec, capacite, disponibilite);
    bool test = C.ajouterCenter();

    if (test) {
        QMessageBox::information(this, "Ajout réussi", "L'enregistrement a été ajouté avec succès.");
        ui->tableView_center->setModel(C.afficherCenter());
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
    }

    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit->clear();
    ui->lineEdit_capacite->clear();
    ui->lineEdit_disponibilite->clear();
}

void MainWindow::on_pushButton_annuler_clicked()
{
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit->clear();
    ui->lineEdit_capacite->clear();
    ui->lineEdit_disponibilite->clear();
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int idcenter = ui->lineEdit_idcenter->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QDate datec = ui->dateEdit->date();
    int capacite = ui->lineEdit_capacite->text().toInt();
    int disponibilite = ui->lineEdit_disponibilite->text().toInt();

    if (idcenter <= 0 || nom.isEmpty() || adresse.isEmpty() || capacite <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "Veuillez remplir tous les champs correctement !");
        return;
    }

    if (disponibilite != 0 && disponibilite != 1) {
        QMessageBox::critical(this, "Erreur de saisie", "La disponibilité doit être 1 (disponible) ou 0 (non disponible).");
        return;
    }

     center C(nom, adresse, datec, capacite,disponibilite);
    bool test = C.modifierCenter(C.getidcenter(), C.getnom(), C.getadresse(), C.getdatec(), C.getcapacite(), C.getdisponibilite());

    if (test) {
        QMessageBox::information(this, "Modification réussie", "Les modifications ont été enregistrées.");
        ui->tableView_center->setModel(C.afficherCenter());
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }

    ui->lineEdit_idcenter->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit->clear();
    ui->lineEdit_capacite->clear();
    ui->lineEdit_disponibilite->clear();
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    C.setidcenter(ui->lineEdit_idcenter->text().toInt());
    bool test = C.supprimerCenter(C.getidcenter());
    QMessageBox msgBox;
    if (ui->lineEdit_idcenter->text() == "") {
        QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                              QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de idcenter"), QMessageBox::Cancel);
    } else if (test) {
        QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                                 QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
        ui->tableView_center->setModel(C.afficherCenter());
    }

    ui->lineEdit_idcenter->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit->clear();
    ui->lineEdit_capacite->clear();
    ui->lineEdit_disponibilite->clear();
}

void MainWindow::on_tableView_center_clicked(const QModelIndex &index)
{
    ui->lineEdit_idcenter->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 0)).toString());
    ui->lineEdit_nom->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 1)).toString());
    ui->lineEdit_adresse->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 2)).toString());
    ui->lineEdit_capacite->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 4)).toString());
    ui->lineEdit_disponibilite->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 5)).toString());
}

void MainWindow::on_pb_pdf_clicked() {
    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (!nomFichier.isEmpty()) {
        center centre;
        QSqlQueryModel *model = centre.afficherCenter();
        centre.exporterPDF(nomFichier, model);
        delete model;
        QMessageBox::information(this, "PDF Créé", "Le fichier PDF du centre a été généré avec succès.");
    }
}

void MainWindow::on_rechercherButton_clicked() {
    int id = ui->lineEdit_idcenter->text().toInt();  // Récupérer l'ID à partir de l'interface
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide (entier positif) pour la recherche.");
        return;
    }

    QSqlQueryModel* model = C.rechercher(id);

    if (model && model->rowCount() > 0) {
        ui->tableView_center->setModel(model);
        QMessageBox::information(this, "Recherche réussie", "Le centre avec l'ID spécifié a été trouvé.");
    } else {
        QMessageBox::warning(this, "Erreur", "Aucun centre trouvé avec cet ID.");
        delete model;
    }
}
void MainWindow::on_trierButton_clicked() {
    ui->tableView_center->setModel(C.trierParCapacite());
    QMessageBox::information(this, "Tri par Capacité", "Les centres ont été triés du plus grand au plus petit.");
}

/*void MainWindow::on_statistiqueButton_centres_clicked() {
    // Appel de la méthode statique pour obtenir les statistiques de disponibilité des centres
    QMap<QString, double> stats = center::obtenirStatistiquesDisponibilite();

    // Effacer les éléments précédents dans le listWidget
    ui->listWidget->clear();

    // Ajouter les résultats au listWidget sous forme de pourcentages
    for (auto it = stats.constBegin(); it != stats.constEnd(); ++it) {
        QString result = QString("%1 : %2%").arg(it.key()).arg(QString::number(it.value(), 'f', 2));
        ui->listWidget->addItem(result);
    }
   // addToHistory("Statistique des centres en texte", 0);
}
void MainWindow::on_statistiqueButton_centres_graph_clicked() {
    // Appel de la méthode pour obtenir les statistiques de disponibilité des centres
    QMap<QString, double> stats = center::obtenirStatistiquesDisponibilite();

    // Calculer le total des centres
    double totalCenters = 0;
    for (auto it = stats.constBegin(); it != stats.constEnd(); ++it) {
        totalCenters += it.value();
    }

    // Vider le layout avant d'ajouter un nouveau graphique
    QLayoutItem* item;
    while ((item = ui->verticalLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Créer un pie series pour le graphique
    QPieSeries *series = new QPieSeries();

    // Ajouter les données de disponibilité dans le graphique avec le pourcentage
    for (auto it = stats.constBegin(); it != stats.constEnd(); ++it) {
        QString label = QString("%1: %2%").arg(it.key()).arg(it.value(), 0, 'f', 1);
        series->append(label, it.value());
    }

    // Créer un graphique à partir de la série
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques de disponibilité des centres");

    // Créer un chart view pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);  // Améliorer l'anti-aliasing

    // Afficher le graphique dans le layout
    ui->verticalLayout->addWidget(chartView);
    addToHistory("Statistique des centres par graphe", 0);
}
*/
