#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTableWidgetItem>
#include <QSystemTrayIcon>
#include <QMenu>

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

    void on_tableWidget_examens_cellClicked(int row, int column);

    void on_pushButton_3_clicked();

private:
    QTimer *examNotificationTimer;
    Ui::MainWindow *ui;
    void populateTransportComboBox();

    QSystemTrayIcon *m_trayIcon;
    void checkUpcomingExams();
     QList<QString> m_upcomingExams;
    void updateExamButton();
     void on_checkExamsButton_clicked();
    void displayExamStatsChart() ;







};

#endif // MAINWINDOW_H
