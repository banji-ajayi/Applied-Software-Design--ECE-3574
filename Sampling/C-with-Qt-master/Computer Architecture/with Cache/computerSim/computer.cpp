// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 4/12/13

#include<QtGui>

#include "computer.h"
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
    cacheActivated = false;
}

//receives filename and sends initial data to gui
void Computer::initialize(QString fileName)
{
    //sets defaults
    currentInstructionNumber = 0;
    accumulatorValue = 0;
    programCounter = 0;
    error = false;

    //opens file given from gui
    QFile file ( fileName );
    file.open( QIODevice::ReadOnly );
    QTextStream readFile( &file );
    QStringList temp;
    //gets instructions from file
    for(int i = 0; !readFile.atEnd() && i < 128; i++ )
    {
        instructionMemory.insert( i,readFile.readLine() );

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
    if( cacheActivated)
    {
        emit clearCacheTable();
    }
}

//performs next operation and returns results to gui
void Computer::stepPushedSlot()
{
    //parses given data
    QStringList instructionAndData = instructionMemory[ currentInstructionNumber ].split(' ');
    instruction = QString( instructionAndData[0] ).toUpper();
    QString data;

    //runs given command
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
            flushCache();
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
        else if( instruction == "LOADA" )
        {
            loada();
        }
        else
        {
            flushCache();
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
        else if ( instruction == "STOREA" )
        {
            storea( data );
        }
        else
        {
            flushCache();
            emit inputError( instruction );
            error = true;
        }
    }
    else
    {
        flushCache();
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
        flushCache();
        emit inputError( addend );
        error = true;
    }
    else
    {
        //checks that value does not overflows 10 bit signed integer
        if( accumulatorValue + addend.toInt() > 511 || accumulatorValue + addend.toInt() < -512 )
        {
            flushCache();
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
            programCounter++;
            //stores data in cache
            if( cacheActivated )
            {
                cacheStore( memoryAddressDecimal );
                emit loadNewAccumulatorValue( accumulatorValue, programCounter );
            }
            //stores data in data memory
            else
            {
                dataMemory[ memoryAddressDecimal ] = accumulatorValue;
                emit changeMemoryData( memoryAddressDecimal, accumulatorValue, programCounter );
            }
        }
        else
        {
            flushCache();
            emit inputError( memoryAddress );
            error = true;
        }
    }
    else
    {
        flushCache();
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
            programCounter++;
            //loads from cache memory
            if( cacheActivated )
            {
                cacheLoad( memoryAddressDecimal );
            }
            //loads from data memory
            else
            {
                accumulatorValue = dataMemory[ memoryAddressDecimal ];
            }


            emit loadNewAccumulatorValue( accumulatorValue, programCounter );
        }
        else
        {
            flushCache();
            emit inputError( memoryAddress );
            error = true;
        }
    }
    else
    {
        flushCache();
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
                flushCache();
                emit overFlow( "accumulator" );
            }
            //adds and emits new accumulator value
            else
            {
                programCounter++;
                //gets data from cache
                if( cacheActivated )
                {
                    cacheAdd( memoryAddressDecimal );
                }
                //gets data from data memory
                else
                {
                    accumulatorValue += dataMemory[ memoryAddressDecimal ];
                }

                emit addSignal( accumulatorValue, programCounter );
            }
        }
        else
        {
            flushCache();
            emit inputError( memoryAddress );
            error = true;
        }
    }
    else
    {
        flushCache();
        emit inputError( memoryAddress );
        error = true;
    }
}

//changes accumulator value to given decimal number
void Computer::bgtz( QString number )
{
    //converts qstring to int
    int value = number.toInt();

    //check accumulator value is greater than 0
    if( accumulatorValue > 0 )
    {
        //checks value less than 128
        if( value > 0 && value < 128 )
        {
            currentInstructionNumber = value - 1;
            programCounter = value;
            emit newProgramCounterValueSignal( programCounter, currentInstructionNumber );
        }
        //emits error if value is greater than 128
        else
        {
            flushCache();
            emit inputError( number );
            error = true;
        }
    }
    //increments program counter by 1 if accumulator value is less than 0
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
    flushCache();
    emit haltSignal();
    error = true;
}

//takes accumulator value, finds value at that address, and load to acccumulator
void Computer::loada()
{
    //checks if accumulator value will be a valid memory address
    if( accumulatorValue > 511 || accumulatorValue < 0 )
    {
        QString output;

        //converts accumulator value to qstring
        output.setNum( accumulatorValue );

        flushCache();
        emit inputError( output );
        error = true;
    }
    //outputs value at address given by accumulator value
    else
    {
        programCounter++;

        //gets value from cache
        if( cacheActivated )
        {
            cacheLoada( accumulatorValue );
        }
        //gets value from data memory
        else
        {
            accumulatorValue = dataMemory[ accumulatorValue ];
        }

        emit loadNewAccumulatorValue( accumulatorValue, programCounter );
    }
}

//takes given address, gets value there, converts to a hex address, and stores
//the accumulator value there
void Computer::storea( QString memoryAddress )
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
            //finds value in cache
            if( cacheActivated )
            {

                cacheStorea( memoryAddressDecimal );
                emit loadNewAccumulatorValue( accumulatorValue, programCounter );
            }
            //finds value in data memory
            else if( !cacheActivated )
            {
                int temp = dataMemory[ memoryAddressDecimal ];
                //checks value in given memory location is a valid memory
                if( temp >= 0 && temp <= 511 )
                {
                    programCounter++;

                    dataMemory[ temp ] = accumulatorValue;


                    emit changeMemoryData( temp, accumulatorValue, programCounter );
                }
            }
            else
            {
                flushCache();
                emit inputError( memoryAddress );
                error = true;
            }

        }
        else
        {
            flushCache();
            emit inputError( memoryAddress );
            error = true;
        }
    }

    else
    {
        flushCache();
        emit inputError( memoryAddress );
        error = true;
    }
}

//runs through commands until invalid input, halt, or end of instruction memory
void Computer::runPushedSlot()
{
    while( currentInstructionNumber < 128 )
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
    if( currentInstructionNumber > 127 && !error && instruction != "HALT" )
    {
        emit standardOutput( "Warning program finished and halt was not reached", programCounter );
        emit halt();
    }
}
//resets program counter, accumulator value, and data memory values
void Computer::acceptReset()
{
    programCounter = 0;
    accumulatorValue = 0;
    currentInstructionNumber = 0;
    error = false;

    for( int i = 0; i < 512; i ++ )
    {
        dataMemory[ i ] = 0;
    }
    cache.clear();
    //emit cacheClear();
}

//clears data and instruction memory, accumulator value, and program counter
void Computer::acceptClear()
{
    programCounter = 0;
    accumulatorValue = 0;
    currentInstructionNumber = 0;

    for( int i = 0; i < 512; i ++ )
    {
        dataMemory[ i ] = 0;
    }

    cache.clear();
    instructionMemory.clear();

}

//tells computer caching is enabled
void Computer::acceptCacheEnable(int cacheSize, int numberOfBlocks, int blockSizeGiven, bool cacheStatus )
{
    //sets number of blocks allowed in cache
    maxBlocksAllowed = numberOfBlocks;
    //enables caching on computer
    cacheActivated = cacheStatus;
    //tells cache block size
    blockSize = blockSizeGiven;


    //finds number of row bits
    int cacheBits = log2( cacheSize );
    columnBits = log2( blockSizeGiven );
    rowBits = cacheBits - columnBits;
}

//stores data in cache
void Computer::cacheStore( int address )
{
    getInitialValues( address );
    bool temp = false;

    //block of memory already is in cache
    if( cache.contains( currentBlock.key )) //( cache.value( keyz[i] ).tag==currentBlock.tag && cache.value( keyz[i] ).rowValue==currentBlock.rowValue  )
    {
        //gets block in cache
        currentBlock= cache.value( currentBlock.key ); //.tag

        //increments hit count
        currentBlock.hitCount += 1;
        emit cacheGuiHitOrMiss( true );
        emit simGuiHitOrMiss( true );

        //inserts new data value
        currentBlock.data[ dataToBeChanged ] = accumulatorValue;
        currentBlock.dirtyBit = true;
        temp =true;
    }
    //block of memory not in cache
    else
    {
        //retrives data from data memory
        for( int i = 0; startPoint <= endPoint; startPoint++, i ++ )
        {
            if( i == dataToBeChanged )
            {
                currentBlock.data.insert( i, accumulatorValue );
            }
            else
            {
                currentBlock.data.insert( i, dataMemory[ startPoint ] );
            }
        }

        //initializes data in new block
        currentBlock.hitCount = 0;

        currentBlock.dirtyBit = true;

        emit cacheGuiHitOrMiss( false );
        emit simGuiHitOrMiss( false );
    }

    insert( currentBlock );
}

//loads value from  cache into accumulator
void Computer::cacheLoad( int address )
{
    getInitialValues( address );

    ///HIT
    if( cache.contains( currentBlock.key) )
    {
        //gets block in cache
        currentBlock= cache.value( currentBlock.key );

        //increments hit count
        currentBlock.hitCount += 1;
        emit cacheGuiHitOrMiss( true );
        emit simGuiHitOrMiss( true );

        //inserts data value from cache to accumulator
        accumulatorValue = currentBlock.data[ dataToBeChanged ];
    }
    else
    {
        //retrives data from data memory
        for( int i = 0; startPoint <= endPoint; startPoint++, i ++ )
        {
            if( i == dataToBeChanged )
            {
                accumulatorValue =  dataMemory[ startPoint ];
            }

            currentBlock.data.insert( i, dataMemory[ startPoint ] );
        }

        //initializes data in new block
        currentBlock.hitCount = 0;
        currentBlock.dirtyBit = false;

        emit cacheGuiHitOrMiss( false );
        emit simGuiHitOrMiss( false );
    }

    insert(currentBlock );
}

//adds item fom given address in cache to accumulator value
void Computer::cacheAdd( int address )
{
    getInitialValues( address );

    ///HIT
    if( cache.contains( currentBlock.key) )
    {
        //gets block in cache
        currentBlock= cache.value( currentBlock.key );

        //increments hit count
        currentBlock.hitCount += 1;
        emit cacheGuiHitOrMiss( true );
        emit simGuiHitOrMiss( true );

        //inserts data value from cache to accumulator
        accumulatorValue += currentBlock.data[ dataToBeChanged ];
    }

    else
    {
        //retrives data from data memory
        for( int i = 0; startPoint <= endPoint; startPoint++, i ++ )
        {
            if( i == dataToBeChanged )
            {
                accumulatorValue +=  dataMemory[ startPoint ];
            }

            currentBlock.data.insert( i, dataMemory[ startPoint ] );
        }

        //initializes data in new block
        currentBlock.hitCount = 0;
        currentBlock.dirtyBit = false;

        emit cacheGuiHitOrMiss( false );
        emit simGuiHitOrMiss( false );
    }

    insert(currentBlock );
}

//inserts block of data into cache
void Computer::insert( BlockData newData )
{
    QString tagToRemove = "";
    int leastUsedCount = 10000000;

    //removes item and inserts new item if cache is full
    if( maxBlocksAllowed - 1 < cache.size() )
    {
        //looks for least used dirty block

        int i = 0;
        QList<QString> keyz = cache.keys();
        QMap<QString, BlockData>::iterator it;
        for( it = cache.begin(); it != cache.end(); it++, i++)
        {
            if( cache.value( keyz[i] ).hitCount <  leastUsedCount )
            {
                tagToRemove = it.key();
                leastUsedCount = cache.value( keyz[i] ).hitCount;
            }
        }

        int removeStartAddress = cache.value(tagToRemove).startAddress;

        //puts block to be removed back in data memory
        for( int i = 0; removeStartAddress < cache.value(tagToRemove).endAddress; removeStartAddress++, i++ )
        {
            dataMemory[ startPoint ] = cache.value(tagToRemove).data[ i ];
        }

        emit returnMemoryBlock( cache.value(tagToRemove) );

        //removes block from cache
        cache.remove( tagToRemove );
    }

    //inserts new cache value
    cache.insert( newData.key, newData );
    emit newCacheData( cache );
    currentBlock.data.clear();

}

//gets initial values for cache operations
void Computer::getInitialValues( int address )
{
    //gets tag from address
    QString tempAddress = QString::number( address, 2 );
    QString rowValue;
    while( tempAddress.length() < 9 )
    {
        tempAddress.prepend( "0" );
    }

    //removes cloumn value
    for( int i = 0; i < columnBits; i++ )
    {
        tempAddress.remove( 8 - i, 1 );
    }

    int j = 0;
    //sets row bits
    for( int i = 8 - columnBits ; j < rowBits; i--, j++ )
    {
        rowValue.prepend( tempAddress[ i ] );
        tempAddress.remove( i, 1 );
    }

    //inserts
    currentBlock.rowValue = rowValue;
    currentBlock.tag = tempAddress;

    //finds block to insert into cache
    dataToBeChanged = address % blockSize;
    startPoint = address - dataToBeChanged;
    endPoint = startPoint + blockSize;

    currentBlock.startAddress = startPoint;
    currentBlock.endAddress = endPoint;
    currentBlock.key = tempAddress + rowValue;
}

//takes accumulator value, finds value at that address, and load to acccumulator from cache
void Computer::cacheLoada( int address )
{
    getInitialValues( address );

    //gets data from cache
    if( cache.contains( currentBlock.key) )
    {
        //gets block in cache
        currentBlock= cache.value( currentBlock.key );

        //increments hit count
        currentBlock.hitCount += 1;
        emit cacheGuiHitOrMiss( true );
        emit simGuiHitOrMiss( true );

        //inserts data value from cache to accumulator
        accumulatorValue = currentBlock.data[ dataToBeChanged ];
    }
    //gets data from data memory
    else
    {
        for( int i = 0; startPoint <= endPoint; startPoint++, i ++ )
        {
            if( i == dataToBeChanged )
            {
                accumulatorValue =  dataMemory[ startPoint ];
            }

            currentBlock.data.insert( i, dataMemory[ startPoint ] );
        }

        //initializes data in new block
        currentBlock.hitCount = 0;
        currentBlock.dirtyBit = false;
        emit cacheGuiHitOrMiss( false );
        emit simGuiHitOrMiss( false );
    }

    insert(currentBlock );
}

//takes given address, gets value there, converts to a hex address, and stores
//the accumulator value there in cache
void Computer::cacheStorea( int address )
{
    //find value at address given and pass that as address
    QString key( QString::number( address, 2 ) );
    key = key.rightJustified(9,'0');
    key.chop(columnBits);

    //finds value in cache
    if( cache.contains( key ) )
    {
        getInitialValues( address );
        address = cache.value( key ).data[ dataToBeChanged ];
    }
    //find value in data memory
    else
    {
        address = dataMemory[ dataToBeChanged ];
    }

    //check that value is valid
    if( address >= 0 && address <= 512 )
    {
        cacheStore( address );
    }
    else
    {
        QString addressString = QString::number(address, 10);
        flushCache();
        emit inputError( addressString );
        error = true;
    }
}

//flushes cache to data memory when incorrect command or halt if called
void Computer::flushCache()
{
    //sends items in cache to data memory in gui
    QMap<QString, BlockData>::iterator it;
    for( it = cache.begin(); it != cache.end(); it++)
    {
        emit returnMemoryBlock( it.value() );
    }

    //clears cache
    cache.clear();
    emit clearCacheTable();
}

//inputs new instruction from gui into instruction memory
void Computer::acceptNewInstruction(QString newInstruction, int location)
{
    instructionMemory[location] = newInstruction;
}

//flushes cache to data memory and disables caching
void Computer::acceptCacheOff()
{
    if( cacheActivated)
    {
        flushCache();
    }
    cacheActivated = false;
}
