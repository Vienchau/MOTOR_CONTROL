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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_2;
    QWidget *pidPlotWidget;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *motionPushButton;
    QPushButton *runPushButton;
    QVBoxLayout *verticalLayout_4;
    QPushButton *senparamsPushButton;
    QPushButton *getPushButton;
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
    QPushButton *sendButton;
    QTextEdit *textEdit_2;
    QGroupBox *groupBox;
    QWidget *posPlotWidget;
    QWidget *velPlotWidget;
    QWidget *accPlotWidget;
    QLabel *label_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1083, 604);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 341, 111));
        textBrowser = new QTextBrowser(groupBox_4);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 321, 71));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(360, 10, 211, 171));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 191, 141));
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

        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 130, 341, 141));
        layoutWidget_2 = new QWidget(groupBox_7);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 171, 121));
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
        lineEdit = new QLineEdit(layoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_5->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_5->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(layoutWidget_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_5->addWidget(lineEdit_3);


        horizontalLayout_3->addLayout(verticalLayout_5);

        layoutWidget_3 = new QWidget(groupBox_7);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(190, 20, 141, 121));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_7->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_7->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_7->addWidget(pushButton_3);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 280, 561, 281));
        pidPlotWidget = new QWidget(groupBox_2);
        pidPlotWidget->setObjectName(QStringLiteral("pidPlotWidget"));
        pidPlotWidget->setGeometry(QRect(10, 30, 541, 241));
        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(360, 190, 211, 81));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        motionPushButton = new QPushButton(layoutWidget_4);
        motionPushButton->setObjectName(QStringLiteral("motionPushButton"));

        verticalLayout_3->addWidget(motionPushButton);

        runPushButton = new QPushButton(layoutWidget_4);
        runPushButton->setObjectName(QStringLiteral("runPushButton"));

        verticalLayout_3->addWidget(runPushButton);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        senparamsPushButton = new QPushButton(layoutWidget_4);
        senparamsPushButton->setObjectName(QStringLiteral("senparamsPushButton"));

        verticalLayout_4->addWidget(senparamsPushButton);

        getPushButton = new QPushButton(layoutWidget_4);
        getPushButton->setObjectName(QStringLiteral("getPushButton"));

        verticalLayout_4->addWidget(getPushButton);


        horizontalLayout_2->addLayout(verticalLayout_4);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(880, 10, 191, 251));
        layoutWidget_5 = new QWidget(groupBox_5);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 20, 163, 221));
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
        groupBox_6->setGeometry(QRect(880, 260, 191, 111));
        sendButton = new QPushButton(groupBox_6);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(10, 70, 171, 31));
        textEdit_2 = new QTextEdit(groupBox_6);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 30, 171, 31));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(580, 10, 291, 551));
        posPlotWidget = new QWidget(groupBox);
        posPlotWidget->setObjectName(QStringLiteral("posPlotWidget"));
        posPlotWidget->setGeometry(QRect(10, 20, 271, 161));
        velPlotWidget = new QWidget(groupBox);
        velPlotWidget->setObjectName(QStringLiteral("velPlotWidget"));
        velPlotWidget->setGeometry(QRect(10, 200, 271, 161));
        accPlotWidget = new QWidget(groupBox);
        accPlotWidget->setObjectName(QStringLiteral("accPlotWidget"));
        accPlotWidget->setGeometry(QRect(10, 380, 271, 161));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(900, 390, 151, 141));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../../../../../../../media/vienchau/DATA/MY_WORK/Qt/Project/PhCode/PhCode/BK.png")));
        label_11->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1083, 20));
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
        groupBox_7->setTitle(QApplication::translate("MainWindow", "PID Tunning", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Kp", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Ki", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Kd", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "SEND", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "TUNING", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "REQUEST", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "PID Tunning Graph", Q_NULLPTR));
        motionPushButton->setText(QApplication::translate("MainWindow", "MOTION", Q_NULLPTR));
        runPushButton->setText(QApplication::translate("MainWindow", "RUN", Q_NULLPTR));
        senparamsPushButton->setText(QApplication::translate("MainWindow", "SEND PARAMS", Q_NULLPTR));
        getPushButton->setText(QApplication::translate("MainWindow", "GET", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Serial Port", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "COM", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "BaudRate", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "DataSize", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Parity", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Send Data", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Control Graph", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
