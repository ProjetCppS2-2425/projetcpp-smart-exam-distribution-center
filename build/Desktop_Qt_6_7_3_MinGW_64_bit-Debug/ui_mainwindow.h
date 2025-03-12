/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *rech_res;
    QPushButton *ajout_res;
    QPushButton *exp_res;
    QPushButton *tri_res;
    QPushButton *mod_res;
    QPushButton *supp_res;
    QTableWidget *aff_res;
    QPushButton *rec_res;
    QGroupBox *groupBox;
    QLineEdit *noml_res;
    QLineEdit *matl_res;
    QLineEdit *notel_res;
    QLineEdit *statutl_res;
    QLineEdit *idl_res;
    QLabel *statutlab_res;
    QLabel *notelab_res;
    QLabel *datelab_res;
    QLabel *matlab_res;
    QLabel *idlab_res;
    QLabel *nomlab_res;
    QDateEdit *datel_res;
    QPushButton *vis_res;
    QTextBrowser *linerech_res;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1261, 615);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 221, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        rech_res = new QPushButton(centralwidget);
        rech_res->setObjectName("rech_res");
        rech_res->setGeometry(QRect(750, 40, 161, 51));
        rech_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.85; /* L\303\251g\303\250rement plus opaque pour un effet sophistiqu\303\251 */\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue, pour un contraste \303\251l\303\251gant */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie pour un effet doux */\n"
"    padding: 8px 12px; /* Un peu d'espacement pour am\303\251liorer le confort */\n"
"    \n"
"    transition: all 0.3s ease; /* Pour une transition fluide des effets */\n"
"}\n"
"\n"
"/* Effet de survol */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    "
                        "border-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au survol */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
"\n"
"/* Effet lorsque le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: rgb(230, 240, 255); /* Teinte encore plus claire au clic */\n"
"    border-color: rgb(20, 80, 130); /* Bordure plus fonc\303\251e */\n"
"    color: rgb(20, 80, 130); /* Texte plus fonc\303\251 lors du clic */\n"
"}\n"
""));
        ajout_res = new QPushButton(centralwidget);
        ajout_res->setObjectName("ajout_res");
        ajout_res->setGeometry(QRect(170, 430, 161, 51));
        ajout_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.85; /* L\303\251g\303\250rement plus opaque pour un effet sophistiqu\303\251 */\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue, pour un contraste \303\251l\303\251gant */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie pour un effet doux */\n"
"    padding: 8px 12px; /* Un peu d'espacement pour am\303\251liorer le confort */\n"
"    \n"
"    transition: all 0.3s ease; /* Pour une transition fluide des effets */\n"
"}\n"
"\n"
"/* Effet de survol */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    "
                        "border-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au survol */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
"\n"
"/* Effet lorsque le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: rgb(230, 240, 255); /* Teinte encore plus claire au clic */\n"
"    border-color: rgb(20, 80, 130); /* Bordure plus fonc\303\251e */\n"
"    color: rgb(20, 80, 130); /* Texte plus fonc\303\251 lors du clic */\n"
"}\n"
""));
        exp_res = new QPushButton(centralwidget);
        exp_res->setObjectName("exp_res");
        exp_res->setGeometry(QRect(990, 510, 231, 51));
        exp_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.85; /* L\303\251g\303\250rement plus opaque pour un effet sophistiqu\303\251 */\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue, pour un contraste \303\251l\303\251gant */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie pour un effet doux */\n"
"    padding: 8px 12px; /* Un peu d'espacement pour am\303\251liorer le confort */\n"
"    \n"
"    transition: all 0.3s ease; /* Pour une transition fluide des effets */\n"
"}\n"
"\n"
"/* Effet de survol */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    "
                        "border-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au survol */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
"\n"
"/* Effet lorsque le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: rgb(230, 240, 255); /* Teinte encore plus claire au clic */\n"
"    border-color: rgb(20, 80, 130); /* Bordure plus fonc\303\251e */\n"
"    color: rgb(20, 80, 130); /* Texte plus fonc\303\251 lors du clic */\n"
"}\n"
""));
        tri_res = new QPushButton(centralwidget);
        tri_res->setObjectName("tri_res");
        tri_res->setGeometry(QRect(960, 40, 161, 51));
        tri_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.85; /* L\303\251g\303\250rement plus opaque pour un effet sophistiqu\303\251 */\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue, pour un contraste \303\251l\303\251gant */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie pour un effet doux */\n"
"    padding: 8px 12px; /* Un peu d'espacement pour am\303\251liorer le confort */\n"
"    \n"
"    transition: all 0.3s ease; /* Pour une transition fluide des effets */\n"
"}\n"
"\n"
"/* Effet de survol */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    "
                        "border-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au survol */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
"\n"
"/* Effet lorsque le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: rgb(230, 240, 255); /* Teinte encore plus claire au clic */\n"
"    border-color: rgb(20, 80, 130); /* Bordure plus fonc\303\251e */\n"
"    color: rgb(20, 80, 130); /* Texte plus fonc\303\251 lors du clic */\n"
"}\n"
""));
        mod_res = new QPushButton(centralwidget);
        mod_res->setObjectName("mod_res");
        mod_res->setGeometry(QRect(710, 410, 161, 51));
        mod_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.85; /* L\303\251g\303\250rement plus opaque pour un effet sophistiqu\303\251 */\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue, pour un contraste \303\251l\303\251gant */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie pour un effet doux */\n"
"    padding: 8px 12px; /* Un peu d'espacement pour am\303\251liorer le confort */\n"
"    \n"
"    transition: all 0.3s ease; /* Pour une transition fluide des effets */\n"
"}\n"
"\n"
"/* Effet de survol */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    "
                        "border-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au survol */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
"\n"
"/* Effet lorsque le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: rgb(230, 240, 255); /* Teinte encore plus claire au clic */\n"
"    border-color: rgb(20, 80, 130); /* Bordure plus fonc\303\251e */\n"
"    color: rgb(20, 80, 130); /* Texte plus fonc\303\251 lors du clic */\n"
"}\n"
""));
        supp_res = new QPushButton(centralwidget);
        supp_res->setObjectName("supp_res");
        supp_res->setGeometry(QRect(910, 410, 161, 51));
        supp_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.85; /* L\303\251g\303\250rement plus opaque pour un effet sophistiqu\303\251 */\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue, pour un contraste \303\251l\303\251gant */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie pour un effet doux */\n"
"    padding: 8px 12px; /* Un peu d'espacement pour am\303\251liorer le confort */\n"
"    \n"
"    transition: all 0.3s ease; /* Pour une transition fluide des effets */\n"
"}\n"
"\n"
"/* Effet de survol */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    "
                        "border-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au survol */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
"\n"
"/* Effet lorsque le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: rgb(230, 240, 255); /* Teinte encore plus claire au clic */\n"
"    border-color: rgb(20, 80, 130); /* Bordure plus fonc\303\251e */\n"
"    color: rgb(20, 80, 130); /* Texte plus fonc\303\251 lors du clic */\n"
"}\n"
""));
        aff_res = new QTableWidget(centralwidget);
        if (aff_res->columnCount() < 6)
            aff_res->setColumnCount(6);
        QFont font;
        font.setBold(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        aff_res->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        aff_res->setObjectName("aff_res");
        aff_res->setGeometry(QRect(600, 110, 601, 291));
        aff_res->setStyleSheet(QString::fromUtf8("/* Style pour le QTableWidget */\n"
"QTableWidget {\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    background-color: white;\n"
"    gridline-color: #E1E1E1;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #0078D7;\n"
"    color: white;\n"
"}\n"
"\n"
"/* En-t\303\252te du tableau */\n"
"QHeaderView::section {\n"
"    background-color: #0078D7;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: none;\n"
"}"));
        rec_res = new QPushButton(centralwidget);
        rec_res->setObjectName("rec_res");
        rec_res->setGeometry(QRect(740, 510, 231, 51));
        rec_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.85; /* L\303\251g\303\250rement plus opaque pour un effet sophistiqu\303\251 */\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue, pour un contraste \303\251l\303\251gant */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie pour un effet doux */\n"
"    padding: 8px 12px; /* Un peu d'espacement pour am\303\251liorer le confort */\n"
"    \n"
"    transition: all 0.3s ease; /* Pour une transition fluide des effets */\n"
"}\n"
"\n"
"/* Effet de survol */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    "
                        "border-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au survol */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
"\n"
"/* Effet lorsque le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: rgb(230, 240, 255); /* Teinte encore plus claire au clic */\n"
"    border-color: rgb(20, 80, 130); /* Bordure plus fonc\303\251e */\n"
"    color: rgb(20, 80, 130); /* Texte plus fonc\303\251 lors du clic */\n"
"}\n"
""));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 100, 301, 351));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 255, 255);QGroupBox {\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"    padding-top: 15px;\n"
"    background-color: rgba(255, 255, 255, 0.9);\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"    color: #0078D7;\n"
"    font-weight: bold;\n"
"    background-color: white;\n"
"}"));
        noml_res = new QLineEdit(groupBox);
        noml_res->setObjectName("noml_res");
        noml_res->setGeometry(QRect(140, 80, 141, 37));
        noml_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"    min-height: 25px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0078D7;\n"
"    background-color: #F0F8FF;\n"
"}"));
        matl_res = new QLineEdit(groupBox);
        matl_res->setObjectName("matl_res");
        matl_res->setGeometry(QRect(140, 130, 141, 37));
        matl_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"    min-height: 25px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0078D7;\n"
"    background-color: #F0F8FF;\n"
"}"));
        notel_res = new QLineEdit(groupBox);
        notel_res->setObjectName("notel_res");
        notel_res->setGeometry(QRect(140, 230, 141, 37));
        notel_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"    min-height: 25px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0078D7;\n"
"    background-color: #F0F8FF;\n"
"}"));
        statutl_res = new QLineEdit(groupBox);
        statutl_res->setObjectName("statutl_res");
        statutl_res->setGeometry(QRect(140, 280, 141, 37));
        statutl_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"    min-height: 25px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0078D7;\n"
"    background-color: #F0F8FF;\n"
"}"));
        idl_res = new QLineEdit(groupBox);
        idl_res->setObjectName("idl_res");
        idl_res->setGeometry(QRect(140, 30, 141, 37));
        idl_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"    min-height: 25px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0078D7;\n"
"    background-color: #F0F8FF;\n"
"}\n"
""));
        statutlab_res = new QLabel(groupBox);
        statutlab_res->setObjectName("statutlab_res");
        statutlab_res->setGeometry(QRect(10, 280, 111, 31));
        statutlab_res->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        notelab_res = new QLabel(groupBox);
        notelab_res->setObjectName("notelab_res");
        notelab_res->setGeometry(QRect(10, 230, 111, 31));
        notelab_res->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        datelab_res = new QLabel(groupBox);
        datelab_res->setObjectName("datelab_res");
        datelab_res->setGeometry(QRect(10, 180, 111, 31));
        datelab_res->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        matlab_res = new QLabel(groupBox);
        matlab_res->setObjectName("matlab_res");
        matlab_res->setGeometry(QRect(10, 130, 111, 31));
        matlab_res->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        idlab_res = new QLabel(groupBox);
        idlab_res->setObjectName("idlab_res");
        idlab_res->setGeometry(QRect(10, 30, 111, 31));
        idlab_res->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        nomlab_res = new QLabel(groupBox);
        nomlab_res->setObjectName("nomlab_res");
        nomlab_res->setGeometry(QRect(10, 80, 111, 31));
        nomlab_res->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        datel_res = new QDateEdit(groupBox);
        datel_res->setObjectName("datel_res");
        datel_res->setGeometry(QRect(140, 180, 151, 41));
        datel_res->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    padding: 5px;"));
        vis_res = new QPushButton(centralwidget);
        vis_res->setObjectName("vis_res");
        vis_res->setGeometry(QRect(460, 510, 261, 51));
        vis_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.85; /* L\303\251g\303\250rement plus opaque pour un effet sophistiqu\303\251 */\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue, pour un contraste \303\251l\303\251gant */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie pour un effet doux */\n"
"    padding: 8px 12px; /* Un peu d'espacement pour am\303\251liorer le confort */\n"
"    \n"
"    transition: all 0.3s ease; /* Pour une transition fluide des effets */\n"
"}\n"
"\n"
"/* Effet de survol */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    "
                        "border-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au survol */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
"\n"
"/* Effet lorsque le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: rgb(230, 240, 255); /* Teinte encore plus claire au clic */\n"
"    border-color: rgb(20, 80, 130); /* Bordure plus fonc\303\251e */\n"
"    color: rgb(20, 80, 130); /* Texte plus fonc\303\251 lors du clic */\n"
"}\n"
""));
        linerech_res = new QTextBrowser(centralwidget);
        linerech_res->setObjectName("linerech_res");
        linerech_res->setGeometry(QRect(470, 40, 271, 51));
        linerech_res->setStyleSheet(QString::fromUtf8("    background-color: rgb(240, 248, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        rech_res->raise();
        exp_res->raise();
        tri_res->raise();
        mod_res->raise();
        supp_res->raise();
        aff_res->raise();
        rec_res->raise();
        groupBox->raise();
        ajout_res->raise();
        vis_res->raise();
        linerech_res->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1261, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        rech_res->setText(QCoreApplication::translate("MainWindow", "RECHECHER", nullptr));
        ajout_res->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        exp_res->setText(QCoreApplication::translate("MainWindow", "EXPORATION EN PDF", nullptr));
        tri_res->setText(QCoreApplication::translate("MainWindow", "TRIER", nullptr));
        mod_res->setText(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        supp_res->setText(QCoreApplication::translate("MainWindow", "SUPPRIMER", nullptr));
        QTableWidgetItem *___qtablewidgetitem = aff_res->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID_ETUDIANT", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = aff_res->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = aff_res->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "MATIERE", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = aff_res->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "DATE", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = aff_res->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "NOTE", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = aff_res->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "STATUT", nullptr));
        rec_res->setText(QCoreApplication::translate("MainWindow", "RECLAMATION", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "AJOUTER LE RESULTAT D'ETUDIANT", nullptr));
        noml_res->setText(QString());
        matl_res->setText(QString());
        notel_res->setText(QString());
        statutl_res->setText(QString());
        idl_res->setText(QString());
        statutlab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">STATUT</span></p></body></html>", nullptr));
        notelab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">NOTE</span></p></body></html>", nullptr));
        datelab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">DATE</span></p></body></html>", nullptr));
        matlab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">MATIERE</span></p></body></html>", nullptr));
        idlab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">ID</span></p></body></html>", nullptr));
        nomlab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">NOM</span></p></body></html>", nullptr));
        vis_res->setText(QCoreApplication::translate("MainWindow", "VISUALISATION GRAPHIQUE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
