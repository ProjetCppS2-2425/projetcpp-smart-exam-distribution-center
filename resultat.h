#ifndef RESULTAT_H
#define RESULTAT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class resultat
{
    int ID_ETUDIANT;
    QString NUMC_ETUDIANT;
    QString NOM, MATIERE, STATUT;
    QDate DATE_RES;
    double NOTE;
    QString IDCENTRE;

public:
    // Constructeurs
    resultat();
    resultat(int ID_ETUDIANT, const QString &NUMC_ETUDIANT, const QString &NOM, const QString &MATIERE, double NOTE, const QDate &DATE_RES, const QString &STATUT, const QString &IDCENTRE);
    resultat(const QString &NUMC_ETUDIANT, const QString &NOM, const QString &MATIERE, double NOTE, const QDate &DATE_RES, const QString &STATUT, const QString &IDCENTRE);

    // Getters
    int getID_ETUDIANT() const;
    QString getNUMC_ETUDIANT() const;
    QString getNOM() const;
    QDate getDATE_RES() const;
    QString getSTATUT() const;
    QString getMATIERE() const;
    float getNOTE() const;
    QString getIDCENTRE() const;

    // Setters
    void setID_ETUDIANT(int id);
    void setNUMC_ETUDIANT(const QString &NUMC_ETUDIANT);
    void setNOM(const QString &NOM);
    void setMATIERE(const QString &MATIERE);
    void setSTATUT(const QString &STATUT);
    void setDATE_RES(const QDate &DATE);
    void setNOTE(double NOTE);
    void setIDCENTRE(const QString &idcentre);

    // Fonctionnalités
    bool ajouter();
    bool modifier(const QString &NUMC_ETUDIANT);
    bool supprimer(const QString &NUMC_ETUDIANT);
    QSqlQueryModel *afficher();
    QSqlQueryModel* rechercher(const QString& critere);
    // Modifier la déclaration de la fonction trier pour accepter un paramètre d'ordre
    QSqlQueryModel* trier(const QString& critere, const QString& ordre);
};

#endif // RESULTAT_H
