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
    chordmanager.cpp \
    wiiyourself/wiimote.cpp \
    WiiAnalyser.cpp \
    WiimoteThread.cpp \
    interface/accord.cpp \
    interface/dragwidget.cpp \
    interface/selection.cpp \
    interface/button.cpp

HEADERS  += mainwindow.h \
    chord.h \
    chordmanager.h \
    wiiyourself/wiimote.h \
    wiiyourself/wiimote_common.h \
    wiiyourself/wiimote_state.h \
    WiiAnalyser.h \
    WiimoteThread.h \
    interface/accord.h \
    interface/dragwidget.h \
    interface/selection.h \
    interface/button.h

FORMS    += mainwindow.ui
include(../drumstick/drumstick.pro)

RESOURCES += \
    images.qrc
