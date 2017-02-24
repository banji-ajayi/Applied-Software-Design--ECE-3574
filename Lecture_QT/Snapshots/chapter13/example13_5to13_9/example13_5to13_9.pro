#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T22:37:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = example13_5to13_9
TEMPLATE = app

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0

SOURCES += main.cpp\
        mainwindow.cpp \
    metadata.cpp \
    metadatafactory.cpp \
    objtostring.cpp \
    playlistsview.cpp \
    playlistview.cpp \
    metadatatablemodel.cpp \
    sourcelistmodel.cpp \
    stardelegate.cpp \
    starrating.cpp \
    stareditor.cpp \
    timedisplay.cpp

HEADERS  += mainwindow.h \
    metadata.h \
    metadatafactory.h \
    objtostring.h \
    playlistsview.h \
    playlistview.h \
    sourcelistmodel.h \
    metadatatablemodel.h \
    stardelegate.h \
    stareditor.h \
    starrating.h \
    timedisplay.h

FORMS    += mainwindow.ui

RESOURCES += \
    ../icons/icons.qrc
