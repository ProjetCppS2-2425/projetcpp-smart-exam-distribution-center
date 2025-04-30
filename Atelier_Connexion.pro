QT += core gui widgets sql charts


# Ajoutez cette ligne pour inclure QtCharts
QT += charts
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    Arduino.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    resultat.cpp \
    stat.cpp

HEADERS += \
    Arduino.h \
        mainwindow.h \
    connection.h \
    resultat.h \
    stat.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
