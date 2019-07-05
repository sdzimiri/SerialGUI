/********************************************************************************
** Form generated from reading UI file 'linechart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINECHART_H
#define UI_LINECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_linechart
{
public:
    QDialogButtonBox *buttonBox;
    QChartView *chartView;

    void setupUi(QDialog *linechart)
    {
        if (linechart->objectName().isEmpty())
            linechart->setObjectName(QString::fromUtf8("linechart"));
        linechart->resize(680, 450);
        buttonBox = new QDialogButtonBox(linechart);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(330, 410, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        chartView = new QChartView(linechart);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        chartView->setGeometry(QRect(10, 10, 661, 391));

        retranslateUi(linechart);
        QObject::connect(buttonBox, SIGNAL(accepted()), linechart, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), linechart, SLOT(reject()));

        QMetaObject::connectSlotsByName(linechart);
    } // setupUi

    void retranslateUi(QDialog *linechart)
    {
        linechart->setWindowTitle(QApplication::translate("linechart", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class linechart: public Ui_linechart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINECHART_H
