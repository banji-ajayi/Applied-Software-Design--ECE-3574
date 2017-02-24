#include <QList>
#include <QtAlgorithms>
#include <QStringList>
#include <QDebug>

#include <QCoreApplication>

class CaseIgnoreString : public QString {
public:
    CaseIgnoreString(const QString& other = QString())
        : QString(other) { }
    bool operator<(const QString& other) const {
        return toLower() < other.toLower();
    }
    bool operator==(const QString& other) const {
        return toLower() == other.toLower();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CaseIgnoreString s1("Apple"), s2("bear"), s3("CaT"), s4("dog"), s5("Dog");

    Q_ASSERT(s4 == s5);
    Q_ASSERT(s2 < s3);
    Q_ASSERT(s3 < s4);

    QList<CaseIgnoreString> namelist;
    namelist << s5 << s1 << s3 << s4 << s2;

    qSort(namelist.begin(), namelist.end());
    int i =0;
    foreach (const QString& stritr, namelist) {
        qDebug () << QString("namelist[%1] = %2").arg(i++).arg(stritr);
    }

    QStringList strlist;
    strlist << s5 << s1 << s3 << s4 << s2;

    qSort(strlist.begin(), strlist.end());
    qDebug() << "StringList sorted: " + strlist.join(", ");

    return EXIT_SUCCESS; //a.exec();
}

/* NOTE
 * in normal character ordering uppercase latters are coming before all lower
 * case letters. The class CaseIgnoreString is canceling this and order the
 * characters in a strict alphabetical order.
 */
