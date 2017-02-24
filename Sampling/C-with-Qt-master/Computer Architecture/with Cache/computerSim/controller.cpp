// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 4/12/13

#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
}

//makes all connections between signals and slots
void Controller::init()
{
    //sends current filename from the gui to computer
    connect( &simGui, SIGNAL( newFileOpen( QString ) ), &myComputer, SLOT( initialize(QString) ) );
    //sends instructions from file to gui
    connect( &myComputer, SIGNAL( returnInstruction(QVariant&) ), &simGui, SLOT( acceptInstruction(QVariant&) ));
    // gui tells computer that step pushbutton has be pushed
    connect( &simGui, SIGNAL( stepPushed() ), &myComputer, SLOT( stepPushedSlot() ));
    //sends error message to gui to be printed to standard output
    connect( &myComputer, SIGNAL(inputError(QString)), &simGui, SLOT(inputErrorSlot(QString)));
    //sends gui new accumulator and program counter values to be displayed
    connect( &myComputer, SIGNAL(newAccumulatorValue(int, int)), &simGui, SLOT(acceptNewAccumulatorValue(int, int)));
    //sends change of memory address value and program counter to gui
    connect( &myComputer, SIGNAL(changeMemoryData(int,int, int)), &simGui, SLOT(acceptChangeMemoryData(int,int, int)));
    //sends new accumulator value and program counter to gui
    connect( &myComputer, SIGNAL(loadNewAccumulatorValue(int, int)), &simGui, SLOT(acceptNewAccumulatorValue(int, int)));
    //sends new accumulator value and program counter to gui
    connect( &myComputer, SIGNAL(addSignal(int, int)), &simGui, SLOT(acceptNewAccumulatorValue(int,int)) );
    //sends new program counter value to gui
    connect( &myComputer, SIGNAL(newProgramCounterValueSignal(int, int)), &simGui, SLOT(acceptNewPCValue(int,int)));
    //sends message to gui standard output
    connect( &myComputer, SIGNAL(standardOutput(QString, int)), &simGui,SLOT(acceptOutput(QString, int)));
    //handles overflow errors of accumulator
    connect( &myComputer, SIGNAL(overFlow(QString)), &simGui, SLOT(acceptOverflow(QString)));
    //halts program
    connect( &myComputer, SIGNAL(haltSignal()), &simGui, SLOT(acceptHaltSignal()));
    //runs entire program
    connect( &simGui, SIGNAL(runPushed()), &myComputer, SLOT(runPushedSlot()));
    //sends signal to reset computer
    connect( &simGui, SIGNAL(reset()), &myComputer, SLOT(acceptReset()));
    //sends signal for computer to clear all values
    connect( &simGui, SIGNAL(clear()), &myComputer, SLOT(acceptClear()));
    //takes new instruction given by user in main window and sets it in instruction memory
    connect( &simGui, SIGNAL(newInstructionSignal(QString,int)), &myComputer, SLOT(acceptNewInstruction(QString,int)));


    //sends block size from data memory cachegui to computer
    connect( &cacheGui, SIGNAL(CacheEnabled(int,int,int,bool)), &myComputer, SLOT(acceptCacheEnable(int,int,int,bool)));
    //sends new data to be displayed in gui
    connect( &myComputer, SIGNAL(newCacheData(QMap<QString,BlockData>)), &cacheGui, SLOT(acceptNewCacheData(QMap<QString,BlockData>)));
    //sends data removed from cache to data memory
    connect(&myComputer, SIGNAL(returnMemoryBlock(BlockData)), &simGui, SLOT(returnMemoryBlock(BlockData)));
    //sends hit or miss signal from cache to cache gui
    connect(&myComputer, SIGNAL(cacheGuiHitOrMiss(bool)), &cacheGui, SLOT(acceptCacheGuiHitOrMiss(bool)));
    //sends hit or miss signal from cache to main window
    connect( &myComputer, SIGNAL(simGuiHitOrMiss(bool)), &simGui, SLOT(acceptSimGuiHitOrMiss(bool)));
    //clears cache gui when reset is pushed in main window
    connect( &simGui, SIGNAL(clearCacheGui()), &cacheGui, SLOT(acceptClearCacheGui()));
    //clears cache gui when new file is opened
    connect(&myComputer, SIGNAL(clearCacheTable()), &cacheGui, SLOT(acceptClearCacheGui()));\
    //closes cache window if main window is closed using system close
    connect( &simGui, SIGNAL(closeAll()), this, SLOT(acceptCloseAll()));
    //flushes cache and disables caching if cache window is closed
    connect(&cacheGui, SIGNAL(cacheOff()), &myComputer, SLOT(acceptCacheOff()));
    //clears red and green marking on main window if caching is disabled
    connect( &cacheGui, SIGNAL(cacheOff()), &simGui, SLOT(acceptCacheExit()));

    simGui.show();
    cacheGui.show();
}

//closes cache gui if main windows is closed
void Controller::acceptCloseAll()
{
    cacheGui.close();
}
