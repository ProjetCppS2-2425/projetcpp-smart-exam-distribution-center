#ifndef CENTER_H
#define CENTER_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

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
    QSqlQueryModel* rechercher(int);
    QSqlQueryModel* trierParCapacite();

    void exporterPDF(const QString&, QAbstractItemModel*);
    static QMap<QString, double> obtenirStatistiquesDisponibilite();

private:
    int idcenter;
    int capacite;
    int disponibilite;
    QString nom;
    QString adresse;
    QDate datec;
};

#endif // CENTER_H
