// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 4/12/13

#ifndef SIMULATORGUI_H
#define SIMULATORGUI_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "computer.h"

namespace Ui {
class SimulatorGui;
}

class SimulatorGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimulatorGui(QWidget *parent = 0);
    ~SimulatorGui();

signals:
    //tells computer a new file has been opened and send filename
    void newFileOpen( QString fileName );
    //tells computer step pushbutton has been pushed in gui
    void stepPushed();
    //tells computer run pushbutton has be pushed in gui
    void runPushed();
    //tells computer to reset button has been pushed
    void reset();
    //tells computer to clear instruction and data memory, program counter, and accumulator value
    void clear();
    //tells cache gui to remove all items
    void clearCacheGui();
    //gives computer new instruction input by user to gui an address to insert
    void newInstructionSignal(QString instruction, int location);
    //closes main window and cache window when system close is pressed in main window
    void closeAll();

public slots:
    //accepts set of instrctions from computer
    void acceptInstruction( QVariant &var );
    //accepts error from computer to display
    void inputErrorSlot( QString output);
    //accepts new accumulator value from computer to display
    void acceptNewAccumulatorValue( int value, int count );
    //accepts new memory value and displays in gui
    void acceptChangeMemoryData( int address, int value, int count );
    //accepts new program counter value
    void acceptNewPCValue( int count, int instructionNumber );
    //returns string to be output to standard output
    void acceptOutput( QString output, int count);
    //outputs an overflow error
    void acceptOverflow( QString item );
    //halts gui
    void acceptHaltSignal();


    //accepts data block from cache to be written to data memory
    void returnMemoryBlock(BlockData cacheOut );
    //accepts hit or miss value from cache
    void acceptSimGuiHitOrMiss( bool status );
    //removes red and green markings if cache is disabled
    void acceptCacheExit();

private slots:
    //opens file browser when open is triggered
    void on_actionOpen_triggered();
    //closes gui when exit is triggered
    void on_actionExit_triggered();
    //steps to next command when step is pushed
    void on_step_released();
    //runs all commands
    void on_run_released();
    //clears cache and data memory but keeps instructions
    void on_reset_released();
    //clears cache, data memory, and instruction memory
    void on_clear_released();
    //returns data changed in gui to instruction memory
    void on_instructionMemory_activated(const QModelIndex &index);

private:
    Ui::SimulatorGui *ui;
    //sets up instruction memory table and displays
    void createInstrutionMemoryTable();
    //creates instruction and data tables
    void createDataMemoryTable();
    //opens file
    void openFile();
    //loads file
    void loadFile(const QString &fileName);
    //sets current file to m_FileName
    void setCurrentFile(const QString &fileName);
    //sets default values in gui
    void defaultValues();
    //highlights next command
    void nextCommand();
    //prints initial instructions memory values
    void initialInstructionMemoryValues( QVariant data );
    //prints initial data memory values
    void initialDataMemoryValues();
    //reimplemets the close event so system closing the main window will close the cache
    void closeEvent(QCloseEvent *event);


    //number of current instruction
    int currentInstruction;
    //instruction memory table template
    QStandardItemModel *instructionMemory;
    //data memory table template
    QStandardItemModel *dataMemory;
    //current filename
    QString m_FileName;
};

#endif
