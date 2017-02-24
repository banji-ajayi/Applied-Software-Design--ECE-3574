#include <iostream>

class MyString {
public:
  MyString();
  explicit MyString(int size);
  MyString(const MyString& str);
  MyString(const char* chptr);
  MyString& operator=(const MyString& a);

  virtual ~MyString();

  friend std::ostream& operator<<(std::ostream& os, const MyString& s);
  friend MyString operator+(const MyString&, const MyString&);
  int length() const;
  MyString& operator +=(const MyString& other);

protected:
  int m_Len;
  char* m_Buffer;
  void copy(const char* chptr);
};
