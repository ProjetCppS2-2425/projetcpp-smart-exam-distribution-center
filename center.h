#ifndef CENTER_H
#define CENTER_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QMap>

class center
{
public:
    center();
    center(QString, QString, QDate, int, int);
    center(int, QString, QString, QDate, int);

    int getidcenter();
    QString getnom();
    QString getadresse();
    QDate getdatec();
    int getcapacite();
    int getdisponibilite();

    void setidcenter(int);
    void setnom(QString);
    void setadresse(QString);
    void setdatec(QDate);
    void setcapacite(int);
    void setdisponibilite(int);

    bool ajouterCenter();
    QSqlQueryModel* afficherCenter();
    bool supprimerCenter(int);
    bool modifierCenter(int, QString, QString, QDate, int, int);
    QSqlQueryModel* rechercherMulti(QString recherche);
    QSqlQueryModel* trierParMultiplesCritères();
    QSqlQueryModel* trierParCapacite();

    void exporterPDF(const QString &nomFichier, QAbstractItemModel *model);
    static QMap<QString, double> obtenirStatistiquesDisponibilite();

    QMap<int, int> getCentersByAvailability();

private:
    int idcenter;
    int capacite;
    int disponibilite;
    QString nom;
    QString adresse;
    QDate datec;
};

#endif // CENTER_H
