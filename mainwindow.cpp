#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "examen.h"
#include "qrcode.h"
#include <QDate>
#include <QPainter>
#include <QGraphicsEffect>  // or more specifically:
#include <QGraphicsDropShadowEffect>
#include <QTimer>
#include <QSqlError>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QBoxLayout>




#include <QFile>
#include <QPdfWriter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPrinter>
#include <QTextDocument>
#include <QDateTime>



#include <QtCharts>         // Main Qt Charts include
#include <QChartView>       // For displaying the chart
#include <QBarSeries>       // For bar series
#include <QBarSet>          // For individual bars
#include <QValueAxis>       // For Y-axis
#include <QBarCategoryAxis> // For X-axis categories
#include <QFrame>           // For the frame container
#include <QVBoxLayout>




Examen examen;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Initialize tray icon
    m_trayIcon = new QSystemTrayIcon(this);
    if (QFile::exists(":/icons/notification.png")) {
        m_trayIcon->setIcon(QIcon(":/icons/notification.png"));
    } else {
        m_trayIcon->setIcon(QIcon::fromTheme("dialog-information"));
    }
    m_trayIcon->show();

    QPushButton *checkExamsBtn = new QPushButton("Check Upcoming Exams", this);
    checkExamsBtn->setObjectName("checkExamsButton");
    checkExamsBtn->setGeometry(10, 10, 200, 40);

    // Add icon to the right of the text
    QIcon examIcon(":/icons/notification.png"); // Replace with your actual icon path
    checkExamsBtn->setIcon(examIcon);
    checkExamsBtn->setIconSize(QSize(20, 20)); // Adjust size as needed

    // Align icon to the right of text
    checkExamsBtn->setLayoutDirection(Qt::RightToLeft);
    checkExamsBtn->setStyleSheet("QPushButton {"
                                 "    padding-right: 5px;"  // Space between icon and right edge
                                 "    text-align: left;"     // Keep text left-aligned
                                 "}");

    connect(checkExamsBtn, &QPushButton::clicked, this, &MainWindow::on_checkExamsButton_clicked);











    // Populate the table with data
    examen.afficher(ui->tableWidget_examens);
    populateTransportComboBox();
    checkUpcomingExams();
    displayExamStatsChart();
    ui->idExam->setVisible(false);



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
    QDate date_examen = ui->dateEdit_exam->date();  // Get date from dateEdit
    int id_transport = ui->comboBox_transport->currentData().toInt();

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
    Examen examen(titre, sujet, statut, date_examen, id_transport);

    // Tentative d'ajout de l'examen à la base de données
    if (examen.ajouter()) {
        // Rafraîchir la table
        examen.afficher(ui->tableWidget_examens);
        checkUpcomingExams();
           displayExamStatsChart();

        // Nettoyer les champs
        ui->lineEdit_titre->clear();
        ui->lineEdit_sujet->clear();
        ui->lineEdit_statut->clear();
        ui->dateEdit_exam->setDate(QDate::currentDate());  // Reset to current date
        ui->comboBox_transport->setCurrentIndex(0);

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
    QDate date_examen = ui->dateEdit_exam->date();
    int id_transport = ui->comboBox_transport->currentData().toInt();

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
    Examen examen(id, titre, sujet, statut, date_examen, id_transport);

    // Attempt to modify the Examen in the database
    if (examen.modifier(id)) {
        // Refresh the table view
        examen.afficher(ui->tableWidget_examens);
           displayExamStatsChart();
           checkUpcomingExams();

        // Clear the input fields
        ui->idExam->clear();
        ui->lineEdit_titre->clear();
        ui->lineEdit_sujet->clear();
        ui->lineEdit_statut->clear();
        ui->dateEdit_exam->setDate(QDate::currentDate());
        ui->comboBox_transport->setCurrentIndex(0);

        QMessageBox::information(this, "Succès", "Examen modifié avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de l'examen.");
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
    QDate date_examen = ui->tableWidget_examens->item(row, 4)->data(Qt::DisplayRole).toDate();
    QString id_transport = ui->tableWidget_examens->item(row, 5)->text();

    // Set the values in their respective line edits
    ui->idExam->setText(id);
    ui->lineEdit_titre->setText(titre);
    ui->lineEdit_sujet->setText(sujet);
    ui->lineEdit_statut->setText(statut);
    ui->dateEdit_exam->setDate(date_examen);

    // Set the transport combo box
    int index = ui->comboBox_transport->findData(id_transport.toInt());
    if (index >= 0) {
        ui->comboBox_transport->setCurrentIndex(index);
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
               displayExamStatsChart();

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


void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
    examen.rechercherExamens(ui->tableWidget_examens, arg1);
}


void MainWindow::on_trier_Butoon_clicked()
{
    // Determine the sort order
    Qt::SortOrder order = Qt::AscendingOrder; // Default to ascending order
    QString orderText = ui->comboBox_order->currentText();

    if (orderText.compare("Descendant", Qt::CaseInsensitive) == 0) {
        order = Qt::DescendingOrder;
    }

    qDebug() << "Order:" << (order == Qt::AscendingOrder ? "Ascendant" : "Descendant");

    // Determine which column to sort by
    int sortColumn = -1;
    QString sortField = ui->comboBoxsortchamp->currentText();

    // Map combo box selections to column indices
    if (sortField.compare("Titre", Qt::CaseInsensitive) == 0) {
        sortColumn = 1; // "Titre" is the 2nd column (index 1)
    }
    else if (sortField.compare("Sujet", Qt::CaseInsensitive) == 0) {
        sortColumn = 2; // "Sujet" is the 3rd column (index 2)
    }
    else if (sortField.compare("Date Examen", Qt::CaseInsensitive) == 0) {
        sortColumn = 4; // "Date Examen" is the 5th column (index 4)
    }

    // Sort the QTableWidget by the selected column
    if (sortColumn != -1) {
        ui->tableWidget_examens->sortItems(sortColumn, order);

        // For date columns, ensure proper sorting by setting custom sort role
        if (sortColumn == 4) { // Date Examen column
            for (int row = 0; row < ui->tableWidget_examens->rowCount(); ++row) {
                QTableWidgetItem *item = ui->tableWidget_examens->item(row, sortColumn);
                if (item) {
                    item->setData(Qt::UserRole, QDate::fromString(item->text(), "dd/MM/yyyy"));
                }
            }
            ui->tableWidget_examens->sortItems(sortColumn, order);
        }
    }
    else {
        qDebug() << "Invalid sort column selected";
    }
}
//nheeeb nrawah l medenine X(


void MainWindow::populateTransportComboBox()
{
    ui->comboBox_transport->clear();

    QSqlQuery query("SELECT id_transport, NOM_LIVREUR FROM transport ORDER BY NOM_LIVREUR");
    while (query.next()) {
        ui->comboBox_transport->addItem(query.value(1).toString(), query.value(0).toInt());
    }

    // Add a default empty option if needed
    ui->comboBox_transport->insertItem(0, "Sélectionnez un transport", 0);
    ui->comboBox_transport->setCurrentIndex(0);
}

void MainWindow::on_tableWidget_examens_cellClicked(int row, int column)
{
    // Get exam ID from the first column of clicked row
    QString examId = ui->tableWidget_examens->item(row, 0)->text();
    QString qrCodeData;
    QString destination;
    // Query to get exam info with transport destination
    QSqlQuery qry;
    qry.prepare("SELECT e.id, e.titre, e.sujet, e.statut, t.destination "
                "FROM examen e "
                "LEFT JOIN transport t ON e.id_transport = t.id_transport "
                "WHERE e.id = :examId");
    qry.bindValue(":examId", examId);
    if(qry.exec() && qry.next())
    {
        // Update UI fields
        ui->idExam->setText(qry.value(0).toString());
        ui->lineEdit_titre->setText(qry.value(1).toString());
        ui->lineEdit_sujet->setText(qry.value(2).toString());
        ui->lineEdit_statut->setText(qry.value(3).toString());
        destination = qry.value(4).toString(); // Get destination
        // Format QR code data
        qrCodeData = QString(
                         "Exam Information\n"
                         "----------------\n"
                         "ID: %1\n"
                         "Title: %2\n"
                         "Subject: %3\n"
                         "Status: %4\n"
                         "Destination: %5")
                         .arg(qry.value(0).toString(),
                              qry.value(1).toString(),
                              qry.value(2).toString(),
                              qry.value(3).toString(),
                              destination.isEmpty() ? "Not specified" : destination);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Could not retrieve exam information.");
        return;
    }
    // Generate QR Code
    using namespace qrcodegen;
    try {
        QrCode qr = QrCode::encodeText(qrCodeData.toUtf8().constData(), QrCode::Ecc::MEDIUM);
        QImage im(qr.getSize(), qr.getSize(), QImage::Format_RGB32);

        // Create QR code image
        for (int y = 0; y < qr.getSize(); y++) {
            for (int x = 0; x < qr.getSize(); x++) {
                im.setPixel(x, y, qr.getModule(x, y) ? qRgb(0, 0, 0) : qRgb(255, 255, 255));
            }
        }

        // Display in label (smaller size)
        if (ui->qrCodeLabel) {
            // Set fixed size for the label (adjust as needed)
            ui->qrCodeLabel->setFixedSize(150, 150);  // Smaller than your current 100x100

            // Scale with smooth transformation
            QPixmap qrPixmap = QPixmap::fromImage(im.scaled(
                ui->qrCodeLabel->width(),
                ui->qrCodeLabel->height(),
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation  // Better quality for small sizes
                ));

            ui->qrCodeLabel->setPixmap(qrPixmap);
            ui->qrCodeLabel->setAlignment(Qt::AlignCenter);

            // Optional: Add a subtle border
            ui->qrCodeLabel->setStyleSheet("border: 1px solid #ddd;");
        }
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "QR Code Error", QString("Failed to generate QR code: %1").arg(e.what()));
    }
}


void MainWindow::checkUpcomingExams()
{
    m_upcomingExams.clear(); // Clear previous notifications

    QDate today = QDate::currentDate();
    QDate tomorrow = today.addDays(1);

    QSqlQuery query;
    query.prepare("SELECT e.titre, e.date_examen, t.nom_livreur "
                  "FROM examen e "
                  "JOIN transport t ON e.id_transport = t.id_transport "
                  "WHERE e.date_examen = :tomorrow");
    query.bindValue(":tomorrow", tomorrow);

    if (!query.exec()) {
        qDebug() << "Error checking upcoming exams:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString examTitle = query.value(0).toString();
        QDate examDate = query.value(1).toDate();
        QString livreurName = query.value(2).toString();

        QString message = QString("Examen '%1' demain (%2)\nLivreur: %3")
                              .arg(examTitle)
                              .arg(examDate.toString("dd/MM/yyyy"))
                              .arg(livreurName);

        // 1. Show temporary notification
        if (m_trayIcon && m_trayIcon->isVisible()) {
            m_trayIcon->showMessage(
                "Rappel Examen",
                message,
                QSystemTrayIcon::Information,
                10000 // Show for 10 seconds
                );
        }

        // 2. Store for later viewing
        m_upcomingExams.append(message);
    }

    // Update the "Check Upcoming Exams" button
    updateExamButton();
}
void MainWindow::updateExamButton()
{
    QPushButton *examBtn = findChild<QPushButton*>("checkExamsButton");
    if (!examBtn) return;

    if (m_upcomingExams.isEmpty()) {
        examBtn->setText("Check Upcoming Exams");
        examBtn->setStyleSheet(""); // Default style
    } else {
        examBtn->setText(QString("Check Upcoming Exams (%1)").arg(m_upcomingExams.size()));
        examBtn->setStyleSheet("background-color: #FFA500; font-weight: bold;"); // Orange highlight
    }
}

void MainWindow::on_checkExamsButton_clicked()
{
    if (m_upcomingExams.isEmpty()) {
        QMessageBox::information(this, "Upcoming Exams", "No upcoming exams found");
        return;
    }

    QString fullMessage = "Upcoming Exams:\n\n" + m_upcomingExams.join("\n\n");

    QMessageBox msgBox;
    msgBox.setWindowTitle("Upcoming Exam Notifications");
    msgBox.setText(fullMessage);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}







void MainWindow::on_pushButton_3_clicked()
{
    // Demander à l'utilisateur où sauvegarder le PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty())
        return;

    // S'assurer que le nom de fichier a l'extension .pdf
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    // Créer l'imprimante
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));


    // Créer le contenu HTML pour le PDF
    QTextDocument doc;
    QString html = "<h1 align='center'>Liste des Examens</h1>";
    html += "<p align='center'>Date: " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss") + "</p>";
    html += "<table border='1' cellspacing='0' cellpadding='3' width='100%'>";

    // Ajouter les en-têtes du tableau
    html += "<tr bgcolor='#eeeeee'>";
    html += "<th>ID</th>";
    html += "<th>Titre</th>";
    html += "<th>Sujet</th>";
    html += "<th>Statut</th>";
    html += "<th>Date Examen</th>";
    html += "<th>Destination</th>";
    html += "<th>Livreur</th>";
    html += "<th>Date Livraison</th>";
    html += "</tr>";

    // Récupérer les données du QTableWidget
    QTableWidget* tableWidget = ui->tableWidget_examens; // Assurez-vous d'utiliser le nom correct de votre QTableWidget

    if (tableWidget->rowCount() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter");
        return;
    }

    // Lire les données du tableau et les ajouter au HTML
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = tableWidget->item(row, col);
            QString cellText = item ? item->text() : "";
            html += "<td>" + cellText + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";

    // Ajouter un pied de page
    html += "<p align='right'><i>Document généré par le système de gestion des examens</i></p>";

    // Définir le contenu HTML et imprimer vers le PDF
    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "PDF Exporté", "Le fichier PDF a été généré avec succès.\n" + fileName);
}


void MainWindow::displayExamStatsChart() {
    // Clear existing content
    QLayout *existingLayout = ui->frame->layout();

    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete existingLayout;
    }

    // Create and configure new layout
    QVBoxLayout *layout = new QVBoxLayout(ui->frame);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Get updated statistics data
    Examen exam;
    auto stats = exam.getExamCountByStatus();

    // ===== BAR CHART =====
    QBarSeries *series = new QBarSeries();

    // Color palette for bars
    const QList<QColor> colors = {
        QColor("#4285F4"), QColor("#EA4335"), QColor("#FBBC05"),
        QColor("#34A853"), QColor("#673AB7")
    };

    // Create categories and barset
    QStringList categories;
    QBarSet *barSet = new QBarSet("Exam Status");

    int colorIndex = 0;
    int maxValue = 0; // Pour stocker la valeur maximale
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        categories << it.key();
        *barSet << it.value();
        barSet->setColor(colors[colorIndex % colors.size()]);
        colorIndex++;

        // Trouver la valeur maximale
        if (it.value() > maxValue) {
            maxValue = it.value();
        }
    }

    series->append(barSet);

    // Chart configuration
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Exam Status Distribution");
    chart->setTitleFont(QFont("Segoe UI", 12, QFont::Bold));
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(false);
    chart->setBackgroundBrush(Qt::transparent);

    // Axes configuration
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    axisY->setTitleText("Number of Exams");

    // Configurer l'échelle de l'axe Y correctement
    axisY->setRange(0, maxValue + 1); // Ajouter 1 pour un peu d'espace au-dessus
    axisY->setTickCount(qMin(maxValue + 2, 10)); // Limiter à 10 ticks maximum

    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Add to layout
    layout->addWidget(chartView);

    // Ensure the frame updates
    ui->frame->update();
}

