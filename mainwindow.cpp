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




#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>

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




#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrinterInfo>
#include <QtGui/QPainter>
#include <QtGui/QFont>
#include <QtCore/QDate>
#include <QtGui/QPageSize>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QMap>

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

    // Initialize painter for PDF
    QPainter painter;
    if(!painter.begin(&printer)) {
        QMessageBox::warning(this, "Export PDF", "Erreur lors de la création du PDF");
        return;
    }

    // Set up fonts
    QFont titleFont("Arial", 18, QFont::Bold);
    QFont headerFont("Arial", 12, QFont::Bold);
    QFont contentFont("Arial", 10);

    // Get model data
    QSqlQueryModel* model = C.afficherCenter();
    int rowCount = model->rowCount();
    int columnCount = model->columnCount() - 1; // Exclude the calendar column

    // Painting constants
    int margin = 50;
    int headerHeight = 50;
    int rowHeight = 30;
    int columnWidth = (printer.width() - 2 * margin) / columnCount;

    // Paint title
    painter.setFont(titleFont);
    painter.drawText(margin, margin, printer.width() - 2 * margin, headerHeight,
                     Qt::AlignCenter, "Liste des Centres");

    // Paint header
    painter.setFont(headerFont);
    for (int col = 0; col < columnCount; ++col) {
        QRect headerRect(margin + col * columnWidth, margin + headerHeight,
                         columnWidth, rowHeight);
        painter.drawRect(headerRect);
        painter.drawText(headerRect, Qt::AlignCenter,
                         model->headerData(col, Qt::Horizontal).toString());
    }

    // Paint data
    painter.setFont(contentFont);
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QRect cellRect(margin + col * columnWidth,
                           margin + headerHeight + (row + 1) * rowHeight,
                           columnWidth, rowHeight);
            painter.drawRect(cellRect);

            // Format date if it's a date column
            QString cellData;
            if (col == 3) { // Date column
                QDate date = model->data(model->index(row, col)).toDate();
                cellData = date.toString("dd/MM/yyyy");
            } else {
                cellData = model->data(model->index(row, col)).toString();
            }

            painter.drawText(cellRect, Qt::AlignCenter, cellData);
        }
    }

    // Paint footer
    QString footer = "Document généré le " + QDate::currentDate().toString("dd/MM/yyyy");
    painter.drawText(margin, printer.height() - margin,
                     printer.width() - 2 * margin, margin,
                     Qt::AlignRight | Qt::AlignBottom, footer);

    // End painting
    painter.end();

    QMessageBox::information(this, "Export PDF", "Le document PDF a été créé avec succès!");

    // Open the PDF

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





void MainWindow::on_pushButton_centre_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}




