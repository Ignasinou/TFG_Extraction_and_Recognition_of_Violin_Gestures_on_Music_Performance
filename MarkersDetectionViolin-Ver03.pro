#-------------------------------------------------
#
# Project created by QtCreator 2018-03-14T17:02:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MarkersDetectionViolin-Ver03
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    markers.cpp \
    colordetection.cpp \
    choosingAndTrack.cpp \
    utilsgesturerecognition.cpp

HEADERS += \
        mainwindow.h \
    markers.h \
    colordetection.h \
    choosingAndTrack.h \
    utilsgesturerecognition.h

FORMS += \
        mainwindow.ui \
    markers.ui \
    colordetection.ui \
    choosingAndTrack.ui \
    utilsgesturerecognition.ui

LIBS += -L/usr/local/Cellar/opencv/3.4.1_1/lib/
LIBS += -L/usr/local/lib/

# The following lines tells Qmake to use pkg-config for opencv
QT_CONFIG -= no-pkg-config
CONFIG  += link_pkgconfig
PKGCONFIG += opencv
