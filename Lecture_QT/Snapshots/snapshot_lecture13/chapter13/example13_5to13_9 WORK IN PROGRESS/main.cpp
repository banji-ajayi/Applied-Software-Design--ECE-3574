#include "mainwindow.h"
#include <QApplication>

#include "starrating.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("playlist");
    a.setOrganizationName("ece.vt.edu");

    qRegisterMetaType<StarRating>("StarRating");

    MainWindow w;
    w.show();

    return a.exec();
}
