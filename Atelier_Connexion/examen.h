#ifndef EXAMEN_H
#define EXAMEN_H

#include <QString>
#include <QSqlQuery>
#include <QTableWidget>
#include <QHeaderView>
#include <QDebug>
#include <QMessageBox>

class Examen {
public:
    Examen();
    Examen(int id, QString titre, QString sujet, QString statut);
    Examen(QString titre, QString sujet, QString statut);

    // Getter methods
    int getID() const;
    QString getTitre() const;
    QString getSujet() const;
    QString getStatut() const;

    // Setter methods
    void setID(int id);
    void setTitre(QString titre);
    void setSujet(QString sujet);
    void setStatut(QString statut);

    // Database operations
    bool ajouter();
    void afficher(QTableWidget *tableWidget);
    bool supprimer(int id);
    bool modifier(int id);
    void rechercherParTitre(QTableWidget *tableWidget, QString titre);
    void Tri(QTableWidget *tableWidget, QString cls, QString champ);

private:
    int id;
    QString titre;
    QString sujet;
    QString statut;
};

#endif // EXAMEN_H
