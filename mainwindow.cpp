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
#include <QRegularExpression>
#include "stat.h"
#include "Arduino.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupArduinoConnection();

    // Connecter le signal de tri
    connect(ui->Ctri_res, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_tri_res_clicked);

    // Afficher les données initiales
    on_pushButton_afficher_clicked();

    // Charger les centres dans le combobox
    QSqlQuery queryCentres;
    queryCentres.exec("SELECT IDCENTRE, NOM FROM CENTRE");
    while (queryCentres.next()) {
        QString idCentre = queryCentres.value(0).toString();
        QString nomCentre = queryCentres.value(1).toString();
        ui->centrebox_res->addItem(nomCentre, idCentre);
    }
}

MainWindow::~MainWindow()
{
    // Libère l'interface utilisateur
    delete ui;
}


void MainWindow::on_pushButton_afficher_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_ETUDIANT, NUMC_ETUDIANT, NOM, MATIERE, NOTE, DATE_RES, STATUT, IDCENTRE FROM RESULTAT");

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

    // Sauvegarder le numéro d'étudiant actuellement sélectionné
    QString selectedNumc = ui->numcl_res->text();
    int selectedRow = -1;

    if (sortOption == "NOTE <") {
        orderBy = "NOTE";
        orderDirection = "ASC";
    } else if (sortOption == "NOTE >") {
        orderBy = "NOTE";
        orderDirection = "DESC";
    } else if (sortOption == "DATE <") {
        orderBy = "DATE_RES";
        orderDirection = "ASC";
    } else if (sortOption == "DATE >") {
        orderBy = "DATE_RES";
        orderDirection = "DESC";
    }

    // Update the table with the new sorted data
    resultat res;
    QSqlQueryModel *model = res.trier(orderBy, orderDirection);

    ui->aff_res->setRowCount(model->rowCount());
    ui->aff_res->setColumnCount(model->columnCount());

    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < model->columnCount(); ++j) {
            QString value = model->data(model->index(i, j)).toString();
            ui->aff_res->setItem(i, j, new QTableWidgetItem(value));

            // Si c'est la colonne du numéro d'étudiant et que la valeur correspond à celle sélectionnée
            if (j == 1 && value == selectedNumc) {
                selectedRow = i;
            }
        }
    }

    // Si on a trouvé la ligne correspondant à l'étudiant sélectionné, la sélectionner
    if (selectedRow >= 0) {
        ui->aff_res->selectRow(selectedRow);
    }
}


void MainWindow::on_tri_res_clicked()
{
    on_sortCriteriaChanged();
}

void MainWindow::on_ajout_res_clicked()
{
    QString NUMC_ETUDIANT = ui->numcl_res->text();
    QString NOM = ui->noml_res->text();
    QString MATIERE = ui->matl_res->text();
    double NOTE = ui->notel_res->text().toDouble();
    QDate DATE_RES = ui->datel_res->date();
    QString STATUT = ui->statutl_res->text();

    // Récupérer l'ID_CENTRE sélectionné dans le combobox
    QString ID_CENTRE = ui->centrebox_res->currentData().toString();

    // Vérifications des champs obligatoires
    if (NUMC_ETUDIANT.isEmpty() || NOM.isEmpty() || MATIERE.isEmpty() || STATUT.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez remplir tous les champs obligatoires."), QMessageBox::Cancel);
        return;
    }

    // Vérification du format NUMC_ETUDIANT (3 chiffres + 3 lettres parmi A,B,C,D + 3 chiffres)
    QRegularExpression regex("^\\d{3}[A-D]{3}\\d{3}$");
    if (!regex.match(NUMC_ETUDIANT).hasMatch()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Le numéro d'étudiant doit suivre le format: 3 chiffres + 3 lettres (A,B,C,D) + 3 chiffres.\nExemple: 123ABC456"),
                              QMessageBox::Cancel);
        return;
    }

    // Vérification que la note est valide (entre 0 et 20)
    if (NOTE < 0 || NOTE > 20) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("La note doit être comprise entre 0 et 20."), QMessageBox::Cancel);
        return;
    }

    // Vérification si l'ID existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM RESULTAT WHERE NUMC_ETUDIANT = :NUMC_ETUDIANT");
    checkQuery.bindValue(":NUMC_ETUDIANT", NUMC_ETUDIANT);
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Cet étudiant a déjà un résultat enregistré."), QMessageBox::Cancel);
        return;
    }

    // Création et exécution de la requête d'insertion
    QSqlQuery query;
    query.prepare("INSERT INTO RESULTAT (NUMC_ETUDIANT, NOM, MATIERE, DATE_RES, STATUT, NOTE, IDCENTRE) "
                  "VALUES (:numc, :nom, :matiere, :date, :statut, :note, :centre)");
    query.bindValue(":numc", NUMC_ETUDIANT);
    query.bindValue(":nom", NOM);
    query.bindValue(":matiere", MATIERE);
    query.bindValue(":date", DATE_RES);
    query.bindValue(":statut", STATUT);
    query.bindValue(":note", NOTE);
    query.bindValue(":centre", ID_CENTRE);

    if (query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Résultat enregistré avec succès."), QMessageBox::Ok);
        on_pushButton_afficher_clicked();

        // Réinitialiser les champs
        ui->numcl_res->clear();
        ui->noml_res->clear();
        ui->matl_res->clear();
        ui->datel_res->setDate(QDate::currentDate());
        ui->notel_res->clear();
        ui->statutl_res->clear();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de l'enregistrement: ") + query.lastError().text(), QMessageBox::Cancel);
    }
}

void MainWindow::on_mod_res_clicked()
{
    QString NUMC_ETUDIANT = ui->numcl_res->text();
    QString NOM = ui->noml_res->text();
    QString MATIERE = ui->matl_res->text();
    double NOTE = ui->notel_res->text().toDouble();
    QDate DATE_RES = ui->datel_res->date();
    QString STATUT = ui->statutl_res->text();

    // Récupérer l'ID_CENTRE sélectionné dans le combobox
    QString ID_CENTRE = ui->centrebox_res->currentData().toString();

    // Vérifications
    if (NUMC_ETUDIANT.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez sélectionner un résultat à modifier."), QMessageBox::Cancel);
        return;
    }

    // Vérification du format NUMC_ETUDIANT (3 chiffres + 3 lettres parmi A,B,C,D + 3 chiffres)
    QRegularExpression regex("^\\d{3}[A-D]{3}\\d{3}$");
    if (!regex.match(NUMC_ETUDIANT).hasMatch()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Le numéro d'étudiant doit suivre le format: 3 chiffres + 3 lettres (A,B,C,D) + 3 chiffres.\nExemple: 123ABC456"),
                              QMessageBox::Cancel);
        return;
    }

    // Vérification que la note est valide (entre 0 et 20)
    if (NOTE < 0 || NOTE > 20) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("La note doit être comprise entre 0 et 20."), QMessageBox::Cancel);
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE RESULTAT SET "
                  "NOM = :nom, "
                  "MATIERE = :matiere, "
                  "DATE_RES = :date, "
                  "STATUT = :statut, "
                  "NOTE = :note, "
                  "IDCENTRE = :centre "
                  "WHERE NUMC_ETUDIANT = :numc");
    query.bindValue(":numc", NUMC_ETUDIANT);
    query.bindValue(":nom", NOM);
    query.bindValue(":matiere", MATIERE);
    query.bindValue(":date", DATE_RES);
    query.bindValue(":statut", STATUT);
    query.bindValue(":note", NOTE);
    query.bindValue(":centre", ID_CENTRE);

    if (query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Modification enregistrée avec succès."), QMessageBox::Ok);
        on_pushButton_afficher_clicked();

        // Réinitialiser les champs
        ui->numcl_res->clear();
        ui->noml_res->clear();
        ui->matl_res->clear();
        ui->datel_res->setDate(QDate::currentDate());
        ui->notel_res->clear();
        ui->statutl_res->clear();

    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de la modification: ") + query.lastError().text(), QMessageBox::Cancel);
    }
}

void MainWindow::on_supp_res_clicked()
{
    QString NUMC_ETUDIANT = ui->numcl_res->text();

    if (NUMC_ETUDIANT.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez sélectionner un résultat à supprimer."), QMessageBox::Cancel);
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM RESULTAT WHERE NUMC_ETUDIANT = :numc");
    query.bindValue(":numc", NUMC_ETUDIANT);

    if (query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Résultat supprimé avec succès."), QMessageBox::Ok);
        on_pushButton_afficher_clicked();

        // Réinitialiser les champs
        ui->numcl_res->clear();
        ui->noml_res->clear();
        ui->matl_res->clear();
        ui->datel_res->setDate(QDate::currentDate());
        ui->notel_res->clear();
        ui->statutl_res->clear();

    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de la suppression: ") + query.lastError().text(), QMessageBox::Cancel);
    }
}

void MainWindow::on_aff_res_cellClicked(int row, int column)
{
    // Sélectionner toute la ligne
    ui->aff_res->selectRow(row);

    QString ID_ETUDIANT = ui->aff_res->item(row, 0)->text();
    QString NUMC_ETUDIANT = ui->aff_res->item(row, 1)->text();
    QString NOM = ui->aff_res->item(row, 2)->text();
    QString MATIERE = ui->aff_res->item(row, 3)->text();
    QString NOTE = ui->aff_res->item(row, 4)->text();
    QString DATE_RES_STR = ui->aff_res->item(row, 5)->text();
    QString STATUT = ui->aff_res->item(row, 6)->text();

    QDate DATE_RES = QDate::fromString(DATE_RES_STR, Qt::ISODate);

    // Afficher les champs
    ui->numcl_res->setText(NUMC_ETUDIANT);
    ui->noml_res->setText(NOM);
    ui->matl_res->setText(MATIERE);
    ui->datel_res->setDate(DATE_RES);
    ui->notel_res->setText(NOTE);
    ui->statutl_res->setText(STATUT);

    // Récupérer l'ID_CENTRE de l'étudiant sélectionné
    QString ID_CENTRE = "";
    if (ui->aff_res->columnCount() > 7) {
        ID_CENTRE = ui->aff_res->item(row, 7)->text();
    }

    // Sélectionner le centre correspondant dans le combobox
    for (int i = 0; i < ui->centrebox_res->count(); i++) {
        if (ui->centrebox_res->itemData(i).toString() == ID_CENTRE) {
            ui->centrebox_res->setCurrentIndex(i);
            break;
        }
    }
}


void MainWindow::on_rech_res_clicked()
{
    QString rech = ui->rechl_res->text();
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT * FROM RESULTAT WHERE NOM LIKE :rech OR MATIERE LIKE :rech OR NUMC_ETUDIANT LIKE :rech");
    query.bindValue(":rech", "%" + rech + "%");

    query.exec();
    model->setQuery(query);

    ui->aff_res->setRowCount(model->rowCount());
    ui->aff_res->setColumnCount(model->columnCount());

    for (int i = 0; i < model->rowCount(); ++i)
        for (int j = 0; j < model->columnCount(); ++j)
            ui->aff_res->setItem(i, j, new QTableWidgetItem(model->data(model->index(i, j)).toString()));
}
void MainWindow::on_exp_res_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter le formulaire", "", "PDF files (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    int margin = 50;
    int y = margin;
    int lineSpacing = 35;

    QFont titleFont("Arial", 14, QFont::Bold);
    QFont normalFont("Arial", 11);
    QFont boldFont("Arial", 11, QFont::Bold);

    // Titre
    painter.setFont(titleFont);
    painter.drawText(QRect(margin, y, pdf.width() - 2 * margin, 50), Qt::AlignCenter, "RÉCLAMATION SUR ABSENCE DES EMPLOYÉS");
    y += 70;

    // Date
    painter.setFont(normalFont);
    painter.drawText(margin, y, "Date: " + QDate::currentDate().toString("dd/MM/yyyy"));
    y += lineSpacing * 2;

    // Section 1
    painter.setFont(boldFont);
    painter.drawText(margin, y, "1. INFORMATIONS DE L'EMPLOYÉ");
    y += lineSpacing;

    painter.setFont(normalFont);
    painter.drawText(margin, y, "Nom et prénom: _________________________________________________");
    y += lineSpacing;
    painter.drawText(margin, y, "Matricule: _____________    Service: ______________________________");
    y += lineSpacing * 2;

    // Section 2
    painter.setFont(boldFont);
    painter.drawText(margin, y, "2. DÉTAILS DE L'ABSENCE");
    y += lineSpacing;

    painter.setFont(normalFont);
    painter.drawText(margin, y, "Date(s) d'absence: du ____/____/____ au ____/____/____");
    y += lineSpacing;

    painter.drawText(margin, y, "Motif (cocher la case appropriée):");
    y += lineSpacing;

    QStringList motifs = {
        "☐ Maladie (avec certificat médical joint)",
        "☐ Raisons familiales impérieuses",
        "☐ Formation professionnelle",
        "☐ Autre (préciser): ____________________________________"
    };
    for (const QString &motif : motifs) {
        painter.drawText(margin + 20, y, motif);
        y += lineSpacing;
    }

    y += lineSpacing;

    // Signature
    painter.drawText(margin, y, "Je certifie sur l'honneur l'exactitude des informations ci-dessus.");
    y += lineSpacing;
    painter.drawText(margin, y, "Signature: __________________________");
    y += lineSpacing * 2;

    // Section 3
    painter.setFont(boldFont);
    painter.drawText(margin, y, "À REMPLIR PAR L'ADMINISTRATION");
    y += lineSpacing;

    painter.setFont(normalFont);
    painter.drawText(margin, y, "Statut de la réclamation:");
    y += lineSpacing;

    painter.drawText(margin + 20, y, "☐ Acceptée     ☐ Refusée");
    y += lineSpacing;

    painter.drawText(margin, y, "Commentaires:");
    y += lineSpacing;

    painter.drawRect(margin, y, pdf.width() - 2 * margin, lineSpacing * 2);
    y += lineSpacing * 2 + 10;

    painter.drawText(margin, y, "Cachet et signature: __________________________");

    painter.end();

    QMessageBox::information(this, "Exportation", "Le formulaire PDF a été généré avec succès.");
}
void MainWindow::on_stats_res_clicked()
{
    StatDialog *statDialog = new StatDialog(this);
    statDialog->updateStatistics();
    statDialog->exec();
}


void MainWindow::setupArduinoConnection()
{
    if(arduino.connect_arduino()) {
        qDebug() << "Connected to Arduino on port" << arduino.portName();
    } else {
        qWarning() << "Arduino connection failed";
        QMessageBox::warning(this, "Arduino",
                             "Could not connect to Arduino. Please check connection.");
    }
}
void MainWindow::on_recherche_etudiant_clicked()
{
    QString numcEtudiant = ui->rech_ard_res->text().trimmed();
    qDebug() << "DEBUG: NUMC_ETUDIANT entré =" << numcEtudiant;

    // Vérification du format
    QRegularExpression regex("^\\d{3}[A-Za-z]{3}\\d{3}$");
    if (!regex.match(numcEtudiant).hasMatch()) {
        QMessageBox::warning(this, "Format incorrect",
                             "Format: 3 chiffres + 3 lettres + 3 chiffres\nEx: 123ABC456");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT MATIERE, NOTE, DATE_RES FROM RESULTAT WHERE NUMC_ETUDIANT = :numc");
    query.bindValue(":numc", numcEtudiant);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "Introuvable", "Aucun étudiant avec ce numéro");
        return;
    }

    // Préparation du message LCD
    QString line1 = "Etud:" + numcEtudiant.left(11); // Max 16 caractères

    // Récupérer la date et la formater (jj-mm)
    QDate date = query.value(2).toDate();
    QString dateStr = date.toString("dd-MM");

    QString matiere = query.value(0).toString().left(4);
    QString note = QString::number(query.value(1).toDouble(), 'f', 1);

    // Construction de la ligne 2 avec date en premier
    QString line2 = dateStr + " " + matiere + ":" + note;

    // Pour les résultats multiples (si nécessaire)
    while (query.next() && line2.length() < 16) {
        QDate nextDate = query.value(2).toDate();
        QString nextDateStr = nextDate.toString("dd-MM");
        QString nextMatiere = query.value(0).toString().left(4);
        QString nextNote = QString::number(query.value(1).toDouble(), 'f', 1);

        QString nextItem = " " + nextDateStr + " " + nextMatiere + ":" + nextNote;

        if (line2.length() + nextItem.length() <= 16) {
            line2 += nextItem;
        }
    }

    // Tronquer si trop long
    line2 = line2.left(16);

    // Envoi à l'Arduino
    if (arduino.isConnected()) {
        QByteArray toSend = (line1 + "\n" + line2).toUtf8();
        qDebug() << "Envoi Arduino:" << toSend;

        // 1. Vider le buffer de réception
        arduino.read_from_arduino();

        // 2. Envoyer les données
        arduino.write_to_arduino(toSend);

        // 3. Attendre la réponse
        QByteArray response;
        for (int i = 0; i < 10; i++) {
            response = arduino.read_from_arduino();
            if (!response.isEmpty()) break;
            QThread::msleep(100);
        }

        qDebug() << "Reponse Arduino:" << response;

        if (response.isEmpty()) {
            QMessageBox::warning(this, "Communication", "Pas de réponse de l'Arduino");
        }
    } else {
        QMessageBox::warning(this, "Connexion", "Arduino non connecté");
    }
}
