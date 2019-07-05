/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *average_Label_2;
    QLabel *average;
    QLabel *average_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button_beginTask;
    QPushButton *button_stop;
    QLabel *label_11;
    QPushButton *button_PortConnection;
    QDoubleSpinBox *doubleSpinBox_setTEC;
    QSpinBox *spinBox_sampleRate;
    QLabel *label_10;
    QPushButton *open_File_button;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *button_DisableTEC;
    QLabel *label_9;
    QComboBox *comboBox_Port;
    QLabel *label_4;
    QPushButton *button_EnableTEC;
    QPushButton *button_setpointTEC;
    QPushButton *button_chart;
    QPushButton *pushButton_close;
    QLabel *label_device;
    QLabel *label_gain;
    QLabel *label_ki_display;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_current_neg;
    QSpinBox *spinBox_current;
    QSpinBox *spinBox_gain;
    QSpinBox *spinBox_ki;
    QSpinBox *spinBox_windup;
    QPushButton *butto_readGain;
    QPushButton *button_readKI;
    QPushButton *button_readW;
    QPushButton *readC_plus;
    QPushButton *button_readC_N;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox_wWindup;
    QSpinBox *spinBox_WRITEki;
    QPushButton *pushButton_writeC;
    QPushButton *pushButton_writegain;
    QSpinBox *spinBox_writegain;
    QPushButton *pushButton_writeKI;
    QSpinBox *spinBox_writeC;
    QPushButton *pushButton_wWindup;
    QPushButton *pushButton;
    QSpinBox *spinBox_writeCp;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1092, 490);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 1071, 441));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 290, 431, 101));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(50);
        font.setStrikeOut(false);
        groupBox_2->setFont(font);
        average_Label_2 = new QLabel(groupBox_2);
        average_Label_2->setObjectName(QString::fromUtf8("average_Label_2"));
        average_Label_2->setGeometry(QRect(30, 50, 71, 31));
        average_Label_2->setContextMenuPolicy(Qt::NoContextMenu);
        average = new QLabel(groupBox_2);
        average->setObjectName(QString::fromUtf8("average"));
        average->setGeometry(QRect(140, 50, 71, 31));
        average_3 = new QLabel(groupBox_2);
        average_3->setObjectName(QString::fromUtf8("average_3"));
        average_3->setGeometry(QRect(230, 50, 71, 31));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 30, 91, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 30, 91, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(230, 30, 91, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(350, 30, 61, 16));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 50, 61, 31));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        label->setFont(font1);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 30, 341, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        button_beginTask = new QPushButton(gridLayoutWidget);
        button_beginTask->setObjectName(QString::fromUtf8("button_beginTask"));

        gridLayout->addWidget(button_beginTask, 7, 1, 1, 1);

        button_stop = new QPushButton(gridLayoutWidget);
        button_stop->setObjectName(QString::fromUtf8("button_stop"));

        gridLayout->addWidget(button_stop, 7, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 7, 0, 1, 1);

        button_PortConnection = new QPushButton(gridLayoutWidget);
        button_PortConnection->setObjectName(QString::fromUtf8("button_PortConnection"));
        button_PortConnection->setEnabled(true);

        gridLayout->addWidget(button_PortConnection, 0, 2, 1, 1);

        doubleSpinBox_setTEC = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBox_setTEC->setObjectName(QString::fromUtf8("doubleSpinBox_setTEC"));
        doubleSpinBox_setTEC->setDecimals(2);

        gridLayout->addWidget(doubleSpinBox_setTEC, 1, 1, 1, 1);

        spinBox_sampleRate = new QSpinBox(gridLayoutWidget);
        spinBox_sampleRate->setObjectName(QString::fromUtf8("spinBox_sampleRate"));
        spinBox_sampleRate->setMinimum(1);

        gridLayout->addWidget(spinBox_sampleRate, 2, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        open_File_button = new QPushButton(gridLayoutWidget);
        open_File_button->setObjectName(QString::fromUtf8("open_File_button"));

        gridLayout->addWidget(open_File_button, 3, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        button_DisableTEC = new QPushButton(gridLayoutWidget);
        button_DisableTEC->setObjectName(QString::fromUtf8("button_DisableTEC"));

        gridLayout->addWidget(button_DisableTEC, 4, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        comboBox_Port = new QComboBox(gridLayoutWidget);
        comboBox_Port->setObjectName(QString::fromUtf8("comboBox_Port"));

        gridLayout->addWidget(comboBox_Port, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        button_EnableTEC = new QPushButton(gridLayoutWidget);
        button_EnableTEC->setObjectName(QString::fromUtf8("button_EnableTEC"));

        gridLayout->addWidget(button_EnableTEC, 4, 1, 1, 1);

        button_setpointTEC = new QPushButton(gridLayoutWidget);
        button_setpointTEC->setObjectName(QString::fromUtf8("button_setpointTEC"));

        gridLayout->addWidget(button_setpointTEC, 1, 2, 1, 1);

        button_chart = new QPushButton(groupBox);
        button_chart->setObjectName(QString::fromUtf8("button_chart"));
        button_chart->setGeometry(QRect(600, 40, 109, 23));
        pushButton_close = new QPushButton(groupBox);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(960, 410, 109, 23));
        label_device = new QLabel(groupBox);
        label_device->setObjectName(QString::fromUtf8("label_device"));
        label_device->setGeometry(QRect(380, 40, 91, 21));
        label_gain = new QLabel(groupBox);
        label_gain->setObjectName(QString::fromUtf8("label_gain"));
        label_gain->setGeometry(QRect(796, 40, 91, 31));
        label_ki_display = new QLabel(groupBox);
        label_ki_display->setObjectName(QString::fromUtf8("label_ki_display"));
        label_ki_display->setGeometry(QRect(930, 52, 61, 21));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(770, 10, 281, 361));
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 20, 241, 141));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox_current_neg = new QSpinBox(gridLayoutWidget_2);
        spinBox_current_neg->setObjectName(QString::fromUtf8("spinBox_current_neg"));
        spinBox_current_neg->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_current_neg->setMaximum(100);

        gridLayout_2->addWidget(spinBox_current_neg, 4, 1, 1, 1);

        spinBox_current = new QSpinBox(gridLayoutWidget_2);
        spinBox_current->setObjectName(QString::fromUtf8("spinBox_current"));
        spinBox_current->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_current->setMaximum(100);

        gridLayout_2->addWidget(spinBox_current, 3, 1, 1, 1);

        spinBox_gain = new QSpinBox(gridLayoutWidget_2);
        spinBox_gain->setObjectName(QString::fromUtf8("spinBox_gain"));
        spinBox_gain->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_gain->setMaximum(9999);

        gridLayout_2->addWidget(spinBox_gain, 0, 1, 1, 1);

        spinBox_ki = new QSpinBox(gridLayoutWidget_2);
        spinBox_ki->setObjectName(QString::fromUtf8("spinBox_ki"));
        spinBox_ki->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ki->setMaximum(1000);

        gridLayout_2->addWidget(spinBox_ki, 1, 1, 1, 1);

        spinBox_windup = new QSpinBox(gridLayoutWidget_2);
        spinBox_windup->setObjectName(QString::fromUtf8("spinBox_windup"));
        spinBox_windup->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_windup->setMaximum(9999);

        gridLayout_2->addWidget(spinBox_windup, 2, 1, 1, 1);

        butto_readGain = new QPushButton(gridLayoutWidget_2);
        butto_readGain->setObjectName(QString::fromUtf8("butto_readGain"));

        gridLayout_2->addWidget(butto_readGain, 0, 0, 1, 1);

        button_readKI = new QPushButton(gridLayoutWidget_2);
        button_readKI->setObjectName(QString::fromUtf8("button_readKI"));

        gridLayout_2->addWidget(button_readKI, 1, 0, 1, 1);

        button_readW = new QPushButton(gridLayoutWidget_2);
        button_readW->setObjectName(QString::fromUtf8("button_readW"));

        gridLayout_2->addWidget(button_readW, 2, 0, 1, 1);

        readC_plus = new QPushButton(gridLayoutWidget_2);
        readC_plus->setObjectName(QString::fromUtf8("readC_plus"));

        gridLayout_2->addWidget(readC_plus, 3, 0, 1, 1);

        button_readC_N = new QPushButton(gridLayoutWidget_2);
        button_readC_N->setObjectName(QString::fromUtf8("button_readC_N"));

        gridLayout_2->addWidget(button_readC_N, 4, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(groupBox_3);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 210, 241, 141));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        spinBox_wWindup = new QSpinBox(gridLayoutWidget_3);
        spinBox_wWindup->setObjectName(QString::fromUtf8("spinBox_wWindup"));
        spinBox_wWindup->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_wWindup->setMaximum(1000);

        gridLayout_3->addWidget(spinBox_wWindup, 2, 1, 1, 1);

        spinBox_WRITEki = new QSpinBox(gridLayoutWidget_3);
        spinBox_WRITEki->setObjectName(QString::fromUtf8("spinBox_WRITEki"));
        spinBox_WRITEki->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_WRITEki->setMaximum(500);

        gridLayout_3->addWidget(spinBox_WRITEki, 1, 1, 1, 1);

        pushButton_writeC = new QPushButton(gridLayoutWidget_3);
        pushButton_writeC->setObjectName(QString::fromUtf8("pushButton_writeC"));

        gridLayout_3->addWidget(pushButton_writeC, 3, 0, 1, 1);

        pushButton_writegain = new QPushButton(gridLayoutWidget_3);
        pushButton_writegain->setObjectName(QString::fromUtf8("pushButton_writegain"));

        gridLayout_3->addWidget(pushButton_writegain, 0, 0, 1, 1);

        spinBox_writegain = new QSpinBox(gridLayoutWidget_3);
        spinBox_writegain->setObjectName(QString::fromUtf8("spinBox_writegain"));
        spinBox_writegain->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_writegain->setMinimum(-10000);
        spinBox_writegain->setMaximum(10000);

        gridLayout_3->addWidget(spinBox_writegain, 0, 1, 1, 1);

        pushButton_writeKI = new QPushButton(gridLayoutWidget_3);
        pushButton_writeKI->setObjectName(QString::fromUtf8("pushButton_writeKI"));

        gridLayout_3->addWidget(pushButton_writeKI, 1, 0, 1, 1);

        spinBox_writeC = new QSpinBox(gridLayoutWidget_3);
        spinBox_writeC->setObjectName(QString::fromUtf8("spinBox_writeC"));
        spinBox_writeC->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_3->addWidget(spinBox_writeC, 3, 1, 1, 1);

        pushButton_wWindup = new QPushButton(gridLayoutWidget_3);
        pushButton_wWindup->setObjectName(QString::fromUtf8("pushButton_wWindup"));

        gridLayout_3->addWidget(pushButton_wWindup, 2, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 4, 0, 1, 1);

        spinBox_writeCp = new QSpinBox(gridLayoutWidget_3);
        spinBox_writeCp->setObjectName(QString::fromUtf8("spinBox_writeCp"));
        spinBox_writeCp->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_3->addWidget(spinBox_writeCp, 4, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1092, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Serial Ports Connection", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Temperature Values (Degrees Celcius)", nullptr));
        average_Label_2->setText(QString());
        average->setText(QString());
        average_3->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Temperature 1", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Temperature 2", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Temperature 3", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "TEC Temp", nullptr));
        label->setText(QString());
        button_beginTask->setText(QApplication::translate("MainWindow", "Start", nullptr));
        button_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Start/Stop ", nullptr));
        button_PortConnection->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Samp Rate (sec)", nullptr));
        open_File_button->setText(QApplication::translate("MainWindow", "Open File", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "TEC Enable/Disable", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "TEC SetPoint", nullptr));
        button_DisableTEC->setText(QApplication::translate("MainWindow", "Disable", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Experiment", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Serial Port Connection ", nullptr));
        button_EnableTEC->setText(QApplication::translate("MainWindow", "Enable", nullptr));
        button_setpointTEC->setText(QApplication::translate("MainWindow", "Set", nullptr));
        button_chart->setText(QApplication::translate("MainWindow", "Display Chart", nullptr));
        pushButton_close->setText(QApplication::translate("MainWindow", "Close", nullptr));
        label_device->setText(QApplication::translate("MainWindow", "Disconnected", nullptr));
        label_gain->setText(QString());
        label_ki_display->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Properties", nullptr));
        butto_readGain->setText(QApplication::translate("MainWindow", "Read Gain", nullptr));
        button_readKI->setText(QApplication::translate("MainWindow", "Read KI", nullptr));
        button_readW->setText(QApplication::translate("MainWindow", "Read WindUp", nullptr));
        readC_plus->setText(QApplication::translate("MainWindow", "Read Current+", nullptr));
        button_readC_N->setText(QApplication::translate("MainWindow", "Read Current-", nullptr));
        pushButton_writeC->setText(QApplication::translate("MainWindow", "Write Current+", nullptr));
        pushButton_writegain->setText(QApplication::translate("MainWindow", "Write Gain", nullptr));
        pushButton_writeKI->setText(QApplication::translate("MainWindow", "Write KI", nullptr));
        pushButton_wWindup->setText(QApplication::translate("MainWindow", "Write WindUp", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Write Current-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
