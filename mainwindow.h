#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "center.h"
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QSystemTrayIcon>
#include <QMenu>
#include "examen.h"
#include "resultat.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_afficher_clicked();
    void on_pushButton_ajouter_clicked();
    void on_pushButton_annuler_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_tableView_center_clicked(const QModelIndex &index);
    void on_pb_pdf_clicked();
    void on_rechercherButton_clicked();
    void on_trierButton_clicked();
    int getCurrentCenterAvailability(int centerId);
    bool sendCenterStatusSMS(const QString& centerName, int newStatus);
    void displayAvailabilityStats();
    //void on_statistiqueButton_centres_clicked();
    //void on_statistiqueButton_centres_graph_clicked();
    void on_pushButton_centre_clicked();
    /////////////////////////////////////////

    void on_ajout_examButton_clicked();

    void on_modifexamButton_clicked();
    void on_suppexamButton_clicked();
    void on_tableWidget_examens_itemDoubleClicked(QTableWidgetItem *item);
    void on_tableWidget_examens_cellClicked(int row, int column);
    void on_pushButton_3_clicked();
    void on_lineEdit_11_textChanged(const QString &arg1);
    void on_trier_Butoon__clicked();
    void on_pushButton_examen_clicked();
    void populateCenterComboBox();

    //////////////////////////////

    void on_pushButton_afficher_res_clicked();
    void on_ajout_res_clicked();
    void on_mod_res_clicked();
    void on_supp_res_clicked();
    void on_rech_res_clicked();
    void on_tri_res_clicked();
    void on_exp_res_clicked();
    void on_aff_res_cellClicked(int row, int column);
    void on_stats_res_clicked();
    void on_pushButton_resultat_clicked();

private:
    Ui::MainWindow *ui;
    center C;
    ///////exam
    void populateTransportComboBox();

    QSystemTrayIcon *m_trayIcon;
    void checkUpcomingExams();
    QList<QString> m_upcomingExams;
    void updateExamButton();
    void on_checkExamsButton_clicked();
    void displayExamStatsChart() ;

    ///////////////////////resultat
    void on_sortCriteriaChanged();



};
#endif // MAINWINDOW_H
