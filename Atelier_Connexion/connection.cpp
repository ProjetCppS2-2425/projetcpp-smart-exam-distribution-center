#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("hexame");
    db.setUserName("rayen");
    db.setPassword("rayen");

    if (db.open()) {
        test = true;
        qDebug() << "Connection successful";
    } else {
        qDebug() << "Error: " << db.lastError().text();
    }

    return test;
}
