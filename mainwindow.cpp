#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>
#include <QSqlQueryModel>

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

// Fonction pour afficher les résultats
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

// Fonction pour ajouter un résultat
void MainWindow::on_ajout_res_clicked()
{
    int ID_ETUDIANT = ui->idl_res->text().toInt();
    QString NOM = ui->noml_res->text();
    QString MATIERE = ui->matl_res->text();
    QDate DATE_RES = ui->datel_res->date();
    double NOTE = ui->notel_res->text().toDouble();
    QString STATUT = ui->statutl_res->text();

    resultat re(ID_ETUDIANT, NOM, MATIERE, STATUT, DATE_RES, NOTE);
    bool test = re.ajouter();
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Ajout réussi."), QMessageBox::Ok);
        on_pushButton_afficher_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec"), QObject::tr("Erreur lors de l'ajout."), QMessageBox::Cancel);
    }
}

// Fonction pour modifier un résultat
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
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec"), QObject::tr("Erreur lors de la modification."), QMessageBox::Cancel);
    }
}

// Fonction pour supprimer un résultat
void MainWindow::on_supp_res_clicked()
{
    int ID_ETUDIANT = ui->idl_res->text().toInt();

    resultat re;
    bool test = re.supprimer(ID_ETUDIANT);
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Suppression réussie."), QMessageBox::Ok);
        on_pushButton_afficher_clicked();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec"), QObject::tr("Erreur lors de la suppression."), QMessageBox::Cancel);
    }
}
