#-------------------------------------------------
#
# Project created by QtCreator 2019-05-15T13:29:57
#
#-------------------------------------------------

QT       += core gui serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        daqcontrol.cpp \
        linechart.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        ../../../../Program Files (x86)/National Instruments/NI-DAQ/DAQmx ANSI C Dev/include/NIDAQmx.h \
        ../../../../Program Files (x86)/National Instruments/NI-DAQ/DAQmx ANSI C Dev/include/NIDAQmx.h \
        daqcontrol.h \
        linechart.h \
        mainwindow.h

FORMS += \
        linechart.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/'../../../../Program Files (x86)/National Instruments/NI-DAQ/DAQmx ANSI C Dev/lib/msvc/' -lNIDAQmx

INCLUDEPATH += $$PWD/'../../../../Program Files (x86)/National Instruments/NI-DAQ/DAQmx ANSI C Dev/include'
DEPENDPATH += $$PWD/'../../../../Program Files (x86)/National Instruments/NI-DAQ/DAQmx ANSI C Dev/include'
