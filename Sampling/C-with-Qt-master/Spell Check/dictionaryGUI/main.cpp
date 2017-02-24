// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 3
// 2/26/13

#include <QtGui/QApplication>
#include "mainWindow.h"
#include"Dictionary.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
