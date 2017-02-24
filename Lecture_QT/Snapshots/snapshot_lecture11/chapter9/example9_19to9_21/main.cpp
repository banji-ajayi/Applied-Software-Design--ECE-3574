
#include "lifewidget.h"
#include "lifemainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Game of Life");
    a.setOrganizationDomain("ece.vt.edu");

    LifeMainWindow w;
    w.show();

    return a.exec();
}
