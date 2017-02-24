#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("Virginia Tech");
    a.setOrganizationDomain("vt.edu");
    a.setApplicationName("mainwindow-test");
    MyMainWindow mw;
    mw.show();
    return a.exec();
}
