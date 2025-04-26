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


#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrinterInfo>
#include <QtGui/QPainter>
#include <QtGui/QFont>
#include <QtCore/QDate>
#include <QtGui/QPageSize>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QMap>

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

QMap<int, int> center::getCentersByAvailability()
{
    QMap<int, int> stats;

    // Initialize with zero values to handle case where query returns no results
    stats.insert(1, 0); // Available (disponibilite = 1)
    stats.insert(0, 0); // Unavailable (disponibilite = 0)

    QSqlQuery query;

    // Count available centers (disponibilite = 1)
    if (query.exec("SELECT COUNT(*) FROM center WHERE disponibilite = 1")) {
        if (query.next()) {
            stats[1] = query.value(0).toInt();
        }
    } else {
        qDebug() << "Error querying available centers:" << query.lastError().text();
    }

    // Count unavailable centers (disponibilite = 0)
    if (query.exec("SELECT COUNT(*) FROM center WHERE disponibilite = 0")) {
        if (query.next()) {
            stats[0] = query.value(0).toInt();
        }
    } else {
        qDebug() << "Error querying unavailable centers:" << query.lastError().text();
    }

    // Add debug output
    qDebug() << "Centers with disponibilite=1:" << stats[1];
    qDebug() << "Centers with disponibilite=0:" << stats[0];

    return stats;
}
