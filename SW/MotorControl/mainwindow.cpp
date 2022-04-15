#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"




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

        ui->sizeComboBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
        ui->sizeComboBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
        ui->sizeComboBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
        ui->sizeComboBox->addItem(QStringLiteral("8"), QSerialPort::Data8);



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

        connect(mSerialScanTimer, &QTimer::timeout, this, &MainWindow::updateSerialPort);
        connect(ui->lineEdit, &QLineEdit::returnPressed,this, &MainWindow::on_sendButton_clicked);
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
        mDatapid = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);
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
        ui->pidPlot->addGraph();

        ui->pidPlot->graph()->setPen(QPen(Qt::black));
        ui->pidPlot->graph()->setData(mDatapid);
        ui->pidPlot->graph()->setName("Tunning");

        //Position plot init
        mDatapos = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);
        ui->posPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->posPlot->legend->setVisible(true);
        ui->posPlot->legend->setFont(legendFont);
        ui->posPlot->legend->setSelectedFont(legendFont);
        ui->posPlot->legend->setSelectableParts(QCPLegend::spItems);
        ui->posPlot->yAxis->setLabel("Magnitude");
        ui->posPlot->xAxis->setLabel("Time");
        ui->posPlot->clearGraphs();
        ui->posPlot->addGraph();

        ui->posPlot->graph()->setPen(QPen(Qt::black));
        ui->posPlot->graph()->setData(mDatapos);
        ui->posPlot->graph()->setName("Posititon");

        //Velocity plot init
        mDatavel = QSharedPointer<QCPGraphDataContainer>(new QCPGraphDataContainer);
        ui->velPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->velPlot->legend->setVisible(true);
        ui->velPlot->legend->setFont(legendFont);
        ui->velPlot->legend->setSelectedFont(legendFont);
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
        ui->accPlot->legend->setFont(legendFont);
        ui->accPlot->legend->setSelectedFont(legendFont);
        ui->accPlot->legend->setSelectableParts(QCPLegend::spItems);
        ui->accPlot->yAxis->setLabel("Magnitude");
        ui->accPlot->xAxis->setLabel("Time");
        ui->accPlot->clearGraphs();
        ui->accPlot->addGraph();

        ui->accPlot->graph()->setPen(QPen(Qt::black));
        ui->accPlot->graph()->setData(mDataacc);
        ui->accPlot->graph()->setName("Accelometer");
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
            ui-> openButton ->setEnabled(true);
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
       QString data = "Data recieved: ";
       QThread::msleep(50);
       QByteArray data_rev = mSerial -> readAll();
       if(data_rev.size() < 17)
       {
           data_rev.clear();
       }
       else
       {
           str = (QString(data_rev));
               QString temp = str;
               //command split
               temp.chop(13);
               ui -> textBrowser -> insertPlainText(cmd);
               temp.append("\n");
               ui -> textBrowser -> insertPlainText(temp);
                //data split
               //QString temp2 = QString::number(data_rev, 16);

               QString temp2 = str;
               temp2.chop(2);
               temp2 = temp2.right(9);
               ui -> textBrowser -> insertPlainText(data);
               temp2.append("\n");
               ui -> textBrowser -> insertPlainText(temp2);
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

