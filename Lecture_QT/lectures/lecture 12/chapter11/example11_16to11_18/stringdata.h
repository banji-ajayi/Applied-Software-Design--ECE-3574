#ifndef STRINGDATA
#define STRINGDATA

#include "mystring.h"
#include <QSharedData>

class StringData : public QSharedData, public MyString {
public:
  friend class SString;
  StringData() { }
  StringData(const char* d) : MyString(d) { }
  explicit StringData(int len) : MyString(len) { }
  StringData(const StringData& other)
    : QSharedData(other), MyString(other) { }
};

#endif // STRINGDATA

