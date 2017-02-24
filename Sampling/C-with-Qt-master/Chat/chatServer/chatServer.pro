#-------------------------------------------------
#
# Project created by QtCreator 2013-04-11T18:13:15
#
#-------------------------------------------------

QT       += core gui

TARGET = chatServer
TEMPLATE = app


SOURCES += main.cpp\
        chatserver.cpp \
    serverthread.cpp

HEADERS  += chatserver.h \
        serverthread.h\
    ../chatClient/message.h

FORMS    += chatserver.ui
