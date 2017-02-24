// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 4/12/13

#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QStringList>
#include <QtGui>
#include <QMap>
#include <cmath>

//data for cache
struct BlockData
{
    //data stores in cache block
    QVector<int> data;
    //blocks tag
    QString tag;
    //key value
    QString key;
    //row value
    QString rowValue;
    //number of times block has been used
    int hitCount;
    //if a value has been changed
    bool dirtyBit;
    //beginning of memory block address
    int startAddress;
    //end of memory block address
    int endAddress;
};

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


    //sends gui new cache entry to be inserted
    void newCacheData( QMap<QString, BlockData> theCache );
    //sends memory block from cache to be displayed in data memory
    void returnMemoryBlock( BlockData cacheOut );
    //tells cache gui there was a hit
    void cacheGuiHitOrMiss( bool status );
    //tells main gui there was a hit
    void simGuiHitOrMiss( bool status );
    //when new file is opened cache table is cleared
    void clearCacheTable();


public slots:
    //receives filename and sends initial data to gui
    void initialize( QString fileName );
    //performs next operation and returns results to gui
    void stepPushedSlot();
    //performs all operations and returns result to gui
    void runPushedSlot();
    //resets program counter, accumulator value, and data memory values
    void acceptReset();
    //clears data and instruction memory, accumulator value, and program counter
    void acceptClear();
    //inputs new instruction from gui into instruction memory
    void acceptNewInstruction(QString newInstruction, int location);
    //flushes cache to data memory and disables caching
    void acceptCacheOff();


    //takes in the size of the block and converts to tag size
    void acceptCacheEnable( int cacheSize, int numberOfBlocks, int blockSizeGiven, bool cacheStatus );

private:
    //cache
    QMap<QString, BlockData> cache;


    //data memory
    int dataMemory[512];
    //instruction memory
    QVector<QString> instructionMemory;


    //current instuctions location
    int currentInstructionNumber;
    //current instruction
    QString instruction;
    //accumulators current value
    int accumulatorValue;
    //counts number of instructions ran
    int programCounter;
    //if error has occurred
    bool error;


    //tells computer if cache is being used
    bool cacheActivated;
    //sets number of row bits
    int rowBits;
    //sets number of column bits
    int columnBits;
    //sets block size
    int blockSize;
    //number of blocks allowed in cache
    int maxBlocksAllowed;
    //location of data to be changed
    int dataToBeChanged;
    //start point of block
    int startPoint;
    //end point of block
    int endPoint;
    //data block currently being used
    BlockData currentBlock;


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
    //takes accumulator value, finds value at that address, and load to acccumulator
    void loada();
    //takes given address, gets value there, converts to a hex address, and stores
    //the accumulator value there
    void storea( QString memoryAddress );


    //stores data from accumulator into cache
    void cacheStore( int address );
    //loads value from  cache into accumulator
    void cacheLoad( int address );
    //inserts items into the cache
    void insert( BlockData newData );
    //gets initial values for cache operations
    void getInitialValues( int address );
    //adds item fom given address in cache to accumulator value
    void cacheAdd( int address );
    //takes accumulator value, finds value at that address, and load to acccumulator from cache
    void cacheLoada( int address );
    //takes given address, gets value there, converts to a hex address, and stores
    //the accumulator value there in cache
    void cacheStorea( int address );
    //flushes cache to data memory when incorrect command or halt if called
    void flushCache();

};

#endif // COMPUTER_H
