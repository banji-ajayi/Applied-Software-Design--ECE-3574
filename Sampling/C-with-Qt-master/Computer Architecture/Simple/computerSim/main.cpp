// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 3/22/13

#include <QtGui/QApplication>
#include "simulatorgui.h"
#include "computer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimulatorGui w;
    Computer myComputer;
    //QObject::connect( &w, SIGNAL( newFileOpen( QString ) ), &myComputer, SLOT( initialize() ) );
    w.show();
    
    return a.exec();
}
