// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 3/22/13

#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QStringList>

class Computer : public QObject
{
    Q_OBJECT
public:
    explicit Computer(QObject *parent = 0);

signals:
    //sends instruction output back to gui to be displayed
    void returnInstruction( QVariant &var );
    //returns invalid instruction
    void inputError( QString error );
    //sends new accumulator value to gui
    void newAccumulatorValue( int value, int count );
    //sends new memory value with given address
    void changeMemoryData( int address, int value, int count );
    //loads new value into accumulator on load command
    void loadNewAccumulatorValue( int value, int count );
    //sends new accumulator value after add is called
    void addSignal( int value, int count );
    //sends program counter new value after bgtz is called
    void newProgramCounterValueSignal( int count, int instructionNumber );
    //outputs non errors to standard out
    void standardOutput( QString output, int count );
    //when 10-bit signed integer is out of range
    void overFlow( QString item );
    //halts program from running
    void haltSignal();

public slots:
    //receives filename and sends initial data to gui
    void initialize( QString fileName );
    //performs next operation and returns results to gui
    void stepPushedSlot();
    //performs all operations and returns result to gui
    void runPushedSlot();

private:
    //data memory
    int dataMemory[512];
    //instruction memory
    QString instructionMemory[128];

    //current instuctions location
    int currentInstructionNumber;
    //accumulators current value
    int accumulatorValue;
    //counts number of instructions ran
    int programCounter;
    //if error has occurred
    bool error;

    //takes given number and adds to accumulator value
    void addv( QString addend );
    //stores value of accumulator to given memory address
    void store( QString memoryAddress );
    //loads value from given memory address into accumulator
    void load( QString memoryAddress );
    //takes value from given memory address and adds it to the accumulator
    void add( QString memoryAddress );
    //changes accumulator value to given decimal number
    void bgtz( QString count );
    //increments counter program counter by one when nop is called
    void nop();
    //clears accumulator
    void clear();
    //outputs strings to the standard output
    void output( QString message );
    //stops program
    void halt();
};

#endif // COMPUTER_H
