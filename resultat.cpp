#include "resultat.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>

resultat::resultat() {}

resultat::resultat(int ID_ETUDIANT, const QString &NOM, const QString &MATIERE, const QString &STATUT, const QDate &DATE_RES, double NOTE)
    : ID_ETUDIANT(ID_ETUDIANT), NOM(NOM), MATIERE(MATIERE), STATUT(STATUT), DATE_RES(DATE_RES), NOTE(NOTE) {}

// Ajouter un résultat
bool resultat::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RESULTAT (ID_ETUDIANT, NOM, MATIERE, DATE_RES, STATUT, NOTE) "
                  "VALUES (:ID_ETUDIANT, :NOM, :MATIERE, :DATE_RES, :STATUT, :NOTE)");
    query.bindValue(":ID_ETUDIANT", ID_ETUDIANT);
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

// Modifier un résultat
bool resultat::modifier(int ID_ETUDIANT)
{
    QSqlQuery query;
    query.prepare("UPDATE RESULTAT SET NOM = :NOM, MATIERE = :MATIERE, DATE_RES = :DATE_RES, STATUT = :STATUT, NOTE = :NOTE WHERE ID_ETUDIANT = :ID_ETUDIANT");
    query.bindValue(":ID_ETUDIANT", ID_ETUDIANT);
    query.bindValue(":NOM", NOM);
    query.bindValue(":MATIERE", MATIERE);
    query.bindValue(":DATE_RES", DATE_RES);
    query.bindValue(":STATUT", STATUT);
    query.bindValue(":NOTE", NOTE);

    return query.exec();
}

// Supprimer un résultat
bool resultat::supprimer(int ID_ETUDIANT)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RESULTAT WHERE ID_ETUDIANT = :ID_ETUDIANT");
    query.bindValue(":ID_ETUDIANT", ID_ETUDIANT);

    return query.exec();
}

// Afficher tous les résultats
QSqlQueryModel *resultat::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM RESULTAT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ETUDIANT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MATIERE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_RES"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOTE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT"));
    return model;
}

// Rechercher par nom ou matière
QSqlQueryModel* resultat::rechercher(const QString& critere)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM RESULTAT WHERE NOM LIKE :critere OR MATIERE LIKE :critere");
    query.bindValue(":critere", "%" + critere + "%");
    query.exec();

    model->setQuery(query);
    return model;
}

// Trier selon un critère
QSqlQueryModel* resultat::trier(const QString& critere, Qt::SortOrder order)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString orderStr = (order == Qt::AscendingOrder) ? "ASC" : "DESC";  // Choisir l'ordre en fonction de l'argument

    QString queryStr;
    if (critere == "NOTE") {
        queryStr = "SELECT * FROM RESULTAT ORDER BY NOTE " + orderStr;  // Trier par note
    }
    else if (critere == "DATE_RES") {
        queryStr = "SELECT * FROM RESULTAT ORDER BY DATE_RES " + orderStr;  // Trier par date
    }

    model->setQuery(queryStr);  // Exécuter la requête

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL lors du tri: " << model->lastError().text();
    }

    return model;  // Retourner le modèle trié
}

