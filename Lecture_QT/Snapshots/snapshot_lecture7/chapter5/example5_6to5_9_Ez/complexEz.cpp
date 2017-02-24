#include "complexEz.h"

Complex::Complex(double r, double i)
  : m_Re(r), m_Im(i) {}

//a += b
Complex& Complex::operator+= (const Complex& c) {
  m_Re += c.m_Re;
  m_Im += c.m_Im;
  return *this;
}

Complex& Complex::operator-= (const Complex& c) {
  m_Re -= c.m_Re;
  m_Im -= c.m_Im;
  return *this;
}

//a = (b + c)
Complex Complex::operator+ (const Complex& c2) {
  return Complex(m_Re + c2.m_Re, m_Im + c2.m_Im);
}

std::string Complex::toString() const {
  std::ostringstream strbuf;
  strbuf << '(' << m_Re << ", i" << m_Im << ')';
  return strbuf.str();
}

