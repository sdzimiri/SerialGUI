 #include "linechart.h"
#include "ui_linechart.h"
#include "mainwindow.h"

using namespace QtCharts;
linechart::linechart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::linechart)
{
    ui->setupUi(this);

    series = new QLineSeries();
    secondseries = new QLineSeries();
    thirdseries = new QLineSeries();
    fourthseries = new QLineSeries();

}
void linechart::addTempData(double t1, double t2, double t3, double tectemp, int time )
{

    temp1Arr.enqueue(t1);
    temp2Arr.enqueue(t2);
    temp3Arr.enqueue(t3);
    tempTecArr.enqueue(tectemp);
    timeArr.enqueue(time);




    if(temp1Arr.length() > WINDOW_SIZE)
    {
        temp1Arr.dequeue();
        temp2Arr.dequeue();
        temp3Arr.dequeue();
        tempTecArr.dequeue();
        timeArr.dequeue();
    }

    //Update series
    series->clear();
    secondseries->clear();
    thirdseries->clear();
    fourthseries->clear();

    for(int i =0; i< temp1Arr.length(); i++)
    {
        series->append(timeArr.at(i), temp1Arr.at(i));
    }
    for (int i =0;i<temp2Arr.length();i++)
    {
        secondseries->append(timeArr.at(i), temp2Arr.at(i));
    }
    for(int i =0; i < temp3Arr.length(); i++)
    {
        thirdseries->append(timeArr.at(i), temp3Arr.at(i));
    }
    for(int i=0; i < tempTecArr.length(); i++)
    {
        fourthseries->append(timeArr.at(i), tempTecArr.at(i));
    }

    //Set up DAQ Chart
     QChart *ch = new QChart();
     //ch->legend()->hide();
     ch->addSeries(series);
     ch->addSeries(secondseries);
     ch->addSeries(thirdseries);
     ch->addSeries(fourthseries);
     ch->createDefaultAxes();
     ch->setTitle("Temperatures");

     ui->chartView->setChart(ch);

}

linechart::~linechart()
{
    delete ui;
}
