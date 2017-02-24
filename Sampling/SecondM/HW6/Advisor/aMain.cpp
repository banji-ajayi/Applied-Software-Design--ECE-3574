#include "aMainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication myApp(argc, argv);
    MainWindow mw;
    mw.show();

    return myApp.exec();
}
