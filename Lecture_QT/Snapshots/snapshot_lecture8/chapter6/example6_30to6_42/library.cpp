#include <QString>
#include <QStringList>
#include <QDebug>

#include "library.h"

/* RefItem */

QString RefItem::toString(QString sep) const {
    return QString("%1%2%3%4%5%6%7").arg(m_ItemType)
            .arg(sep)
            .arg(m_ISBN)
            .arg(sep)
            .arg(m_Title)
            .arg(sep)
            .arg(m_NumberOfCopies);
}

RefItem::RefItem(QString type, QString isbn, QString title, int numCopies)
    : m_ItemType(type), m_ISBN(isbn), m_Title(title), m_NumberOfCopies(numCopies)
{}

RefItem::RefItem(QStringList &plst)
    : m_ItemType(plst.takeFirst()), m_ISBN(plst.takeFirst()), m_Title(plst.takeFirst()), m_NumberOfCopies(plst.takeFirst().toInt())
{}

RefItem::~RefItem()
{}

QString RefItem::getItemType() const {
    return m_ItemType;
}

QString RefItem::getISBN() const {
    return m_ISBN;
}

QString RefItem::getTitle() const {
    return m_Title;
}

int RefItem::getNumberOfCopies() const {
    return m_NumberOfCopies;
}

void RefItem::setNumberOfCopies(int newVal) {
    m_NumberOfCopies = newVal;
}

/* Book */

Book::Book(QString type, QString isbn, QString title, QString author, QString pub, int year, int numCopies)
    : RefItem(type, isbn, title, numCopies), m_Author(author), m_Publisher(pub), m_CopyrightYear(year)
{}

Book::Book(QStringList &plst)
    : RefItem(plst), m_Author(plst.takeFirst()), m_Publisher(plst.takeFirst()), m_CopyrightYear(plst.takeFirst().toInt())
{}

QString Book::toString(QString sep) const {
    return QString("%1%2%3%4%5%6%7").arg(RefItem::toString(sep))
            .arg(sep)
            .arg(m_Author)
            .arg(sep)
            .arg(m_Publisher)
            .arg(sep)
            .arg(m_CopyrightYear);
}

QString Book::getAuthor() const {
    return m_Author;
}

QString Book::getPublisher() const {
    return m_Publisher;
}

int Book::getCopyrightYear() const {
    return m_CopyrightYear;
}

/* ReferenceBook */

ReferenceBook::ReferenceBook(QString type, QString isbn, QString title, QString author, QString pub, int year, RefCategory refcat, int numCopies)
    : Book(type, isbn, title, author, pub, year, numCopies), m_Category(refcat)
{}

ReferenceBook::ReferenceBook(QStringList &plst)
    : Book(plst), m_Category(static_cast<RefCategory>(plst.takeFirst().toInt()))
{}

QString ReferenceBook::toString(QString sep) const {
    return QString("%1%2%3").arg(Book::toString(sep))
            .arg(sep)
            .arg(categoryString());
}

ReferenceBook::RefCategory ReferenceBook::getCategory() const {
    return m_Category;
}

QString ReferenceBook::categoryString() const {
    switch(m_Category) {
    case Art: return "Art";
    case Architecture: return "Architecture";
    case ComputerScience: return "ComputerScience";
    case Literature: return "Literature";
    case Math: return "Math";
    case Music: return "Music";
    case Science: return "Science";
    default: return "None";
    }
}

QStringList ReferenceBook::getRefCategories() {
    QStringList reflst;
    for (int i= (NONE +1); i< (Science +1); i++) {
        QString cats;
        switch(static_cast<RefCategory>(i)) {
        case Art: cats = "Art"; break;
        case Architecture: cats = "Architecture"; break;
        case ComputerScience: cats = "ComputerScience"; break;
        case Literature: cats = "Literature"; break;
        case Math: cats = "Math"; break;
        case Music: cats = "Music"; break;
        case Science: cats =  "Science"; break;
        default: cats = "None";
        }
        reflst << cats;
    }
    return reflst;
}

/* Library */

Library::~Library() {
    qDeleteAll(*this); //NOTE delete each pointed object
    clear(); //NOTE remove all items from the list
}

Library::Library(const Library &)
    : QList<RefItem*>()
{}

Library& Library::operator=(const Library&) {
    return *this;
}

void Library::addRefItem(RefItem *&refitem) {
    QString isbn(refitem->getISBN());
    RefItem* oldItem(findRefItem(isbn));
    if (oldItem == 0)
        append(refitem);
    else {
        qDebug() << isbn << " Already in list:\n"
                 << oldItem->toString()
                 << "\nIncreasing number of copies "
                 << "and deleting new pointer.";
        int newNum(oldItem->getNumberOfCopies() + refitem->getNumberOfCopies());
        oldItem->setNumberOfCopies(newNum);
        delete refitem; //NOTE it is a reference (to the pointer variable)
        refitem = 0; //NOTE because we delete it the pointed object, we should now set the pointer to zero to avoid future dereferences
    }
}

int Library::removeRefItem(QString isbn) {
    RefItem* ref(findRefItem(isbn));
    int numCopies(-1);
    if (ref) {
        numCopies = ref->getNumberOfCopies() -1;
        if (numCopies == 0) {
            removeAll(ref);
            delete ref;
        }
        else
            ref->setNumberOfCopies(numCopies);
    }
    return numCopies;
}

RefItem* Library::findRefItem(QString isbn) {
    for(int i=0; i< size(); ++i) {
        if(at(i)->getISBN().trimmed() == isbn.trimmed())
            return at(i);
    }
    return 0;
}

bool Library::isInList(QString isbn) {
    return findRefItem(isbn); //NOTE defined above
}

QString Library::toString(QString sep) const {
    QStringList reflst;
    for (int i=0; i <size(); ++i)
        reflst << at(i)->toString();
    return reflst.join(sep);
}

QString Library::getItemString(QString isbn) {
    RefItem* ref(findRefItem(isbn));
    if (ref)
        return ref->toString();
    else
        return QString();
}
