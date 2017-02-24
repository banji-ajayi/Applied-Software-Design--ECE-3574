
#include "textbook.h"

#include <QDebug>

QString Textbook::toString() const {
    QString retval;
    QTextStream os (&retval);
    os << m_Author << ", "
       << m_Title << ", "
       << m_Isbn << ", "
       << m_YearPub;
    return retval;
}

TextbookMap::~TextbookMap() {
    qDebug() << "Destroying TextbookMap ... " << endl;
    qDeleteAll(values());
    clear();
}

void TextbookMap::add(Textbook *text) {
    insert(text->getIsbn(), text);
}

// NOTE the book at page 367 propose to dump the content using 'foreach'
QString TextbookMap::toString() const {
    QString retval;
    QTextStream os (&retval);
    ConstIterator itr = constBegin();
    for ( ; itr != constEnd(); ++itr)
        os << '[' << itr.key() << ']' << ": "
           << itr.value()->toString() << endl;
    return retval;
}
