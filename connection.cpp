#include "connection.h"

Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projetQT");
    db.setUserName("ilyes");  // Insérez le bon utilisateur
    db.setPassword("123");    // Insérez le bon mot de passe

    if (db.open())
        test = true;

    return test;
}
