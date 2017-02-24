// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 3/22/13

#include<QtGui>

#include "computer.h"
#include "simulatorgui.h"

Computer::Computer(QObject *parent) :
    QObject(parent)
{
    //sets variables to 0 initially
    currentInstructionNumber = 0;
    accumulatorValue = 0;
    programCounter = 0;

    //sets initial memory values to 0
    for( int i = 0; i < 512; i++)
    {
        dataMemory[i] = 0;
    }

    error = false;

}

//receives filename and sends initial data to gui
void Computer::initialize(QString fileName)
{
    //sets defaults
    currentInstructionNumber = 0;
    accumulatorValue = 0;
    programCounter = 0;
    error = false;

    QFile file ( fileName );
    file.open( QIODevice::ReadOnly );
    QTextStream readFile( &file );

    QStringList temp;

    //gets instructions from file
    for(int i = 0; !readFile.atEnd() && i < 128; i++ )
    {
        instructionMemory[i] =readFile.readLine();

        temp.append( QString( instructionMemory[i] ) );
    }

    file.close();

    QVariant output = temp;

    //sets initial memory values to 0
    for( int i = 0; i < 512; i++)
    {
        dataMemory[i] = 0;
    }

    //outputs instructions to be displayed in gui
    emit returnInstruction( output );
}

//performs next operation and returns results to gui
void Computer::stepPushedSlot()
{
    //parses given data
    QStringList instructionAndData = instructionMemory[ currentInstructionNumber ].split(' ');
    QString instruction = QString( instructionAndData[0] ).toUpper();
    QString data;

    if( instruction == "OUT" )
    {
        QStringList instructionAndData = instructionMemory[ currentInstructionNumber ].split('"');

        //checks if data was given correctly
        if( instructionAndData.size() >=2 )
        {
            QString message = instructionAndData[1];
            output( message );
        }
        else
        {
            emit inputError( "" );
            error = true;
        }
    }

    else if( instructionAndData.size() == 1 )
    {
        if( instruction == "NOP" )
        {
            nop();
        }
        else if( instruction == "CLEAR" )
        {
            clear();
        }
        else if( instruction == "HALT" )
        {
            halt();
        }
        else
        {
            emit inputError( instruction );
            error = true;
        }
    }

    else if( instructionAndData.size() == 2 )
    {
        data = QString( instructionAndData[1] );

        //checks to see which command is to be run
        if( instruction == "LOAD" )
        {
            load( data );
        }

        else if( instruction == "STORE" )
        {
            store( data );
        }

        else if ( instruction == "ADDV" )
        {
            addv( data );
        }

        else if( instruction == "ADD" )
        {
            add( data );
        }
        else if( instruction == "BGTZ" )
        {
            bgtz( data );
        }
        else
        {
            emit inputError( instruction );
            error = true;
        }
    }
    else
    {
        emit inputError( instruction );
        error = true;
    }

    currentInstructionNumber++;
}

//adds given value to the accumulator
void Computer::addv( QString addend )
{
    //makes sure addend is a valid number
    if( addend.toInt() == 0 )
    {
        emit inputError( addend );
        error = true;

    }
    else
    {
        //checks that value does not overflows 10 bit signed integer
        if( accumulatorValue + addend.toInt() > 511 || accumulatorValue + addend.toInt() < -512 )
        {
            emit overFlow( "accumulator" );
            error = true;
        }
        else
        {
            accumulatorValue += addend.toInt();

            programCounter++;
            emit newAccumulatorValue( accumulatorValue, programCounter );
        }
    }
}

//stores value from accumulator into given hex address
void Computer::store( QString memoryAddress )
{
    //hexadecimal string to int
    bool ok;
    int memoryAddressDecimal = memoryAddress.toInt(&ok,16);

    //check that hex number is valid
    if( ok )
    {

        //checks that memory address is valid
        if( memoryAddressDecimal >= 0 && memoryAddressDecimal <=511 )
        {
            dataMemory[ memoryAddressDecimal ] = accumulatorValue;

            programCounter++;
            emit changeMemoryData( memoryAddressDecimal, accumulatorValue, programCounter );
        }
        else
        {
            emit inputError( memoryAddress );
            error = true;
        }
    }
    else
    {
        emit inputError( memoryAddress );
        error = true;
    }
}

//loads value from given address into accumulator
void Computer::load( QString memoryAddress )
{
    //hexadecimal string to int
    bool ok;
    int memoryAddressDecimal = memoryAddress.toInt(&ok,16);

    //checks hex number is valid
    if( ok )
    {
        //checks if memory address is valid
        if( memoryAddressDecimal >= 0 && memoryAddressDecimal <=511 )
        {
            accumulatorValue = dataMemory[ memoryAddressDecimal ];

            programCounter++;
            emit loadNewAccumulatorValue( accumulatorValue, programCounter );
        }
        else
        {
            emit inputError( memoryAddress );
            error = true;
        }
    }
    else
    {
        emit inputError( memoryAddress );
        error = true;
    }
}

//takes value from given memory address and adds it to the accumulator
void Computer::add( QString memoryAddress )
{
    //hexadecimal string to int
    bool ok;
    int memoryAddressDecimal = memoryAddress.toInt(&ok,16);

    if( ok )
    {

        //checks that memory address is valid
        if( memoryAddressDecimal >= 0 && memoryAddressDecimal <=511 )
        {
            //checks to make sure adding does not overflow accumulator
            if( accumulatorValue + dataMemory[ memoryAddressDecimal ] > 511 || accumulatorValue + dataMemory[ memoryAddressDecimal ] < -512 )
            {
                emit overFlow( "accumulator" );
                //halt
            }
            //adds and emits new accumulator value
            else
            {
                accumulatorValue += dataMemory[ memoryAddressDecimal ];

                programCounter++;
                emit addSignal( accumulatorValue, programCounter );
            }
        }
        else
        {
            emit inputError( memoryAddress );
            error = true;
        }
    }
    else
    {
        emit inputError( memoryAddress );
        error = true;
    }
}

//changes accumulator value to given decimal number
void Computer::bgtz( QString number )
{
    int value = number.toInt();

    if( accumulatorValue > 0 )
    {
        if( value > 0 )
        {
            currentInstructionNumber = value - 1;
            programCounter = value;
            emit newProgramCounterValueSignal( programCounter, currentInstructionNumber );
        }

        else
        {
            emit inputError( number );
            error = true;
        }
    }

    else if( accumulatorValue <= 0 )
    {
        programCounter++;
        emit newProgramCounterValueSignal( programCounter, currentInstructionNumber );
    }

}

//increments counter by one
void Computer::nop()
{
    programCounter++;
    emit newProgramCounterValueSignal( programCounter, currentInstructionNumber );
}

//clears accumulator value
void Computer::clear()
{
    accumulatorValue = 0;
    programCounter++;
    emit newAccumulatorValue( accumulatorValue, programCounter  );
}

//outputs strings to the standard output
void Computer::output( QString message )
{

    QStringList data = message.split(' ');

    for( int i = 0; i < data.size(); i++ )
    {
        if( QString( data[i] ).toUpper() == "%A" || QString( data[i] ).toUpper() == "%A," )
        {
            //converts value for output
            QString num;
            num.setNum( accumulatorValue );

            data[i] = num + " ";
        }

        if( QString( data[i] ).toUpper() == "%A." )
        {
            //converts value for output
            QString num;
            num.setNum( accumulatorValue );

            data[i] = num + '.';

        }
    }

    QString output;
    for( int i = 0; i < data.size(); i++ )
    {
        output += data[i] + " ";
    }

    programCounter++;
    emit standardOutput( output, programCounter );
}

//stops program
void Computer::halt()
{
    emit haltSignal();
    error = true;
}

void Computer::runPushedSlot()
{
    int i;
    for( i = 0; i < 128; i++ )
    {

        if( error )
        {
            break;
        }

        else
        {
            stepPushedSlot();
        }
    }

    //checks that halt is the last call
    if( i == 128 && !error )
    {
        emit standardOutput( "Warning program finished and halt was not reached", programCounter );
    }
}
