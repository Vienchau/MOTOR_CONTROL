#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <QObject>
#include <QThread>
#include <QObject>
#include <QString>
#include <QMutex>
#include <QTextBrowser>
#include "qcustomplot.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>

class ProcessThread : public QThread
{
    Q_OBJECT
public:
    ProcessThread(Ui::MainWindow *Ui, QMutex *lock);//, QCustomPlot  *plot1, QCustomPlot  *plot2, QTextBrowser *textbrowser);

    void run();
    void dataPIDProcess(QByteArray &bdata, float * fKp, float *fKi, float *fKd);
    void Ascii2Int(int *a, int *b, int *c, int *d);
    void AsciiConvert(int *a);
    void updatePlot();
    void bigNum();

    void setRunning(bool run)
        {
            running = run;
        }
    void updateData(QByteArray temp)
    {
        mData = temp;
    }

signals:
    void PIDBrowser(QString kp, QString ki, QString kd, QString cmd);
    void TUNBrowser(QString str);
    void updategraph(double x, double y);

private:
    QByteArray mData;
    QCustomPlot *PosPlot;
    QCustomPlot *PIDPlot;
    QMutex *data_lock;
    QTextBrowser *TextBrowser;
    Ui::MainWindow *ui;
    bool running = true;

    QString sdata = "Data recieved:\n";
    float fKp, fKi, fKd;
    int k = 0, counter = 0;
    double posMax = 0;
    double posxl = 0;
    QVector<double> a, b;
    QVector<double> e, f;

    QVector<double> c ={0,200}, d = {91.6667, 91.6667};
signals:

};

#endif // PROCESSTHREAD_H
