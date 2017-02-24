
#include "sstring.h"

SString::SString() {}

SString::SString(int len) : m_d(new StringData(len)) { }

SString::SString(const char *ptr) : m_d(new StringData(ptr)) { }

//SString(const SString& other) { }

SString& SString::operator+=(const SString& other) {
    *m_d += *(other.m_d);
    return *this;
}

//SString& operator=(const SString& other) { }

int SString::length() const {
    return m_d->length();
}

SString operator+ (SString l, SString r) {
    l += r;
    return l;
}

std::ostream& operator<<(std::ostream& os, const SString& s) {
    os << *(s.m_d);
    return os;
}

qlonglong SString::sharedDataAddress() const {
    return (qlonglong) m_d->m_Buffer;
}
