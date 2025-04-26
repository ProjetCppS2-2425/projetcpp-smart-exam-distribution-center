#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("sarra");
    db.setUserName("sarra");//inserer nom de l'utilisateur
    db.setPassword("123456789");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;


    return  test;
}
