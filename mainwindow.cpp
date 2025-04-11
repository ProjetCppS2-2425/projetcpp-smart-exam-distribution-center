#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <string>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTableWidget>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);  // 4 colonnes : Nom, Quantité, Prix achat, Disponibilité

    // Définir les en-têtes (titres) de colonnes
    QStringList headers;
    headers << "Nom" << "Quantité" << "Prix d'achat" << "Disponibilité";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Ajuster la taille des colonnes à la taille du contenu
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Optionnel : rendre le tableau non éditable directement par l'utilisateur
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    QString nom = ui->nom_ajt->text();
    QString quantiteStr = ui->qte_ajt->text();
    QString prix = ui->prix_ajt->text();
    QRegularExpression regex("^[0-9.]+$"); // Only digits allowed
    if(nom.length()==0){
        QMessageBox::warning(this, tr("Erreur"), tr("Le nom ne doit pas etre vide."));
        ui->nom_ajt->clear();
        ui->nom_ajt->setFocus();
        return;
    }
    if (!regex.match(quantiteStr).hasMatch()) {
        QMessageBox::warning(this, tr("Erreur"), tr("La quantité doit contenir uniquement des chiffres."));
        ui->qte_ajt->clear();
        ui->qte_ajt->setFocus();
        return;
    }
    int quantite = quantiteStr.toInt();
    if(quantite<0){
        QMessageBox::warning(this, tr("Erreur"), tr("La quantité ne peut pas être négative."));
        ui->qte_ajt->clear();
        ui->qte_ajt->setFocus();
        return;
    }

    if (!regex.match(prix).hasMatch()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Le prix doit contenir uniquement des chiffres ou des , ."));
        ui->prix_ajt->clear();
        ui->prix_ajt->setFocus();
        return;
    }
    float prix_achat = prix.toFloat();
    if(prix_achat<0){
        QMessageBox::warning(this, tr("Erreur"), tr("Le prix ne peut pas être négatif."));
        ui->prix_ajt->clear();
        ui->prix_ajt->setFocus();
        return;
    }
    produit p(nom, quantite, prix_achat);

    if (p.ajouter())
    {
        QMessageBox::information(this, tr("Succès"), tr("Produit ajouté avec succès."));
        ui->nom_ajt->clear();
        ui->prix_ajt->clear();
        ui->qte_ajt->clear();
    }
    else
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de l'ajout du produit."));
    }
}

void MainWindow::on_supprimer_clicked()
{
    QString nom = ui->nom_supp->text();

    produit p;

    if(nom.length()==0){
        QMessageBox::warning(this, tr("Erreur"), tr("Le nom ne doit pas etre vide."));
        ui->nom_supp->setFocus();
        return;
    }

    if (p.supprimer(nom))
    {
        QMessageBox::information(this, tr("Succès"), tr("Produit supprimé avec succès."));
        ui->nom_supp->clear();
    }
    else
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Produit introuvable."));
        ui->nom_supp->clear();
    }
}
void MainWindow::on_debiter_clicked()
{
    QString nom = ui->nom_deb->text();
    //int qte = ui->qte_deb->text().toInt();
    QString qte = ui->qte_deb->text();
    if(nom.length()==0){
        QMessageBox::warning(this, tr("Erreur"), tr("Le nom ne doit pas etre vide."));
        ui->nom_deb->clear();
        ui->nom_deb->setFocus();
        return;
    }
    QRegularExpression regex("^[0-9.]+$");
    if (!regex.match(qte).hasMatch()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Le prix doit contenir uniquement des chiffres ou des , ."));
        ui->qte_deb->clear();
        ui->qte_deb->setFocus();
        return;
    }
    produit p;
    int result = p.debiter(nom, qte.toInt());
    if (result == 2) {
        QMessageBox::information(this, "Succès", "Quantité débitée avec succès !");
        ui->nom_deb->clear();
        ui->qte_deb->clear();
    } else if (result == 1) {
        QMessageBox::critical(this, "Erreur", "Stock insuffisant pour ce produit.");
        ui->nom_deb->clear();
        ui->qte_deb->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Produit introuvable ou problème lors du débit.");
        ui->nom_deb->clear();
        ui->qte_deb->clear();
    }
}
void MainWindow::on_modifier_clicked(){
    QString nom = ui->nom_mod->text();
    if(nom.length()==0){
        QMessageBox::warning(this, tr("Erreur"), tr("Le nom ne doit pas etre vide."));
        ui->nom_supp->setFocus();
        ui->nom_supp->setFocus();
        return;
    }
    produit p;
    if(p.modifier(nom)){
        QMessageBox::information(this, "Succès", "status modifier avec succes !");
        ui->nom_mod->clear();
    }
    else{
        QMessageBox::critical(this, "Erreur", "probleme");
    }
}

void MainWindow::on_nom_recherche_textChanged(const QString &arg1)
{
    if(! ui->qte_rech->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Un seul critere de recherche est autorise");
        ui->qte_rech->clear();
    }
    if (ui->disp_rech->currentIndex() > 0) {
        QMessageBox::critical(this, "Erreur", "Un seul critere de recherche est autorise");
        ui->disp_rech->setCurrentIndex(0);
    }
    // If the search field is empty, clear the table and return
    if (arg1.isEmpty()) {
        ui->tableWidget->setRowCount(0);
        return;
    }

    produit p;
    QSqlQuery query = p.rechercher(arg1);

    // Nettoyer le TableWidget
    ui->tableWidget->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        // Remplir les colonnes
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // Nom
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));  // Quantité
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));  // Prix achat

        // Disponibilité : afficher "Oui" ou "Non"
        QString dispo = query.value(3).toBool() ? "Oui" : "Non";
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(dispo));

        row++;
    }
}

void MainWindow::on_qte_rech_textChanged(const QString &text){
    if(! ui->nom_recherche->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Un seul critere de recherche est autorise");
        ui->nom_recherche->clear();
    }
    if (ui->disp_rech->currentIndex() > 0) {
        QMessageBox::critical(this, "Erreur", "Un seul critere de recherche est autorise");
        ui->disp_rech->setCurrentIndex(0);
    }
    if (text.isEmpty()) {
        ui->tableWidget->setRowCount(0);
        return;
    }
    bool ok;
    int qte=text.toInt(&ok);
    if (!ok) {
        ui->tableWidget->setRowCount(0);
        QMessageBox::critical(this, "Erreur", "Entiers seulement.");
        ui->qte_rech->clear();
        return; // Invalid input (non-numeric)
    }
    produit p;
    QSqlQuery query = p.rechercheqte(qte);

    // Nettoyer le TableWidget
    ui->tableWidget->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        // Remplir les colonnes
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // Nom
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));  // Quantité
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));  // Prix achat

        // Disponibilité : afficher "Oui" ou "Non"
        QString dispo = query.value(3).toBool() ? "Oui" : "Non";
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(dispo));

        row++;
    }
}
void MainWindow::on_disp_rech_currentTextChanged(const QString &text)
{
    int dispo = (text.toLower() == "disponible") ? 1 : 0;
    produit p;
    QSqlQuery query = p.recherchedisp(dispo);
    ui->tableWidget->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        QString dispoText = query.value(3).toInt() == 1 ? "Oui" : "Non";
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(dispoText));
        row++;
    }
}
void MainWindow::on_crit_tri_currentTextChanged(const QString &text)
{
    produit p;
    QSqlQuery query = p.tri(text);

    ui->tableWidget->setRowCount(0);
    int row = 0;

    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // Nom
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));  // Quantité
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));  // Prix
        QString dispoText = query.value(3).toInt() == 1 ? "Oui" : "Non";
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(dispoText));
        row++;
    }
}
void MainWindow::on_pdf_clicked() {
    if (ui->tableWidget->rowCount() == 0) {
        QMessageBox::warning(this, "PDF", "Le tableau est vide. Aucun PDF généré.");
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);

    QTextDocument doc;
    QTextCursor cursor(&doc);

    QTextTableFormat tableFormat;
    tableFormat.setBorder(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setCellPadding(4);
    tableFormat.setCellSpacing(0);
    tableFormat.setAlignment(Qt::AlignCenter);

    int rows = ui->tableWidget->rowCount();
    int cols = ui->tableWidget->columnCount();

    QTextTable *table = cursor.insertTable(rows + 1, cols, tableFormat);

    // Insert headers
    for (int col = 0; col < cols; ++col) {
        cursor.insertText(ui->tableWidget->horizontalHeaderItem(col)->text());
        cursor.movePosition(QTextCursor::NextCell);
    }

    // Insert table data
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            cursor.insertText(item ? item->text() : "");
            cursor.movePosition(QTextCursor::NextCell);
        }
    }

    doc.print(&writer);

    QMessageBox::information(this, "PDF", "Fichier PDF généré avec succès !");
}

