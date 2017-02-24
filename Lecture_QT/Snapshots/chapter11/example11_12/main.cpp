#include <QCoreApplication>
#include <QDebug>

#define FUNC_PTR
#ifdef FUNC_PTR
QString name() {
    return QString("Antonio");
}

typedef QString (*funcPtr) ();
Q_DECLARE_METATYPE(funcPtr); //NOTE this is only needed for registering the typ in the QT metaobject system
#else
class name {
public:
    QString operator() () {
        return QString("Antonio");
    }
};
#endif

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef FUNC_PTR
    qRegisterMetaType<funcPtr>("funcPtr"); //NOTE this is only needed for registering the typ in the QT metaobject system
    funcPtr ptr = name;
#else
    name ptr;
#endif

    //QString v = (*ptr)(); //NOTE equivalent
    QString v = ptr(); //NOTE equivalent
    qDebug() << v << endl;

    return EXIT_SUCCESS; //a.exec();
}

