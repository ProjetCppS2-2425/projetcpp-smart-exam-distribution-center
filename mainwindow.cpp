#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transport.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}








void MainWindow::on_transport_clicked()
{
    transport *trans = new transport(this);
    trans->setModal(true);
    trans->exec();
}
