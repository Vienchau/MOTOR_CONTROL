#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"


void MainWindow::serialport_read()
{

}

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

void MainWindow::updateSerialPort()
{

}


void MainWindow::on_openButton_clicked()
{

}

void MainWindow::on_sendButton_clicked()
{

}

void MainWindow::on_sendpidButton_clicked()
{

}

void MainWindow::on_tunningButton_clicked()
{

}

void MainWindow::on_requestButton_clicked()
{

}

void MainWindow::on_motionButton_clicked()
{

}

void MainWindow::on_runButton_clicked()
{

}

void MainWindow::on_senparamsButton_clicked()
{

}

void MainWindow::on_getButton_clicked()
{

}

void MainWindow::serialReadyRead()
{

}
