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
    data.cpp \
    controller.cpp

HEADERS  += \
    data.h \
    controller.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    images/bright_sun_T.png

RESOURCES += \
    resources.qrc
