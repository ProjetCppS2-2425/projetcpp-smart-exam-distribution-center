#include "resultat.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>

resultat::resultat() {}

resultat::resultat(const QString &NUMC_ETUDIANT, const QString &NOM, const QString &MATIERE, double NOTE, const QDate &DATE_RES, const QString &STATUT)
    : NUMC_ETUDIANT(NUMC_ETUDIANT), NOM(NOM), MATIERE(MATIERE), NOTE(NOTE), DATE_RES(DATE_RES), STATUT(STATUT) {}

// Ajouter un résultat
bool resultat::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RESULTAT (NUMC_ETUDIANT, NOM, MATIERE, DATE_RES, STATUT, NOTE) "
                  "VALUES (:NUMC_ETUDIANT, :NOM, :MATIERE, :DATE_RES, :STATUT, :NOTE)");
    query.bindValue(":NUMC_ETUDIANT", NUMC_ETUDIANT);
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

// Modifier un résultat par ID
bool resultat::modifier(const QString &NUMC_ETUDIANT)
{
    QSqlQuery query;
    query.prepare("UPDATE RESULTAT SET NOM = :NOM, MATIERE = :MATIERE, DATE_RES = :DATE_RES, STATUT = :STATUT, NOTE = :NOTE WHERE NUMC_ETUDIANT = :NUMC_ETUDIANT");
    query.bindValue(":NUMC_ETUDIANT", NUMC_ETUDIANT);
    query.bindValue(":NOM", NOM);
    query.bindValue(":MATIERE", MATIERE);
    query.bindValue(":DATE_RES", DATE_RES);
    query.bindValue(":STATUT", STATUT);
    query.bindValue(":NOTE", NOTE);

    return query.exec();
}

// Supprimer un résultat
bool resultat::supprimer(const QString &NUMC_ETUDIANT)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RESULTAT WHERE NUMC_ETUDIANT = :NUMC_ETUDIANT");
    query.bindValue(":NUMC_ETUDIANT", NUMC_ETUDIANT);
    return query.exec();
}

// Afficher tous les résultats
QSqlQueryModel *resultat::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_ETUDIANT, NUMC_ETUDIANT, NOM, MATIERE, NOTE, DATE_RES, STATUT FROM RESULTAT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Matière"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Note"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Résultat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut"));
    return model;
}

// Rechercher par nom ou matière
QSqlQueryModel* resultat::rechercher(const QString& critere)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_ETUDIANT, NUMC_ETUDIANT, NOM, MATIERE, NOTE, DATE_RES, STATUT FROM RESULTAT WHERE NOM LIKE :critere OR MATIERE LIKE :critere");
    query.bindValue(":critere", "%" + critere + "%");
    query.exec();

    model->setQuery(std::move(query));
    return model;
}

// Fonction trier complètement réécrite avec support pour le tri numérique
// Modifier la fonction trier pour qu'elle retourne correctement les données triées
QSqlQueryModel* resultat::trier(const QString& critere, const QString& ordre)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr;

    if (critere.isEmpty()) {
        // Si aucun critère n'est spécifié, trier par ID par défaut
        queryStr = "SELECT ID_ETUDIANT, NUMC_ETUDIANT, NOM, MATIERE, NOTE, DATE_RES, STATUT FROM RESULTAT ORDER BY ID_ETUDIANT ASC";
    } else {
        queryStr = "SELECT ID_ETUDIANT, NUMC_ETUDIANT, NOM, MATIERE, NOTE, DATE_RES, STATUT FROM RESULTAT ORDER BY " + critere + " " + ordre;
    }

    model->setQuery(queryStr);
    if (model->lastError().isValid()) {
        qDebug() << "SQL Error: " << model->lastError().text();
    }

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Matière"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Note"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Résultat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut"));

    return model;
}
