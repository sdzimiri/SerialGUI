#ifndef DAQCONTROL_H
#define DAQCONTROL_H

#include <QObject>
#include <NIDAQmx.h>
#include <QDebug>
#include <QTimer>

#define DAQCHAN "Dev1/ai0:2"
#define SAMP_RATE 10000
#define NUM_SAMPS 1000


class DaqControl : public QObject
{
    Q_OBJECT

public:
    DaqControl();

public slots:
    void SetupTask();
    void ReadTemp();
    void stopTask();

signals:
    void daqError(QString errMessage);
    void txTemp(float val, float av_2, float av_3);

private slots:
    void readDaqData();

private:

    void createTask();
    void startTask();
    void configureAOVoltageTask();
    void configureTiming();
    void readSample();
    void processError(int32 error);

    TaskHandle measTask;

    //Timers to check for new data / errors
    //This is necessary because NIDAQ callbacks must be static (no signals/slots)
    QTimer *errTimer;

};

#endif // DAQCONTROL_H
