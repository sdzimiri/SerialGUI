#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QtCharts>

using namespace QtCharts;
bool pressed;
bool write;
bool nott;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    state = none;
    ui->setupUi(this);

    //Search for existing com ports
    QList<QSerialPortInfo> infoList = QSerialPortInfo::availablePorts();

    QStringList portList;
    for (int i =0; i < infoList.size();i++)
        portList << infoList[i].portName();

    //Populate fields with ports
    ui->comboBox_Port->addItems(portList);
    serial = new QSerialPort(this);
    bForButton = false;
    pressed=true;

    write=false;
    elapsedTime = 0;

    sample = 1000;

    //linechartThread=new QThread();

    chart=new linechart();
    connect(this, SIGNAL(txTempData(double, double, double,double, int)), chart, SLOT(addTempData(double, double, double, double, int)));


    //chart->moveToThread(linechartThread);
    //linechartThread->start();

    //thread and connect the signals to the slots
    daqThread = new QThread();
    daq = new DaqControl();
    connect(daq,SIGNAL(txTemp(float, float,float)),this,SLOT(rxTemp(float, float, float)));
    connect(this, SIGNAL(txDaqTempRequest()), daq, SLOT(ReadTemp()));
    connect(this, SIGNAL(txDaqCfgRequest()), daq, SLOT(SetupTask()));
    connect(daq, SIGNAL(daqError(QString)), this, SLOT(rxdaqError(QString)));
    daq->moveToThread(daqThread);
    daqThread->start();

}


MainWindow::~MainWindow()
{
    delete ui;
    serial->close();

}

void MainWindow::rxTemp(float temp, float av_2, float av_3)
{

        double setpoint= ui->doubleSpinBox_setTEC->value();

        elapsedTime++;


        QString TECtemp = ui->label->text();

        double tectemp = TECtemp.toDouble();

        qDebug() << "HIGH" << tectemp;

        //calculate the average value and display to the screen
        average=(double) temp;
        double average_2=(double) av_2;
        double average_3 =(double) av_3;

        //10mV per degree for the lm35
        average_2=(average_2) /0.01;
        average_3=(average_3) /0.01;
        average=(average)/0.01;

        //display the average to the screen
        ui->average_Label_2->setNum(average);
        ui->average->setNum(average_2);
        ui->average_3->setNum(average_3);


        if(dataFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QMessageBox::warning(this, "Title", "File not open");
        }

        QDateTime currentDateTime = QDateTime::currentDateTime();
        if(!write){
            dataStream<<  currentDateTime.toString() << "\n";
            write=true;

        }
        if(!nott)
        {
             dataStream << "Time,Setpoint,TEC_temp,Temp1,Temp2,Temp3" << "\n";
             nott=true;

        }
        emit txTempData(average, average_2, average_3, tectemp, elapsedTime);

        waitMsec(100);
        dataStream << elapsedTime<< "," << setpoint<< "," << tectemp << "," << average << "," << average_2 << "," << average_3 << "\n";

       //optional, as QFile destructor will already do it
       dataStream.flush();



}

void MainWindow::readTECTemp()
{

    if(serial->isOpen() /*&& bForButton == true*/)
    {
        //Write 0x24 0x20 0x00 0x00 0x00 0xFF to read temp

        QByteArray ba;
        ba.append(0x24);
        ba.append(0x20);
        ba.append('\0');
        ba.append('\0');
        ba.append('\0');
        ba.append(0xFF);

        serial->write(ba, ba.size());
    }
    else
    {
        ui->label_device->setText("Disconnected");

    }

}

void MainWindow::serialReceived()
{


    QByteArray ba = serial->readAll();

    qDebug() << "SERIAL" << ba;
    QTime timeoutTime=QTime::currentTime().addMSecs(2000);

    while(ba.size() < 3)
    {

        QCoreApplication::processEvents(QEventLoop::AllEvents, 2000);

        if (QTime::currentTime() >= timeoutTime)
        {

            serial->flush();
            return;
        }

   }

    if(state==gain )  //|| state==interg || state==windup || state==currentn || state==currentp
    {
        uint val = ba.at(1);
        val = val + (ba.at(0) << 8);

        int value=((int)val);
        ui->spinBox_gain->setValue(value);
    }
    if(state==tectemp)
    {
        uint val = ba.at(1);
        val = val + (ba.at(0) << 8);

        float value=((float)val /100);
        ui->label->setNum(value);
    }
   if( state==interg)
    {
        uint val = ba.at(1);
        val = val + (ba.at(0) << 8);

        int value=((int)val);
        ui->spinBox_ki->setValue(value);
    }
   if(state==windup)
   {
       uint val = ba.at(1);
       val = val + (ba.at(0) << 8);

       int value=((int)val);
       ui->spinBox_windup->setValue(value);

   }

   if(state==currentp)
   {
       uint val = ba.at(1);
       val = val + (ba.at(0) << 8);

       int value=((int)val);
       ui->spinBox_current->setValue(value);
   }

   if(state==currentn)
   {
       uint val = ba.at(1);
       val = val + (ba.at(0) << 8);

       int value=((int)val);
       ui->spinBox_current_neg->setValue(value);
   }
   state=none;


}

void MainWindow::on_button_PortConnection_clicked()
{
    QString portname = ui->comboBox_Port->currentText();
    serial = new QSerialPort(this);


    serial->setPortName(portname);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if(!serial->open(QIODevice::ReadWrite))
    {
        //error message.
        QMessageBox message;
        message.warning(0, "Warning",  serial->errorString() );

    }
    else
    {
        //if successfully open, then connect.
        connect(serial, SIGNAL(readyRead()), this, SLOT(serialReceived()));
        ui->button_PortConnection->setEnabled(false);
        ui->label_device->setText("Connected");
        ui->comboBox_Port->setEnabled(false);

    }


}

void MainWindow::on_button_EnableTEC_clicked()
{
    if(serial->isOpen())
    {
        //Write 0x24 0x10 0x01 0x00 0x00 0xFF to enable TEC

        QByteArray array;
        array.append(0x24);
        array.append(0x10);
        array.append(0x01);
        array.append('\0');
        array.append('\0');
        array.append(0xFF);

        serial->write(array, array.size());
        bForButton = !bForButton;

        state=tectemp;

    }
}

void MainWindow::on_button_DisableTEC_clicked()
{
    if(serial->isOpen())
    {
        //Write 0x24 0x10 0x02 0x00 0x00 0xFF

        QByteArray arry;
        arry.append(0x24);
        arry.append(0x10);
        arry.append(0x02);
        arry.append('\0');
        arry.append('\0');
        arry.append(0xFF);

        serial->write(arry, arry.size());

    }
}
void MainWindow::on_button_setpointTEC_clicked()
{
  double setpoint= ui->doubleSpinBox_setTEC->value();
  setpoint= setpoint * 100;

  uint b;
  b= (uint) setpoint;

  qDebug() << b;

  unsigned char LSB = b & 0x00FF;
  int MSB = b & 0xFF00;
  MSB = MSB >>8;
  MSB = (unsigned char) MSB;

  //write 0x24 0x10 0x00 tempMSB tempLSB 0xFF

  QByteArray array;
  array.append(0x24);
  array.append(0x10);
  array.append('\0');
  array.append(MSB);
  array.append(LSB);
  array.append(0xFF);


   serial->write(array, array.size());

   state=tectemp;


}

void MainWindow::rxdaqError(QString errMessage)
{
    QMessageBox message;
    message.warning(0, "Error", errMessage);
    message.show();

}


void MainWindow::on_button_beginTask_clicked()
{

    if(!pressed)
    {
        //setup signal and slot

        emit txDaqCfgRequest();
        timer=new QTimer(this);
        connect(timer, SIGNAL(timeout()), daq, SLOT(ReadTemp()));

        connect(timer, SIGNAL(timeout()), this, SLOT( readTECTemp()));

        //msec
        timer->start(sample);

        //ui->button_beginTask->setText("Stop");

        ui->button_EnableTEC->setEnabled(false);
        ui->doubleSpinBox_setTEC->setEnabled(false);
        ui->button_setpointTEC->setEnabled(false);
        ui->spinBox_sampleRate->setEnabled(false);
       // ui->button_setSampleRate->setEnabled(false);
        ui->button_beginTask->setEnabled(false);

        elapsedTime =0;

    }

}

void MainWindow::on_open_File_button_clicked()
{

   if (dataFile.isOpen())
   {
        //if file is open, close it
       dataFile.close();
       ui->open_File_button->setText("Open File");

   }
   else
   {
       //if file isnt open, open one
       QString file_name = QFileDialog::getSaveFileName(this, "Save As", QDir::homePath());
       QMessageBox::information(this, "Saved file directory", file_name);

       //open file
       dataFile.setFileName(file_name);
       if(!dataFile.open(QIODevice::WriteOnly | QIODevice::Text))
       {
            QMessageBox::warning(this, "Title", "File not open");
       }
       else {

           dataStream.setDevice(&dataFile);
           pressed=false;
           //dataFile.close();


       }
   }

}

void MainWindow::on_pushButton_close_clicked()
{
    this->close();
}


void MainWindow::waitMsec(int msec)
{

    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 2000);

}


void MainWindow::on_button_stop_clicked()
{
    ui->button_EnableTEC->setEnabled(true);
    ui->doubleSpinBox_setTEC->setEnabled(true);
    ui->button_setpointTEC->setEnabled(true);
    ui->spinBox_sampleRate->setEnabled(true);
    ui->button_PortConnection->setEnabled(true);
    ui->comboBox_Port->setEnabled(true);
    ui->button_beginTask->setEnabled(true);



    timer->stop();
}

void MainWindow::on_button_chart_clicked()
{
    chart->show();
}

void MainWindow::on_spinBox_sampleRate_valueChanged(int arg1)
{
    sample=arg1*1000;
}

void MainWindow::on_butto_readGain_clicked()
{
    if(serial->isOpen())
    {
        //Write 0x24 0x80 0x00 0x00 0x00 0xFF to enable TEC

       QByteArray array;
       array.append(0x24);
       array.append(0x80);
       array.append('\0');
       array.append('\0');
       array.append('\0');
       array.append(0xFF);

       serial->write(array, array.size());

       state= gain;

    }
}

void MainWindow::on_button_readKI_clicked()
{
    if(serial->isOpen())
    {
        //Write 0x24 0x80 0x00 0x00 0x00 0xFF to enable TEC

       QByteArray array;
       array.append(0x24);
       array.append(0x80);
       array.append(0x01);
       array.append('\0');
       array.append('\0');
       array.append(0xFF);

       serial->write(array, array.size());

       state= interg;

    }
}

void MainWindow::on_button_readW_clicked()
{
    if(serial->isOpen())
    {
        //Write 0x24 0x80 0x00 0x00 0x00 0xFF to enable TEC

       QByteArray array;
       array.append(0x24);
       array.append(0x80);
       array.append(0x02);
       array.append('\0');
       array.append('\0');
       array.append(0xFF);

       serial->write(array, array.size());

       state= windup;

    }

}

void MainWindow::on_readC_plus_clicked()
{


    if(serial->isOpen())
    {
        //Write 0x24 0x80 0x00 0x00 0x00 0xFF to enable TEC

       QByteArray array;
       array.append(0x24);
       array.append(0x80);
       array.append(0x03);
       array.append('\0');
       array.append('\0');
       array.append(0xFF);

       serial->write(array, array.size());

       state= currentp;

    }

}

void MainWindow::on_button_readC_N_clicked()
{

    if(serial->isOpen())
    {
        //Write 0x24 0x80 0x00 0x00 0x00 0xFF to enable TEC

       QByteArray array;
       array.append(0x24);
       array.append(0x80);
       array.append(0x04);
       array.append('\0');
       array.append('\0');
       array.append(0xFF);

       serial->write(array, array.size());

       state= currentn;

    }
}

void MainWindow::on_pushButton_writegain_clicked()
{

    double gain= ui->spinBox_writegain->value();
    //setpoint= setpoint * 100;

    uint b;
    b= (uint) gain;

    qDebug() << "GAIN" << b;

    unsigned char LSB = b & 0x00FF;
    int MSB = b & 0xFF00;
    MSB = MSB >>8;
    MSB = (unsigned char) MSB;

    //write 0x24 0x10 0x00 tempMSB tempLSB 0xFF

    QByteArray array;
    array.append(0x24);
    array.append(0x30);
    array.append('\0');
    array.append(MSB);
    array.append(LSB);
    array.append(0xFF);


     serial->write(array, array.size());

     //state=gain;

}
