#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream qtts(stdout);

    qtts << "Hello World!" << endl;

    //return a.exec();
    return EXIT_SUCCESS;
}

