#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "examen.h"

Examen examen;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize the table


    // Populate the table with data
    examen.afficher(ui->tableWidget_examens);


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_ajout_examButton_clicked()
{
    // Récupération des valeurs des champs
    QString titre = ui->lineEdit_titre->text();
    QString sujet = ui->lineEdit_sujet->text();
    QString statut = ui->lineEdit_statut->text();

    // Vérifier si les champs sont vides
    if (titre.isEmpty() || sujet.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }

    // Vérifier si les champs contiennent uniquement des chiffres
    QRegularExpression onlyNumbers("^\\d+$");
    if (onlyNumbers.match(titre).hasMatch() || onlyNumbers.match(sujet).hasMatch() || onlyNumbers.match(statut).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Les champs Titre, Sujet et Statut ne doivent pas être uniquement numériques.");
        return;
    }

    // Création de l'objet Examen
    Examen examen(titre, sujet, statut);

    // Tentative d'ajout de l'examen à la base de données
    if (examen.ajouter()) {
        // Rafraîchir la table
        examen.afficher(ui->tableWidget_examens);

        // Nettoyer les champs
        ui->lineEdit_titre->clear();
        ui->lineEdit_sujet->clear();
        ui->lineEdit_statut->clear();

        QMessageBox::information(this, "Succès", "Examen ajouté avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'examen.");
    }
}


void MainWindow::on_modifexamButton_clicked()
{
    // Retrieve the ID from the UI field
    bool ok;
    int id = ui->idExam->text().toInt(&ok);

    // Validate the ID
    if (!ok || id <= 0) {
        QMessageBox::critical(this, "ID invalide", "Veuillez entrer un ID valide.");
        return;
    }



    // Retrieve data from the UI fields
    QString titre = ui->lineEdit_titre->text();
    QString sujet = ui->lineEdit_sujet->text();
    QString statut = ui->lineEdit_statut->text();


    // Validate the input fields
    if (titre.isEmpty() || sujet.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }
    // Vérifier si les champs contiennent uniquement des chiffres
    QRegularExpression onlyNumbers("^\\d+$");
    if (onlyNumbers.match(titre).hasMatch() || onlyNumbers.match(sujet).hasMatch() || onlyNumbers.match(statut).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Les champs Titre, Sujet et Statut ne doivent pas être uniquement numériques.");
        return;
    }

    // Create an Examen object
    Examen examen(id, titre, sujet, statut);

    // Attempt to modify the Examen in the database
    if (examen.modifier(id)) {
        // Refresh the table view
        examen.afficher(ui->tableWidget_examens);

        // Clear the input fields
        ui->idExam->clear();
        ui->lineEdit_titre->clear();
        ui->lineEdit_sujet->clear();
        ui->lineEdit_statut->clear();

        QMessageBox::information(this, "Succès", "Examen modifié avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de l'examen.");
    }
}

void MainWindow::on_suppexamButton_clicked()
{
    // Get the currently selected row
    int currentRow = ui->tableWidget_examens->currentRow();

    // Check if a row is selected
    if (currentRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Veuillez sélectionner un examen à supprimer.");
        return;
    }

    // Get the ID from the first column of the selected row
    int id = ui->tableWidget_examens->item(currentRow, 0)->text().toInt();

    // Confirm deletion with the user
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
                                                              "Êtes-vous sûr de vouloir supprimer cet examen?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Create an Examen object
        Examen examen;

        // Attempt to delete the Examen from the database
        if (examen.supprimer(id)) {
            // Refresh the table widget
            examen.afficher(ui->tableWidget_examens);

            // Clear the input fields
            ui->idExam->clear();
            ui->lineEdit_titre->clear();
            ui->lineEdit_sujet->clear();
            ui->lineEdit_statut->clear();

            QMessageBox::information(this, "Succès", "Examen supprimé avec succès.");
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression de l'examen.");
        }
    }
}

void MainWindow::on_tableWidget_examens_itemDoubleClicked(QTableWidgetItem *item)
{
    // Get the selected row
    int row = item->row();

    // Retrieve values from all columns of the selected row
    QString id = ui->tableWidget_examens->item(row, 0)->text();
    QString titre = ui->tableWidget_examens->item(row, 1)->text();
    QString sujet = ui->tableWidget_examens->item(row, 2)->text();
    QString statut = ui->tableWidget_examens->item(row, 3)->text();

    // Set the values in their respective line edits
    ui->idExam->setText(id);
    ui->lineEdit_titre->setText(titre);  // Replace with your actual line edit name
    ui->lineEdit_sujet->setText(sujet);  // Replace with your actual line edit name
    ui->lineEdit_statut->setText(statut);



}


void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
    examen.rechercherParTitre(ui->tableWidget_examens, arg1);
}


void MainWindow::on_trier_Butoon_clicked()
{
    // Determine the sort order
    Qt::SortOrder order = Qt::AscendingOrder; // Default to ascending order

    if (ui->comboBox_order->currentText().compare("Descendant", Qt::CaseInsensitive) == 0) {
        order = Qt::DescendingOrder;
    }

    qDebug() << "Order:" << (order == Qt::AscendingOrder ? "Ascendant" : "Descendant");

    // Sort the QTableWidget by the "Sujet" column
    ui->tableWidget_examens->sortItems(2, order); // Assuming "Sujet" is the 3rd column (index 2)
}
//nheeeb nrawah l medenine X(
