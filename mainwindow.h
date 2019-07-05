#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QSerialPort>
#include <QSerialPortInfo>
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <daqcontrol.h>
#include <QThread>
#include <QFile>
#include <QTimer>
#include <QDateTime>
#include <QTime>
#include "linechart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double average;
    int state;
    //0 = gain
    //1 = tectemp
    //2 = req_pos
    //3 = req_limit

    enum state{none, gain, tectemp, interg, windup, currentp, currentn};

signals:
    void txDaqTempRequest();
    void txDaqCfgRequest();
    void txTempData(double t1, double t2, double t3, double TEC, int time);


private slots:

    void rxTemp(float temp, float av_2, float av_3);

    void readTECTemp();

    void serialReceived();

    void on_button_PortConnection_clicked();

    void on_button_EnableTEC_clicked();

    void on_button_DisableTEC_clicked();

    void on_button_setpointTEC_clicked();

    void rxdaqError(QString errMessage);

    void on_button_beginTask_clicked();

    void on_open_File_button_clicked();

    void on_pushButton_close_clicked();

    void on_button_stop_clicked();

    void on_button_chart_clicked();

    void on_spinBox_sampleRate_valueChanged(int arg1);

    void on_butto_readGain_clicked();

    void on_button_readKI_clicked();

    void on_button_readW_clicked();

    void on_readC_plus_clicked();

    void on_button_readC_N_clicked();

    void on_pushButton_writegain_clicked();

private:
    QSerialPort *serial;
    Ui::MainWindow *ui;
    bool bForButton;
    QPushButton *button_ReadTemp; 
    QTimer *timer;
    int elapsedTime;

    DaqControl *daq;
    QThread *daqThread;

    QFile dataFile;
    QTextStream dataStream;

    int sample;
    linechart *chart;

    void waitMsec(int msec);
};

#endif // MAINWINDOW_H
