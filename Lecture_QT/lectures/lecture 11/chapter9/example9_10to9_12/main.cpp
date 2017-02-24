#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    Product pasta;
    pasta.m_name = "Barilla";
    pasta.m_description = "It is not made in Italy";
    pasta.m_price = 1.59;
    pasta.m_dateValid = QDate(2020,12,12);

    Dialog ddd;
    ddd.setModel(&pasta);
    ddd.show();

    return a.exec();
}
