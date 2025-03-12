#include "resultat.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>

resultat::resultat(){}

resultat::resultat(int ID_ETUDIANT, const QString &NOM, const QString &MATIERE, const QString &STATUT, const QDate &DATE_RES, double NOTE)
    : ID_ETUDIANT(ID_ETUDIANT), NOM(NOM), MATIERE(MATIERE), STATUT(STATUT), DATE_RES(DATE_RES), NOTE(NOTE) {}

bool resultat ::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(ID_ETUDIANT);
    query.prepare("INSERT INTO RESULTAT (ID_ETUDIANT, NOM, MATIERE, DATE_RES, STATUT, NOTE) "
                  "VALUES (:ID_ETUDIANT, :NOM, :MATIERE, :DATE_RES, :STATUT, :NOTE)");
    query.bindValue(":ID_ETUDIANT", res);
    query.bindValue(":NOM", NOM);
    query.bindValue(":MATIERE", MATIERE);
    query.bindValue(":DATE_RES", DATE_RES);
    query.bindValue(":STATUT", STATUT);
    query.bindValue(":NOTE", NOTE);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout :" << query.lastError().text();
        return false;
    }
    return true;
}


//modifier un resultat
bool resultat::modifier(int ID_ETUDIANT)
{
    QSqlQuery query;
    query.prepare("UPDATE RESULTAT SET  NOM = :NOM, MATIERE = :MATIERE, DATE_RES = :DATE_RES, STATUT = :STATUT, NOTE = :NOTE WHERE ID_ETUDIANT = :ID_ETUDIANT");
    query.bindValue(":ID_ETUDIANT", ID_ETUDIANT);
    query.bindValue(":NOM", NOM);
    query.bindValue(":MATIERE", MATIERE);
    query.bindValue(":DATE_RES", DATE_RES);
    query.bindValue(":STATUT", STATUT);
    query.bindValue(":NOTE", NOTE);
    return query.exec();
}

//Afficher les resultat
QSqlQueryModel * resultat::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM RESULTAT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ETUDIANT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MATIERE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_RES"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOTE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT"));
    return model;}
bool resultat::supprimer(int ID_ETUDIANT)
{
    QSqlQuery query;
    QString res = QString::number(ID_ETUDIANT);
    query.prepare("DELETE FROM RESULTAT WHERE ID_ETUDIANT = :ID_ETUDIANT");
    query.bindValue(":ID_ETUDIANT", res);
    return query.exec();
}

