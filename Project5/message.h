////////////////////////////////////////////////////////
// ECE 3574, Homework 5, Bowei Zhao
//// ID: 905789193
// email: bowei@vt.edu
// File name: message.h
// Description: message header file
// Date: 4/09/2016

//
// *-----------------------------------------------* //

#ifndef MESSAGE_H
#define MESSAGE_H

#include <pthread.h>
#include <mqueue.h>
#include <errno.h>

#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QList>
#include <QDebug>
#include <QByteArray>
#include <QtGui>
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QCoreApplication>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>


#include <time.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;



int StartupErrorCheck(int &argc, QStringList arginput);

#endif // MESSAGE_H