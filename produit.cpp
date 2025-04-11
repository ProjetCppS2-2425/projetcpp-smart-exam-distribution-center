#include "produit.h"
#include "qsqlerror.h"
#include <QMessageBox>
produit::produit() {
    code=0;
    nom="";
    quantite=0;
    disponibilite=false;
    prix_achat=0;
}
produit::produit(QString nom, int quantite, float pra) {
    this->nom = nom;
    this->quantite = quantite;
    this->prix_achat= pra;
}
bool produit::ajouter() {
    QSqlQuery query;
    int quantite_existante = 0;

    // Vérifier si le produit existe déjà
    query.prepare("SELECT quantite FROM produits WHERE nom = :nom");
    query.bindValue(":nom", nom);

    if (query.exec()) {
        if (query.next()) {
            // Le produit existe, on récupère sa quantité actuelle
            quantite_existante = query.value(0).toInt();
            int nouvelle_quantite = quantite_existante + quantite;

            // Mise à jour de la quantité
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE produits SET quantite = :quantite WHERE nom = :nom");
            updateQuery.bindValue(":quantite", nouvelle_quantite);
            updateQuery.bindValue(":nom", nom);

            if (updateQuery.exec()) {
                return true;  // OK
            } else {
                QMessageBox::critical(nullptr, "Erreur", "Erreur mise à jour : " + updateQuery.lastError().text());
                return false;
            }
        } else {
            // Produit n'existe pas, insertion
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO produits (nom, quantite, disponibilite, prix_achat) "
                                "VALUES (:nom, :quantite, 1, :prix_achat)");
            insertQuery.bindValue(":nom", nom);
            insertQuery.bindValue(":quantite", quantite);
            insertQuery.bindValue(":prix_achat", prix_achat);

            if (insertQuery.exec()) {
                return true;  // OK
            } else {
                QMessageBox::critical(nullptr, "Erreur", "Erreur insertion : " + insertQuery.lastError().text());
                return false;
            }
        }
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Erreur recherche : " + query.lastError().text());
        return false;
    }
}
bool produit::modifier(QString nom){
    QSqlQuery query;
    query.prepare("SELECT DISPONIBILITE FROM produits WHERE NOM =:nom");
    query.bindValue(":nom", nom);
    if(query.exec() && query.next()){
        int d=query.value(0).toInt();
        QSqlQuery updateQuery;
        if(d==0){
            updateQuery.prepare("UPDATE produits SET DISPONIBILITE = 1 WHERE NOM = :nom");
        }
        else{
            updateQuery.prepare("UPDATE produits SET DISPONIBILITE = 0 WHERE NOM = :nom");
        }
        updateQuery.bindValue(":nom", nom);
        return updateQuery.exec();
    }
    else{
        QMessageBox::critical(nullptr, "Erreur", "Nom invalide");
        return false;
    }
}
bool produit::supprimer(QString nom){
    QSqlQuery query;
    query.prepare("DELETE FROM produits WHERE NOM = :nom");
    query.bindValue(":nom", nom);
    if (query.exec()) {
        return query.numRowsAffected() > 0; // Only return true if a row was deleted
    }
    else{
        return false;
    }
}
int produit::debiter(QString nom, int qter){
    QSqlQuery query;
    int quantite_actuelle = 0;
    // Rechercher le produit
    query.prepare("SELECT QUANTITE FROM produits WHERE NOM = :nom");
    query.bindValue(":nom", nom);
    if (query.exec() && query.next()) {
        quantite_actuelle = query.value(0).toInt();
        // Vérifier la quantité
        if (quantite_actuelle >= qter) {
            int nouvelle_quantite = quantite_actuelle - qter;
            // Mise à jour
            QSqlQuery updateQuery;
            if(nouvelle_quantite==0){
                updateQuery.prepare("UPDATE produits SET QUANTITE = :qte, disponibilite = 0 WHERE NOM = :nom");
            }
            else{
                updateQuery.prepare("UPDATE produits SET QUANTITE = :qte WHERE NOM = :nom");
            }
            updateQuery.bindValue(":qte", nouvelle_quantite);
            updateQuery.bindValue(":nom", nom);

            if (updateQuery.exec())
                return 2;
            else
                return 0;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}
QSqlQuery produit::rechercher(QString nom) {
    QSqlQuery query;
    query.prepare("SELECT nom, quantite, prix_achat, disponibilite FROM produits WHERE nom LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");
    query.exec();
    return query;
}
QSqlQuery produit::rechercheqte(int qte) {
    QSqlQuery query;
    query.prepare("SELECT nom, quantite, prix_achat, disponibilite FROM produits WHERE quantite = :qte");
    query.bindValue(":qte",qte);
    query.exec();
    return query;
}
QSqlQuery produit::recherchedisp(int disponibilite){
    QSqlQuery query;
    query.prepare("SELECT nom, quantite, prix_achat, disponibilite FROM produits WHERE disponibilite = :dispo");
    query.bindValue(":dispo", disponibilite);
    query.exec();
    return query;
}
QSqlQuery produit::tri(QString critere) {
    QSqlQuery query;
    QString queryText;

    if (critere.toLower() == "quantite") {
        queryText = "SELECT nom, quantite, prix_achat, disponibilite FROM produits ORDER BY quantite ASC";
    } else if (critere.toLower() == "nom") {
        queryText = "SELECT nom, quantite, prix_achat, disponibilite FROM produits ORDER BY nom ASC";
    } else if (critere.toLower() == "prix") {
        queryText = "SELECT nom, quantite, prix_achat, disponibilite FROM produits ORDER BY prix_achat ASC";
    }
    query.prepare(queryText);
    if (!query.exec()) {
        qDebug() << "Erreur de tri:" << query.lastError().text();
    }

    return query;
}

