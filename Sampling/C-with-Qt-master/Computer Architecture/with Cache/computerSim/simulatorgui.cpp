// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 4/12/13

#include "simulatorgui.h"
#include "ui_simulatorgui.h"
#include<QtGui>

//constructor
SimulatorGui::SimulatorGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimulatorGui)
{
    ui->setupUi(this);

    //sets up tables
    createInstrutionMemoryTable();
    createDataMemoryTable();
    currentInstruction = 0;

    //disables buttons until file is loaded
    ui->step->setEnabled( false );
    ui->run->setEnabled( false );
    ui->reset->setEnabled( false );
    ui->clear->setEnabled( false );
}

//sets up instruction memory table and displays
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

    //makes all rows in instruction memory white
    for( int i = 0; i < 128; i++ )
    {
        instructionMemory->setData(instructionMemory->index(i,0), Qt::white, Qt::BackgroundRole);
    }

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
    //emit clearCacheGui();
}

//closes gui when exit is triggered
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
    //ui->standardOutput->clear();

    output += " is an invalid input";

    //ouputs error from invalid input
    ui->standardOutput->insertPlainText( output + '\n' );

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

    //takes gui to changed memory location
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

    //ouput
    ui->standardOutput->insertPlainText( output + '\n' );
    ui->programCounter->display( count );
}

//stop program if accumulator or memory address is overflown
void SimulatorGui::acceptOverflow( QString item )
{
    //outputs overflow error to standard out
    ui->standardOutput->insertPlainText( item + " overflow\n");

    //stops program
    acceptHaltSignal();
}

//stops program on bad command or halt
void SimulatorGui::acceptHaltSignal()
{
    QModelIndex index = instructionMemory->index( currentInstruction - 1, 1 );
    ui->instructionMemory->setCurrentIndex( index );
    instructionMemory->setData(instructionMemory->index(( currentInstruction ),0), Qt::yellow, Qt::BackgroundRole);
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
    ui->reset->setEnabled( true );
    ui->clear->setEnabled( true );
}

//highlights next command
void SimulatorGui::nextCommand()
{
    currentInstruction++;

    QModelIndex index = instructionMemory->index(currentInstruction, 0);
    ui->instructionMemory->setCurrentIndex( index );
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

//prints initial data memory values
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

//clears cache and data memory but keeps instructions
void SimulatorGui::on_reset_released()
{
    //resets accumulator
    ui->accumulator->clear();
    ui->accumulator->setPlainText( "0");

    //reset program counter
    ui->programCounter->display( 0 );

    //resets data memory values
    initialDataMemoryValues();

    //resets standard output
    ui->standardOutput->clear();

    //starts at instruction 0 and clear previous coloring
    instructionMemory->setData(instructionMemory->index(currentInstruction,0), Qt::white, Qt::BackgroundRole);
    currentInstruction = -1;
    for( int i = 0; i < 128; i ++ )
    {
        instructionMemory->setData(instructionMemory->index(i,0), Qt::white, Qt::BackgroundRole);
    }
    ui->step->setEnabled( true );
    ui->run->setEnabled( true );

    nextCommand();

    emit reset();
    emit clearCacheGui();
}

//clears gui and computer of data and instruction memory, program counter, and accumulator values
void SimulatorGui::on_clear_released()
{
    //resets accumulator
    ui->accumulator->clear();
    ui->accumulator->setPlainText("0");

    //reset program counter
    ui->programCounter->display( 0 );

    //resets data memory values
    initialDataMemoryValues();

    //resets standard output
    ui->standardOutput->clear();

    //starts at instruction 0
    instructionMemory->setData(instructionMemory->index(currentInstruction,0), Qt::white, Qt::BackgroundRole);
    currentInstruction = 0;

    //clears
    createInstrutionMemoryTable();

    emit clear();
    emit clearCacheGui();
}

//displays values from cache in data memory
void SimulatorGui::returnMemoryBlock( BlockData cacheOut )
{
    QString output;

    //outputs data
    for( int i = 0; cacheOut.startAddress < cacheOut.endAddress; i++, cacheOut.startAddress++ )
    {
        output.setNum( cacheOut.data[i] );
        dataMemory->setItem( cacheOut.startAddress, 1, new QStandardItem( output ) );
    }

    //sets index to last changed data memory location
    QModelIndex index = dataMemory->index(cacheOut.endAddress , 1 );
    ui->dataMemory->setCurrentIndex( index );
}

//accepts hit or miss value from cache
void SimulatorGui::acceptSimGuiHitOrMiss( bool status )
{
    if( status )
    {
        //highlight cache hit green
        instructionMemory->setData(instructionMemory->index(( currentInstruction ),0), Qt::green, Qt::BackgroundRole);
    }
    else if( !status )
    {
        //highlight cache miss red
        instructionMemory->setData(instructionMemory->index(( currentInstruction ),0), Qt::red, Qt::BackgroundRole);
    }
}

//returns data changed in gui to instruction memory
void SimulatorGui::on_instructionMemory_activated(const QModelIndex &index)
{
    //gets new instruction entered
    QString newInstruction = index.data().toString();

    //gets address of new instruction
    int row = index.row();

    emit newInstructionSignal(newInstruction, row);

}

//reimplemets the close event so system closing the main window will close the cache
void SimulatorGui::closeEvent(QCloseEvent *event)
{
    emit closeAll();
}

//removes red and green markings if cache is disabled
void SimulatorGui::acceptCacheExit()
{
    //makes all rows in instruction memory white
    for( int i = 0; i < 128; i++ )
    {
        instructionMemory->setData(instructionMemory->index(i,0), Qt::white, Qt::BackgroundRole);
    }
}
