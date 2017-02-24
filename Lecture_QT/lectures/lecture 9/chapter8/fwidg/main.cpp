#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec(); // enters event loop here
}

/* event loop is a "passive interface of functions that get called in response
 * to" events "such as mouse clicks, touch pad gesture, key clicks, signals
 * being emitted, window managers events or messages from other programs"
 */
