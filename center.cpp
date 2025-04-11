#include "center.h"
#include "qcolor.h"
#include "qfont.h"
#include "qsqlerror.h"
#include "qwindowdefs.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

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

    model->setQuery("SELECT * FROM center");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id unique"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datec"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("capacite"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("disponibilité"));

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
    query.prepare("UPDATE center SET nom=:nom, adresse=:adresse, datec=:datec, capacite=:capacite, disponibilite=:disponibilite WHERE idcenter=:idcenter");
    query.bindValue(":idcenter", idcenter);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":datec", datec);
    query.bindValue(":capacite", capacite);
    query.bindValue(":disponibilite", disponibilite);
    return query.exec();
}

void center::exporterPDF(const QString &nomFichier, QAbstractItemModel *model)
{
    QPdfWriter pdfWriter(nomFichier);
    QPainter painter(&pdfWriter);

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(2500, 1100, "Liste des Centres");

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
}

QSqlQueryModel* center::rechercher(int id)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM center WHERE idcenter = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
    }

    model->setQuery(query);
    return model;
}

QSqlQueryModel* center::trierParCapacite()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM center ORDER BY capacite DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Création"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Capacité"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Disponibilité"));

    return model;
}


/*QMap<QString, double> center::obtenirStatistiquesDisponibilite() {
    QMap<QString, double> stats;
    QSqlQuery query;

    // Calculer le nombre total de centres
    query.prepare("SELECT COUNT(*) FROM CENTER");
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération du nombre total de centres :" << query.lastError().text();
        return stats;
    }

    query.next();
    int totalCenters = query.value(0).toInt();
    if (totalCenters == 0) {
        return stats;
    }

    // Récupérer les statistiques de disponibilité des centres
    query.prepare("SELECT DISPONIBILITE, COUNT(*) FROM CENTER GROUP BY DISPONIBILITE");
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des statistiques de disponibilité des centres :" << query.lastError().text();
        return stats;
    }

    // Calculer le pourcentage pour chaque disponibilité
    while (query.next()) {
        int disponibilite = query.value(0).toInt();
        int count = query.value(1).toInt();

        double percentage = (count * 100.0) / totalCenters;

        if (disponibilite == 1) {
            stats["Disponible"] = percentage;
        } else {
            stats["Non Disponible"] = percentage;
        }
    }

    return stats;
}*/
