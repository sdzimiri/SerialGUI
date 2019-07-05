#include "daqcontrol.h"
QString errorMessage;
bool configured;

DaqControl::DaqControl() : QObject ()
{
    //Daqmx variables
    measTask= 0;

    //error timer, neccessary to operate DAQ in static functions
    errorMessage = "";
    errTimer=new QTimer();
    configured=false;
    // connect(errTimer, SIGNAL(timeout()), SLOT(errPeriod()));
    // errTimer->start(100);

}

void DaqControl::SetupTask()
{
    if(!configured)
    {
        createTask();
        configureAOVoltageTask();
        configureTiming();
        configured = true;
    }
}

void DaqControl::ReadTemp()
{

    startTask();
    QTimer::singleShot(600,this,SLOT(readDaqData()));


}

void DaqControl::readDaqData()
{
    readSample();
}

//create measurement task
void DaqControl::createTask()
{
    int32 status;

    status = DAQmxCreateTask("AI" , &measTask);

    if (status < 0)
    {
        processError(status);
    }
    else if (status > 0)
    {
        processError(status);
    }
    else
    {
        //this means that it has been successful and no error code
        qDebug() << "Task created. Status " << status;
        return;
    }
}

//add analog input voltage channels
void DaqControl::configureAOVoltageTask()
{
    int32 status;

    status = DAQmxCreateAIVoltageChan( measTask, DAQCHAN , "AI", DAQmx_Val_RSE, 0, 10, DAQmx_Val_Volts, NULL);
    if(status ==0)
    {
        qDebug() << "Channel Created " << status;

    }
    else if (status < 0)
    {
        processError(status);

    }
    else{
        processError(status);
        return;
    }
}

void DaqControl::configureTiming()
{
    int32 status;

    status=DAQmxCfgSampClkTiming(measTask,"", SAMP_RATE,DAQmx_Val_Rising,DAQmx_Val_FiniteSamps, NUM_SAMPS*3);
    if(status==0)
    {
        //this indicates success and do nothing
         qDebug() << "Timing Configured" << status;

    }
    else if(status < 0)
    {
        processError(status);

    }
    else
    {
        processError(status);
        return;
    }
}

//stops the measurement task when called
void DaqControl::stopTask()
{
    int32 status;

    status = DAQmxStopTask(measTask);
    if(status ==0)
    {
       qDebug() << "Task Stopped" << status;
    }
    else if(status <0)
    {
        processError(status);
    }
    else{

        processError(status);
        return;
    }
}


//reads the sample and calculate the average of the voltage to use this to calculate the temperature
void DaqControl::readSample()
{
    int32 status;
    float64 readArray[NUM_SAMPS*3];
    int32 sampsRead=0;


    status = DAQmxReadAnalogF64(measTask, NUM_SAMPS, 10.0, DAQmx_Val_GroupByScanNumber,readArray, NUM_SAMPS*3, &sampsRead, NULL);

    qDebug() << "SR " << sampsRead;
    stopTask();
    if(status ==0)
    {

        float average = 0;
        float average_2 =0;
        float average_3 = 0;

        double sum=0;
        double sum_2=0;
        double sum_3 =0;

        //do something with readArray
        for(int i=0; i<NUM_SAMPS*3; i+=3)
        {
            //qDebug() << "val " << readArray[i];
            sum=sum + readArray[i];
            sum_2=sum_2 + readArray[i+1];
            sum_3=sum_3 + readArray[i+2];
        }


        //calculate the average to obtain more accurate values
        average = (float) sum / NUM_SAMPS;
        average_2= (float) sum_2/ NUM_SAMPS;
        average_3 = (float) sum_3 / NUM_SAMPS;

        qDebug() << "Sample Read" <<  average;

        //emits the signal with the average value
        emit txTemp(average, average_2, average_3);

        return;
    }
    else if(status <0)
    {
        processError(status);
    }
    else{
         processError(status);
         return;
    }
}

void DaqControl::processError(int32 error)
{
    char *data;
    uInt32 numBytes;

    //find out the length of the error message
    numBytes= DAQmxGetErrorString (error, NULL, 0);

    //allocate the space for an error message
    data = (char *)malloc(numBytes);

    DAQmxGetErrorString(error, data, numBytes);

    QString str(data);
    qDebug() << "MODE Read" <<  NUM_SAMPS*3;
    errorMessage =str;   //"Error: " +


    //emits the signal for the error message
    emit daqError(errorMessage);

    free(data);
}


//starts the task when called
void DaqControl::startTask()
{

    //int32 status;
    int32 status;
    status = DAQmxStartTask (measTask);
    if(status == 0)
    {
        qDebug() << "Task started.  Status " << status;
    }
    else if (status < 0)
    {
         processError(status);

    }
    else{
       processError(status);
       return;
    }
}


