#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void serialport_read();


    void on_openButton_clicked();

    void on_sendButton_clicked();

    void on_sendpidButton_clicked();

    void on_tunningButton_clicked();

    void on_requestButton_clicked();

    void on_motionButton_clicked();

    void on_runButton_clicked();

    void on_senparamsButton_clicked();

    void on_getButton_clicked();


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void updateSerialPort();
    void plotConfig();
    QSerialPort *mSerial;
    QList <QSerialPortInfo> mSerialPorts;
    QTimer *mSerialScanTimer;
    QSharedPointer<QCPGraphDataContainer> mDatapid;
    QSharedPointer<QCPGraphDataContainer> mDatapos;
    QSharedPointer<QCPGraphDataContainer> mDatavel;
    QSharedPointer<QCPGraphDataContainer> mDataacc;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
