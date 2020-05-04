#-------------------------------------------------
#
# Project created by QtCreator 2020-05-04T11:30:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Adapters
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../TableModel/TableModel.cpp \
    DataMapperWid.cpp

HEADERS  += mainwindow.h \
    ../TableModel/TableModel.h \
    DataMapperWid.h

FORMS    += mainwindow.ui \
    DataMapperWid.ui
