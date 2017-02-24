#include <QCoreApplication>
#include <QTextStream>

	QTextStream qtCout(stdout);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qtCout << "Hello World!" << endl;

    //return a.exec();
    return EXIT_SUCCESS;
}

