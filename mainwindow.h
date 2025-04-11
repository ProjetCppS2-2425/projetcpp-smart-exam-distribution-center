#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "resultat.h"
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
    void on_sortCriteriaChanged();
    void on_exp_res_clicked();
    void on_aff_res_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
