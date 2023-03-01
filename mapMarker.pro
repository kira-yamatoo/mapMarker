#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T23:10:38
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mapMarker
TEMPLATE = app


SOURCES += main.cpp\
        MyPushButton.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    MyPushButton.h \
    connection.h

FORMS    += mainwindow.ui
