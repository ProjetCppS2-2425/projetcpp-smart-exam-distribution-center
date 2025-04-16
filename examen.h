#ifndef EXAMEN_H
#define EXAMEN_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QTableWidget>
#include <QHeaderView>
#include <QDebug>
#include <QMessageBox>

class Examen {
public:
    Examen();
    Examen(int id, QString titre, QString sujet, QString statut, QDate date_examen, int id_transport);
    Examen(QString titre, QString sujet, QString statut, QDate date_examen, int id_transport);

    // Getter methods
    int getID() const;
    QString getTitre() const;
    QString getSujet() const;
    QString getStatut() const;
    QDate getDateExamen() const;
    int getIdTransport() const;

    // Setter methods
    void setID(int id);
    void setTitre(QString titre);
    void setSujet(QString sujet);
    void setStatut(QString statut);
    void setDateExamen(QDate date_examen);
    void setIdTransport(int id_transport);

    // Database operations
    bool ajouter();
    void afficher(QTableWidget *tableWidget);
    bool supprimer(int id);
    bool modifier(int id);
    void rechercherExamens(QTableWidget *tableWidget, QString searchText);
    void Tri(QTableWidget *tableWidget, QString cls, QString champ);
    QMap<QString, int> getExamCountByStatus();

private:
    int id;
    QString titre;
    QString sujet;
    QString statut;
    QDate date_examen;
    int id_transport;
};

#endif // EXAMEN_H
