#ifndef LIBRARY
#define LIBRARY

/* Inheritance Tree ******************/

class RefItem {
public:
    virtual ~RefItem();
    QString getItemType() const;
    QString getISBN() const;
    QString getTitle() const;
    int getNumberOfCopies() const;
    virtual QString toString(QString sep="[::]") const;
    void setNumberOfCopies(int newVal);
protected:
    // these makes the class abstract - you cannot directly instantiate a RefItem object
    RefItem(QString type, QString isbn, QString title, int numCopies=1);
    RefItem(QStringList& proplist);
private:
    QString m_ItemType, m_ISBN, m_Title;
    int m_NumberOfCopies;
};

class Book: public RefItem {
public:
    Book(QString type, QString isbn, QString title, QString author, QString pub, int year, int numCopies=1);
    Book(QStringList& proplist);
    virtual QString toString(QString sep="[::]") const;
    QString getAuthor() const;
    QString getPublisher() const;
    int getCopyrightYear() const;
private:
    QString m_Author, m_Publisher;
    int m_CopyrightYear;
};

class ReferenceBook: public Book {
public:
    enum RefCategory {NONE = -1, Art, Architecture, ComputerScience, Literature, Math, Music, Science};
    ReferenceBook(QString type, QString isbn, QString title, QString author, QString pub, int year, RefCategory refcat, int numCopies=1);
    ReferenceBook(QStringList& proplist);
    QString toString(QString sep="[::]") const;
    RefCategory getCategory() const;
    QString categoryString() const;
    static QStringList getRefCategories();
private:
    RefCategory m_Category;
};

/* Container *************************/

class Library : public QList<RefItem*> {
public:
    Library() {}
    ~Library();
    void addRefItem(RefItem*& refitem);
    int removeRefItem(QString isbn);
    QString toString(QString sep="\n") const;
    bool isInList(QString isbn);
    QString getItemString(QString isbn);
private:
    Library(const Library&); //NOTE the copy constructor is private to avoid the compiler-generated one
    Library& operator=(const Library&); //NOTE the assignment operator is private to avoid the compiler-generated one
    RefItem* findRefItem(QString isbn);
};

#endif // LIBRARY

