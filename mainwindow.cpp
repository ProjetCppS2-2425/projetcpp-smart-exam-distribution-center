#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QCalendarWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextEdit>
#include <QHorizontalBarSeries>


#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDesktopServices>

#include <QVBoxLayout>
#include <QLabel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QAuthenticator>
#include <QEventLoop>
#include <QDebug>
#include <QNetworkRequest>
#include <QTextEdit>
#include <QCalendarWidget>

#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QRegularExpression>

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrinterInfo>
#include <QtGui/QPainter>
#include <QtGui/QFont>
#include <QtCore/QDate>
#include <QtGui/QPageSize>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QMap>

#include "examen.h"
#include "qrcode.h"
#include "resultat.h"


Examen examen;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableView_center->setModel(C.afficherCenter());
    displayAvailabilityStats();

    ui->lineEdit_capacite->setValidator(new QIntValidator(0, 99, this));
    ui->lineEdit_nom->setMaxLength(10);
    ui->lineEdit_adresse->setMaxLength(10);
    ui->lineEdit_disponibilite->setMaxLength(1);
    connect(ui->pb_pdf, &QPushButton::clicked, this, &MainWindow::on_pb_pdf_clicked);


    /////////////////////////////////////examen
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
    populateCenterComboBox();


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
    QDate datec = ui->dateEdit_->date();
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
         populateCenterComboBox();
         displayAvailabilityStats();
        QMessageBox::information(this, "Ajout réussi", "L'enregistrement a été ajouté avec succès.");
        ui->tableView_center->setModel(C.afficherCenter());
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
    }

    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit_->clear();
    ui->lineEdit_capacite->clear();
    ui->lineEdit_disponibilite->clear();
}
void MainWindow::on_pushButton_annuler_clicked()
{
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit_->clear();
    ui->lineEdit_capacite->clear();
    ui->lineEdit_disponibilite->clear();
}
void MainWindow::on_pushButton_modifier_clicked()
{
    int idcenter = ui->lineEdit_idcenter->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QDate datec = ui->dateEdit_->date();
    int capacite = ui->lineEdit_capacite->text().toInt();
    int newDisponibilite = ui->lineEdit_disponibilite->text().toInt();
    // Input validation (unchanged)
    if (idcenter <= 0 || nom.isEmpty() || adresse.isEmpty() || capacite <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "Veuillez remplir tous les champs correctement !");
        return;
    }
    if (newDisponibilite != 0 && newDisponibilite != 1) {
        QMessageBox::critical(this, "Erreur de saisie", "La disponibilité doit être 1 (disponible) ou 0 (non disponible).");
        return;
    }
    // Get current availability before modification
    int oldDisponibilite = getCurrentCenterAvailability(idcenter);
    // Perform modification
    bool test = C.modifierCenter(idcenter, nom, adresse, datec, capacite, newDisponibilite);

    if (test) {
         populateCenterComboBox();
        displayAvailabilityStats();
        QMessageBox::information(this, "Modification réussie", "Le centre a été modifié avec succès.");
        ui->tableView_center->setModel(C.afficherCenter());

        // Additional notification for availability change
        if (oldDisponibilite != newDisponibilite) {
            QString statusMessage = (newDisponibilite == 1)
            ? "Le centre " + nom + " est maintenant disponible ✅"
            : "Le centre " + nom + " est maintenant non disponible ❌";
            QString fullMessage = QString("%1\n\nAdresse: %2\nCapacité: %3 personnes")
                                      .arg(statusMessage)
                                      .arg(adresse)
                                      .arg(capacite);
            if (!sendCenterStatusSMS(nom, newDisponibilite)) {
                qDebug() << "Échec d'envoi SMS, mais modification sauvegardée";
                QMessageBox::warning(this, "Notification SMS",
                                     "Le statut a été mis à jour mais l'envoi du SMS a échoué");
            } else {
                qDebug() << "SMS envoyé avec succès pour le centre" << nom;
            }
        }
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }

    // Clear fields (unchanged)
    ui->lineEdit_idcenter->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit_->clear();
    ui->lineEdit_capacite->clear();
    ui->lineEdit_disponibilite->clear();
}
// Helper function to get current availability
int MainWindow::getCurrentCenterAvailability(int centerId)
{
    QSqlQuery query;
    query.prepare("SELECT DISPONIBILITE FROM CENTER WHERE IDCENTER = :id");
    query.bindValue(":id", centerId);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return -1; // Return -1 if error occurs
}
void MainWindow::on_pushButton_supprimer_clicked()
{
    C.setidcenter(ui->lineEdit_idcenter->text().toInt());
    bool test = C.supprimerCenter(C.getidcenter());
    if (ui->lineEdit_idcenter->text() == "") {
        QMessageBox::critical(this, QObject::tr("Suppression Erreur"),
                              QObject::tr("Echec de Suppression!!!\n""Veuillez remplir le champ idcenter"), QMessageBox::Cancel);
    } else if (test) {
         populateCenterComboBox();

            displayAvailabilityStats();
        QMessageBox::information(this, QObject::tr("Suppression avec Succès"),
                                 QObject::tr("Suppression avec succès"), QMessageBox::Cancel);
        ui->tableView_center->setModel(C.afficherCenter());
    }

    ui->lineEdit_idcenter->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit_->clear();
    ui->lineEdit_capacite->clear();
    ui->lineEdit_disponibilite->clear();
}
void MainWindow::on_tableView_center_clicked(const QModelIndex &index)
{
    // Fill the form fields as before
    ui->lineEdit_idcenter->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 0)).toString());
    ui->lineEdit_nom->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 1)).toString());
    ui->lineEdit_adresse->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 2)).toString());
    ui->dateEdit_->setDate(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 3)).toDate());
    ui->lineEdit_capacite->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 4)).toString());
    ui->lineEdit_disponibilite->setText(ui->tableView_center->model()->data(ui->tableView_center->model()->index(index.row(), 5)).toString());

    // Check if the clicked cell is in the calendar column (column 6)
    if (index.column() == 6) {
        int row = index.row();
        int centerId = ui->tableView_center->model()->data(ui->tableView_center->model()->index(row, 0)).toInt();

        // Create a calendar dialog
        QDialog *calendarDialog = new QDialog(this);
        calendarDialog->setWindowTitle("Examens programmés");
        calendarDialog->setMinimumSize(600, 400);

        QVBoxLayout *layout = new QVBoxLayout(calendarDialog);

        // Get center name for display
        QString centerName = ui->tableView_center->model()->data(ui->tableView_center->model()->index(row, 1)).toString();
        QLabel *titleLabel = new QLabel("Calendrier des examens pour " + centerName);
        titleLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(titleLabel);

        // Create calendar widget
        QCalendarWidget *calendar = new QCalendarWidget(calendarDialog);
        layout->addWidget(calendar);

        // Get exam dates from database for this center - NOTE THE CHANGED COLUMN NAME
        QSqlQuery query;
        query.prepare("SELECT date_examen FROM examen WHERE id_centre = :id_centre");  // Changed to id_centre
        query.bindValue(":id_centre", centerId);  // Changed parameter name for clarity

        // Store all exam dates
        QList<QDate> examDates;

        if (query.exec()) {
            while (query.next()) {
                QDate examDate = query.value("date_examen").toDate();
                examDates.append(examDate);
            }
        } else {
            qDebug() << "Error fetching exam dates:" << query.lastError().text();
            QMessageBox::warning(this, "Erreur", "Impossible de charger les dates d'examen");
        }

        // Set up calendar formatting for dates with exams
        QTextCharFormat examFormat;
        examFormat.setBackground(QBrush(QColor(100, 250, 100, 100))); // Light green background
        examFormat.setForeground(QBrush(Qt::darkGreen));              // Dark green text
        examFormat.setFontWeight(QFont::Bold);

        // Apply formatting to dates with exams
        for (const QDate &date : examDates) {
            calendar->setDateTextFormat(date, examFormat);
        }

        // Add labels showing exam info when a date is clicked
        QLabel *examInfoLabel = new QLabel("Cliquez sur une date pour voir les détails des examens");
        examInfoLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(examInfoLabel);

        QTextEdit *examDetailsText = new QTextEdit();
        examDetailsText->setReadOnly(true);
        examDetailsText->setMaximumHeight(150);
        layout->addWidget(examDetailsText);

        connect(calendar, &QCalendarWidget::clicked, [=](const QDate &date) {
            QSqlQuery detailsQuery;
            QString dateStr = date.toString("yyyy-MM-dd");

            detailsQuery.prepare(
                "SELECT id, titre, sujet, statut, TO_CHAR(date_examen, 'HH24:MI') as heure "
                "FROM examen "
                "WHERE id_centre = :id_centre AND TRUNC(date_examen) = TO_DATE(:date_examen, 'YYYY-MM-DD') "
                "ORDER BY date_examen");
            detailsQuery.bindValue(":id_centre", centerId);
            detailsQuery.bindValue(":date_examen", dateStr);

            QString details = QString("<h3>Examens du %1</h3>").arg(date.toString("dd/MM/yyyy"));

            if (detailsQuery.exec()) {
                if (detailsQuery.size() == 0) {
                    details += "<p style='color:gray;'>Aucun examen prévu cette journée</p>";
                } else {
                    while (detailsQuery.next()) {
                        details += "<div style='margin-bottom:15px; padding:5px; background-color:#f5f5f5;'>";
                        details += QString("<b>%1</b> (ID: %2)<br>")
                                       .arg(detailsQuery.value("titre").toString())
                                       .arg(detailsQuery.value("id").toInt());
                        details += QString("<b>Heure:</b> %1<br>").arg(detailsQuery.value("heure").toString());
                        details += QString("<b>Sujet:</b> %1<br>").arg(detailsQuery.value("sujet").toString());

                        // Color code the status
                        QString status = detailsQuery.value("statut").toString();
                        QString statusColor = "black";
                        if (status == "planifié") statusColor = "blue";
                        else if (status == "terminé") statusColor = "green";
                        else if (status == "annulé") statusColor = "red";

                        details += QString("<b>Statut:</b> <span style='color:%1'>%2</span><br>")
                                       .arg(statusColor)
                                       .arg(status);

                        details += "</div>";
                    }
                }
            } else {
                details += "<p style='color:red;'>Erreur de chargement des détails</p>";
                qDebug() << "Error fetching exam details:" << detailsQuery.lastError().text();
            }

            examDetailsText->setHtml(details);
        });

        // Add a close button
        QPushButton *closeButton = new QPushButton("Fermer");
        layout->addWidget(closeButton);
        connect(closeButton, &QPushButton::clicked, calendarDialog, &QDialog::accept);

        // Show dialog
        calendarDialog->exec();
        delete calendarDialog; // Clean up after dialog is closed
    }
}
void MainWindow::on_pb_pdf_clicked() {

        // Get file name and location from user
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF",
                                                        QDir::homePath() + "/centres.pdf",
                                                        "Fichiers PDF (*.pdf)");
        if (fileName.isEmpty())
            return;

        // Initialize PDF printer
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        printer.setPageOrientation(QPageLayout::Landscape); // Use landscape for more space

        // Initialize painter for PDF
        QPainter painter;
        if(!painter.begin(&printer)) {
            QMessageBox::warning(this, "Export PDF", "Erreur lors de la création du PDF");
            return;
        }

        // Set up fonts
        QFont titleFont("Arial", 18, QFont::Bold);
        QFont headerFont("Arial", 12, QFont::Bold);
        QFont subHeaderFont("Arial", 11, QFont::Bold);
        QFont contentFont("Arial", 10);

        // Get center model data
        QSqlQueryModel* centerModel = C.afficherCenter();
        int centerRowCount = centerModel->rowCount();
        int centerColumnCount = centerModel->columnCount() - 1; // Exclude the calendar column

        // Painting constants
        int margin = 50;
        int headerHeight = 50;
        int rowHeight = 30;
        int centerColumnWidth = (printer.width() - 2 * margin) / centerColumnCount;
        int y = margin; // Current y position for painting

        // Paint main title
        painter.setFont(titleFont);
        painter.drawText(margin, y, printer.width() - 2 * margin, headerHeight,
                         Qt::AlignCenter, "Liste des Centres et leurs Examens");
        y += headerHeight + 20;

        // For each center, paint its details and associated exams
        for (int centerRow = 0; centerRow < centerRowCount; ++centerRow) {
            // Check if we need a new page
            if (y > printer.height() - margin * 2) {
                printer.newPage();
                y = margin;
            }

            // Get center ID for fetching exams
            int centerID = centerModel->data(centerModel->index(centerRow, 0)).toInt();

            // Paint center title
            painter.setFont(subHeaderFont);
            QString centerName = centerModel->data(centerModel->index(centerRow, 1)).toString();
            painter.drawText(margin, y, printer.width() - 2 * margin, rowHeight,
                             Qt::AlignLeft, "Centre: " + centerName);
            y += rowHeight;

            // Paint center header
            painter.setFont(headerFont);
            for (int col = 0; col < centerColumnCount; ++col) {
                QRect headerRect(margin + col * centerColumnWidth, y,
                                 centerColumnWidth, rowHeight);
                painter.drawRect(headerRect);
                painter.drawText(headerRect, Qt::AlignCenter,
                                 centerModel->headerData(col, Qt::Horizontal).toString());
            }
            y += rowHeight;

            // Paint center data
            painter.setFont(contentFont);
            for (int col = 0; col < centerColumnCount; ++col) {
                QRect cellRect(margin + col * centerColumnWidth, y,
                               centerColumnWidth, rowHeight);
                painter.drawRect(cellRect);

                // Format date if it's a date column
                QString cellData;
                if (col == 3) { // Date column
                    QDate date = centerModel->data(centerModel->index(centerRow, col)).toDate();
                    cellData = date.toString("dd/MM/yyyy");
                } else {
                    cellData = centerModel->data(centerModel->index(centerRow, col)).toString();
                }
                painter.drawText(cellRect, Qt::AlignCenter, cellData);
            }
            y += rowHeight + 20;

            // Fetch exams for this center - Fixed query to match calendar implementation
            QSqlQuery examQuery;
            examQuery.prepare("SELECT id, titre, sujet, statut, id_transport, TO_CHAR(date_examen, 'DD/MM/YYYY HH24:MI') as date_examen "
                              "FROM examen WHERE id_centre = :id_centre ORDER BY date_examen");
            examQuery.bindValue(":id_centre", centerID);

            if (examQuery.exec()) {
                // Check if we have results
                bool hasExams = false;
                // We need to check if there are records but preserve the query position
                if (examQuery.first()) {
                    hasExams = true;
                    examQuery.seek(-1); // Reset position to before first record
                }

                if (hasExams) {
                    // Paint exams title
                    painter.setFont(subHeaderFont);
                    painter.drawText(margin, y, printer.width() - 2 * margin, rowHeight,
                                     Qt::AlignLeft, "Examens associés:");
                    y += rowHeight;

                    // Define exam columns and widths
                    QStringList examHeaders;
                    examHeaders << "ID" << "TITRE" << "SUJET" << "STATUT" << "ID_TRANSPORT" << "DATE_EXAMEN";
                    int examColumnCount = examHeaders.size();
                    int examColumnWidth = (printer.width() - 2 * margin) / examColumnCount;

                    // Paint exam header
                    painter.setFont(headerFont);
                    for (int col = 0; col < examColumnCount; ++col) {
                        QRect headerRect(margin + col * examColumnWidth, y,
                                         examColumnWidth, rowHeight);
                        painter.drawRect(headerRect);
                        painter.drawText(headerRect, Qt::AlignCenter, examHeaders[col]);
                    }
                    y += rowHeight;

                    // Paint exam data
                    painter.setFont(contentFont);
                    while (examQuery.next()) {
                        // Check if we need a new page
                        if (y > printer.height() - margin * 2) {
                            printer.newPage();
                            y = margin;

                            // Repaint exam header on new page
                            painter.setFont(headerFont);
                            for (int col = 0; col < examColumnCount; ++col) {
                                QRect headerRect(margin + col * examColumnWidth, y,
                                                 examColumnWidth, rowHeight);
                                painter.drawRect(headerRect);
                                painter.drawText(headerRect, Qt::AlignCenter, examHeaders[col]);
                            }
                            y += rowHeight;
                            painter.setFont(contentFont);
                        }

                        for (int col = 0; col < examColumnCount; ++col) {
                            QRect cellRect(margin + col * examColumnWidth, y,
                                           examColumnWidth, rowHeight);
                            painter.drawRect(cellRect);

                            QString cellData = examQuery.value(col).toString();
                            painter.drawText(cellRect, Qt::AlignCenter, cellData);
                        }
                        y += rowHeight;
                    }
                } else {
                    // No exams for this center
                    painter.setFont(contentFont);
                    painter.drawText(margin, y, printer.width() - 2 * margin, rowHeight,
                                     Qt::AlignLeft, "Aucun examen associé à ce centre.");
                    y += rowHeight;
                }
            } else {
                // Query error
                painter.setFont(contentFont);
                painter.drawText(margin, y, printer.width() - 2 * margin, rowHeight,
                                 Qt::AlignLeft, "Erreur lors de la récupération des examens.");
                qDebug() << "Exam query error:" << examQuery.lastError().text();
                y += rowHeight;
            }

            y += 30; // Add extra space between centers

            // Add a page break after each center except the last one
            if (centerRow < centerRowCount - 1) {
                printer.newPage();
                y = margin;
            }
        }

        // Paint footer on last page
        QString footer = "Document généré le " + QDate::currentDate().toString("dd/MM/yyyy");
        painter.drawText(margin, printer.height() - margin,
                         printer.width() - 2 * margin, margin,
                         Qt::AlignRight | Qt::AlignBottom, footer);

        // End painting
        painter.end();
        QMessageBox::information(this, "Export PDF", "Le document PDF a été créé avec succès!");

        // Open the PDF with default system viewer
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    }
void MainWindow::on_rechercherButton_clicked()
{
    QString recherche = ui->lineEdit_recherche_multi->text();
    QSqlQueryModel* model = C.rechercherMulti(recherche);
    ui->tableView_center->setModel(model);

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Recherche", "Aucun centre ne correspond à votre recherche.");
    }
}
void MainWindow::on_trierButton_clicked() {
    ui->tableView_center->setModel(C.trierParMultiplesCritères());
    QMessageBox::information(this, "Tri effectué", "Les centres ont été triés par capacité croissante, date de création décroissante et nom en ordre alphabétique.");
}
bool MainWindow::sendCenterStatusSMS(const QString& centerName, int newStatus)
{
    const QString TWILIO_ACCOUNT_SID = "AC31f1268ce2f6a62341a342d17cb39186";
    const QString TWILIO_AUTH_TOKEN = "d4523496fcb8d795cae2622ac68076c2";
    const QString TWILIO_PHONE_NUMBER = "+19162326244";
    const QString TO_PHONE_NUMBER = "+21652551135";

    QString statusText = (newStatus == 1) ? "disponible" : "pas disponible";
    QString message = QString("Nous vous informons que notre centre \"%1\" est %2.")
                          .arg(centerName)
                          .arg(statusText);

    QNetworkAccessManager manager;
    QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json")
                 .arg(TWILIO_ACCOUNT_SID));

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QString auth = QString("%1:%2").arg(TWILIO_ACCOUNT_SID).arg(TWILIO_AUTH_TOKEN);
    request.setRawHeader("Authorization", QString("Basic %1").arg(QString(auth.toUtf8().toBase64())).toUtf8());

    QUrlQuery params;
    params.addQueryItem("From", TWILIO_PHONE_NUMBER);
    params.addQueryItem("To", TO_PHONE_NUMBER);
    params.addQueryItem("Body", message);

    QNetworkReply* reply = manager.post(request, params.toString().toUtf8());

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    bool success = (reply->error() == QNetworkReply::NoError);
    reply->deleteLater();
    return success;
}
void MainWindow::displayAvailabilityStats()
{
    // Get data
    QMap<int, int> stats = C.getCentersByAvailability();
    int available = stats.value(1);
    int unavailable = stats.value(0);
    int total = available + unavailable;
    int maxValue = qMax(available, unavailable);

    qDebug() << "Stats - Available:" << available << "Unavailable:" << unavailable;

    // Clear frame
    QLayout* layout = ui->frame->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0))) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete layout;
    }

    // Create new layout
    QVBoxLayout* newLayout = new QVBoxLayout(ui->frame);
    ui->frame->setLayout(newLayout);

    // Create chart
    QBarSet* availableSet = new QBarSet("Disponibles");
    QBarSet* unavailableSet = new QBarSet("Non disponibles");

    *availableSet << available;
    *unavailableSet << unavailable;

    availableSet->setColor(QColor(67, 160, 71));    // Green
    unavailableSet->setColor(QColor(229, 57, 53));  // Red

    QHorizontalBarSeries* series = new QHorizontalBarSeries();
    series->append(availableSet);
    series->append(unavailableSet);
    series->setBarWidth(0.7);  // Make bars wider

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Centres par disponibilité");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Force minimum chart size
    chart->setMinimumSize(350, 250);

    // Categories for X axis
    QStringList categories;
    categories << "Status";

    // Configure axes
    QBarCategoryAxis* axisY = new QBarCategoryAxis();
    axisY->append(categories);
    axisY->setLabelsVisible(false);  // Hide category label

    QValueAxis* axisX = new QValueAxis();
    axisX->setLabelFormat("%d");

    // Calculate optimal axis max and tick count
    int step = 1;
    int xMax = maxValue;

    if (maxValue > 10) {
        step = (maxValue <= 20) ? 2 :
                   (maxValue <= 50) ? 5 :
                   (maxValue <= 100) ? 10 : 20;
        xMax = ((maxValue / step) + 1) * step;
    } else if (maxValue == 0) {
        xMax = 2;  // Show some scale even when zero
    }

    axisX->setRange(0, xMax);
    axisX->setTickCount(xMax/step + 1);
    axisX->setMinorTickCount(0);

    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addAxis(axisX, Qt::AlignBottom);

    series->attachAxis(axisY);
    series->attachAxis(axisX);

    // Display chart
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Add chart to layout
    newLayout->addWidget(chartView);

    // Add text summary
    QString summaryText = QString("Total: %1 | Disponibles: %2 (%3%) | Non disponibles: %4 (%5%)")
                              .arg(total)
                              .arg(available)
                              .arg(total > 0 ? qRound(available * 100.0 / total) : 0)
                              .arg(unavailable)
                              .arg(total > 0 ? qRound(unavailable * 100.0 / total) : 0);

    QLabel* summaryLabel = new QLabel(summaryText);
    summaryLabel->setAlignment(Qt::AlignCenter);
    newLayout->addWidget(summaryLabel);
}
////////////////////////////////////////////////////////// examen
void MainWindow::on_ajout_examButton_clicked()
{
    // Récupération des valeurs des champs
    QString titre = ui->lineEdit_titre->text();
    QString sujet = ui->lineEdit_sujet->text();
    QString statut = ui->lineEdit_statut->text();
    QDate date_examen = ui->dateEdit_exam->date();
    int id_transport = ui->comboBox_transport->currentData().toInt();
    int id_centre = ui->comboBox_foreign_center->currentData().toInt();

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
    Examen examen(titre, sujet, statut, date_examen, id_transport, id_centre);

    // Tentative d'ajout de l'examen à la base de données
    if (examen.ajouter()) {
        ui->tableView_center->setModel(C.afficherCenter());
        // Rafraîchir la table
        examen.afficher(ui->tableWidget_examens);
        checkUpcomingExams();
        displayExamStatsChart();

        // Nettoyer les champs
        ui->lineEdit_titre->clear();
        ui->lineEdit_sujet->clear();
        ui->lineEdit_statut->clear();
        ui->dateEdit_exam->setDate(QDate::currentDate());
        ui->comboBox_transport->setCurrentIndex(0);
        ui->comboBox_foreign_center->setCurrentIndex(0);

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
    int id_centre = ui->comboBox_foreign_center->currentData().toInt();

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
    Examen examen(id, titre, sujet, statut, date_examen, id_transport, id_centre);

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
        ui->comboBox_foreign_center->setCurrentIndex(0);

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
    QString id_centre = ui->tableWidget_examens->item(row, 8)->text(); // Assuming centre is column 8

    // Set the values in their respective line edits
    ui->idExam->setText(id);
    ui->lineEdit_titre->setText(titre);
    ui->lineEdit_sujet->setText(sujet);
    ui->lineEdit_statut->setText(statut);
    ui->dateEdit_exam->setDate(date_examen);

    // Set the transport combo box
    int transportIndex = ui->comboBox_transport->findData(id_transport.toInt());
    if (transportIndex >= 0) {
        ui->comboBox_transport->setCurrentIndex(transportIndex);
    }

    // Set the centre combo box
    int centreIndex = ui->comboBox_foreign_center->findData(id_centre.toInt());
    if (centreIndex >= 0) {
        ui->comboBox_foreign_center->setCurrentIndex(centreIndex);
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
    // Récupérer l'ID de l'examen depuis la première colonne
    QString examId = ui->tableWidget_examens->item(row, 0)->text();
    qDebug() << "Exam ID clicked:" << examId;

    if (examId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'examen est vide.");
        return;
    }

    QString qrCodeData;
    QString destination;

    // Préparer la requête SQL - NOTE THE COLUMN NAME CHANGE TO DESTINAION
    QSqlQuery qry;
    qry.prepare("SELECT e.id, e.titre, e.sujet, e.statut, t.DESTINATION "
                "FROM examen e "
                "LEFT JOIN transport t ON e.id_transport = t.id_transport "
                "WHERE e.id = :examId");

    qry.bindValue(":examId", examId);

    if (!qry.exec()) {
        qDebug() << "Query failed:" << qry.lastError().text();
        QMessageBox::critical(this, "Erreur", "Échec de la requête SQL : " + qry.lastError().text());
        return;
    }

    if (!qry.next()) {
        qDebug() << "Query returned no results for exam ID:" << examId;
        QMessageBox::warning(this, "Information", "Aucun examen trouvé avec cet ID.");
        return;
    }

    // Mise à jour des champs de l'interface
    ui->idExam->setText(qry.value(0).toString());
    ui->lineEdit_titre->setText(qry.value(1).toString());
    ui->lineEdit_sujet->setText(qry.value(2).toString());
    ui->lineEdit_statut->setText(qry.value(3).toString());
    destination = qry.value(4).toString();

    // Formatage du texte à encoder dans le QR code
    qrCodeData = QString(
                     "Exam Information\n"
                     "----------------\n"

                     "Title: %2\n"
                     "Subject: %3\n"
                     "Status: %4\n"
                     "Destination: %5")
                     .arg(qry.value(0).toString(),
                          qry.value(1).toString(),
                          qry.value(2).toString(),
                          qry.value(3).toString(),
                          destination.isEmpty() ? "Not specified" : destination);

    // Génération du QR Code
    using namespace qrcodegen;
    try {
        QrCode qr = QrCode::encodeText(qrCodeData.toUtf8().constData(), QrCode::Ecc::MEDIUM);
        QImage im(qr.getSize(), qr.getSize(), QImage::Format_RGB32);

        for (int y = 0; y < qr.getSize(); y++) {
            for (int x = 0; x < qr.getSize(); x++) {
                im.setPixel(x, y, qr.getModule(x, y) ? qRgb(0, 0, 0) : qRgb(255, 255, 255));
            }
        }

        if (ui->qrCodeLabel) {
            ui->qrCodeLabel->setFixedSize(150, 150);
            QPixmap qrPixmap = QPixmap::fromImage(im.scaled(
                ui->qrCodeLabel->width(),
                ui->qrCodeLabel->height(),
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation
                ));
            ui->qrCodeLabel->setPixmap(qrPixmap);
            ui->qrCodeLabel->setAlignment(Qt::AlignCenter);
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
    //Clear existing content
    QLayout *existingLayout = ui->frame_exam->layout();

    // Delete all widgets from the frame
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
    QVBoxLayout *layout = new QVBoxLayout(ui->frame_exam);
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
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        categories << it.key();
        *barSet << it.value();
        barSet->setColor(colors[colorIndex % colors.size()]);
        colorIndex++;
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
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Add to layout
    layout->addWidget(chartView);

    // Ensure the frame updates
    ui->frame_exam->update();

}
void MainWindow::on_lineEdit_11_textChanged(const QString &arg1)
{
    examen.rechercherExamens(ui->tableWidget_examens, arg1);
}
void MainWindow::on_trier_Butoon__clicked()
{
    // Determine the sort order
    Qt::SortOrder order = Qt::AscendingOrder; // Default to ascending order

    if (ui->comboBox_order->currentText().compare("Descendant", Qt::CaseInsensitive) == 0) {
        order = Qt::DescendingOrder;
    }

    qDebug() << "Order:" << (order == Qt::AscendingOrder ? "Ascendant" : "Descendant");

    // Determine which column to sort by (Sujet or Date Examen)
    int sortColumn = -1;

    if (ui->comboBoxsortchamp->currentText().compare("Sujet", Qt::CaseInsensitive) == 0) {
        sortColumn = 2; // "Sujet" is the 3rd column (index 2)
    }
    else if (ui->comboBoxsortchamp->currentText().compare("Date Examen", Qt::CaseInsensitive) == 0) {
        sortColumn = 4; // "Date Examen" is the 5th column (index 4)
    }

    // Sort the QTableWidget by the selected column
    if (sortColumn != -1) {
        ui->tableWidget_examens->sortItems(sortColumn, order);
    }
}
void MainWindow::on_pushButton_examen_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_pushButton_centre_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_resultat_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::populateCenterComboBox()
{
    ui->comboBox_foreign_center->clear();

    QSqlQuery query("SELECT idcenter, nom FROM center ORDER BY nom");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->comboBox_foreign_center->addItem(name, id);
    }

    // Add a default empty option
    ui->comboBox_foreign_center->insertItem(0, "Sélectionner un centre", 0);
    ui->comboBox_foreign_center->setCurrentIndex(0);
}



////////////////////////////////////////////////////////// resultat


void MainWindow::on_pushButton_afficher_res_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_ETUDIANT, NUMC_ETUDIANT, NOM, MATIERE, NOTE, DATE_RES, STATUT FROM RESULTAT");

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
    query.prepare("INSERT INTO RESULTAT (NUMC_ETUDIANT, NOM, MATIERE, DATE_RES, STATUT, NOTE) "
                  "VALUES (:numc, :nom, :matiere, :date, :statut, :note)");
    query.bindValue(":numc", NUMC_ETUDIANT);
    query.bindValue(":nom", NOM);
    query.bindValue(":matiere", MATIERE);
    query.bindValue(":date", DATE_RES);
    query.bindValue(":statut", STATUT);
    query.bindValue(":note", NOTE);

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
                  "NOTE = :note "
                  "WHERE NUMC_ETUDIANT = :numc");
    query.bindValue(":numc", NUMC_ETUDIANT);
    query.bindValue(":nom", NOM);
    query.bindValue(":matiere", MATIERE);
    query.bindValue(":date", DATE_RES);
    query.bindValue(":statut", STATUT);
    query.bindValue(":note", NOTE);

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
    // Supprimer tout contenu existant dans le QFrame
    QLayout* existingLayout = ui->frame_res->layout();
    if (existingLayout) {
        QLayoutItem* item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete existingLayout;
    }

    // Créer un nouveau layout pour le QFrame
    QVBoxLayout* layout = new QVBoxLayout(ui->frame_res);
    ui->frame_res->setLayout(layout);

    // Obtenir les statistiques
    QMap<QString, int> stats;
    QSqlQuery query;

    query.prepare("SELECT "
                  "COUNT(CASE WHEN NOTE < 8 THEN 1 END) as refuse, "
                  "COUNT(CASE WHEN NOTE >= 8 AND NOTE < 10 THEN 1 END) as controle, "
                  "COUNT(CASE WHEN NOTE >= 10 THEN 1 END) as admis, "
                  "COUNT(*) as total "
                  "FROM RESULTAT");

    if (query.exec() && query.next()) {
        stats["refuse"] = query.value("refuse").toInt();
        stats["controle"] = query.value("controle").toInt();
        stats["admis"] = query.value("admis").toInt();
        stats["total"] = query.value("total").toInt();
    } else {
        qDebug() << "Erreur lors du calcul des statistiques:" << query.lastError().text();
        return;
    }
    // Ajouter un graphique circulaire
    QPieSeries *pieSeries = new QPieSeries();

    QPieSlice *refuseSlice = pieSeries->append("Refusé (<8)", stats["refuse"]);
    QPieSlice *controleSlice = pieSeries->append("Controle (8-9.99)", stats["controle"]);
    QPieSlice *admisSlice = pieSeries->append("Admis (≥10)", stats["admis"]);

    refuseSlice->setColor(QColor(255, 99, 71));
    controleSlice->setColor(QColor(255, 165, 0));
    admisSlice->setColor(QColor(60, 179, 113));

    int total = stats["refuse"] + stats["controle"] + stats["admis"];

    if (total > 0) {
        refuseSlice->setLabel(QString("Refusé: %1%").arg((stats["refuse"] * 100.0) / total, 0, 'f', 1));
        controleSlice->setLabel(QString("Contrôle: %1%").arg((stats["controle"] * 100.0) / total, 0, 'f', 1));
        admisSlice->setLabel(QString("Admis: %1%").arg((stats["admis"] * 100.0) / total, 0, 'f', 1));
    }

    refuseSlice->setExploded();
    refuseSlice->setLabelVisible();
    controleSlice->setLabelVisible();
    admisSlice->setLabelVisible();

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition des Notes (%)");
    pieChart->legend()->setVisible(true);
    pieChart->legend()->setAlignment(Qt::AlignRight);

    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(pieChartView);

    // Afficher le QFrame
    ui->frame_res->show();
}
