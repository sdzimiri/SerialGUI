#ifndef LINECHART_H
#define LINECHART_H

#include <QDialog>
#include <QDebug>
#include <QQueue>
#include <QtCharts>

#define WINDOW_SIZE 150

namespace Ui {
class linechart;
}

class linechart : public QDialog
{
    Q_OBJECT

public:
    explicit linechart(QWidget *parent = nullptr);

     ~linechart();


public slots:
    void addTempData(double t1, double t2, double t3, double tectemp, int time );



private:
    Ui::linechart *ui;

    QQueue<int> timeArr;
    QQueue<double> temp1Arr;
    QQueue<double> temp2Arr;
    QQueue<double> temp3Arr;
    QQueue<double> tempTecArr;

    QLineSeries *series;
    QLineSeries *secondseries;
    QLineSeries *thirdseries;
    QLineSeries *fourthseries;


    QChart *chart;
    QChartView *chartView;

};

#endif // LINECHART_H
