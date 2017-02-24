////////////////////////////////////////////////////////
// ECE 3574, Homework 6, Bowei Zhao
//// ID: 905789193
// email: bowei@vt.edu
// File name: matrix-multiply.h
// Description: header file
// Date: 4/20/2016

//
// *-----------------------------------------------* //

#ifndef MATRIX_H
#define MATRIX_H

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
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
#include <QFile>
#include <QRegExp>
#include <QRegularExpression>

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
#include <fcntl.h>

using namespace std;

typedef QList<QStringList> defMat;

extern defMat matrix1, matrix2, matrix3;

struct Mat_Struct
{
	QString M_FileName;
	QString M_ID;
	int M_row;
	int M_col;
};

extern struct Mat_Struct sMatrix1, sMatrix2, sMatrix3;

extern QFile inputFile1, inputFile2, outFile, tempFiles;


int StartupErrorCheck(int &argc, QStringList arginput);
int TotalMatrixCheck(defMat checkM1, defMat checkM2);
void *InitFileManip(void *IVar);
void *MatrixMultiplication(void *ElmPos);



#endif // MATRIX_H