#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString.h>
#include<QSqlQuery>
#include<QSqlQueryModel>

class produit
{
private:
    int code;
    QString nom;
    int quantite;
    bool disponibilite;
    float prix_achat;
    QString id_emp;
public:
    produit();
    produit(QString,int,float);
    int get_code(){return code;}
    void set_code(int c) {code=c;}
    QString get_nom(){return nom;}
    void set_nom(QString n) {nom=n;}
    int get_qte(){return quantite;}
    void set_qte(int q) {quantite+=q;}
    int get_disp(){return disponibilite;}
    void set_disp(){disponibilite=!disponibilite;}
    float get_prix(){return prix_achat;}
    void set_prix(float p){prix_achat=p;}
    bool ajouter();
    int debiter(QString nom, int qter);
    QSqlQuery rechercher(QString nom);
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQuery rechercheqte(int qte);
    QSqlQuery recherchedisp(int disponibilite);
    QSqlQuery tri(QString critere);

};

#endif // PRODUIT_H
