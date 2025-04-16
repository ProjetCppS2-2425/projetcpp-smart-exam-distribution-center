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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *ajout_examButton;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_10;
    QTableWidget *tableWidget_examens;
    QLabel *label;
    QPushButton *suppexamButton;
    QPushButton *modifexamButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_titre;
    QLineEdit *lineEdit_sujet;
    QLineEdit *lineEdit_statut;
    QLabel *label_5;
    QComboBox *comboBox;
    QPushButton *pushButton_6;
    QLineEdit *idExam;
    QLabel *label_6;
    QWidget *page_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1442, 834);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 210, 75, 23));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-20, -40, 1451, 731));
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
        page = new QWidget();
        page->setObjectName("page");
        ajout_examButton = new QPushButton(page);
        ajout_examButton->setObjectName("ajout_examButton");
        ajout_examButton->setGeometry(QRect(110, 400, 111, 41));
        ajout_examButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Users/Pc/Desktop/Downloads/projetcpp-2a33-smart-pharmacy-gestioncommande/projetcpp-2a33-smart-pharmacy-gestioncommande/461755239_1311673180207872_9007432977068590092_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ajout_examButton->setIcon(icon);
        ajout_examButton->setIconSize(QSize(50, 50));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(1030, 560, 201, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8(""));
        lineEdit_10 = new QLineEdit(page);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(590, 80, 151, 41));
        lineEdit_10->setStyleSheet(QString::fromUtf8("color: black;"));
        tableWidget_examens = new QTableWidget(page);
        if (tableWidget_examens->columnCount() < 4)
            tableWidget_examens->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_examens->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_examens->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_examens->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_examens->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_examens->setObjectName("tableWidget_examens");
        tableWidget_examens->setGeometry(QRect(540, 130, 661, 411));
        tableWidget_examens->setStyleSheet(QString::fromUtf8("color: #007BFF;"));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 40, 191, 41));
        suppexamButton = new QPushButton(page);
        suppexamButton->setObjectName("suppexamButton");
        suppexamButton->setGeometry(QRect(380, 400, 141, 41));
        suppexamButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Users/Pc/Desktop/Downloads/460177168_1665954550921902_7047727999174566408_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        suppexamButton->setIcon(icon1);
        modifexamButton = new QPushButton(page);
        modifexamButton->setObjectName("modifexamButton");
        modifexamButton->setGeometry(QRect(240, 400, 121, 41));
        modifexamButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../Users/Pc/Desktop/Downloads/461508595_825905609429817_3860263783025879477_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        modifexamButton->setIcon(icon2);
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 190, 51, 27));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 250, 48, 27));
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 320, 61, 27));
        lineEdit_titre = new QLineEdit(page);
        lineEdit_titre->setObjectName("lineEdit_titre");
        lineEdit_titre->setGeometry(QRect(170, 180, 311, 45));
        lineEdit_titre->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_sujet = new QLineEdit(page);
        lineEdit_sujet->setObjectName("lineEdit_sujet");
        lineEdit_sujet->setGeometry(QRect(170, 240, 311, 45));
        lineEdit_sujet->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_statut = new QLineEdit(page);
        lineEdit_statut->setObjectName("lineEdit_statut");
        lineEdit_statut->setGeometry(QRect(170, 310, 311, 45));
        lineEdit_statut->setStyleSheet(QString::fromUtf8("color: black;"));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(870, 40, 101, 41));
        comboBox = new QComboBox(page);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(870, 80, 111, 41));
        comboBox->setStyleSheet(QString::fromUtf8("color: black;"));
        pushButton_6 = new QPushButton(page);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(750, 80, 111, 41));
        idExam = new QLineEdit(page);
        idExam->setObjectName("idExam");
        idExam->setGeometry(QRect(170, 120, 311, 45));
        idExam->setStyleSheet(QString::fromUtf8("color: black;"));
        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(100, 130, 51, 27));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1442, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        ajout_examButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        lineEdit_10->setText(QString());
        lineEdit_10->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisir le titre", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_examens->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Titre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_examens->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Sujet", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_examens->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_examens->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Rechercher par titre:", nullptr));
        suppexamButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        modifexamButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Titre:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Sujet:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Statut:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Trier par:", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Sujet", nullptr));

        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
