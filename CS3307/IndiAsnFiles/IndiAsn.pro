#-------------------------------------------------
#
# Project created by QtCreator 2013-09-18T14:36:49
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Asn1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    data.cpp \
    controller.cpp \
    interface.cpp

HEADERS  += mainwindow.h \
    data.h \
    controller.h \
    interface.h

FORMS    += mainwindow.ui
