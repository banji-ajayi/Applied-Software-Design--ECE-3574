#include "mainwindow.h"
#include <QApplication>

#include <QObject>
#include <QMap>
#include <QtGui>
#include <QChar>
#include <QString>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QWidget>

#include "cardpics.h"
#include "cardtable.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //CardPics *cp = CardPics::instance(&a);
    //delete cp;

    CardTable ct;
    ct.show();

    return a.exec();
}
