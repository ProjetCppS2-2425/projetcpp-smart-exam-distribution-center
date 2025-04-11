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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLineEdit *nom_recherche;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *crit_tri;
    QComboBox *disp_rech;
    QLineEdit *qte_rech;
    QPushButton *stat;
    QPushButton *ajouter;
    QPushButton *debiter;
    QPushButton *modifier;
    QPushButton *pdf;
    QLineEdit *nom_ajt;
    QLineEdit *qte_ajt;
    QLineEdit *prix_ajt;
    QLineEdit *nom_deb;
    QLineEdit *qte_deb;
    QLineEdit *nom_mod;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *nom_supp;
    QPushButton *supprimer;
    QLabel *label_11;
    QMenuBar *menubar;
    QMenu *menuGestion_de_stock;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 661);
        MainWindow->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral de la fen\303\252tre */\n"
"QWidget {\n"
"    background-color: #f5f5f5;\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Style des labels */\n"
"QLabel {\n"
"    color: #333;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style des champs de saisie */\n"
"QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0078d7;\n"
"}\n"
"\n"
"/* Style des ComboBox */\n"
"QComboBox {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    border: 1px solid #ccc;\n"
"    selection-background-color: #0078d7;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* Style des boutons */\n"
"QPushButton {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"    border-radius: 5px"
                        ";\n"
"    padding: 7px 15px;\n"
"    border: none;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #005a9e;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #003f73;\n"
"}\n"
"\n"
"/* Style du QTableWidget */\n"
"QTableWidget {\n"
"    border: 1px solid #ccc;\n"
"    gridline-color: #ddd;\n"
"    background-color: white;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: none;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"}\n"
"QTableWidget::column {\n"
"    width: 20%;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 410, 301, 161));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setBold(false);
        font.setItalic(false);
        tableWidget->setFont(font);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #f8f9fa;\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 8px;\n"
"    gridline-color: #ccc;\n"
"    font-size: 16px;\n"
"	color: black; \n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #a5d6a7;\n"
"    color: black;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #e8f5e9;\n"
"}\n"
""));
        nom_recherche = new QLineEdit(centralwidget);
        nom_recherche->setObjectName("nom_recherche");
        nom_recherche->setGeometry(QRect(340, 299, 113, 31));
        nom_recherche->setFont(font);
        nom_recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    font-size: 16px;\n"
"    background-color: #f8f9fa;\n"
"    selection-background-color: #4CAF50;\n"
"    color: black; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4CAF50;\n"
"    background-color: #ffffff;\n"
"}\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 310, 151, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 380, 221, 16));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 340, 331, 16));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(520, 380, 91, 16));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        crit_tri = new QComboBox(centralwidget);
        crit_tri->addItem(QString());
        crit_tri->addItem(QString());
        crit_tri->addItem(QString());
        crit_tri->addItem(QString());
        crit_tri->setObjectName("crit_tri");
        crit_tri->setGeometry(QRect(630, 370, 121, 31));
        crit_tri->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 243, 255);\n"
"color: rgb(0, 0, 0);"));
        disp_rech = new QComboBox(centralwidget);
        disp_rech->addItem(QString());
        disp_rech->addItem(QString());
        disp_rech->addItem(QString());
        disp_rech->setObjectName("disp_rech");
        disp_rech->setGeometry(QRect(340, 370, 131, 31));
        disp_rech->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 243, 255);\n"
"color: rgb(0, 0, 0);"));
        qte_rech = new QLineEdit(centralwidget);
        qte_rech->setObjectName("qte_rech");
        qte_rech->setGeometry(QRect(340, 340, 113, 31));
        qte_rech->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    font-size: 16px;\n"
"    background-color: #f8f9fa;\n"
"    selection-background-color: #4CAF50;\n"
"    color: black; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4CAF50;\n"
"    background-color: #ffffff;\n"
"}\n"
""));
        stat = new QPushButton(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(500, 490, 181, 31));
        stat->setFont(font1);
        stat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 12px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 35px;\n"
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
"}"));
        ajouter = new QPushButton(centralwidget);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(60, 240, 141, 41));
        ajouter->setFont(font1);
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 12px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 35px;\n"
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
"}"));
        debiter = new QPushButton(centralwidget);
        debiter->setObjectName("debiter");
        debiter->setGeometry(QRect(260, 240, 131, 41));
        debiter->setFont(font1);
        debiter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 12px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 35px;\n"
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
"}"));
        modifier = new QPushButton(centralwidget);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(430, 240, 141, 41));
        modifier->setFont(font1);
        modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 12px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 35px;\n"
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
"}"));
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(500, 540, 161, 31));
        pdf->setFont(font1);
        pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 12px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 35px;\n"
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
"}"));
        nom_ajt = new QLineEdit(centralwidget);
        nom_ajt->setObjectName("nom_ajt");
        nom_ajt->setGeometry(QRect(60, 80, 113, 20));
        nom_ajt->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: black; \n"
"}"));
        qte_ajt = new QLineEdit(centralwidget);
        qte_ajt->setObjectName("qte_ajt");
        qte_ajt->setGeometry(QRect(60, 130, 113, 20));
        qte_ajt->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: black; \n"
"}"));
        prix_ajt = new QLineEdit(centralwidget);
        prix_ajt->setObjectName("prix_ajt");
        prix_ajt->setGeometry(QRect(60, 180, 113, 20));
        prix_ajt->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: black; \n"
"}"));
        nom_deb = new QLineEdit(centralwidget);
        nom_deb->setObjectName("nom_deb");
        nom_deb->setGeometry(QRect(260, 130, 113, 20));
        nom_deb->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: black; \n"
"}"));
        qte_deb = new QLineEdit(centralwidget);
        qte_deb->setObjectName("qte_deb");
        qte_deb->setGeometry(QRect(260, 180, 113, 20));
        qte_deb->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: black; \n"
"}"));
        nom_mod = new QLineEdit(centralwidget);
        nom_mod->setObjectName("nom_mod");
        nom_mod->setGeometry(QRect(430, 180, 113, 20));
        nom_mod->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: black; \n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 60, 111, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 110, 111, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 160, 111, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(260, 110, 111, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(260, 160, 131, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(430, 160, 111, 16));
        nom_supp = new QLineEdit(centralwidget);
        nom_supp->setObjectName("nom_supp");
        nom_supp->setGeometry(QRect(630, 180, 113, 20));
        nom_supp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: black; \n"
"}"));
        supprimer = new QPushButton(centralwidget);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(630, 240, 141, 41));
        supprimer->setFont(font1);
        supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
"    background-color: white; /* Fond blanc pour l'int\303\251rieur du bouton */\n"
"    font-size: 12px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 35px;\n"
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
"}"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(630, 160, 111, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuGestion_de_stock = new QMenu(menubar);
        menuGestion_de_stock->setObjectName("menuGestion_de_stock");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGestion_de_stock->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Dispo", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Recherche par nom :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Rechercher par disponibilte :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Rechercher par quantite :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Trier selon :", nullptr));
        crit_tri->setItemText(0, QCoreApplication::translate("MainWindow", "Choisissez", nullptr));
        crit_tri->setItemText(1, QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        crit_tri->setItemText(2, QCoreApplication::translate("MainWindow", "Prix", nullptr));
        crit_tri->setItemText(3, QCoreApplication::translate("MainWindow", "nom", nullptr));

        disp_rech->setItemText(0, QCoreApplication::translate("MainWindow", "Choisissez", nullptr));
        disp_rech->setItemText(1, QCoreApplication::translate("MainWindow", "Disponible", nullptr));
        disp_rech->setItemText(2, QCoreApplication::translate("MainWindow", "Non disponible", nullptr));

        stat->setText(QCoreApplication::translate("MainWindow", "Gerer Des Statistiques \360\237\223\212", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Stocker/Ajouter \342\236\225", nullptr));
        debiter->setText(QCoreApplication::translate("MainWindow", "Debiter \342\236\226", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modifer Status \360\237\223\235", nullptr));
        pdf->setText(QCoreApplication::translate("MainWindow", "Convertir en PDF \360\237\223\204", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Prix d'achat", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Quantite a debiter", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        menuGestion_de_stock->setTitle(QCoreApplication::translate("MainWindow", "Gestion de stock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
