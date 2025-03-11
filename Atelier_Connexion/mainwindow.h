#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

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



    void on_ajout_examButton_clicked();

    void on_modifexamButton_clicked();





    void on_suppexamButton_clicked();



    void on_tableWidget_examens_itemDoubleClicked(QTableWidgetItem *item);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_trier_Butoon_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
