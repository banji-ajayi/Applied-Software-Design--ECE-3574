#ifndef SSTRING_H
#define SSTRING_H

#include "stringdata.h"
#include <QSharedDataPointer>
#include <iostream>

class SString {
public:
    SString();
    explicit SString(int len);
    SString(const char* ptr);
//    SString(const SString& other);

    SString& operator+=(const SString& other);
//    SString& operator=(const SString& other);
    int length() const;
    int refcount() const {return m_d->ref;}

    friend SString operator+(SString, SString);
    friend std::ostream& operator<< (std::ostream&, const SString&);

    qlonglong sharedDataAddress() const;

private:
    QSharedDataPointer<StringData> m_d;
};

#endif // SSTRING_H

