/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_4;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *posLineEdit;
    QLineEdit *velLineEdit;
    QLineEdit *accLineEdit;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *motionButton;
    QPushButton *runButton;
    QVBoxLayout *verticalLayout_4;
    QPushButton *senparamsButton;
    QPushButton *getButton;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *kpEdit;
    QLineEdit *kiEdit;
    QLineEdit *kdEdit;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_7;
    QPushButton *sendpidButton;
    QPushButton *tunningButton;
    QPushButton *requestButton;
    QGroupBox *groupBox_2;
    QCustomPlot *pidPlot;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QComboBox *serialComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QComboBox *baudComboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QComboBox *sizeComboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QComboBox *parityComboBox;
    QGroupBox *groupBox_6;
    QLineEdit *sendEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout_13;
    QPushButton *sendButton;
    QPushButton *clearButton;
    QGroupBox *groupBox;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_10;
    QCustomPlot *posPlot;
    QCustomPlot *velPlot;
    QCustomPlot *accPlot;
    QLabel *label_11;
    QGroupBox *groupBox_8;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_11;
    QPushButton *savePIDButton;
    QPushButton *clearPIDButton;
    QVBoxLayout *verticalLayout_12;
    QPushButton *infoPIDButton;
    QPushButton *clearReceiveButton;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_9;
    QPushButton *openButton;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1329, 805);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 391, 171));
        textBrowser = new QTextBrowser(groupBox_4);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 371, 131));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(410, 10, 211, 211));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 191, 111));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        posLineEdit = new QLineEdit(layoutWidget);
        posLineEdit->setObjectName(QStringLiteral("posLineEdit"));

        verticalLayout->addWidget(posLineEdit);

        velLineEdit = new QLineEdit(layoutWidget);
        velLineEdit->setObjectName(QStringLiteral("velLineEdit"));

        verticalLayout->addWidget(velLineEdit);

        accLineEdit = new QLineEdit(layoutWidget);
        accLineEdit->setObjectName(QStringLiteral("accLineEdit"));

        verticalLayout->addWidget(accLineEdit);


        horizontalLayout->addLayout(verticalLayout);

        layoutWidget_4 = new QWidget(groupBox_3);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 130, 191, 71));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        motionButton = new QPushButton(layoutWidget_4);
        motionButton->setObjectName(QStringLiteral("motionButton"));

        verticalLayout_3->addWidget(motionButton);

        runButton = new QPushButton(layoutWidget_4);
        runButton->setObjectName(QStringLiteral("runButton"));

        verticalLayout_3->addWidget(runButton);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        senparamsButton = new QPushButton(layoutWidget_4);
        senparamsButton->setObjectName(QStringLiteral("senparamsButton"));

        verticalLayout_4->addWidget(senparamsButton);

        getButton = new QPushButton(layoutWidget_4);
        getButton->setObjectName(QStringLiteral("getButton"));

        verticalLayout_4->addWidget(getButton);


        horizontalLayout_2->addLayout(verticalLayout_4);

        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 190, 391, 151));
        layoutWidget_2 = new QWidget(groupBox_7);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 20, 211, 121));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_6->addWidget(label_4);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_6->addWidget(label_5);

        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_6->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        kpEdit = new QLineEdit(layoutWidget_2);
        kpEdit->setObjectName(QStringLiteral("kpEdit"));

        verticalLayout_5->addWidget(kpEdit);

        kiEdit = new QLineEdit(layoutWidget_2);
        kiEdit->setObjectName(QStringLiteral("kiEdit"));

        verticalLayout_5->addWidget(kiEdit);

        kdEdit = new QLineEdit(layoutWidget_2);
        kdEdit->setObjectName(QStringLiteral("kdEdit"));

        verticalLayout_5->addWidget(kdEdit);


        horizontalLayout_3->addLayout(verticalLayout_5);

        layoutWidget_3 = new QWidget(groupBox_7);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(240, 20, 141, 121));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        sendpidButton = new QPushButton(layoutWidget_3);
        sendpidButton->setObjectName(QStringLiteral("sendpidButton"));

        verticalLayout_7->addWidget(sendpidButton);

        tunningButton = new QPushButton(layoutWidget_3);
        tunningButton->setObjectName(QStringLiteral("tunningButton"));

        verticalLayout_7->addWidget(tunningButton);

        requestButton = new QPushButton(layoutWidget_3);
        requestButton->setObjectName(QStringLiteral("requestButton"));

        verticalLayout_7->addWidget(requestButton);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 350, 611, 411));
        pidPlot = new QCustomPlot(groupBox_2);
        pidPlot->setObjectName(QStringLiteral("pidPlot"));
        pidPlot->setGeometry(QRect(10, 30, 591, 371));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(1130, 30, 191, 241));
        layoutWidget_5 = new QWidget(groupBox_5);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 20, 171, 211));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(layoutWidget_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        serialComboBox = new QComboBox(layoutWidget_5);
        serialComboBox->setObjectName(QStringLiteral("serialComboBox"));

        horizontalLayout_4->addWidget(serialComboBox);


        verticalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(layoutWidget_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        baudComboBox = new QComboBox(layoutWidget_5);
        baudComboBox->setObjectName(QStringLiteral("baudComboBox"));

        horizontalLayout_5->addWidget(baudComboBox);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_9 = new QLabel(layoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        sizeComboBox = new QComboBox(layoutWidget_5);
        sizeComboBox->setObjectName(QStringLiteral("sizeComboBox"));

        horizontalLayout_6->addWidget(sizeComboBox);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_10 = new QLabel(layoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        parityComboBox = new QComboBox(layoutWidget_5);
        parityComboBox->setObjectName(QStringLiteral("parityComboBox"));

        horizontalLayout_7->addWidget(parityComboBox);


        verticalLayout_8->addLayout(horizontalLayout_7);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(1130, 340, 191, 171));
        sendEdit = new QLineEdit(groupBox_6);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setGeometry(QRect(10, 30, 171, 51));
        widget = new QWidget(groupBox_6);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 90, 171, 71));
        verticalLayout_13 = new QVBoxLayout(widget);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        verticalLayout_13->addWidget(sendButton);

        clearButton = new QPushButton(widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        verticalLayout_13->addWidget(clearButton);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(630, 10, 491, 751));
        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 30, 471, 711));
        verticalLayout_10 = new QVBoxLayout(widget1);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        posPlot = new QCustomPlot(widget1);
        posPlot->setObjectName(QStringLiteral("posPlot"));

        verticalLayout_10->addWidget(posPlot);

        velPlot = new QCustomPlot(widget1);
        velPlot->setObjectName(QStringLiteral("velPlot"));

        verticalLayout_10->addWidget(velPlot);

        accPlot = new QCustomPlot(widget1);
        accPlot->setObjectName(QStringLiteral("accPlot"));

        verticalLayout_10->addWidget(accPlot);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1150, 620, 161, 141));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../../../../../../../media/vienchau/DATA/MY_WORK/tai_lieu/logo/Logo BK.png")));
        label_11->setScaledContents(true);
        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(410, 229, 211, 111));
        widget2 = new QWidget(groupBox_8);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 20, 191, 91));
        horizontalLayout_8 = new QHBoxLayout(widget2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        savePIDButton = new QPushButton(widget2);
        savePIDButton->setObjectName(QStringLiteral("savePIDButton"));

        verticalLayout_11->addWidget(savePIDButton);

        clearPIDButton = new QPushButton(widget2);
        clearPIDButton->setObjectName(QStringLiteral("clearPIDButton"));

        verticalLayout_11->addWidget(clearPIDButton);


        horizontalLayout_8->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        infoPIDButton = new QPushButton(widget2);
        infoPIDButton->setObjectName(QStringLiteral("infoPIDButton"));

        verticalLayout_12->addWidget(infoPIDButton);

        clearReceiveButton = new QPushButton(widget2);
        clearReceiveButton->setObjectName(QStringLiteral("clearReceiveButton"));

        verticalLayout_12->addWidget(clearReceiveButton);


        horizontalLayout_8->addLayout(verticalLayout_12);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(1130, 280, 191, 54));
        verticalLayout_9 = new QVBoxLayout(widget3);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        openButton = new QPushButton(widget3);
        openButton->setObjectName(QStringLiteral("openButton"));

        verticalLayout_9->addWidget(openButton);

        closeButton = new QPushButton(widget3);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        verticalLayout_9->addWidget(closeButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1329, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Received Data", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Control Parameters", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Position", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Velocity", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Accelometer", Q_NULLPTR));
        motionButton->setText(QApplication::translate("MainWindow", "MOTION", Q_NULLPTR));
        runButton->setText(QApplication::translate("MainWindow", "RUN", Q_NULLPTR));
        senparamsButton->setText(QApplication::translate("MainWindow", "SEND PARAMS", Q_NULLPTR));
        getButton->setText(QApplication::translate("MainWindow", "GET", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "PID Tunning", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Kp", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Ki", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Kd", Q_NULLPTR));
        sendpidButton->setText(QApplication::translate("MainWindow", "SEND", Q_NULLPTR));
        tunningButton->setText(QApplication::translate("MainWindow", "TUNING", Q_NULLPTR));
        requestButton->setText(QApplication::translate("MainWindow", "REQUEST", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "PID Tunning Graph", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Serial Port", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "COM", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "BaudRate", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "DataSize", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Parity", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Send Data", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Control Graph", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        savePIDButton->setText(QApplication::translate("MainWindow", "Print PID", Q_NULLPTR));
        clearPIDButton->setText(QApplication::translate("MainWindow", "Clear PID", Q_NULLPTR));
        infoPIDButton->setText(QApplication::translate("MainWindow", "PID Info", Q_NULLPTR));
        clearReceiveButton->setText(QApplication::translate("MainWindow", "Clear Box", Q_NULLPTR));
        openButton->setText(QApplication::translate("MainWindow", "OPEN", Q_NULLPTR));
        closeButton->setText(QApplication::translate("MainWindow", "CLOSE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
