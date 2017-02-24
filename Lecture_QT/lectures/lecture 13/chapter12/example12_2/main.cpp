//#include <QCoreApplication>
#include <QApplication>

#include <QAbstractSlider>
#include <QScrollBar>
#include <QListView>

#include <QString>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //QCoreApplication a(argc, argv);
    QTextStream QtCout(stdout);
    QScrollBar s;
    QWidget* w = &s;

    QtCout << "We are testing a base class poitner that has the address of a QScrollBar\n"
              "First, we use qobject_cast to investigate." << endl;
    QScrollBar* ptr1 = qobject_cast<QScrollBar*>(w);
    if (ptr1)
        QtCout << "Yes, it is ";
    else
        QtCout << "No, it is not ";
    QtCout << "a QScrollBar!" << endl;

    QAbstractSlider* ptr2 = qobject_cast<QAbstractSlider*>(w);
    if (ptr2)
        QtCout << "Yes, it is ";
    else
        QtCout << "No, it is not ";
    QtCout << "a QAbstractSlider!" << endl;

    QListView* ptr3 = qobject_cast<QListView*>(w);
    if (ptr3)
        QtCout << "Yes, it is ";
    else
        QtCout << "No, it is not ";
    QtCout << "a QListView!" << endl;

    //QString* ptr4 = qobject_cast<QString*>(w); // It is not processed by moc, cannot be done

/*****************************************************************************/

    if (w->inherits("QAbstractSlider"))
        QtCout << "Yes, it is ";
    else
        QtCout << "No, it is not ";
    QtCout << "a QAbstractSlider!" << endl;

    if (w->inherits("QListView"))
        QtCout << "Yes, it is ";
    else
        QtCout << "No, it is not ";
    QtCout << "a QListView!" << endl;

    return EXIT_SUCCESS; //a.exec();
}

