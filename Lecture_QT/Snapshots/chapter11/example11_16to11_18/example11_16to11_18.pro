QT += core
QT -= gui

TARGET = example11_16to11_18
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    sstring.cpp \
    mystring.cpp

HEADERS += \
    sstring.h \
    stringdata.h \
    mystring.h

