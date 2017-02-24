#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream qtCout(stdout);

    qtCout << "Hello World!" << endl;

    //return a.exec();
    return EXIT_SUCCESS;
}

