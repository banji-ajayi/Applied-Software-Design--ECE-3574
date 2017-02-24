// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 4/12/13

#include "datamemorycachegui.h"
#include "ui_datamemorycachegui.h"

#include<QtGui>

#include "computer.h"

//constructor
DataMemoryCacheGui::DataMemoryCacheGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataMemoryCacheGui)
{
    ui->setupUi(this);
    //makes QlineEdit cacheEfficiency not editable from GUI
    ui->cacheEfficiency->setReadOnly( true );
    wordSizeSet = false;
    blockSizeSet = false;
    currentRow = 0;
    hit = 0;
    total = 0;
    cacheEfficiency = 0;
    numberOfRows =0;
}

//desctructor
DataMemoryCacheGui::~DataMemoryCacheGui()
{
    delete ui;
}

//returns cache size given from gui
void DataMemoryCacheGui::on_cacheSize_currentIndexChanged(const QString &arg1)
{
    int temp = arg1.toInt();

    if( temp != 0 )
    {
        wordSize = temp;
        wordSizeSet = true;
    }
    else
    {
        wordSizeSet = false;
    }
}

//returns block size given from gui
void DataMemoryCacheGui::on_blockSize_currentIndexChanged(const QString &arg1)
{
    int temp = arg1.toInt();

    if( temp != 0 )
    {
        blockSizeGui = temp;
        blockSizeSet = true;
    }
    else
    {
        blockSizeSet = false;
    }

}

//sets cache size and builds table
void DataMemoryCacheGui::createCacheTable()
{
    int rows = wordSize / blockSizeGui;

    int columns = blockSizeGui + 2;

    cacheTable = new QStandardItemModel( rows, columns, this );

    //horizontal headers
    cacheTable->setHorizontalHeaderItem( 0, new QStandardItem( QString( "Dirty Bit" ) ) );
    cacheTable->setHorizontalHeaderItem( 1, new QStandardItem( QString( "Tag" ) ) );
    cacheTable->setHorizontalHeaderItem( 2, new QStandardItem( QString( "Row" ) ) );
    if( blockSizeGui == 2 )
    {
        //QString a = QString::number( i //loop, 2 )
        //a = a.rightjustified( 0s to the left, what you want to fill with )
        cacheTable->setHorizontalHeaderItem( 3, new QStandardItem( QString( "0" ) ) );
        cacheTable->setHorizontalHeaderItem( 4, new QStandardItem( QString( "1" ) ) );
    }
    else if( blockSizeGui == 4 )
    {
        cacheTable->setHorizontalHeaderItem( 3, new QStandardItem( QString( "00" ) ) );
        cacheTable->setHorizontalHeaderItem( 4, new QStandardItem( QString( "01" ) ) );
        cacheTable->setHorizontalHeaderItem( 5, new QStandardItem( QString( "10" ) ) );
        cacheTable->setHorizontalHeaderItem( 6, new QStandardItem( QString( "11" ) ) );
    }
    else if( blockSizeGui == 8 )
    {
        cacheTable->setHorizontalHeaderItem( 3, new QStandardItem( QString( "000" ) ) );
        cacheTable->setHorizontalHeaderItem( 4, new QStandardItem( QString( "001" ) ) );
        cacheTable->setHorizontalHeaderItem( 5, new QStandardItem( QString( "010" ) ) );
        cacheTable->setHorizontalHeaderItem( 6, new QStandardItem( QString( "011" ) ) );
        cacheTable->setHorizontalHeaderItem( 7, new QStandardItem( QString( "100" ) ) );
        cacheTable->setHorizontalHeaderItem( 8, new QStandardItem( QString( "101" ) ) );
        cacheTable->setHorizontalHeaderItem( 9, new QStandardItem( QString( "110" ) ) );
        cacheTable->setHorizontalHeaderItem( 10, new QStandardItem(QString( "111" ) ) );

    }
    //sets row count in instruction memory to 0-127
    QStringList rowCount;
    for( int i = 0; i <rows; i++)
    {
        QString tempVar;
        tempVar.setNum( i );
        rowCount.append( tempVar );
    }
    cacheTable->setVerticalHeaderLabels( rowCount );

    //allows columns to adjust with size of window
    ui->cacheTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    //display Instruction Memory Table
    ui->cacheTable->setModel(cacheTable);

}

//sets cache size and builds table
void DataMemoryCacheGui::on_setCacheSize_released()
{
    //disables editing of cache size if word size and block size have been selected
    // and set cache size is pushed
    if( blockSizeSet && wordSizeSet )
    {
        createCacheTable();
        ui->blockSize->setEnabled( false );
        ui->cacheSize->setEnabled( false );
        ui->setCacheSize->setEnabled( false );

        int rows = wordSize / blockSizeGui;

        currentRow = rows;

        emit CacheEnabled( wordSize, rows, blockSizeGui, true );
    }
}

//takes in new data to disaply
void DataMemoryCacheGui::acceptNewCacheData(QMap<QString, BlockData> theCache)
{
    if( currentRow < numberOfRows + 1 )
    {
        for( int i = 0; i < currentRow; i++ )
        {
            cacheTable->removeRow( i );
        }
    }

    QList<QString> keys = theCache.keys();
    int i = 0;
    QMap<QString, BlockData>::iterator it;
    for( it = theCache.begin(); it != theCache.end(); it++, i++ )
    {
        //adds dirty bit to gui
        QStandardItem *dirtyBitItem= new QStandardItem( QString::number(theCache.value(keys[i]).dirtyBit,10));
        cacheTable->setItem( i, 0,  dirtyBitItem );

        //adds row bits to gui
        QStandardItem *rows = new QStandardItem( theCache.value(keys[i]).rowValue );
        cacheTable->setItem( i, 2,  rows );


        //inserts data values into table
        QStandardItem *data;
        for( int j = 0; j < theCache.value(keys[i]).data.size() -1; j++ )
        {
            data = new QStandardItem( QString::number( theCache.value(keys[i]).data.at(j) , 10 ) );
            cacheTable->setItem( i, j + 3, data );
        }


        //adds tag bit to gui
        QStandardItem *guiTag = new QStandardItem( QString( theCache.value( keys[i] ).tag ) );
        cacheTable->setItem( i, 1,  guiTag );
    }
}

//receives hit from cache
void DataMemoryCacheGui::acceptCacheGuiHitOrMiss( bool status )
{
    //dirty bit is 1 hit count increments
    if( status )
    {
        hit++;
    }
    //dirty bit is 0
    else
    {
        numberOfRows++;
    }
    total++;

    //outputs cache efficiency
    cacheEfficiency = 100 * hit / total;
    QString output= QString::number(cacheEfficiency, 'f', 2);
    ui->cacheEfficiency->clear();
    ui->cacheEfficiency->insert(( output + "%" ));


}

//clears values in cache gui
void DataMemoryCacheGui::acceptClearCacheGui()
{
    //clears cache table and resets values
    createCacheTable();
    hit = 0;
    total = 0;
    cacheEfficiency = 0;
    ui->cacheEfficiency->clear();
    numberOfRows =0;
}

//reimplemets the close event so system closing the cache window will flush
// and disable the cache
void DataMemoryCacheGui::closeEvent(QCloseEvent *event)
{
    emit cacheOff();
}
