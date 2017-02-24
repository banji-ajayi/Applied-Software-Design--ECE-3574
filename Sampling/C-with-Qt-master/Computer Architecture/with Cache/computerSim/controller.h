// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 4/12/13

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "computer.h"
#include "datamemorycachegui.h"
#include "simulatorgui.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    //makes all connections between signals and slots
    void init();

public slots:
    //closes main window and cache window when system close is pressed in main window
    void acceptCloseAll();

private:
    //instance of computer class
    Computer myComputer;
    //instance of data memory cache gui
    DataMemoryCacheGui cacheGui;
    //instance of simulatorgui
    SimulatorGui simGui;
};

#endif // CONTROLLER_H
