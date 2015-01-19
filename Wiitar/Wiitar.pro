#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T11:50:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlayMidiNote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chord.cpp \
    chordmanager.cpp

HEADERS  += mainwindow.h \
    chord.h \
    chordmanager.h

FORMS    += mainwindow.ui
include(../drumstick/drumstick.pro)
