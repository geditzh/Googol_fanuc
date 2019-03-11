#-------------------------------------------------
#
# Project created by QtCreator 2018-08-08T18:32:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = googol
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    AssemblyRobot.cpp

HEADERS  += mainwindow.h \
    AssemblyRobot.h \
    RobotDefine.h

FORMS    += mainwindow.ui

LIBS += -LC:\Users\df\Desktop\Googol_fanuc\googol -lgts
LIBS += -LC:\Users\df\Desktop\Googol_fanuc\googol -lExtMdl
