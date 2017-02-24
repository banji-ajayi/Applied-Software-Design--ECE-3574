// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 4
// 4/12/13

#ifndef DATAMEMORYCACHEGUI_H
#define DATAMEMORYCACHEGUI_H

#include <QWidget>
#include <QtGui>

#include"computer.h"

namespace Ui {
class DataMemoryCacheGui;
}

class DataMemoryCacheGui : public QWidget
{
    Q_OBJECT

public:
    explicit DataMemoryCacheGui(QWidget *parent = 0);
    ~DataMemoryCacheGui();

public slots:
    //takes in new data to disaply
    void acceptNewCacheData( QMap<QString, BlockData> theCache );
    //receives hit from cache
    void acceptCacheGuiHitOrMiss( bool status );
    //clears values in cache gui
    void acceptClearCacheGui();

signals:
    //sends cache table data computer
    void CacheEnabled(int cacheSize, int numberOfBlocks, int blockSizeGiven, bool cacheStatus );
    //flushes cache to data memory and disables caching
    void cacheOff();

private slots:
    //returns cache size given from gui
    void on_cacheSize_currentIndexChanged(const QString &arg1);
    //returns block size given from gui
    void on_blockSize_currentIndexChanged(const QString &arg1);
    //sets cache size and builds table
    void on_setCacheSize_released();

private:
    Ui::DataMemoryCacheGui *ui;

    //model for cache table to be displayed in gui
    QStandardItemModel *cacheTable;    
    //reimplemets the close event so system closing the cache window will flush
    // and disable the cache
    void closeEvent(QCloseEvent *event);
    //tells pushutton if word size has been selected
    bool wordSizeSet;
    //tells pushbutton if block size has been selected
    bool blockSizeSet;
    // number of rows in table
    int numberOfRows;
    //number of words in cache
    int wordSize;
    //block size in cache
    int blockSizeGui;
    //hit count
    double hit;
    //total number of hits/misses
    double total;
    //cache efficiency
    double cacheEfficiency;
    //row to insert data
    int currentRow;
    //creates cache from values given in gui
    void createCacheTable();

};

#endif // DATAMEMORYCACHEGUI_H
