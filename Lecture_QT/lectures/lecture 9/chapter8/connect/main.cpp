#include "widget.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    QPushButton *button = new QPushButton("click me");
    QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
    button->show();

    return a.exec();
}

// from programmingexamples.wikidot.com/qt-signals-and-slots
