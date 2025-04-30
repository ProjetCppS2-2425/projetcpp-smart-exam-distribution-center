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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_7;
    QTableWidget *aff_res;
    QPushButton *stats_res;
    QPushButton *tri_res;
    QPushButton *mod_res;
    QGroupBox *groupBox_2;
    QLineEdit *noml_res;
    QLineEdit *matl_res;
    QLineEdit *notel_res;
    QLineEdit *statutl_res;
    QLineEdit *numcl_res;
    QLabel *statutlab_res;
    QLabel *notelab_res;
    QLabel *datelab_res;
    QLabel *matlab_res;
    QLabel *idlab_res;
    QLabel *nomlab_res;
    QDateEdit *datel_res;
    QLabel *centrelab_res;
    QComboBox *centrebox_res;
    QPushButton *supp_res;
    QPushButton *exp_res;
    QPushButton *rech_res;
    QLineEdit *rechl_res;
    QComboBox *Ctri_res;
    QFrame *frame_res;
    QPushButton *ajout_res;
    QWidget *page_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_modifier;
    QPushButton *trierButton;
    QPushButton *pushButton_supprimer;
    QPushButton *rechercherButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_afficher;
    QTableView *tableView_center;
    QLabel *label_6;
    QLineEdit *lineEdit_idcenter;
    QGroupBox *groupBox;
    QPushButton *pushButton_annuler;
    QPushButton *pushButton_ajouter;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_adresse;
    QLineEdit *lineEdit_capacite;
    QLabel *label_13;
    QLineEdit *lineEdit_disponibilite;
    QLabel *label_12;
    QDateEdit *dateEdit_;
    QPushButton *pb_pdf;
    QLineEdit *lineEdit_recherche_multi;
    QComboBox *comboBox_tri;
    QFrame *frame;
    QWidget *page_6;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_sujet;
    QComboBox *comboBox_order;
    QDateEdit *dateEdit_exam;
    QLabel *label_14;
    QPushButton *trier_Butoon_;
    QFrame *frame_exam;
    QLabel *label_15;
    QPushButton *pushButton_7;
    QTableWidget *tableWidget_examens;
    QLineEdit *lineEdit_statut;
    QPushButton *suppexamButton;
    QLineEdit *lineEdit_titre;
    QComboBox *comboBoxsortchamp;
    QLabel *label_16;
    QPushButton *pushButton_5;
    QLabel *label_17;
    QPushButton *modifexamButton;
    QLabel *label_18;
    QLabel *label_19;
    QComboBox *comboBox_transport;
    QLabel *label_20;
    QLineEdit *idExam;
    QPushButton *ajout_examButton;
    QLabel *qrCodeLabel;
    QComboBox *comboBox_foreign_center;
    QLabel *label;
    QPushButton *pushButton_examen;
    QPushButton *pushButton_centre;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_resultat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1868, 1105);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(210, -20, 1611, 981));
        stackedWidget->setStyleSheet(QString::fromUtf8("/* === Background with Linear Gradient === */\n"
"QWidget {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 #007BFF, stop:1 #F8F9FA);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 12pt;\n"
"}\n"
"\n"
"/* === Group Box Styling === */\n"
"QGroupBox {\n"
"    border: 2px solid #0056b3;\n"
"    border-radius: 10px;\n"
"    margin-top: 10px;\n"
"    padding: 15px;\n"
"    background: transparent; /* Semi-transparent */\n"
"}\n"
"\n"
"/* === Stylish Input Fields === */\n"
"QLineEdit, QComboBox, QDateEdit {\n"
"    border: 2px solid #007BFF;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    background: white;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* === Input Fields on Focus === */\n"
"QLineEdit:focus, QComboBox:focus, QDateEdit:focus {\n"
"    border: 2px solid #0056b3;\n"
"    background: #e6f2ff;\n"
"}\n"
"\n"
"/* === Modern Buttons === */\n"
"QPushButton {\n"
"    background-color: #007BFF;\n"
"    c"
                        "olor: white;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* === Button Hover Effect === */\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"/* === Button Click Effect === */\n"
"QPushButton:pressed {\n"
"    background-color: #003d82;\n"
"    transform: scale(0.95);\n"
"}\n"
"\n"
"/* === Table Styling === */\n"
"QTableWidget {\n"
"    background: white;\n"
"    border: 2px solid #007BFF;\n"
"    gridline-color: #007BFF;\n"
"    selection-background-color: #CDE1F8;\n"
"}\n"
"\n"
"/* === Headers in Table === */\n"
"QHeaderView::section {\n"
"    background-color: #007BFF;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    padding: 5px;\n"
"    border: 1px solid #0056b3;\n"
"}\n"
"\n"
"/* === Scrollbar for Table === */\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    background: white;\n"
"    border: 2px solid #007BFF;\n"
"  "
                        "  width: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical, QScrollBar::handle:horizontal {\n"
"    background: #007BFF;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover, QScrollBar::handle:horizontal:hover {\n"
"    background: #0056b3;\n"
"}\n"
"\n"
"QLabel{\n"
"background-color:transparent;\n"
"}\n"
"\n"
"QFormLayout{\n"
"background-color:transparent;\n"
"}"));
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        aff_res = new QTableWidget(page_7);
        if (aff_res->columnCount() < 8)
            aff_res->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font;
        font.setBold(false);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        aff_res->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        aff_res->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        aff_res->setObjectName("aff_res");
        aff_res->setGeometry(QRect(500, 130, 701, 291));
        aff_res->setStyleSheet(QString::fromUtf8("/* Style pour le QTableWidget */\n"
"QTableWidget {\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    background-color: white;\n"
"	color: rgb(0, 0, 0);\n"
"    gridline-color: #E1E1E1;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #0078D7;\n"
"    color: black;\n"
"}\n"
"\n"
"/* En-t\303\252te du tableau */\n"
"QHeaderView::section {\n"
"    background-color: #0078D7;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: none;\n"
"}"));
        stats_res = new QPushButton(page_7);
        stats_res->setObjectName("stats_res");
        stats_res->setGeometry(QRect(150, 640, 231, 51));
        stats_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tri_res = new QPushButton(page_7);
        tri_res->setObjectName("tri_res");
        tri_res->setGeometry(QRect(1040, 60, 161, 51));
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
        mod_res = new QPushButton(page_7);
        mod_res->setObjectName("mod_res");
        mod_res->setGeometry(QRect(1230, 220, 161, 51));
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
        groupBox_2 = new QGroupBox(page_7);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(80, 140, 381, 461));
        groupBox_2->setStyleSheet(QString::fromUtf8("/* Style du groupe de boutons CRUD (QGroupBox) */\n"
"QGroupBox {\n"
"    background-color: #f7f9fc; /* Fond clair pour le groupe */\n"
"    border: 2px solid #2980b9; /* Bordure bleue pour d\303\251limiter la zone */\n"
"    border-radius: 10px; /* Coins arrondis pour une touche moderne */\n"
"    padding: 20px; /* Espacement interne pour a\303\251rer le contenu */\n"
"    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1); /* Ombre l\303\251g\303\250re pour donner de la profondeur */\n"
"    margin: 20px 0; /* Espacement ext\303\251rieur entre les groupes */\n"
"}\n"
"\n"
"/* Titre du QGroupBox */\n"
"QGroupBox::title {\n"
"    color: rgb(51, 102, 153); /* Couleur du texte du titre du groupe */\n"
"    font-size: 20px; /* Taille du texte */\n"
"    font-weight: bold;\n"
"    padding: 5px; /* Espacement autour du texte du titre */\n"
"    background-color: transparent; /* Aucun fond derri\303\250re le titre */\n"
"}\n"
"\n"
"/* Style des boutons CRUD \303\240 l'int\303\251rieur du QGroupBox */\n"
"QPushButton {\n"
"   "
                        " color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
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
"/* Effet de survol sur les boutons */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    borde"
                        "r-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
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
        noml_res = new QLineEdit(groupBox_2);
        noml_res->setObjectName("noml_res");
        noml_res->setGeometry(QRect(140, 130, 191, 37));
        noml_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        matl_res = new QLineEdit(groupBox_2);
        matl_res->setObjectName("matl_res");
        matl_res->setGeometry(QRect(140, 180, 191, 37));
        matl_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        notel_res = new QLineEdit(groupBox_2);
        notel_res->setObjectName("notel_res");
        notel_res->setGeometry(QRect(140, 280, 191, 37));
        notel_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        statutl_res = new QLineEdit(groupBox_2);
        statutl_res->setObjectName("statutl_res");
        statutl_res->setGeometry(QRect(140, 330, 191, 37));
        statutl_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        numcl_res = new QLineEdit(groupBox_2);
        numcl_res->setObjectName("numcl_res");
        numcl_res->setGeometry(QRect(140, 80, 191, 37));
        numcl_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        statutlab_res = new QLabel(groupBox_2);
        statutlab_res->setObjectName("statutlab_res");
        statutlab_res->setGeometry(QRect(20, 330, 111, 41));
        statutlab_res->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        notelab_res = new QLabel(groupBox_2);
        notelab_res->setObjectName("notelab_res");
        notelab_res->setGeometry(QRect(20, 280, 111, 41));
        notelab_res->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        datelab_res = new QLabel(groupBox_2);
        datelab_res->setObjectName("datelab_res");
        datelab_res->setGeometry(QRect(20, 230, 111, 41));
        datelab_res->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        matlab_res = new QLabel(groupBox_2);
        matlab_res->setObjectName("matlab_res");
        matlab_res->setGeometry(QRect(20, 180, 111, 41));
        matlab_res->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        idlab_res = new QLabel(groupBox_2);
        idlab_res->setObjectName("idlab_res");
        idlab_res->setGeometry(QRect(20, 80, 111, 41));
        idlab_res->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        nomlab_res = new QLabel(groupBox_2);
        nomlab_res->setObjectName("nomlab_res");
        nomlab_res->setGeometry(QRect(20, 130, 111, 41));
        nomlab_res->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        datel_res = new QDateEdit(groupBox_2);
        datel_res->setObjectName("datel_res");
        datel_res->setGeometry(QRect(140, 230, 191, 41));
        datel_res->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #0078D7;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"    min-height: 25px;\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid #0078D7;\n"
"    background-color: #F0F8FF;\n"
"}"));
        centrelab_res = new QLabel(groupBox_2);
        centrelab_res->setObjectName("centrelab_res");
        centrelab_res->setGeometry(QRect(20, 380, 111, 41));
        centrelab_res->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        centrebox_res = new QComboBox(groupBox_2);
        centrebox_res->setObjectName("centrebox_res");
        centrebox_res->setGeometry(QRect(140, 380, 191, 41));
        centrebox_res->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QComboBox:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QComboBox:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QComboBox:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QComboBox::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        supp_res = new QPushButton(page_7);
        supp_res->setObjectName("supp_res");
        supp_res->setGeometry(QRect(1230, 280, 161, 51));
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
        exp_res = new QPushButton(page_7);
        exp_res->setObjectName("exp_res");
        exp_res->setGeometry(QRect(1230, 60, 231, 51));
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
        rech_res = new QPushButton(page_7);
        rech_res->setObjectName("rech_res");
        rech_res->setGeometry(QRect(740, 60, 161, 51));
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
        rechl_res = new QLineEdit(page_7);
        rechl_res->setObjectName("rechl_res");
        rechl_res->setGeometry(QRect(490, 60, 241, 51));
        rechl_res->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Ctri_res = new QComboBox(page_7);
        Ctri_res->addItem(QString());
        Ctri_res->addItem(QString());
        Ctri_res->addItem(QString());
        Ctri_res->addItem(QString());
        Ctri_res->setObjectName("Ctri_res");
        Ctri_res->setGeometry(QRect(920, 60, 111, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(12);
        font1.setBold(true);
        Ctri_res->setFont(font1);
        Ctri_res->setStyleSheet(QString::fromUtf8("    background-color: rgb(230, 240, 255); \n"
"    border-color: rgb(20, 80, 130);\n"
"    color: rgb(20, 80, 130)"));
        frame_res = new QFrame(page_7);
        frame_res->setObjectName("frame_res");
        frame_res->setGeometry(QRect(500, 450, 701, 281));
        frame_res->setFrameShape(QFrame::Shape::StyledPanel);
        frame_res->setFrameShadow(QFrame::Shadow::Raised);
        ajout_res = new QPushButton(page_7);
        ajout_res->setObjectName("ajout_res");
        ajout_res->setGeometry(QRect(180, 570, 161, 51));
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
        stackedWidget->addWidget(page_7);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        tabWidget = new QTabWidget(page_5);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 0, 1591, 881));
        tabWidget->setStyleSheet(QString::fromUtf8("/* === Background with Linear Gradient === */\n"
"QWidget {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 #007BFF, stop:1 #F8F9FA);\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 12pt;\n"
"}\n"
"\n"
"/* === Group Box Styling === */\n"
"QGroupBox {\n"
"    border: 2px solid #0056b3;\n"
"    border-radius: 10px;\n"
"    margin-top: 10px;\n"
"    padding: 15px;\n"
"    background: transparent; /* Semi-transparent */\n"
"}\n"
"\n"
"/* === Stylish Input Fields === */\n"
"QLineEdit, QComboBox, QDateEdit {\n"
"    border: 2px solid #007BFF;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    background: white;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* === Input Fields on Focus === */\n"
"QLineEdit:focus, QComboBox:focus, QDateEdit:focus {\n"
"    border: 2px solid #0056b3;\n"
"    background: #e6f2ff;\n"
"}\n"
"\n"
"/* === Modern Buttons === */\n"
"QPushButton {\n"
"    background-color: #007BFF;\n"
"    c"
                        "olor: white;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* === Button Hover Effect === */\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"/* === Button Click Effect === */\n"
"QPushButton:pressed {\n"
"    background-color: #003d82;\n"
"    transform: scale(0.95);\n"
"}\n"
"\n"
"/* === Table Styling === */\n"
"QTableWidget {\n"
"    background: white;\n"
"    border: 2px solid #007BFF;\n"
"    gridline-color: #007BFF;\n"
"    selection-background-color: #CDE1F8;\n"
"}\n"
"\n"
"/* === Headers in Table === */\n"
"QHeaderView::section {\n"
"    background-color: #007BFF;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    padding: 5px;\n"
"    border: 1px solid #0056b3;\n"
"}\n"
"\n"
"/* === Scrollbar for Table === */\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    background: white;\n"
"    border: 2px solid #007BFF;\n"
"  "
                        "  width: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical, QScrollBar::handle:horizontal {\n"
"    background: #007BFF;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover, QScrollBar::handle:horizontal:hover {\n"
"    background: #0056b3;\n"
"}\n"
"\n"
"QLabel{\n"
"background-color:transparent;\n"
"}\n"
"\n"
"QFormLayout{\n"
"background-color:transparent;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        pushButton_modifier = new QPushButton(tab);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(630, 380, 131, 41));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Downloads/461508595_825905609429817_3860263783025879477_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_modifier->setIcon(icon);
        trierButton = new QPushButton(tab);
        trierButton->setObjectName("trierButton");
        trierButton->setGeometry(QRect(570, 80, 141, 41));
        trierButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../Downloads/461484528_521659267261567_8640738131585914016_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        trierButton->setIcon(icon1);
        pushButton_supprimer = new QPushButton(tab);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(950, 380, 121, 41));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../Downloads/460177168_1665954550921902_7047727999174566408_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_supprimer->setIcon(icon2);
        rechercherButton = new QPushButton(tab);
        rechercherButton->setObjectName("rechercherButton");
        rechercherButton->setGeometry(QRect(570, 20, 141, 41));
        rechercherButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../Downloads/460563423_1575797083314263_1051363182548254163_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        rechercherButton->setIcon(icon3);
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(790, 380, 131, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_3->setIcon(icon);
        pushButton_afficher = new QPushButton(tab);
        pushButton_afficher->setObjectName("pushButton_afficher");
        pushButton_afficher->setGeometry(QRect(430, 80, 131, 41));
        pushButton_afficher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_afficher->setIcon(icon);
        tableView_center = new QTableView(tab);
        tableView_center->setObjectName("tableView_center");
        tableView_center->setGeometry(QRect(500, 150, 831, 221));
        tableView_center->setStyleSheet(QString::fromUtf8("/* Style de la table QTableWidget */\n"
"QTableWidget {\n"
"    background-color: #ffffff; /* Fond blanc pour la table */\n"
"    border: 2px solid #2980b9; /* Bordure bleue pour d\303\251limiter la table */\n"
"    border-radius: 8px; /* Coins arrondis pour une pr\303\251sentation douce */\n"
"    padding: 10px; /* Espacement interne pour \303\251viter que le contenu touche les bords */\n"
"    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1); /* Ombre discr\303\250te pour ajouter de la profondeur */\n"
"    font-size: 14px; /* Taille de la police pour le contenu de la table */\n"
"    color: rgb(51, 102, 153); /* Couleur du texte pour la lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Style pour les lignes de la table (QTableWidget::item) */\n"
"QTableWidget::item {\n"
"    padding: 12px; /* Espacement des cellules */\n"
"    border-bottom: 1px solid #f0f0f0; /* Ligne de s\303\251paration entre les lignes */\n"
"    background-color: #ffffff; /* Fond blanc pour chaque cellule */\n"
"    transition: background-color 0.3s ease"
                        "; /* Transition douce pour le survol */\n"
"}\n"
"\n"
"/* Effet de survol sur les cellules */\n"
"QTableWidget::item:hover {\n"
"    background-color: rgb(240, 248, 255); /* Teinte bleue l\303\251g\303\250re sur survol */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
"\n"
"/* Style des cellules s\303\251lectionn\303\251es */\n"
"QTableWidget::item:selected {\n"
"    background-color: rgb(51, 102, 153); /* Fond bleu pour la cellule s\303\251lectionn\303\251e */\n"
"    color: white; /* Texte blanc pour une bonne visibilit\303\251 */\n"
"    border-radius: 8px; /* Coins arrondis pour la cellule s\303\251lectionn\303\251e */\n"
"}\n"
"\n"
"/* Style des ent\303\252tes de colonnes */\n"
"QHeaderView::section {\n"
"    background-color: #f7f9fc; /* Fond clair pour les ent\303\252tes */\n"
"    color: rgb(51, 102, 153); /* Couleur du texte des ent\303\252tes */\n"
"    font-weight: bold; /* Mettre en gras les ent\303\252tes */\n"
"    padding: 10px; /* Espacement autour du texte des ent\303\252tes "
                        "*/\n"
"    border: 1px solid #dcdfe6; /* Bordure l\303\251g\303\250re autour des ent\303\252tes */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"}\n"
"\n"
"/* Style des boutons dans les ent\303\252tes de colonnes */\n"
"QHeaderView::section:hover {\n"
"    background-color: rgb(240, 248, 255); /* Teinte bleue l\303\251g\303\250re au survol des ent\303\252tes */\n"
"    cursor: pointer; /* Curseur en forme de main */\n"
"}\n"
""));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(130, 120, 131, 41));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        lineEdit_idcenter = new QLineEdit(tab);
        lineEdit_idcenter->setObjectName("lineEdit_idcenter");
        lineEdit_idcenter->setGeometry(QRect(50, 180, 241, 41));
        lineEdit_idcenter->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 40, 411, 401));
        groupBox->setStyleSheet(QString::fromUtf8("/* Style du groupe de boutons CRUD (QGroupBox) */\n"
"QGroupBox {\n"
"    background-color: #f7f9fc; /* Fond clair pour le groupe */\n"
"    border: 2px solid #2980b9; /* Bordure bleue pour d\303\251limiter la zone */\n"
"    border-radius: 10px; /* Coins arrondis pour une touche moderne */\n"
"    padding: 20px; /* Espacement interne pour a\303\251rer le contenu */\n"
"    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1); /* Ombre l\303\251g\303\250re pour donner de la profondeur */\n"
"    margin: 20px 0; /* Espacement ext\303\251rieur entre les groupes */\n"
"}\n"
"\n"
"/* Titre du QGroupBox */\n"
"QGroupBox::title {\n"
"    color: rgb(51, 102, 153); /* Couleur du texte du titre du groupe */\n"
"    font-size: 20px; /* Taille du texte */\n"
"    font-weight: bold;\n"
"    padding: 5px; /* Espacement autour du texte du titre */\n"
"    background-color: transparent; /* Aucun fond derri\303\250re le titre */\n"
"}\n"
"\n"
"/* Style des boutons CRUD \303\240 l'int\303\251rieur du QGroupBox */\n"
"QPushButton {\n"
"   "
                        " color: rgb(51, 102, 153); /* Texte bleu pour correspondre \303\240 la bordure */\n"
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
"/* Effet de survol sur les boutons */\n"
"QPushButton:hover {\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue pour le survol */\n"
"    borde"
                        "r-color: rgb(30, 95, 150); /* Changement de bordure au survol */\n"
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
        pushButton_annuler = new QPushButton(groupBox);
        pushButton_annuler->setObjectName("pushButton_annuler");
        pushButton_annuler->setGeometry(QRect(40, 350, 141, 41));
        pushButton_annuler->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_annuler->setIcon(icon3);
        pushButton_ajouter = new QPushButton(groupBox);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(210, 350, 141, 41));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_ajouter->setIcon(icon3);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 80, 131, 41));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 140, 131, 41));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 240, 131, 41));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(150, 80, 241, 41));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        lineEdit_adresse = new QLineEdit(groupBox);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(150, 140, 241, 41));
        lineEdit_adresse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        lineEdit_capacite = new QLineEdit(groupBox);
        lineEdit_capacite->setObjectName("lineEdit_capacite");
        lineEdit_capacite->setGeometry(QRect(150, 240, 241, 41));
        lineEdit_capacite->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 190, 131, 41));
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        lineEdit_disponibilite = new QLineEdit(groupBox);
        lineEdit_disponibilite->setObjectName("lineEdit_disponibilite");
        lineEdit_disponibilite->setGeometry(QRect(150, 290, 241, 41));
        lineEdit_disponibilite->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px; /* Taille de police */\n"
"    border: 2px solid rgb(51, 102, 153); /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement \303\240 l'int\303\251rieur */\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Effet de focus (lorsque l'utilisateur clique dans le champ) */\n"
"QLineEdit:focus {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au focus */\n"
"    background-color: rgb(240, 248, 255); /* Fond l\303\251g\303\250rement bleu clair */\n"
"    color: rgb(30, 95, 150); /* Texte bleu au focus */\n"
"}\n"
"\n"
"/* Effet au survol (lorsque l'utilisateur passe la souris sur la barre de recherche) */\n"
"QLineEdit:hover {\n"
"    border-color: rgb(30, 95, 150); /* Bordure bleue au survol */\n"
"    background-color: rgb(240, 248, 255); /* L\303\251g\303\250re teinte bleue au survol */\n"
""
                        "    cursor: pointer; /* Curseur de la souris sous forme de main */\n"
"}\n"
"\n"
"/* Lorsque l'utilisateur commence \303\240 taper (focus + survol) */\n"
"QLineEdit:active {\n"
"    background-color: rgb(230, 240, 255); /* Fond encore plus clair */\n"
"}\n"
"\n"
"/* Pour le texte d'exemple (placeholder) */\n"
"QLineEdit::placeholder {\n"
"    color: rgb(150, 150, 150); /* Texte gris pour le placeholder */\n"
"    font-style: italic; /* Style italique pour le placeholder */\n"
"}\n"
""));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 290, 131, 41));
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: rgb(51, 102, 153); /* Texte bleu */\n"
"    background-color: white; /* Fond blanc */\n"
"    font-size: 18px;\n"
"    line-height: 1.5;\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    border-width: 2px; \n"
"    border-color: rgb(51, 102, 153); /* Bordure bleue */\n"
"    \n"
"    border-radius: 8px; /* Bordure l\303\251g\303\250rement arrondie */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"}\n"
"\n"
""));
        dateEdit_ = new QDateEdit(groupBox);
        dateEdit_->setObjectName("dateEdit_");
        dateEdit_->setGeometry(QRect(149, 190, 241, 41));
        pb_pdf = new QPushButton(tab);
        pb_pdf->setObjectName("pb_pdf");
        pb_pdf->setGeometry(QRect(1090, 80, 121, 41));
        pb_pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pb_pdf->setIcon(icon2);
        lineEdit_recherche_multi = new QLineEdit(tab);
        lineEdit_recherche_multi->setObjectName("lineEdit_recherche_multi");
        lineEdit_recherche_multi->setGeometry(QRect(730, 20, 311, 41));
        comboBox_tri = new QComboBox(tab);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName("comboBox_tri");
        comboBox_tri->setGeometry(QRect(730, 80, 311, 41));
        frame = new QFrame(tab);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(540, 440, 761, 281));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        tabWidget->addTab(tab, QString());
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        lineEdit_11 = new QLineEdit(page_6);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(400, 60, 151, 41));
        lineEdit_11->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_sujet = new QLineEdit(page_6);
        lineEdit_sujet->setObjectName("lineEdit_sujet");
        lineEdit_sujet->setGeometry(QRect(90, 190, 181, 45));
        lineEdit_sujet->setStyleSheet(QString::fromUtf8("color: black;"));
        comboBox_order = new QComboBox(page_6);
        comboBox_order->addItem(QString());
        comboBox_order->addItem(QString());
        comboBox_order->setObjectName("comboBox_order");
        comboBox_order->setGeometry(QRect(1090, 210, 121, 41));
        comboBox_order->setStyleSheet(QString::fromUtf8("color: black;"));
        dateEdit_exam = new QDateEdit(page_6);
        dateEdit_exam->setObjectName("dateEdit_exam");
        dateEdit_exam->setGeometry(QRect(100, 320, 171, 41));
        label_14 = new QLabel(page_6);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(520, 20, 191, 41));
        trier_Butoon_ = new QPushButton(page_6);
        trier_Butoon_->setObjectName("trier_Butoon_");
        trier_Butoon_->setGeometry(QRect(1090, 260, 151, 41));
        trier_Butoon_->setStyleSheet(QString::fromUtf8(""));
        frame_exam = new QFrame(page_6);
        frame_exam->setObjectName("frame_exam");
        frame_exam->setGeometry(QRect(430, 460, 681, 251));
        frame_exam->setFrameShape(QFrame::Shape::StyledPanel);
        frame_exam->setFrameShadow(QFrame::Shadow::Raised);
        label_15 = new QLabel(page_6);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 270, 61, 27));
        pushButton_7 = new QPushButton(page_6);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(570, 60, 111, 41));
        tableWidget_examens = new QTableWidget(page_6);
        if (tableWidget_examens->columnCount() < 4)
            tableWidget_examens->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_examens->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_examens->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_examens->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_examens->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        tableWidget_examens->setObjectName("tableWidget_examens");
        tableWidget_examens->setGeometry(QRect(300, 110, 781, 331));
        tableWidget_examens->setStyleSheet(QString::fromUtf8("color: #007BFF;"));
        lineEdit_statut = new QLineEdit(page_6);
        lineEdit_statut->setObjectName("lineEdit_statut");
        lineEdit_statut->setGeometry(QRect(90, 260, 181, 45));
        lineEdit_statut->setStyleSheet(QString::fromUtf8("color: black;"));
        suppexamButton = new QPushButton(page_6);
        suppexamButton->setObjectName("suppexamButton");
        suppexamButton->setGeometry(QRect(280, 500, 141, 41));
        suppexamButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../wetransfer_rayen_2025-03-10_2229/rayen/Users/Pc/Desktop/Downloads/460177168_1665954550921902_7047727999174566408_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        suppexamButton->setIcon(icon4);
        lineEdit_titre = new QLineEdit(page_6);
        lineEdit_titre->setObjectName("lineEdit_titre");
        lineEdit_titre->setGeometry(QRect(90, 120, 181, 45));
        lineEdit_titre->setStyleSheet(QString::fromUtf8("color: black;"));
        comboBoxsortchamp = new QComboBox(page_6);
        comboBoxsortchamp->addItem(QString());
        comboBoxsortchamp->addItem(QString());
        comboBoxsortchamp->setObjectName("comboBoxsortchamp");
        comboBoxsortchamp->setGeometry(QRect(1090, 160, 121, 41));
        comboBoxsortchamp->setStyleSheet(QString::fromUtf8("color: black;"));
        label_16 = new QLabel(page_6);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 330, 101, 27));
        pushButton_5 = new QPushButton(page_6);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(1090, 310, 201, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8(""));
        label_17 = new QLabel(page_6);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 200, 48, 27));
        modifexamButton = new QPushButton(page_6);
        modifexamButton->setObjectName("modifexamButton");
        modifexamButton->setGeometry(QRect(140, 500, 121, 41));
        modifexamButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../wetransfer_rayen_2025-03-10_2229/rayen/Users/Pc/Desktop/Downloads/461508595_825905609429817_3860263783025879477_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        modifexamButton->setIcon(icon5);
        label_18 = new QLabel(page_6);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 390, 101, 27));
        label_19 = new QLabel(page_6);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(1100, 120, 101, 41));
        comboBox_transport = new QComboBox(page_6);
        comboBox_transport->setObjectName("comboBox_transport");
        comboBox_transport->setGeometry(QRect(100, 380, 191, 41));
        label_20 = new QLabel(page_6);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(10, 130, 51, 27));
        idExam = new QLineEdit(page_6);
        idExam->setObjectName("idExam");
        idExam->setGeometry(QRect(80, 60, 311, 45));
        idExam->setStyleSheet(QString::fromUtf8("color: black;"));
        ajout_examButton = new QPushButton(page_6);
        ajout_examButton->setObjectName("ajout_examButton");
        ajout_examButton->setGeometry(QRect(10, 500, 111, 41));
        ajout_examButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../wetransfer_rayen_2025-03-10_2229/rayen/Users/Pc/Desktop/Downloads/projetcpp-2a33-smart-pharmacy-gestioncommande/projetcpp-2a33-smart-pharmacy-gestioncommande/461755239_1311673180207872_9007432977068590092_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ajout_examButton->setIcon(icon6);
        ajout_examButton->setIconSize(QSize(50, 50));
        qrCodeLabel = new QLabel(page_6);
        qrCodeLabel->setObjectName("qrCodeLabel");
        qrCodeLabel->setGeometry(QRect(100, 540, 321, 191));
        comboBox_foreign_center = new QComboBox(page_6);
        comboBox_foreign_center->setObjectName("comboBox_foreign_center");
        comboBox_foreign_center->setGeometry(QRect(100, 430, 201, 41));
        label = new QLabel(page_6);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 450, 81, 20));
        stackedWidget->addWidget(page_6);
        pushButton_examen = new QPushButton(centralwidget);
        pushButton_examen->setObjectName("pushButton_examen");
        pushButton_examen->setGeometry(QRect(20, 200, 181, 41));
        pushButton_centre = new QPushButton(centralwidget);
        pushButton_centre->setObjectName("pushButton_centre");
        pushButton_centre->setGeometry(QRect(20, 260, 181, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 201, 141));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/icons/BG.png);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 320, 181, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 380, 181, 41));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 440, 181, 41));
        pushButton_resultat = new QPushButton(centralwidget);
        pushButton_resultat->setObjectName("pushButton_resultat");
        pushButton_resultat->setGeometry(QRect(20, 500, 181, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1868, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = aff_res->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID_ETUDIANT", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = aff_res->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "NUMC_ETUD", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = aff_res->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = aff_res->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "MATIERE", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = aff_res->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "NOTE", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = aff_res->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "DATE", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = aff_res->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "STATUT", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = aff_res->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "ID_CENTRE", nullptr));
        stats_res->setText(QCoreApplication::translate("MainWindow", "STATISTIQUES", nullptr));
        tri_res->setText(QCoreApplication::translate("MainWindow", "TRIER", nullptr));
        mod_res->setText(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "AJOUTER LE RESULTAT D'ETUDIANT", nullptr));
        noml_res->setText(QString());
        matl_res->setText(QString());
        notel_res->setText(QString());
        statutl_res->setText(QString());
        numcl_res->setText(QString());
        statutlab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">STATUT</span></p></body></html>", nullptr));
        notelab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">NOTE</span></p></body></html>", nullptr));
        datelab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">DATE</span></p></body></html>", nullptr));
        matlab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">MATIERE</span></p></body></html>", nullptr));
        idlab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">NUM</span></p></body></html>", nullptr));
        nomlab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">NOM</span></p></body></html>", nullptr));
        centrelab_res->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">CENTRE</span></p></body></html>", nullptr));
        supp_res->setText(QCoreApplication::translate("MainWindow", "SUPPRIMER", nullptr));
        exp_res->setText(QCoreApplication::translate("MainWindow", "EXPORATION EN PDF", nullptr));
        rech_res->setText(QCoreApplication::translate("MainWindow", "RECHECHER", nullptr));
        rechl_res->setInputMask(QString());
        rechl_res->setText(QString());
        rechl_res->setPlaceholderText(QCoreApplication::translate("MainWindow", "num carte etudiant,nom,matiere", nullptr));
        Ctri_res->setItemText(0, QCoreApplication::translate("MainWindow", "NOTE >", nullptr));
        Ctri_res->setItemText(1, QCoreApplication::translate("MainWindow", "NOTE <", nullptr));
        Ctri_res->setItemText(2, QCoreApplication::translate("MainWindow", "DATE >", nullptr));
        Ctri_res->setItemText(3, QCoreApplication::translate("MainWindow", "DATE <", nullptr));

        ajout_res->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        trierButton->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        rechercherButton->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "entrer id", nullptr));
        pushButton_afficher->setText(QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "id-centre", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter un centre d examen", nullptr));
        pushButton_annuler->setText(QCoreApplication::translate("MainWindow", "annuler -", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "ajouter +", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "nom_centre", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "adresse", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "capacit\303\251", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "disponibilite", nullptr));
        pb_pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        lineEdit_recherche_multi->setPlaceholderText(QCoreApplication::translate("MainWindow", "(nom,adresse,date)", nullptr));
        comboBox_tri->setItemText(0, QCoreApplication::translate("MainWindow", "capacite", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("MainWindow", "date", nullptr));
        comboBox_tri->setItemText(2, QCoreApplication::translate("MainWindow", "nom", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        lineEdit_11->setText(QString());
        lineEdit_11->setPlaceholderText(QCoreApplication::translate("MainWindow", "titre,sujet;statut", nullptr));
        comboBox_order->setItemText(0, QCoreApplication::translate("MainWindow", "Ascendant", nullptr));
        comboBox_order->setItemText(1, QCoreApplication::translate("MainWindow", "Descendant", nullptr));

        label_14->setText(QCoreApplication::translate("MainWindow", "Rechercher par titre:", nullptr));
        trier_Butoon_->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Statut:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_examens->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Titre", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_examens->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Sujet", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_examens->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_examens->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        suppexamButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        comboBoxsortchamp->setItemText(0, QCoreApplication::translate("MainWindow", "Sujet", nullptr));
        comboBoxsortchamp->setItemText(1, QCoreApplication::translate("MainWindow", "Date Examen", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "Date ", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Sujet:", nullptr));
        modifexamButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "transport:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Trier par:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Titre:", nullptr));
        ajout_examButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        qrCodeLabel->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Center", nullptr));
        pushButton_examen->setText(QCoreApplication::translate("MainWindow", "examen", nullptr));
        pushButton_centre->setText(QCoreApplication::translate("MainWindow", "centre", nullptr));
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "employee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "transport", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "produit", nullptr));
        pushButton_resultat->setText(QCoreApplication::translate("MainWindow", "resultat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
