#-------------------------------------------------
#
# Project created by QtCreator 2015-09-10T10:17:57
#
#-------------------------------------------------

QT       += core gui

TARGET = GPSMapDemo
TEMPLATE = app

include(GPSMapManager/GPSMapManager.pri)
SOURCES += main.cpp\
        mainwindow.cpp \
    mappanel.cpp

HEADERS  += mainwindow.h \
    mappanel.h

FORMS    += mainwindow.ui
