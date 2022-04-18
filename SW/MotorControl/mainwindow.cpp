#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QDebug>
#include <sstream>
#include <iostream>
#include <boost/format.hpp>
#include <QVector>

int k = 0;
int t = 0;
QVector<double> a(201), b(201);

QVector<double> c ={0,200}, d = {91.6667, 91.6667};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        this->setWindowTitle("PID Tunning GUI");


        mSerial = new QSerialPort(this);
        updateSerialPort();

        ui->baudComboBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        ui->baudComboBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
        ui->baudComboBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
        ui->baudComboBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
        ui->baudComboBox->setCurrentIndex(3);

        ui->sizeComboBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
        ui->sizeComboBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
        ui->sizeComboBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
        ui->sizeComboBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
        ui->sizeComboBox->setCurrentIndex(3);
        ui->serialComboBox->setCurrentIndex(1);
        ui -> kpEdit -> setText("38.50");
        ui -> kiEdit -> setText("00.03");
        ui -> kdEdit -> setText("00.01");

        QStringList parity = {"none"};
        ui -> parityComboBox -> addItems(parity);

        mSerialScanTimer = new QTimer(this);
        mSerialScanTimer->setInterval(5000);
        mSerialScanTimer->start();

        ui-> requestButton -> setEnabled(false);
        ui-> sendpidButton -> setEnabled(false);
        ui-> tunningButton -> setEnabled(false);
        ui-> motionButton -> setEnabled(false);
        ui -> runButton -> setEnabled(false);
        ui -> senparamsButton -> setEnabled(false);
        ui -> getButton -> setEnabled(false);
        ui -> sendButton -> setEnabled(false);

        plotConfig();

        //connect(mSerialScanTimer, &QTimer::timeout, this, &MainWindow::updateSerialPort);

        connect(mSerial, &QSerialPort::readyRead, this, &MainWindow::serialport_read);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSerialPort()
{
        mSerialPorts = QSerialPortInfo::availablePorts();
        ui->serialComboBox->clear();
        for(const QSerialPortInfo &port: mSerialPorts)
        {
            ui -> serialComboBox -> addItem(port.portName(),  port.systemLocation());
        }
}


void MainWindow::plotConfig()
{
        //PID tunning plot init
        /*mDatapid = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);
        ui->pidPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->pidPlot->legend->setVisible(true);
        QFont legendFont = font();
        legendFont.setPointSize(10);
        ui->pidPlot->legend->setFont(legendFont);
        ui->pidPlot->legend->setSelectedFont(legendFont);
        ui->pidPlot->legend->setSelectableParts(QCPLegend::spItems);
        ui->pidPlot->yAxis->setLabel("Magnitude");
        ui->pidPlot->xAxis->setLabel("Time");
        ui->pidPlot->clearGraphs();
        ui->pidPlot->addGraph();*/
        ui -> pidPlot -> addGraph();
        ui -> pidPlot -> graph(0) -> setLineStyle(QCPGraph::lsLine);
        ui->pidPlot->graph(0)->setPen(QPen(Qt::black));
        ui -> pidPlot -> addGraph();
        ui -> pidPlot -> graph(1) -> setLineStyle(QCPGraph::lsLine);
        ui->pidPlot->graph(1)->setPen(QPen(Qt::red));

        ui->pidPlot->yAxis->setLabel("Magnitude");
        ui->pidPlot->xAxis->setLabel("Time");
        ui->pidPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

        ui->pidPlot->graph(0)->setName("Tunning");
        ui->pidPlot->graph(1)->setName("Ref");
        ui->pidPlot->legend->setVisible(true);
        QFont legendFont = font();
        legendFont.setPointSize(8);
        ui->pidPlot->legend->setFont(legendFont);
        ui->pidPlot->legend->setSelectedFont(legendFont);
        ui->pidPlot->legend->setSelectableParts(QCPLegend::spItems);


        //Position plot init
        mDatapos = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);
        ui->posPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->posPlot->legend->setVisible(true);
        //ui->posPlot->legend->setFont(legendFont);
        //ui->posPlot->legend->setSelectedFont(legendFont);
        ui->posPlot->legend->setSelectableParts(QCPLegend::spItems);
        ui->posPlot->yAxis->setLabel("Magnitude");
        ui->posPlot->xAxis->setLabel("Time");
        //ui -> pidPlot -> xAxis -> setRange(0, 201);
        //ui -> pidPlot -> xAxis -> setRange(0, 150);
        ui->posPlot->clearGraphs();
        ui->posPlot->addGraph();

        ui->posPlot->graph()->setPen(QPen(Qt::black));

        //ui->posPlot->graph()->setData(mDatapos);
        ui->posPlot->graph()->setName("Posititon");

        //Velocity plot init
        mDatavel = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);
        ui->velPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->velPlot->legend->setVisible(true);
        //ui->velPlot->legend->setFont(legendFont);
        //ui->velPlot->legend->setSelectedFont(legendFont);
        ui->velPlot->legend->setSelectableParts(QCPLegend::spItems);
        ui->velPlot->yAxis->setLabel("Magnitude");
        ui->velPlot->xAxis->setLabel("Time");
        ui->velPlot->clearGraphs();
        ui->velPlot->addGraph();

        ui->velPlot->graph()->setPen(QPen(Qt::black));
        ui->velPlot->graph()->setData(mDatavel);
        ui->velPlot->graph()->setName("Velocity");

        //Acc plot init
        mDataacc = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);
        ui->accPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->accPlot->legend->setVisible(true);
       //ui->accPlot->legend->setFont(legendFont);
        //ui->accPlot->legend->setSelectedFont(legendFont);
        ui->accPlot->legend->setSelectableParts(QCPLegend::spItems);
        ui->accPlot->yAxis->setLabel("Magnitude");
        ui->accPlot->xAxis->setLabel("Time");
        ui->accPlot->clearGraphs();
        ui->accPlot->addGraph();

        ui->accPlot->graph()->setPen(QPen(Qt::black));
        ui->accPlot->graph()->setData(mDataacc);
        ui->accPlot->graph()->setName("Accelometer");
}

void MainWindow::dataPIDProcessing(QByteArray &bdata, float *fKp, float *fKi, float *fKd)
{
    QByteArray bKRev;
    bKRev.resize(2);
    bKRev.clear();


    bKRev.append(bdata[0]);
    bKRev.append(bdata[1]);
    bool bStatus;
    uint iKpRev1 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[2]);
    bKRev.append(bdata[3]);
    bStatus = false;
    uint iKpRev2 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[4]);
    bKRev.append(bdata[5]);
    bStatus = false;
    uint iKiRev1 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[6]);
    bKRev.append(bdata[7]);
    bStatus = false;
    uint iKiRev2 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[8]);
    bKRev.append(bdata[9]);
    bStatus = false;
    uint iKdRev1 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[10]);
    bKRev.append(bdata[11]);
    bStatus = false;
    uint iKdRev2 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    *fKp = (float)iKpRev1 + (float)iKpRev2/100 ;
    *fKi = (float)iKiRev1 + (float)iKiRev2/100;
    *fKd = (float)iKdRev1 + (float)iKdRev2/100;
}

void MainWindow::Ascii2int(int *a, int *b, int *c, int *d)
{
    AsciiConvertCase(a);
    AsciiConvertCase(b);
    AsciiConvertCase(c);
    AsciiConvertCase(d);
}

void MainWindow::AsciiConvertCase(int *a)
{
    switch(*a)
    {
    case 48:
        *a = 0;
        break;
    case 49:
        *a = 1;
        break;
    case 50:
        *a = 2;
        break;
    case 51:
        *a = 3;
        break;
    case 52:
        *a = 4;
        break;
    case 53:
        *a = 5;
        break;
    case 54:
        *a = 6;
        break;
    case 55:
        *a = 7;
        break;
    case 56:
        *a = 8;
        break;
    case 57:
        *a = 9;
        break;
    case 97:
        *a = 10;
        break;
    case 98:
        *a = 11;
        break;
    case 99:
        *a = 12;
        break;
    case 100:
        *a = 13;
        break;
    case 101:
        *a = 14;
        break;
    case 102:
        *a = 15;
        break;
    case 65:
        *a = 10;
        break;
    case 66:
        *a = 11;
        break;
    case 67:
        *a = 12;
        break;
    case 68:
        *a = 13;
        break;
    case 69:
        *a = 14;
        break;
    case 70:
        *a = 15;
        break;
    default:
        break;
    }
}


void MainWindow::on_openButton_clicked()
{
    ui->openButton->setEnabled(false);
        QString serialLoc  =  ui->serialComboBox->currentData().toString();

        mSerial->setPortName(serialLoc);
        mSerial->setBaudRate(static_cast<QSerialPort::BaudRate>(ui->baudComboBox->itemData(ui->baudComboBox->currentIndex()).toInt()));
        mSerial->setDataBits(static_cast<QSerialPort::DataBits>(ui->sizeComboBox->itemData(ui->sizeComboBox->currentIndex()).toInt()));

        mSerial->setParity(QSerialPort::NoParity);
        mSerial->setStopBits(QSerialPort::OneStop);
        mSerial->setFlowControl(QSerialPort::NoFlowControl);

        if(mSerial->open(QIODevice::ReadWrite)) {

            QString text = "SERIAL: OK!\n";
            ui->textBrowser->insertPlainText(text);
        } else {
            QString text = "SERIAL: ERROR!\n";
            ui->textBrowser->insertPlainText(text);
        }

            ui-> requestButton -> setEnabled(true);
            ui-> sendpidButton -> setEnabled(true);
            ui-> tunningButton -> setEnabled(true);
            ui-> motionButton -> setEnabled(true);
            ui -> runButton -> setEnabled(true);
            ui -> senparamsButton -> setEnabled(true);
            ui -> getButton -> setEnabled(true);
            ui -> sendButton -> setEnabled(true);
            ui-> openButton ->setEnabled    (true);
}

void MainWindow::on_sendButton_clicked()
{
    if(mSerial-> isOpen())
        {
            QString str = ui ->sendEdit->text();
            ui->sendEdit->clear();
            str.append("\r\n");
            mSerial -> write(str.toLocal8Bit());
        }
        else
        {
            QString text = "Transmit mission failed!\n";
            ui->textBrowser->insertPlainText(text);
        }
}

void MainWindow::serialport_read()
{
        QString str;
       QString cmd = "Command recieved: ";
       QString data = "Data recieved:\n";
       QThread::msleep(30);
       QByteArray data_rev = mSerial -> readAll();
       qDebug() << data_rev.size() << "\n" ;
       if((data_rev.size() < 17) && (data_rev.size() >18))
       {
          data_rev.clear();
       }
       else
       {
           qDebug() << "data raw: " << data_rev << "\n" ;
           str = (QString(data_rev));
           QByteArray temp2 = data_rev;

           QString temp = str;
           qDebug() << "Command: " << temp << "\n" ;
           temp.append("\n");

            if(temp == "SPID\n")
            {
                ui -> textBrowser -> insertPlainText(cmd);
                ui -> textBrowser -> insertPlainText(temp);

                ui -> textBrowser -> insertPlainText(data);
                temp2.chop(2);
                temp2 = temp2.right(8).toHex();

                float fKp, fKi, fKd;
                dataPIDProcessing(temp2, &fKp, &fKi, &fKd);

                QString text ="Kpset: " + QString::number(fKp) + "\n";
                ui -> textBrowser -> insertPlainText(text);

                text ="Kiset: " + QString::number(fKi) + "\n";
                ui -> textBrowser -> insertPlainText(text);

                text ="Kdset: " + QString::number(fKd) + "\n";
                ui -> textBrowser -> insertPlainText(text);

                qDebug() << "PID Pramas: " << QString::number(fKp) << " " << QString::number(fKi) << " " << QString::number(fKd) << "\n" ;
            }

            if(temp == "CTUN\n")
            {
                ui -> textBrowser -> insertPlainText(cmd);
                ui -> textBrowser -> insertPlainText(temp);
                QString text = "CTUN cmd completed \n";
                ui -> textBrowser -> insertPlainText(text);
                a.fill(0);
                a.fill(0);
                ui -> pidPlot -> graph(1) -> setData(c,d);
                ui -> pidPlot -> graph(0) -> setData(a,b);
                ui->pidPlot->rescaleAxes();
                ui->pidPlot->replot();
                ui-> pidPlot -> update();


            }

            if((temp == "\u0002GPID\n" )||( temp == "GPID\n") )
            {
                ui -> textBrowser -> insertPlainText(cmd);
                ui -> textBrowser -> insertPlainText("GPID \n");
                temp2.chop(2);
                temp2 = temp2.right(8).toHex().toUpper();
                qDebug() << "Total:" << temp2 << "\n" ;



                   long bCount;
                   long bPosition;
                   bool ok;

                   int iCount1 = static_cast<quint8>(temp2[4]);
                   int iCount2 = static_cast<quint8>(temp2[5]);
                   int iCount3 = static_cast<quint8>(temp2[6]);
                   int iCount4 = static_cast<quint8>(temp2[7]);
                   int iPos1 = static_cast<quint8>(temp2[12]);
                   int iPos2 = static_cast<quint8>(temp2[13]);
                   int iPos3 = static_cast<quint8>(temp2[14]);
                   int iPos4 = static_cast<quint8>(temp2[15]);


                   Ascii2int( &iCount1,&iCount2, &iCount3, &iCount4);
                   Ascii2int( &iPos1,&iPos2, &iPos3, &iPos4);

                   bCount= (double)(iCount1*4096 +iCount2*256 + iCount3*16 + iCount4);
                   bPosition= (double)(iPos1*4096 +iPos2*256 + iPos3*16 + iPos4);




                   if( (bPosition != 0) && (bPosition < 180) && (bCount != 0))
                   {
                       a[k] = bCount;
                       b[k] =bPosition;


                   ui -> pidPlot -> graph(0) ->setData(a, b);


                   ui->pidPlot->rescaleAxes();
                   ui->pidPlot->replot();
                   ui-> pidPlot -> update();
                   qDebug() << "Positon: " <<bPosition  << " " << "Count: " <<bCount << "\n" ;
                    k++;
                    t++;
                    }

                   if(k > bCount)
                   {
                       k = 0;
                   }

            }
        //clear data remain
           str.clear();
           temp.clear();
           data_rev.clear();
       }
       QScrollBar *sb = ui->textBrowser->verticalScrollBar();
       sb->setValue(sb->maximum());
}

void MainWindow::on_sendpidButton_clicked()
{
            QString temp;
            std::string result;
            std::ostringstream sstream;
            //reading params from Line Edit
            QString kp = ui ->kpEdit->text();
            QString ki = ui ->kiEdit->text();
            QString kd = ui ->kdEdit->text();

            //Kp convert
            QByteArray bKp;
            QStringList  list1 = kp.split(".");
            foreach (temp, list1)
            {
                result = (boost::format("%x") % temp.toInt()).str();
                bKp.append(" " + QByteArray::fromHex(QString::fromStdString(result).toUtf8()));
            }
            qDebug() << bKp << "\n";

            //Ki convert
            QByteArray bKi;
            QStringList  list2 = ki.split(".");
            foreach (temp, list2)
            {
                result = (boost::format("%x") % temp.toInt()).str();
                bKi.append(" " +  QByteArray::fromHex(QString::fromStdString(result).toUtf8()));
            }
            qDebug() << bKi << "\n";

            //Kd convert
            QByteArray bKd;
            QStringList  list3 = kd.split(".");
            foreach (temp, list3)
            {
                result = (boost::format("%x") % temp.toInt()).str();
                bKd.append(" " + QByteArray::fromHex(QString::fromStdString(result).toUtf8()));
            }
            qDebug() << bKd << "\n";


            QByteArray bytes("02 53 50 49 44 00 00 00");
            bytes = QByteArray::fromHex(bytes);

            //merge params
            QByteArray temp2;
            temp2.append(bKp + bKi + bKd);
            bytes.append(temp2);


            //protocal last byte
            QByteArray temp_byte("00 00 16 03");
            temp_byte = QByteArray::fromHex(temp_byte);

            //send pid parmas
            bytes.append(temp_byte);
            bytes.replace(" ", "");
            qDebug() << bytes << "\n";
            mSerial->write(bytes);
            if(mSerial -> isWritable())
                    {
                QString text = "Send succeed \n";
                ui->textBrowser->insertPlainText(text);
                    }
}

void MainWindow::on_tunningButton_clicked()
{
            QByteArray str("02 43 54 55 4E 00 00 00 00 00 00 00 00 00 00 00 16 03");
            QByteArray t = str.replace(" ", "");
            QByteArray bytes = QByteArray::fromHex(t);
            mSerial->write(bytes);
}

void MainWindow::on_requestButton_clicked()
{
            QByteArray str("02 47 50 49 44 00 00 00 00 00 00 00 00 00 00 00 16 03");
            QByteArray t = str.replace(" ", "");
            QByteArray bytes = QByteArray::fromHex(t);
            mSerial->write(bytes);
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

