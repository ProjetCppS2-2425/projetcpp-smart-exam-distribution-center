#ifndef CENTER_H
#define CENTER_H
#include<QString>
#include <QDate>
#include <QSqlQueryModel>

class center
{

public:
    center();
    center(QString,QString,QDate,int);
    center(int,QString,QString,QDate,int);
    int getidcenter();
    QString getnom();
    QString getadresse();
    QDate getdatec();
    int getcapacite();



    void setidcenter(int);
    void setnom(QString);
    void setadresse(QString);
    void setdatec(QDate);
    void setcapacite(int);


    bool ajouterCenter();
    QSqlQueryModel* afficherCenter();
    bool supprimerCenter(int);
    bool modifierCenter(int,QString,QString,QDate,int);


private:
    int idcenter,capacite ;
    QString nom,adresse;
    QDate datec;

};

#endif // CENTER_H
