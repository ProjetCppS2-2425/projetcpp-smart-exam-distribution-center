#include "examen.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QSqlError> // Add this line to fix the error

// Constructors
Examen::Examen() {}

Examen::Examen(int id, QString titre, QString sujet, QString statut)
    : id(id), titre(titre), sujet(sujet), statut(statut) {}

Examen::Examen(QString titre, QString sujet, QString statut)
    : titre(titre), sujet(sujet), statut(statut) {}

// Getters
int Examen::getID() const {
    return id;
}

QString Examen::getTitre() const {
    return titre;
}

QString Examen::getSujet() const {
    return sujet;
}

QString Examen::getStatut() const {
    return statut;
}

// Setters
void Examen::setID(int id) {
    this->id = id;
}

void Examen::setTitre(QString titre) {
    this->titre = titre;
}

void Examen::setSujet(QString sujet) {
    this->sujet = sujet;
}

void Examen::setStatut(QString statut) {
    this->statut = statut;
}

// Database operations
bool Examen::ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO examen (titre, sujet, statut) "
                  "VALUES (:titre, :sujet, :statut)");

    query.bindValue(":titre", titre);
    query.bindValue(":sujet", sujet);
    query.bindValue(":statut", statut);

    if (query.exec()) {
        qDebug() << "Examen ajouté avec succès!";
        return true;
    } else {
        qDebug() << "Échec de l'ajout de l'examen:" << query.lastError().text();
        return false;
    }
}

void Examen::afficher(QTableWidget *tableWidget) {
    QSqlQuery query("SELECT id, titre, sujet, statut FROM examen ORDER BY id");

    // Clear the table widget
    tableWidget->setRowCount(0);

    // Set the number of columns
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels({"ID", "Titre", "Sujet", "Statut"});

    // Populate the table widget
    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);

        // Add data to each column
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Titre
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Sujet
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Statut

        row++;
    }

    // Adjust column widths
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

bool Examen::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM examen WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Examen supprimé avec succès!";
        return true;
    } else {
        qDebug() << "Échec de la suppression de l'examen:" << query.lastError().text();
        return false;
    }
}

bool Examen::modifier(int id) {
    QSqlQuery query;

    query.prepare("UPDATE examen SET titre = :titre, sujet = :sujet, statut = :statut WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":titre", titre);
    query.bindValue(":sujet", sujet);
    query.bindValue(":statut", statut);

    if (query.exec()) {
        qDebug() << "Examen modifié avec succès!";
        return true;
    } else {
        qDebug() << "Échec de la modification de l'examen:" << query.lastError().text();
        return false;
    }
}

void Examen::rechercherParTitre(QTableWidget *tableWidget, QString titre) {
    QSqlQuery query;
    query.prepare("SELECT id, titre, sujet, statut FROM examen WHERE titre LIKE :titre");
    query.bindValue(":titre", "%" + titre + "%");

    if (query.exec()) {
        // Clear the table widget
        tableWidget->setRowCount(0);

        // Populate the table widget
        int row = 0;
        while (query.next()) {
            tableWidget->insertRow(row);

            // Add data to each column
            tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
            tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Titre
            tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Sujet
            tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Statut

            row++;
        }
    } else {
        qDebug() << "Échec de la recherche:" << query.lastError().text();
    }
}

void Examen::Tri(QTableWidget *tableWidget, QString cls, QString champ) {
    QString queryString = "SELECT id, titre, sujet, statut FROM examen ORDER BY " + champ + " " + cls;
    QSqlQuery query(queryString);

    // Clear the table widget
    tableWidget->setRowCount(0);

    // Populate the table widget
    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);

        // Add data to each column
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Titre
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Sujet
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Statut

        row++;
    }
}
