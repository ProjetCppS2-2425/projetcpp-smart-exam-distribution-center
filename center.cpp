#include "center.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

center::center()
{
    idcenter=0; nom=" "; adresse=" "; capacite= 0;
}

center::center(int idcenter,QString nom,QString adresse,QDate datec, int capacite)
{
    this->idcenter=idcenter;
    this->nom=nom;
    this->adresse=adresse;
    this->datec=datec;
    this->capacite=capacite;
}

center::center(QString nom,QString adresse,QDate datec, int capacite)
{
    this->nom=nom;
    this->adresse=adresse;
    this->datec=datec;
    this->capacite=capacite;
}


int center::getidcenter(){return idcenter;}
QString center::getnom(){return nom;}
QString center::getadresse(){return adresse;}
QDate center::getdatec(){return datec;}
int center::getcapacite(){return capacite;}


void center::setidcenter(int idcenter){this->idcenter=idcenter;}
void center::setnom(QString nom){this->nom=nom;}
void center::setadresse(QString adresse){this->adresse=adresse;}
void center::setdatec(QDate datec){this->datec=datec;}
void center::setcapacite(int capacite){this->capacite=capacite;}




bool center::ajouterCenter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO center (nom, adresse, datec, capacite) "
                  "VALUES (:nom, :adresse, :datec, :capacite)");// prparation de requette
    query.bindValue(":nom", nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":datec",datec );
    query.bindValue(":capacite",capacite);
    return query.exec();

}



/***********************************************************************************************/


QSqlQueryModel* center::afficherCenter()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM center ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id unique"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datec"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("capacite"));

    return model;
}


/***********************************************************************************************/


bool center::supprimerCenter(int idcenter)
{
    QSqlQuery query;
    query.prepare(" Delete from center where idcenter=:idcenter ");
    query.bindValue(":idcenter",idcenter);

    return query.exec();
}



/***********************************************************************************************/



bool center::modifierCenter(int idcenter,QString nom,QString adresse,QDate datec,int capacite)
{

    QSqlQuery query;
    query.prepare("update center set nom=:nom,adresse=:adresse,datec=:datec,capacite=:capacite where idcenter=:idcenter");
    query.bindValue(":idcenter",idcenter);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":datec",datec);
    query.bindValue(":capacite",capacite);
    return query.exec();

}





