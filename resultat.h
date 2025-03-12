#ifndef RESULTAT_H
#define RESULTAT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class resultat
{
    int ID_ETUDIANT;
    QString NOM,MATIERE,STATUT;
    QDate DATE_RES;
    double NOTE;
public:
    //constructeurs
    resultat();
    resultat(int ID_ETUDIANT, const QString &NOM, const QString &MATIERE, const QString &STATUT, const QDate &DATE_RES,  double NOTE);

    //Getters
    int getID_ETUDIANT()const;
    QString getNOM()const;
    QDate getDATE_RES()const;
    QString getSTATUT()const;
    QString getMATIERE()const;
    float getNOTE()const;

    //setters
    void setNOM(const QString &NOM);
    void setMATIERE(const QString &MATIERE);
    void setSTATUT(const QString &STATUT);
    void setDATE_RES(const QDate &DATE);
    void setID_ETUDIANT(int ID_ETUDIANT);
    void setNOTE(double NOTE);


    // fonctionnalites
    bool ajouter();
    bool modifier(int ID_ETUDIANT );
    QSqlQueryModel * afficher();
    bool supprimer(int ID_ETUDIANT);
    };
#endif // RESULTAT_H
