#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_center->setModel(C.afficherCenter());

    ui->lineEdit_capacite->setValidator(new QIntValidator(0, 99, this));
    ui->lineEdit_nom->setMaxLength(10);
    ui->lineEdit_adresse->setMaxLength(10);
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

    if (nom.isEmpty() || adresse.isEmpty() || capacite <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "Veuillez remplir tous les champs correctement !");
        return;
    }

    center C(nom, adresse, datec, capacite);
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
}


void MainWindow::on_pushButton_annuler_clicked()
{
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit->clear();
    ui->lineEdit_capacite->clear();
}


void MainWindow::on_pushButton_modifier_clicked()
{
    int idcenter = ui->lineEdit_idcenter->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QDate datec = ui->dateEdit->date();
    int capacite = ui->lineEdit_capacite->text().toInt();

    if (idcenter <= 0 || nom.isEmpty() || adresse.isEmpty() || capacite <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "Veuillez remplir tous les champs correctement !");
        return;
    }

    center C(idcenter, nom, adresse, datec, capacite);
    bool test = C.modifierCenter(C.getidcenter(), C.getnom(), C.getadresse(), C.getdatec(), C.getcapacite());

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
}


void MainWindow::on_pushButton_supprimer_clicked()
{

    C.setidcenter(ui->lineEdit_idcenter->text().toInt());
    bool test=C.supprimerCenter(C.getidcenter());
    QMessageBox msgBox;
    if (ui->lineEdit_idcenter->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                              QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de idcenter"), QMessageBox::Cancel);
    }
    else if (test)
    {
        QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                                 QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
        ui->tableView_center->setModel(C.afficherCenter());
    }

    ui->lineEdit_idcenter->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit->clear();
    ui->lineEdit_capacite->clear();
}


void MainWindow::on_tableView_center_clicked(const QModelIndex &index)
{
    ui->lineEdit_idcenter->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(),0)).toString());
    ui->lineEdit_nom->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(),1)).toString());
    ui->lineEdit_adresse->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(),2)).toString());
    ui->lineEdit_capacite->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(),4)).toString());

}

