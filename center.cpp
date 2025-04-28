#include "center.h"
#include "qcolor.h"
#include "qfont.h"
#include "qwindowdefs.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlError>

center::center()
{
    idcenter = 0;
    nom = " ";
    adresse = " ";
    capacite = 0;
    disponibilite = 1;
}

center::center(QString nom, QString adresse, QDate datec, int capacite, int disponibilite)
{
    this->nom = nom;
    this->adresse = adresse;
    this->datec = datec;
    this->capacite = capacite;
    this->disponibilite = disponibilite;
}

int center::getidcenter() { return idcenter; }
QString center::getnom() { return nom; }
QString center::getadresse() { return adresse; }
QDate center::getdatec() { return datec; }
int center::getcapacite() { return capacite; }
int center::getdisponibilite() { return disponibilite; }

void center::setidcenter(int idcenter) { this->idcenter = idcenter; }
void center::setnom(QString nom) { this->nom = nom; }
void center::setadresse(QString adresse) { this->adresse = adresse; }
void center::setdatec(QDate datec) { this->datec = datec; }
void center::setcapacite(int capacite) { this->capacite = capacite; }
void center::setdisponibilite(int disponibilite) { this->disponibilite = disponibilite; }

bool center::ajouterCenter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO center (nom, adresse, datec, capacite, disponibilite) "
                  "VALUES (:nom, :adresse, :datec, :capacite, :disponibilite)");
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":datec", datec);
    query.bindValue(":capacite", capacite);
    query.bindValue(":disponibilite", disponibilite);
    return query.exec();
}

QSqlQueryModel* center::afficherCenter()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Modified query to include calendar data
    model->setQuery("SELECT idcenter, nom, adresse, datec, capacite, disponibilite, "
                    "'📅' AS calendar FROM center"); // Add calendar icon/text as 7th column

    // Set headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Création"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Capacité"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Disponibilité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Calendrier"));

    return model;
}

bool center::supprimerCenter(int idcenter)
{
    QSqlQuery query;
    query.prepare("DELETE FROM center WHERE idcenter=:idcenter");
    query.bindValue(":idcenter", idcenter);
    return query.exec();
}

bool center::modifierCenter(int idcenter, QString nom, QString adresse, QDate datec, int capacite, int disponibilite)
{
    QSqlQuery query;
    query.prepare("UPDATE center SET nom=:nom, adresse=:adresse, datec=:datec, capacite=:capacite, disponibilite=:disponibilite "
                  "WHERE idcenter=:idcenter");
    query.bindValue(":idcenter", idcenter);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":datec", datec);
    query.bindValue(":capacite", capacite);
    query.bindValue(":disponibilite", disponibilite);
    return query.exec();
}

QSqlQueryModel* center::rechercherMulti(QString recherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QString req = "SELECT * FROM center WHERE nom LIKE :recherche OR adresse LIKE :recherche OR TO_CHAR(datec, 'YYYY-MM-DD') LIKE :recherche";
    query.prepare(req);
    query.bindValue(":recherche", "%" + recherche + "%");
    query.exec();

    // Passez le query par move ici
    model->setQuery(std::move(query));  // Correction ici

    return model;
}


QSqlQueryModel* center::trierParMultiplesCritères()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM center ORDER BY capacite ASC, datec DESC");
    return model;
}
void center::exporterPDF(const QString &nomFichier, QAbstractItemModel *model)
{
    QPdfWriter pdfWriter(nomFichier);
    QPainter painter(&pdfWriter);

    // Title and metadata
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 16));
    painter.drawText(2000, 1100, "Liste des Centres");
    painter.setFont(QFont("Arial", 10));
    painter.drawText(2000, 1200, "Exporté le: " + QDate::currentDate().toString("dd-MM-yyyy"));

    // Table headers and body
    int startX = 200;
    int startY = 1800;
    int cellWidth = 1100;
    int cellHeight = 450;

    QStringList headers = {"ID", "Nom", "Adresse", "Date", "Capacité", "Disponibilité"};
    painter.setFont(QFont("Arial", 10, QFont::Bold));

    for (int col = 0; col < headers.size(); ++col) {
        painter.drawText(startX + col * cellWidth, startY, cellWidth, cellHeight, Qt::AlignCenter, headers[col]);
        painter.drawRect(startX + col * cellWidth, startY, cellWidth, cellHeight);
    }

    // Table rows
    painter.setFont(QFont("Arial", 10));
    int rowCount = model->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        QColor bgColor = (row % 2 == 0) ? Qt::lightGray : Qt::white;

        for (int col = 0; col < headers.size(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            QRect cellRect(startX + col * cellWidth, startY + (row + 1) * cellHeight, cellWidth, cellHeight);

            painter.fillRect(cellRect, bgColor);
            painter.drawText(cellRect, Qt::AlignCenter, data);
            painter.drawRect(cellRect);
        }
    }

    // Summary
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.drawText(2000, startY + (rowCount + 1) * cellHeight + 200, "Résumé:");
    painter.setFont(QFont("Arial", 10));
    painter.drawText(2000, startY + (rowCount + 2) * cellHeight + 200, "Nombre total de centres: " + QString::number(rowCount));
}

QMap<int, int> center::getCentersByAvailability()
{
    QMap<int, int> availabilityStats;

    QSqlQuery query;
    // Count centers by disponibilite status
    query.prepare("SELECT disponibilite, COUNT(*) FROM center GROUP BY disponibilite");

    if (query.exec()) {
        while (query.next()) {
            int status = query.value(0).toInt();
            int count = query.value(1).toInt();
            availabilityStats[status] = count;
        }
    } else {
        qDebug() << "Error fetching availability stats:" << query.lastError().text();
    }

    // Ensure all statuses are represented (0 and 1)
    if (!availabilityStats.contains(0)) availabilityStats[0] = 0;
    if (!availabilityStats.contains(1)) availabilityStats[1] = 0;

    return availabilityStats;
}
