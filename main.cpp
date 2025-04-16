#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QRadioButton>
#include <QTextStream>
#include <QDebug>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Initialize database connection
    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              QObject::tr("Failed to connect to database.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        return 1; // Early exit on database connection failure
    }

    // Show the main window
    MainWindow w;
    w.show();
    QMessageBox::information(nullptr, QObject::tr("Database Open"),
                             QObject::tr("Connection successful.\nClick Cancel to exit."),
                             QMessageBox::Cancel);

    return a.exec(); // Start the event loop
}
