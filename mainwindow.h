#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include "resultat.h"
#include "stat.h"
#include "Arduino.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_afficher_clicked();
    void on_ajout_res_clicked();
    void on_mod_res_clicked();
    void on_supp_res_clicked();
    void on_rech_res_clicked();
    void on_tri_res_clicked();
    //void on_sortCriteriaChanged();
    void on_exp_res_clicked();
    void on_aff_res_cellClicked(int row, int column);
    void on_stats_res_clicked();

    void on_recherche_etudiant_clicked();

private:
    Ui::MainWindow *ui;
    Arduino arduino;

    void on_sortCriteriaChanged();
    void setupArduinoConnection();
};

#endif // MAINWINDOW_H
