#ifndef TEXTBOOK
#define TEXTBOOK

#include <QObject>
#include <QString>
#include <QMap>

class Textbook : public QObject {
    Q_OBJECT
public:
    Textbook(QString title, QString author, QString isbn, uint year)
        : m_Author(author), m_Title(title), m_Isbn(isbn), m_YearPub(year)
    { }

    QString getAuthor() const { return m_Author; }
    QString getTitle() const { return m_Title; }
    QString getIsbn() const { return m_Isbn; }
    uint getYearPub() const { return m_YearPub; }

    QString toString() const;

public slots:
    void setAuthor(const QString& newAuthor) { m_Author = newAuthor; }
    void setTitle(const QString& newTitle) { m_Title = newTitle; }
    void setIsbn(const QString& newIsbn) { m_Isbn = newIsbn; }
    void setYearPub(uint newYear) { m_YearPub = newYear; }

private:
    QString m_Author, m_Title, m_Isbn;
    uint m_YearPub;
};

class TextbookMap : public QMap<QString, Textbook*> {
public:
    ~TextbookMap();
    void add(Textbook* text);
    QString toString() const;
};
#endif // TEXTBOOK

