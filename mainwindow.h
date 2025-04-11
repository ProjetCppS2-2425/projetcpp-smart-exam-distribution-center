#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"

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
    void on_ajouter_clicked();
    void on_supprimer_clicked();
    void on_debiter_clicked();
    void on_modifier_clicked();
    void on_nom_recherche_textChanged(const QString &arg1);
    void on_qte_rech_textChanged(const QString &text);
    void on_disp_rech_currentTextChanged(const QString &text);
    void on_crit_tri_currentTextChanged(const QString &text);
    void on_pdf_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
