#include "examen.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QSqlError>

// Constructors
Examen::Examen() : id_transport(0), id_centre(0) {}

Examen::Examen(int id, QString titre, QString sujet, QString statut, QDate date_examen, int id_transport, int id_centre)
    : id(id), titre(titre), sujet(sujet), statut(statut), date_examen(date_examen),
    id_transport(id_transport), id_centre(id_centre) {}

Examen::Examen(QString titre, QString sujet, QString statut, QDate date_examen, int id_transport, int id_centre)
    : titre(titre), sujet(sujet), statut(statut), date_examen(date_examen),
    id_transport(id_transport), id_centre(id_centre) {}

// Getters
int Examen::getID() const { return id; }
QString Examen::getTitre() const { return titre; }
QString Examen::getSujet() const { return sujet; }
QString Examen::getStatut() const { return statut; }
QDate Examen::getDateExamen() const { return date_examen; }
int Examen::getIdTransport() const { return id_transport; }
int Examen::getIdCentre() const { return id_centre; }

// Setters
void Examen::setID(int id) { this->id = id; }
void Examen::setTitre(QString titre) { this->titre = titre; }
void Examen::setSujet(QString sujet) { this->sujet = sujet; }
void Examen::setStatut(QString statut) { this->statut = statut; }
void Examen::setDateExamen(QDate date_examen) { this->date_examen = date_examen; }
void Examen::setIdTransport(int id_transport) { this->id_transport = id_transport; }
void Examen::setIdCentre(int id_centre) { this->id_centre = id_centre; }

// Database operations
bool Examen::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO examen (titre, sujet, statut, date_examen, id_transport, id_centre) "
                  "VALUES (:titre, :sujet, :statut, :date_examen, :id_transport, :id_centre)");

    query.bindValue(":titre", titre);
    query.bindValue(":sujet", sujet);
    query.bindValue(":statut", statut);
    query.bindValue(":date_examen", date_examen);
    query.bindValue(":id_transport", id_transport);
    query.bindValue(":id_centre", id_centre);

    return query.exec();
}

void Examen::afficher(QTableWidget *tableWidget) {
    QSqlQuery query("SELECT e.id, e.titre, e.sujet, e.statut, e.date_examen, "
                    "t.DESTINATION, t.nom_livreur, t.date_livraison, c.nom as centre_nom "
                    "FROM examen e "
                    "LEFT JOIN transport t ON e.id_transport = t.id_transport "
                    "LEFT JOIN center c ON e.id_centre = c.IDCENTER "
                    "ORDER BY e.id");

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(9);
    tableWidget->setHorizontalHeaderLabels({"ID", "Titre", "Sujet", "Statut", "Date Examen",
                                            "Destination", "Livreur", "Date Livraison", "Centre"});

    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toDate().toString("dd/MM/yyyy")));
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Destination
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // Livreur
        tableWidget->setItem(row, 7, new QTableWidgetItem(query.value(7).toDate().toString("dd/MM/yyyy"))); // Date Livraison
        tableWidget->setItem(row, 8, new QTableWidgetItem(query.value(8).toString())); // Centre
        row++;
    }

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    if (query.lastError().isValid()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
    }
}

bool Examen::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM examen WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Examen::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE examen SET titre = :titre, sujet = :sujet, statut = :statut, "
                  "date_examen = :date_examen, id_transport = :id_transport, id_centre = :id_centre "
                  "WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":titre", titre);
    query.bindValue(":sujet", sujet);
    query.bindValue(":statut", statut);
    query.bindValue(":date_examen", date_examen);
    query.bindValue(":id_transport", id_transport);
    query.bindValue(":id_centre", id_centre);
    return query.exec();
}

void Examen::rechercherExamens(QTableWidget *tableWidget, QString searchText) {
    QSqlQuery query;
    query.prepare("SELECT e.id, e.titre, e.sujet, e.statut, e.date_examen, "
                  "t.DESTINAION, t.nom_livreur, t.date_livraison, c.nom as centre_nom "
                  "FROM examen e "
                  "LEFT JOIN transport t ON e.id_transport = t.id_transport "
                  "LEFT JOIN centre c ON e.id_centre = c.id "
                  "WHERE e.titre LIKE :searchText OR e.sujet LIKE :searchText OR e.statut LIKE :searchText");
    query.bindValue(":searchText", "%" + searchText + "%");

    if (query.exec()) {
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(9);
        tableWidget->setHorizontalHeaderLabels({"ID", "Titre", "Sujet", "Statut", "Date Examen",
                                                "Destination", "Livreur", "Date Livraison", "Centre"});

        int row = 0;
        while (query.next()) {
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
            tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toDate().toString("dd/MM/yyyy")));
            tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
            tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
            tableWidget->setItem(row, 7, new QTableWidgetItem(query.value(7).toDate().toString("dd/MM/yyyy")));
            tableWidget->setItem(row, 8, new QTableWidgetItem(query.value(8).toString()));
            row++;
        }
    }
}

void Examen::Tri(QTableWidget *tableWidget, QString cls, QString champ) {
    QString queryString = QString("SELECT e.id, e.titre, e.sujet, e.statut, e.date_examen, "
                                  "t.DESTINAION, t.nom_livreur, t.date_livraison, c.nom as centre_nom "
                                  "FROM examen e "
                                  "LEFT JOIN transport t ON e.id_transport = t.id_transport "
                                  "LEFT JOIN center c ON e.id_centre = c.id "
                                  "ORDER BY %1 %2").arg(champ, cls);
    QSqlQuery query(queryString);

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(9);
    tableWidget->setHorizontalHeaderLabels({"ID", "Titre", "Sujet", "Statut", "Date Examen",
                                            "Destination", "Livreur", "Date Livraison", "Centre"});

    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toDate().toString("dd/MM/yyyy")));
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
        tableWidget->setItem(row, 7, new QTableWidgetItem(query.value(7).toDate().toString("dd/MM/yyyy")));
        tableWidget->setItem(row, 8, new QTableWidgetItem(query.value(8).toString()));
        row++;
    }
}

QMap<QString, int> Examen::getExamCountByStatus() {
    QMap<QString, int> statusCounts;
    QSqlQuery query("SELECT statut, COUNT(*) FROM examen GROUP BY statut");
    while (query.next()) {
        QString status = query.value(0).toString();
        int count = query.value(1).toInt();
        statusCounts[status] = count;
    }
    return statusCounts;
}
