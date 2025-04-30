QT       += core gui sql
QT       += network
QT += core gui widgets
QT += charts

 QT += printsupport
#QT += charts  #*

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    center.cpp \
    connexion.cpp \
    examen.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcode.cpp \
    resultat.cpp

HEADERS += \
    center.h \
    connexion.h \
    examen.h \
    mainwindow.h \
    qrcode.h \
    resultat.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../bg/bg.qrc \
    ../bg/bg.qrc \
    ../bg/bg.qrc \
    Resources.qrc
