#include "transport.h"
#include "ui_transport.h"
#include <QSqlError>
#include <QQuickWidget>
#include <QQmlContext>
#include <QTimer>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QGeoCoordinate>  // Ajoutez cette ligne
#include <QQuickItem>
#include <QPieSeries>
#include <QChartView>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QStandardPaths>
#include <QSqlRecord>


transport::transport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transport),
    m_quickWidget(nullptr)
{
    ui->setupUi(this);

    // Initialisation des connexions
    connect(ui->recherche, &QPushButton::clicked, this, &transport::on_recherche_clicked);
    connect(ui->ajouter, &QPushButton::clicked, this, &transport::on_ajouter_clicked);
    connect(ui->tableWidgetlivraison, &QTableWidget::itemClicked, this, &transport::on_tableWidgetlivraison_itemClicked);
    connect(ui->modifier, &QPushButton::clicked, this, &transport::on_modifier_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &transport::on_supprimer_clicked);
    connect(ui->annuler, &QPushButton::clicked, this, &transport::on_annuler_clicked);

    // Combo box
    ui->statut_de_livraison->addItem("en cours");
    ui->statut_de_livraison->addItem("livree");
    ui->statut_de_livraison->addItem("en stock");

    // Initialisation de la carte------------------------------------
    initMap();

    afficherTransports();

    // Connexions pour le calendrier--------------------
    connect(ui->calendarLivraison, &QCalendarWidget::clicked,
            this, &transport::on_calendarLivraison_clicked);
    connect(ui->comboLivreurs, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &transport::on_comboLivreurs_currentIndexChanged);

    // Style du calendrier
    ui->calendarLivraison->setStyleSheet("alternate-background-color: #E6E6FA;");
    QTimer::singleShot(1000, this, &transport::colorierDatesLivraison);

    chargerLivreurs();
}

transport::~transport()
{
    delete ui;
}

void transport::initMap()
{
    if (!ui->mapContainer) {
        qCritical() << "Erreur: mapContainer non trouvé dans l'UI";
        return;
    }

    m_quickWidget = new QQuickWidget(this);
    m_quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    m_quickWidget->setClearColor(Qt::transparent);

    connect(m_quickWidget, &QQuickWidget::statusChanged,
            this, &transport::handleQmlStatusChanged);

    if (!ui->mapContainer->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->mapContainer);
        layout->setContentsMargins(0, 0, 0, 0);
        ui->mapContainer->setLayout(layout);
    }
    ui->mapContainer->layout()->addWidget(m_quickWidget);

    // Connexion du contexte
    m_quickWidget->rootContext()->setContextProperty("transportWindow", this);
    m_quickWidget->setSource(QUrl("qrc:/map.qml"));

    // Connexion explicite du signal markersChanged
    connect(this, &transport::markersChanged, this, [this]() {
        if (m_quickWidget && m_quickWidget->rootObject()) {
            QVariant markersVariant = QVariant::fromValue(markersToAdd());
            m_quickWidget->rootObject()->setProperty("markersToAdd", markersVariant);

            // Debug: Vérifiez que les marqueurs sont bien transmis
            qDebug() << "Markers envoyés à QML:" << markersVariant;
        }
    });

    m_quickWidget->update();

    // Charger les marqueurs après un court délai
    QTimer::singleShot(500, this, [this]() {
        loadAllMarkers();

        // Debug: Vérifiez que les marqueurs sont chargés
        qDebug() << "Marqueurs chargés depuis la base:" << m_markers;
    });
}
// 2/import  marker fi map-------

void transport::loadAllMarkers()
{
    m_markers.clear();
    QSqlQuery query("SELECT destination, latitude, longitude FROM transport WHERE latitude IS NOT NULL AND longitude IS NOT NULL");

    // Debug: Vérifiez la requête SQL
    qDebug() << "Exécution de la requête pour les marqueurs";

    while (query.next()) {
        QVariantMap marker;
        marker["latitude"] = query.value("latitude").toDouble();
        marker["longitude"] = query.value("longitude").toDouble();
        marker["destination"] = query.value("destination").toString();
        m_markers.append(marker);

        // Debug: Affichez chaque marqueur chargé
        qDebug() << "Marqueur chargé:" << marker;
    }

    emit markersChanged();  // Émettre le signal pour mettre à jour QML
}
// charger la  carte---------------

void transport::handleQmlStatusChanged(QQuickWidget::Status status)
{
    qDebug() << "QML Status:" << status;
    if (status == QQuickWidget::Error) {
        qCritical() << "Erreurs QML:";
        for (const QQmlError &error : m_quickWidget->errors()) {
            qCritical() << "  -" << error.toString();
        }
        QMessageBox::critical(this, "Erreur QML", "Impossible de charger la carte. Voir la console pour les détails.");
    }
}
   // ecrire x y fi formulaire-------------
void transport::onMapClicked(double lat, double lng)
{
    qDebug() << "Carte cliquée - Lat:" << lat << "Lng:" << lng;
    ui->lineEdit_latitude_2->setText(QString::number(lat, 'f', 6));
    ui->lineEdit_longitude_2->setText(QString::number(lng, 'f', 6));
}

QVariantList transport::markersToAdd() const
{
    return m_markers;
}



void transport::clearMarkers()
{
    m_markers.clear();
    emit markersChanged();
}

void transport::addMarker(double lat, double lng, const QString &destination)
{
    QVariantMap marker;
    marker["latitude"] = lat;
    marker["longitude"] = lng;
    marker["destination"] = destination;
    m_markers.append(marker);
    emit markersChanged();
}

void transport::addMarkerToMap(double lat, double lng, const QString &destination)
{
    addMarker(lat, lng, destination);
}

void transport::onMarkerAdded(double lat, double lng)
{
    ui->lineEdit_latitude_2->setText(QString::number(lat, 'f', 6));
    ui->lineEdit_longitude_2->setText(QString::number(lng, 'f', 6));
    qDebug() << "Marqueur ajouté à :" << lat << lng;
}

// Fonction pour afficher tous les transports
void transport::afficherTransports() {
    QSqlQuery query("SELECT * FROM transport");

    ui->tableWidgetlivraison->setRowCount(0);

    while (query.next()) {
        int row = ui->tableWidgetlivraison->rowCount();
        ui->tableWidgetlivraison->insertRow(row);

        ui->tableWidgetlivraison->setItem(row, 0, new QTableWidgetItem(query.value("code_box").toString()));
        ui->tableWidgetlivraison->setItem(row, 1, new QTableWidgetItem(query.value("prenom_livreur").toString()));
        ui->tableWidgetlivraison->setItem(row, 2, new QTableWidgetItem(query.value("destination").toString()));
        ui->tableWidgetlivraison->setItem(row, 3, new QTableWidgetItem(query.value("date_de_livraison").toString()));
        ui->tableWidgetlivraison->setItem(row, 4, new QTableWidgetItem(query.value("nbr_de_box").toString()));
        ui->tableWidgetlivraison->setItem(row, 5, new QTableWidgetItem(query.value("statut_de_livraison").toString()));
        ui->tableWidgetlivraison->setItem(row, 6, new QTableWidgetItem(query.value("latitude").toString()));
        ui->tableWidgetlivraison->setItem(row, 7, new QTableWidgetItem(query.value("longitude").toString()));
    }
}

// Fonction pour rechercher un transport
void transport::on_recherche_clicked() {
    QString critere = ui->lineEdit_recherche->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM transport WHERE code_box LIKE :critere "
                  "OR prenom_livreur LIKE :critere "
                  "OR destination LIKE :critere "
                  "OR statut_de_livraison LIKE :critere "
                  "OR latitude LIKE :critere "
                  "OR longitude LIKE :critere");
    query.bindValue(":critere", "%" + critere + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche.");
        return;
    }

    ui->tableWidgetlivraison->setRowCount(0);

    while (query.next()) {
        int row = ui->tableWidgetlivraison->rowCount();
        ui->tableWidgetlivraison->insertRow(row);

        ui->tableWidgetlivraison->setItem(row, 0, new QTableWidgetItem(query.value("code_box").toString()));
        ui->tableWidgetlivraison->setItem(row, 1, new QTableWidgetItem(query.value("prenom_livreur").toString()));
        ui->tableWidgetlivraison->setItem(row, 2, new QTableWidgetItem(query.value("destination").toString()));
        ui->tableWidgetlivraison->setItem(row, 3, new QTableWidgetItem(query.value("date_de_livraison").toString()));
        ui->tableWidgetlivraison->setItem(row, 4, new QTableWidgetItem(query.value("nbr_de_box").toString()));
        ui->tableWidgetlivraison->setItem(row, 5, new QTableWidgetItem(query.value("statut_de_livraison").toString()));
        ui->tableWidgetlivraison->setItem(row, 6, new QTableWidgetItem(query.value("latitude").toString()));
        ui->tableWidgetlivraison->setItem(row, 7, new QTableWidgetItem(query.value("longitude").toString()));
    }
}

void transport::on_ajouter_clicked()
{
    QString code_box = ui->code_box->text();
    QString prenom_livreur = ui->prenom_livreur->text();
    QString destination = ui->destination->text();
    QDate date_de_livraison = ui->date_de_livraison->date();
    QString nbr_de_box = ui->nbr_de_box->text();
    QString statut_de_livraison = ui->statut_de_livraison->currentText();
    QString latitude = ui->lineEdit_latitude_2->text();
    QString longitude = ui->lineEdit_longitude_2->text();

    // Contrôle de saisie
    bool valide = true;

    if (code_box.isEmpty()) {
        ui->code_box->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    QRegularExpression regex("^[a-zA-ZÀ-ÿ\\s\\-']+$");
    if (!regex.match(prenom_livreur).hasMatch()) {
        ui->prenom_livreur->setStyleSheet("border: 2px solid red;");
        valide = false;
    }
    if (!regex.match(destination).hasMatch()) {
        ui->destination->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    bool nbrOk;
    int nbr = nbr_de_box.toInt(&nbrOk);
    if (!nbrOk || nbr <= 0) {
        ui->nbr_de_box->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    // Validation des coordonnées GPS
    bool latOk, longOk;
    latitude.toDouble(&latOk);
    longitude.toDouble(&longOk);
    if (!latOk || !longOk) {
        ui->lineEdit_latitude_2->setStyleSheet("border: 2px solid red;");
        ui->lineEdit_longitude_2->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    if (!valide) return;

    // Insertion dans la base de données
    QSqlQuery query;
    query.prepare("INSERT INTO transport (code_box, prenom_livreur, destination, date_de_livraison, nbr_de_box, statut_de_livraison, latitude, longitude) "
                  "VALUES (:code_box, :prenom_livreur, :destination, TO_DATE(:date_de_livraison, 'YYYY-MM-DD'), :nbr_de_box, :statut_de_livraison, :latitude, :longitude)");
    query.bindValue(":code_box", code_box);
    query.bindValue(":prenom_livreur", prenom_livreur);
    query.bindValue(":destination", destination);
    query.bindValue(":date_de_livraison", date_de_livraison.toString("yyyy-MM-dd"));
    query.bindValue(":nbr_de_box", nbr);
    query.bindValue(":statut_de_livraison", statut_de_livraison);
    query.bindValue(":latitude", latitude);
    query.bindValue(":longitude", longitude);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Transport ajouté avec succès.");
        afficherTransports();
        // Ajouter le marqueur sur la carte
        addMarkerToMap(latitude.toDouble(), longitude.toDouble(), destination);
        // Réinitialiser les champs
        ui->code_box->clear();
        ui->prenom_livreur->clear();
        ui->destination->clear();
        ui->date_de_livraison->setDate(QDate::currentDate());
        ui->nbr_de_box->clear();
        ui->lineEdit_latitude_2->clear();
        ui->lineEdit_longitude_2->clear();
    } else {
        QMessageBox::information(this, "failed", "Transport failed: " + query.lastError().text());
    }
}
void transport::on_tableWidgetlivraison_itemClicked(QTableWidgetItem *item)
{
    int row=0;
    try {
        // Vérification de base
        if (!item || !ui->tableWidgetlivraison || row < 0 || row >= ui->tableWidgetlivraison->rowCount()) {
            qWarning() << "Item ou ligne invalide";
            return;
        }

        int row = item->row();

        // Remplissage des champs avec vérification de chaque item
        auto setTextIfValid = [](QLineEdit* edit, QTableWidgetItem* item) {
            if (item && edit) edit->setText(item->text());
        };

        setTextIfValid(ui->code_box, ui->tableWidgetlivraison->item(row, 0));
        setTextIfValid(ui->prenom_livreur, ui->tableWidgetlivraison->item(row, 1));
        setTextIfValid(ui->destination, ui->tableWidgetlivraison->item(row, 2));
        setTextIfValid(ui->nbr_de_box, ui->tableWidgetlivraison->item(row, 4));
        setTextIfValid(ui->lineEdit_latitude_2, ui->tableWidgetlivraison->item(row, 6));
        setTextIfValid(ui->lineEdit_longitude_2, ui->tableWidgetlivraison->item(row, 7));

        // Gestion de la date
        if (auto dateItem = ui->tableWidgetlivraison->item(row, 3)) {
            QDate date = QDate::fromString(dateItem->text(), "yyyy-MM-dd");
            if (date.isValid() && ui->date_de_livraison) {
                ui->date_de_livraison->setDate(date);
            }
        }

        // Gestion du statut
        if (auto statutItem = ui->tableWidgetlivraison->item(row, 5)) {
            if (ui->statut_de_livraison) {
                int index = ui->statut_de_livraison->findText(statutItem->text());
                if (index >= 0) ui->statut_de_livraison->setCurrentIndex(index);
            }
        }

        // Centrage de la carte avec vérifications supplémentaires
        if (!ui->lineEdit_latitude_2->text().isEmpty() &&
            !ui->lineEdit_longitude_2->text().isEmpty() &&
            m_quickWidget &&
            m_quickWidget->rootObject())
        {
            bool latOk, lngOk;
            double lat = ui->lineEdit_latitude_2->text().toDouble(&latOk);
            double lng = ui->lineEdit_longitude_2->text().toDouble(&lngOk);

            if (latOk && lngOk) {
                QVariantMap center;
                center["latitude"] = lat;
                center["longitude"] = lng;

                // Debug avant modification
                qDebug() << "Setting map center to:" << center;

                m_quickWidget->rootObject()->setProperty("center", center);
                m_quickWidget->rootObject()->setProperty("zoomLevel", 15);
            }
        }
    }
    catch (const std::exception& e) {
        qCritical() << "Exception dans on_tableWidgetlivraison_itemClicked:" << e.what();
        QMessageBox::critical(this, "Erreur", "Une erreur critique est survenue");
    }
    catch (...) {
        qCritical() << "Exception inconnue dans on_tableWidgetlivraison_itemClicked";
        QMessageBox::critical(this, "Erreur", "Erreur inconnue");
    }
}

void transport::on_modifier_clicked()
{
    QString code_box = ui->code_box->text();
    QString prenom_livreur = ui->prenom_livreur->text();
    QString destination = ui->destination->text();
    QDate date_de_livraison = ui->date_de_livraison->date();
    QString nbr_de_box = ui->nbr_de_box->text();
    QString statut_de_livraison = ui->statut_de_livraison->currentText();
    QString latitude = ui->lineEdit_latitude_2->text();
    QString longitude = ui->lineEdit_longitude_2->text();

    if (code_box.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un transport à modifier.");
        return;
    }

    // Validation des coordonnées GPS
    bool latOk, longOk;
    latitude.toDouble(&latOk);
    longitude.toDouble(&longOk);
    if (!latOk || !longOk) {
        QMessageBox::warning(this, "Erreur", "Coordonnées GPS invalides.");
        return;
    }

    // Mettre à jour les données dans la base
    QSqlQuery query;
    query.prepare("UPDATE transport SET prenom_livreur = :prenom_livreur, destination = :destination, "
                  "date_de_livraison = TO_DATE(:date_de_livraison, 'YYYY-MM-DD'), "
                  "nbr_de_box = :nbr_de_box, statut_de_livraison = :statut_de_livraison, "
                  "latitude = :latitude, longitude = :longitude "
                  "WHERE code_box = :code_box");
    query.bindValue(":code_box", code_box);
    query.bindValue(":prenom_livreur", prenom_livreur);
    query.bindValue(":destination", destination);
    query.bindValue(":date_de_livraison", date_de_livraison.toString("yyyy-MM-dd"));
    query.bindValue(":nbr_de_box", nbr_de_box.toInt());
    query.bindValue(":statut_de_livraison", statut_de_livraison);
    query.bindValue(":latitude", latitude);
    query.bindValue(":longitude", longitude);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Transport modifié avec succès.");
        afficherTransports();
        // Mettre à jour les marqueurs sur la carte
        loadAllMarkers();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification : " + query.lastError().text());
    }
}

void transport::on_supprimer_clicked()
{
    QString code_box = ui->code_box->text();

    if (code_box.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un transport à supprimer.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce transport ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM transport WHERE code_box = :code_box");
        query.bindValue(":code_box", code_box);

        if (query.exec()) {
            QMessageBox::information(this, "Succès", "Transport supprimé avec succès.");
            afficherTransports();
            // Mettre à jour les marqueurs sur la carte
            loadAllMarkers();
            // Réinitialiser les champs
            ui->code_box->clear();
            ui->prenom_livreur->clear();
            ui->destination->clear();
            ui->date_de_livraison->setDate(QDate::currentDate());
            ui->nbr_de_box->clear();
            ui->lineEdit_latitude_2->clear();
            ui->lineEdit_longitude_2->clear();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    }
}

void transport::on_annuler_clicked()
{
    ui->lineEdit_recherche->clear();
    afficherTransports();
}

void transport::chargerLivreurs()
{
    ui->comboLivreurs->clear();
    ui->comboLivreurs->addItem("Tous les livreurs", "");

    QSqlQuery query("SELECT DISTINCT prenom_livreur FROM transport");
    while (query.next()) {
        ui->comboLivreurs->addItem(query.value(0).toString(),
                                   query.value(0).toString());
    }
}

void transport::afficherLivraisonsParDate(const QDate &date, const QString &livreur)
{
    QString queryStr = "SELECT code_box, destination, statut_de_livraison "
                       "FROM transport WHERE TO_CHAR(date_de_livraison, 'YYYY-MM-DD') = :date";

    if (!livreur.isEmpty()) {
        queryStr += " AND prenom_livreur = :livreur";
    }

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));

    if (!livreur.isEmpty()) {
        query.bindValue(":livreur", livreur);
    }

    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur",
                             "Impossible de charger les livraisons:\n" + query.lastError().text());
        qDebug() << "Erreur SQL:" << query.lastQuery();
        qDebug() << "Valeurs bindées:"
                 << date.toString("yyyy-MM-dd") << livreur;
        return;
    }

    ui->tableLivraisonsCalendar->setRowCount(0);

    while (query.next()) {
        int row = ui->tableLivraisonsCalendar->rowCount();
        ui->tableLivraisonsCalendar->insertRow(row);

        ui->tableLivraisonsCalendar->setItem(row, 0,
                                             new QTableWidgetItem(query.value("code_box").toString()));
        ui->tableLivraisonsCalendar->setItem(row, 1,
                                             new QTableWidgetItem(query.value("destination").toString()));
        ui->tableLivraisonsCalendar->setItem(row, 2,
                                             new QTableWidgetItem(query.value("statut_de_livraison").toString()));
    }

    if (ui->tableLivraisonsCalendar->rowCount() == 0) {
        ui->tableLivraisonsCalendar->setRowCount(1);
        ui->tableLivraisonsCalendar->setItem(0, 0,
                                             new QTableWidgetItem("Aucune livraison cette journée"));
    }
}
void transport::on_calendarLivraison_clicked(const QDate &date)
{
    QString livreur = ui->comboLivreurs->currentData().toString();
    afficherLivraisonsParDate(date, livreur);
}

void transport::on_comboLivreurs_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    on_calendarLivraison_clicked(ui->calendarLivraison->selectedDate());
}

// Ajoutez cette méthode pour colorer les dates avec des livraisons
void transport::colorierDatesLivraison()
{
    QSqlQuery query("SELECT DISTINCT TO_CHAR(date_de_livraison, 'YYYY-MM-DD') FROM transport");
    QTextCharFormat format;
    format.setBackground(Qt::green);
    format.setForeground(Qt::white);

    while (query.next()) {
        QDate date = QDate::fromString(query.value(0).toString(), "yyyy-MM-dd");
        if (date.isValid()) {
            ui->calendarLivraison->setDateTextFormat(date, format);
        }
    }
}

// statistiques -------------

void transport::on_statistique_clicked()
{
    // Récupérer les données statistiques par statut de livraison
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT statut_de_livraison, COUNT(*) FROM transport GROUP BY statut_de_livraison");

    if (model->lastError().isValid()) {
        QMessageBox::critical(this, "Erreur", "Échec de récupération des statistiques: " + model->lastError().text());
        return;
    }

    // Créer la série de données
    QPieSeries *series = new QPieSeries();

    // Calculer le total pour les pourcentages
    int total = 0;
    for (int i = 0; i < model->rowCount(); ++i) {
        total += model->record(i).value(1).toInt();
    }

    // Ajouter les données au diagramme
    for (int i = 0; i < model->rowCount(); ++i) {
        QString statut = model->record(i).value(0).toString();
        int count = model->record(i).value(1).toInt();
        double percentage = (count * 100.0) / total;

        QPieSlice *slice = series->append(statut, count);
        slice->setLabel(QString("%1 (%2%)")
                            .arg(statut)
                            .arg(QString::number(percentage, 'f', 1)));
        slice->setLabelVisible(true);
    }

    // Créer et configurer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des livraisons par statut");
    chart->legend()->setAlignment(Qt::AlignRight);

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer une boîte de dialogue personnalisée
    QDialog *statsDialog = new QDialog(this);
    statsDialog->setWindowTitle("Statistiques des livraisons");
    statsDialog->setMinimumSize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(statsDialog);
    layout->addWidget(chartView);

    // Ajouter un bouton d'export
    QPushButton *exportButton = new QPushButton("Exporter en PDF", statsDialog);
    connect(exportButton, &QPushButton::clicked, [this, chartView, statsDialog]() {
        QString fileName = QFileDialog::getSaveFileName(statsDialog,
                                                        "Exporter le graphique",
                                                        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                        "PDF (*.pdf)");

        if (!fileName.isEmpty()) {
            QPdfWriter pdfWriter(fileName);
            pdfWriter.setPageSize(QPageSize(QPageSize::A4));
            pdfWriter.setTitle("Statistiques des livraisons");

            QPainter painter(&pdfWriter);
            painter.setRenderHint(QPainter::Antialiasing, true);

            // Redimensionner le graphique pour le PDF
            QRect rect(0, 0, pdfWriter.width(), pdfWriter.height()/2);
            chartView->render(&painter, rect);

            // Ajouter des informations supplémentaires
            painter.drawText(100, pdfWriter.height()/2 + 50,
                             "Statistiques générées le " + QDateTime::currentDateTime().toString());

            painter.end();
        }
    });
    layout->addWidget(exportButton);

    statsDialog->exec();
}



void transport::generatePdfForTransport(const QString& codeBox)
{
    // Configuration du PDF
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString filename = QString("%1/Fiche_Transport_%2.pdf").arg(desktopPath).arg(codeBox);

    QPdfWriter pdfWriter(filename);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setTitle("Fiche Transport - " + codeBox);
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);

    // Dimensions
    const int margin = 50;
    const int contentWidth = pdfWriter.width() - 2 * margin;
    int yPos = margin;

    // En-tête
    QFont headerFont("Arial", 20, QFont::Bold);
    painter.setFont(headerFont);
    painter.drawText(QRect(margin, yPos, contentWidth, 60), Qt::AlignCenter, "FICHE TRANSPORT");
    yPos += 70;

    QFont subHeaderFont("Arial", 16, QFont::Normal);
    painter.setFont(subHeaderFont);
    painter.drawText(QRect(margin, yPos, contentWidth, 40), Qt::AlignCenter, "Code Box: " + codeBox);
    yPos += 50;

    // Ligne de séparation
    painter.drawLine(margin, yPos, pdfWriter.width() - margin, yPos);
    yPos += 30;

    // Requête des données
    QSqlQuery query;
    query.prepare("SELECT * FROM transport WHERE code_box = :codeBox");
    query.bindValue(":codeBox", codeBox);

    if (!query.exec() || !query.next()) {
        qWarning() << "Erreur requête pour" << codeBox;
        return;
    }

    // Paramètres du tableau
    const int rowHeight = 50;  // Augmenté pour plus d'espace
    const int headerHeight = 40;
    const QList<int> colWidths = {contentWidth / 3, contentWidth / 3, contentWidth / 3};
    QList<QString> headers = {"Champ", "Valeur", "Détails"};

    auto calcXPos = [&colWidths](int col) {
        int x = 0;
        for (int i = 0; i < col; ++i) x += colWidths[i];
        return x;
    };

    // En-tête du tableau
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setBrush(QBrush(QColor(230, 230, 250)));
    for (int col = 0; col < headers.size(); ++col) {
        painter.drawRect(margin + calcXPos(col), yPos, colWidths[col], headerHeight);
        painter.drawText(QRect(margin + calcXPos(col), yPos, colWidths[col], headerHeight),
                         Qt::AlignCenter, headers[col]);
    }
    yPos += headerHeight;

    // Contenu du tableau
    painter.setFont(QFont("Arial", 10));
    QStringList fields = {"prenom_livreur", "destination", "date_de_livraison",
                          "nbr_de_box", "statut_de_livraison", "latitude", "longitude"};

    for (const QString &field : fields) {
        bool isEven = fields.indexOf(field) % 2 == 0;
        QBrush rowBrush = isEven ? QBrush(QColor(245, 245, 245)) : QBrush(Qt::white);
        painter.setBrush(rowBrush);

        // CHAMP
        QString displayField = field;
        displayField.replace("_", " ");
        displayField = displayField.toUpper();

        painter.drawRect(margin + calcXPos(0), yPos, colWidths[0], rowHeight);
        painter.drawText(QRect(margin + calcXPos(0), yPos, colWidths[0], rowHeight),
                         Qt::AlignLeft | Qt::AlignVCenter, "  " + displayField);

        // VALEUR
        QString value = query.value(field).toString();
        painter.drawRect(margin + calcXPos(1), yPos, colWidths[1], rowHeight);
        painter.drawText(QRect(margin + calcXPos(1), yPos, colWidths[1], rowHeight),
                         Qt::AlignLeft | Qt::AlignVCenter, "  " + value);

        // DÉTAILS
        QString details;
        if (field == "date_de_livraison") {
            QDate date = QDate::fromString(value.left(10), "yyyy-MM-dd");
            details = date.toString("dddd d MMMM yyyy");
        } else if (field == "statut_de_livraison") {
            details = (value == "livree") ? "✔ Livraison effectuée" : "En cours";
        }

        painter.drawRect(margin + calcXPos(2), yPos, colWidths[2], rowHeight);
        painter.drawText(QRect(margin + calcXPos(2), yPos, colWidths[2], rowHeight),
                         Qt::AlignLeft | Qt::AlignVCenter, "  " + details);

        yPos += rowHeight;
    }


    // Localisation
    yPos += 40;
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.drawText(margin, yPos, "Localisation:");
    yPos += 30;

    double lat = query.value("latitude").toDouble();
    double lng = query.value("longitude").toDouble();
    QString coords = QString("Latitude: %1, Longitude: %2").arg(lat).arg(lng);
    painter.setFont(QFont("Arial", 10));
    painter.drawText(margin, yPos, coords);
    yPos += 50;

    // Pied de page
    painter.setFont(QFont("Arial", 8));
    painter.drawText(margin, pdfWriter.height() - 50,
                     "Généré le " + QDate::currentDate().toString("dd/MM/yyyy"));
    painter.drawText(pdfWriter.width() - margin - 200, pdfWriter.height() - 50,
                     "© Système de Gestion des Transports");

    painter.end();
    qDebug() << "PDF généré:" << filename;
}

void transport::on_pdf_2_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT DISTINCT code_box FROM transport");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur",
                              "Échec de récupération des transports: " + query.lastError().text());
        return;
    }

    int successCount = 0;
    while (query.next()) {
        QString codeBox = query.value(0).toString();
        generatePdfForTransport(codeBox);
        successCount++;
    }

    QMessageBox::information(this, "Rapport PDF",
                             QString("%1 Fiche(s) Transport PDF générée(s)").arg(successCount));

}


void transport::on_tri_clicked()
{
    // Étape 1: Extraire les données de la table
    QList<QList<QTableWidgetItem*>> rows;
    for (int row = 0; row < ui->tableWidgetlivraison->rowCount(); ++row) {
        QList<QTableWidgetItem*> rowItems;
        for (int column = 0; column < ui->tableWidgetlivraison->columnCount(); ++column) {
            rowItems.append(ui->tableWidgetlivraison->takeItem(row, column));
        }
        rows.append(rowItems);
    }

    // Étape 2: Trier les données par prenom_livreur (supposons que prenom_livreur est dans la deuxième colonne)
    std::sort(rows.begin(), rows.end(), [](const QList<QTableWidgetItem*>& a, const QList<QTableWidgetItem*>& b) {
        return a[1]->text() < b[1]->text(); // Comparaison par prenom_livreur (index 1)
    });

    // Étape 3: Réinsérer les données triées dans le QTableWidget
    ui->tableWidgetlivraison->setRowCount(0); // Vider la table
    for (const auto& rowItems : rows) {
        int newRow = ui->tableWidgetlivraison->rowCount();
        ui->tableWidgetlivraison->insertRow(newRow);
        for (int column = 0; column < rowItems.size(); ++column) {
            ui->tableWidgetlivraison->setItem(newRow, column, rowItems[column]);
        }
    }
}
