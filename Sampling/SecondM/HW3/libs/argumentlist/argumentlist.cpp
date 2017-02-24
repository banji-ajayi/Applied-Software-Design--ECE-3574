#include <QCoreApplication>
#include <QRegExp>
#include <QDebug>
#include "argumentlist.h"

ArgumentList::ArgumentList() {
    if (qApp != NULL)  /* A global pointer to the current QApplication. */
        *this = qApp->arguments();
}

ArgumentList::ArgumentList(int argc, char* argv[]) {
    argsToStringlist(argc, argv);
}

bool ArgumentList::getSwitch (QString option) {
    QMutableStringListIterator itr(*this);
    while (itr.hasNext()) {
        if (option == itr.next()) {
            itr.remove();
            return true;
        }
    }
    return false;
}

QString ArgumentList::getSwitchArg(QString option, QString defaultValue) {
    if (isEmpty())
        return defaultValue;
    QMutableStringListIterator itr(*this);
    while (itr.hasNext()) {
        if (option == itr.next()) {
            itr.remove();
            if (itr.hasNext()) {
                QString retval = itr.next();
                itr.remove();
                return retval;
            }
            else {
                qDebug() << "Missing Argument for " << option;
                return QString();
            }
        }
    }
    return defaultValue;
}

QString ArgumentList::getSwitchEqualsArg(QString option) {
    QRegExp optRegex(option);
    QMutableStringListIterator itr(*this);
    QString retString = "";

    while (itr.hasNext()) {
        if (optRegex.indexIn(itr.next()) != -1) {
            retString = itr.value().split("=")[1];
            itr.remove();
        }
    }
    return retString;
}

void ArgumentList::argsToStringlist(int argc, char * argv []) {
    for (int i=0; i < argc; ++i) {
        *this += argv[i];
    }
}
