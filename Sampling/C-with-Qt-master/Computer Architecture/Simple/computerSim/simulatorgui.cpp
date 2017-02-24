// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 3/22/13

#include "simulatorgui.h"
#include "ui_simulatorgui.h"
#include<QtGui>

SimulatorGui::SimulatorGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimulatorGui)
{
    ui->setupUi(this);

    createInstrutionMemoryTable();

    createDataMemoryTable();

    connectSignalsAndSlots();

    currentInstruction = 0;

    //disables buttons until file is loaded
    ui->step->setEnabled( false );
    ui->run->setEnabled( false );
}

void SimulatorGui::createInstrutionMemoryTable()
{
    ui->programCounter->display( 0 );

    //creates Instruction Memory Table:  128 Rows and 1 Columns
    instructionMemory = new QStandardItemModel(128,1,this);
    instructionMemory->setHorizontalHeaderItem(0, new QStandardItem(QString("Instruction")));
    //sets row count in instruction memory to 0-127
    QStringList rowCount;
    for( int i = 0; i <128; i++)
    {
       QString tempVar;
       tempVar.setNum( i );
        rowCount.append( tempVar );
    }
    instructionMemory->setVerticalHeaderLabels( rowCount );

    //allows columns to adjust with size of window
    ui->instructionMemory->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    //display Instruction Memory Table
    ui->instructionMemory->setModel(instructionMemory);

}

//creates instruction and data memory tables
void SimulatorGui::createDataMemoryTable()
{
    //creates Data Memory Table: 512 Rows and 2 Columns
    dataMemory = new QStandardItemModel(512,2,this);
    dataMemory->setHorizontalHeaderItem(0, new QStandardItem(QString("Address")));
    dataMemory->setHorizontalHeaderItem(1, new QStandardItem(QString("Value")));

    //allows columns to adjust with size of window
    ui->dataMemory->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    QStringList rowCount;

    //sets row count in data memory to 0-511
    for( int i = 0; i <512; i++)
    {
       QString tempVar;
       tempVar.setNum( i );
        rowCount.append( tempVar );
    }
    dataMemory->setVerticalHeaderLabels( rowCount );

    //display Instruction Memory Table
    ui->dataMemory->setModel(dataMemory);

}

//connects all signales and slots
void SimulatorGui::connectSignalsAndSlots()
{
    //sends current filename from the gui to computer
    connect( this, SIGNAL( newFileOpen( QString ) ), &myComputer, SLOT( initialize(QString) ) );
    //sends instructions from file to gui
    connect( &myComputer, SIGNAL( returnInstruction(QVariant&) ), this, SLOT( acceptInstruction(QVariant&) ));
    // gui tells computer that step pushbutton has be pushed
    connect( this, SIGNAL( stepPushed() ), &myComputer, SLOT( stepPushedSlot() ));
    //sends error message to gui to be printed to standard output
    connect( &myComputer, SIGNAL(inputError(QString)), this, SLOT(inputErrorSlot(QString)));
    //sends gui new accumulator and program counter values to be displayed
    connect( &myComputer, SIGNAL(newAccumulatorValue(int, int)), this, SLOT(acceptNewAccumulatorValue(int, int)));
    //sends change of memory address value and program counter to gui
    connect( &myComputer, SIGNAL(changeMemoryData(int,int, int)), this, SLOT(acceptChangeMemoryData(int,int, int)));
    //sends new accumulator value and program counter to gui
    connect( &myComputer, SIGNAL(loadNewAccumulatorValue(int, int)), this, SLOT(acceptNewAccumulatorValue(int, int)));
    //sends new accumulator value and program counter to gui
    connect( &myComputer, SIGNAL(addSignal(int, int)), this, SLOT(acceptNewAccumulatorValue(int,int)) );
    //sends new program counter value to gui
    connect( &myComputer, SIGNAL(newProgramCounterValueSignal(int, int)), this, SLOT(acceptNewPCValue(int,int)));
    //sends message to gui standard output
    connect( &myComputer, SIGNAL(standardOutput(QString, int)), this,SLOT(acceptOutput(QString, int)));
    //handles overflow errors of accumulator
    connect( &myComputer, SIGNAL(overFlow(QString)), this, SLOT(acceptOverflow(QString)));
    //halts program
    connect( &myComputer, SIGNAL(haltSignal()), this, SLOT(acceptHaltSignal()));
    //runs entire program
    connect( this, SIGNAL(runPushed()), &myComputer, SLOT(runPushedSlot()));
}

//destructor
SimulatorGui::~SimulatorGui()
{
    delete ui;
}

//when open pushed
void SimulatorGui::on_actionOpen_triggered()
{
    openFile();
}

//opens file
void SimulatorGui::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
    {
        loadFile(fileName);
    }
}

//loads file
void SimulatorGui::loadFile(const QString &fileName)
{

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Mian Window"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return;
    }

    setCurrentFile(fileName);

    statusBar()->showMessage(tr("File loaded"), 2000);
}

//sets name of file being used as current file m_FileName
void SimulatorGui::setCurrentFile(const QString &fileName)
{
    m_FileName = fileName;

    //clears previous files gui
    ui->programCounter->display( 0 );


    emit newFileOpen( m_FileName );
}

void SimulatorGui::on_actionExit_triggered()
{
    qApp->quit();
}

//accepts instruction file and outputs it to gui with deafault data memory values
void SimulatorGui::acceptInstruction( QVariant &var )
{
    //clears previous files data and restores defaults
    defaultValues();

    //displays initial values of instruction memory
    initialInstructionMemoryValues( var );

    //displays initial values of data memory
    initialDataMemoryValues();

}

//steps to next command when step is pushed
void SimulatorGui::on_step_released()
{
    emit stepPushed();
}

//displays error given from computer in gui
void SimulatorGui::inputErrorSlot( QString output)
{
    //clears any previous error input
    ui->standardOutput->clear();

    output += " is an invalid input";

    //ouputs error from invalid input
    ui->standardOutput->insertPlainText( output );

    //stops program after bad input
    acceptHaltSignal();
}

//outputs new accumulator value from addv
void SimulatorGui::acceptNewAccumulatorValue( int value, int count )
{
    ui->accumulator->clear();
    nextCommand();

    //converts value for output
    QString output;
    output.setNum( value );

    //outputs
    ui->accumulator->insertPlainText( output );
    ui->programCounter->display( count );

}

//changes value of memory address when from save
void SimulatorGui::acceptChangeMemoryData( int address, int value, int count )
{
    nextCommand();

    //converts value for output
    QString output;
    output.setNum( value );

    //outputs
    QStandardItem *addressValue = new QStandardItem( output );
    dataMemory->setItem( address, 1, addressValue );
    ui->programCounter->display( count );


    QModelIndex index = dataMemory->index( address, 1 );
    ui->dataMemory->setCurrentIndex( index );

}

//gives program counter a new value
void SimulatorGui::acceptNewPCValue( int count, int instructionNumber )
{
    ui->programCounter->display( count );

    //moves highlight to given instruction number
    instructionMemory->setData(instructionMemory->index(( currentInstruction ),0), Qt::white, Qt::BackgroundRole);
    currentInstruction = instructionNumber;
    nextCommand();
}

//returns string to be output to standard output
void SimulatorGui::acceptOutput( QString output, int count)
{
    nextCommand();
    //clears any previous error input
    ui->standardOutput->clear();

    //ouput
    ui->standardOutput->insertPlainText( output );
    ui->programCounter->display( count );
}

//stop program if accumulator or memory address is overflown
void SimulatorGui::acceptOverflow( QString item )
{
    //outputs overflow error to standard out
    ui->standardOutput->clear();
    ui->standardOutput->insertPlainText( item + " overflow" );

    //stops program
    acceptHaltSignal();
}

//stops program on bad command or halt
void SimulatorGui::acceptHaltSignal()
{
    QModelIndex index = instructionMemory->index( currentInstruction - 1, 1 );
    ui->instructionMemory->setCurrentIndex( index );
    ui->step->setEnabled( false );
    ui->run->setEnabled( false );
}

//sets default values of variables when file is loaded
void SimulatorGui::defaultValues()
{
    instructionMemory->takeColumn( 0 );
    instructionMemory->setHorizontalHeaderItem(0, new QStandardItem(QString("Instruction")));
    ui->instructionMemory->setModel( instructionMemory );

    instructionMemory->setData(instructionMemory->index(( currentInstruction ),0), Qt::white, Qt::BackgroundRole);
    ui->accumulator->clear();
    ui->accumulator->append("0");
    ui->standardOutput->clear();
    currentInstruction = 0;
    ui->step->setEnabled( true );
    ui->run->setEnabled( true );

}

//highlights next command
void SimulatorGui::nextCommand()
{
    currentInstruction++;

    QModelIndex index = instructionMemory->index(currentInstruction, 0);
    ui->instructionMemory->setCurrentIndex( index );

    //removes highlight from previous instruction
    instructionMemory->setData(instructionMemory->index(( currentInstruction - 1 ),0), Qt::white, Qt::BackgroundRole);
    //highlights current instruction
    instructionMemory->setData(instructionMemory->index(currentInstruction,0), Qt::yellow, Qt::BackgroundRole);
}

//sends signal to computer that run has been pushed
void SimulatorGui::on_run_released()
{
    emit runPushed();
}

//prints initial instructions memory values
void SimulatorGui::initialInstructionMemoryValues(QVariant data)
{
    QStringList output = data.toStringList();

    //outputs instructions to gui
    for( int i = 0; i < 128 && i < output.size(); i++)
    {
        QStandardItem *insert = new QStandardItem( output[i] );

        if( i == 0 )
        {
            instructionMemory->setItem( i, 0, insert );

            //highlights current instruction
            instructionMemory->setData(instructionMemory->index(i,0), Qt::yellow, Qt::BackgroundRole );
            QModelIndex index = instructionMemory->index(currentInstruction, 0);
            ui->instructionMemory->setCurrentIndex( index );
        }

        else
        {
            instructionMemory->setItem( i, 0, insert );
        }
    }

    ui->instructionMemory->setModel(instructionMemory);
}

void SimulatorGui::initialDataMemoryValues()
{
    //outputs default data memory values to gui
    for( int i = 0; i < 512; i++ )
    {
        //sets default memory values
        QStandardItem *dataValue = new QStandardItem( "0" );
        dataMemory->setItem( i, 1, dataValue );

        //sets precision to 3 for addresses
        if( i < 16 )
        {
            QStandardItem *address = new QStandardItem( "0x00" + QString::number( i, 16 ).toUpper() );
            dataMemory->setItem( i, 0, address );
        }
        else if( i < 256 )
        {
            QStandardItem *address = new QStandardItem( "0x0" + QString::number( i, 16 ).toUpper() );
            dataMemory->setItem( i, 0, address );
        }
        else
        {
            QStandardItem *address = new QStandardItem( "0x" + QString::number( i, 16 ).toUpper() );
            dataMemory->setItem( i, 0, address );
        }
    }

    //displays data memory
    ui->dataMemory->setModel( ( dataMemory ) );
}
