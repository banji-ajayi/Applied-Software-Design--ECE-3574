#include "complex.h"

Complex::Complex(double r, double i)
  : m_Re(r), m_Im(i) {}

Complex& Complex::operator+= (const Complex& c) {
  m_Re += c.m_Re;
  m_Im += c.m_Im;
  return *this;
}

Complex Complex::operator+ (const Complex& c2) {
  return Complex(m_Re + c2.m_Re, m_Im + c2.m_Im);
}

Complex& Complex::operator-= (const Complex& c) {
  m_Re -= c.m_Re;
  m_Im -= c.m_Im;
  return *this;
}

/* FRIENDS global functions */

ostream& operator<< (ostream& out, const Complex& c) {
  out << '(' << c.m_Re << ',' << c.m_Im << ')';
  return out;
}

Complex operator- (const Complex& c1, const Complex& c2) {
  return Complex(c1.m_Re - c2.m_Re, c1.m_Im - c2.m_Im);
}

Complex operator* (const Complex& c1, const Complex& c2) {
  return Complex(((c1.m_Re * c2.m_Re) - (c1.m_Im * c2.m_Im)),
		((c1.m_Re * c2.m_Im) + (c1.m_Im * c2.m_Re)));
}

Complex operator/ (const Complex& c1, const Complex& c2) {
  return Complex(((c1.m_Re * c2.m_Re) + (c1.m_Im * c2.m_Im)) / ((c2.m_Re * c2.m_Re) + (c2.m_Im * c2.m_Im)),
		((c1.m_Im * c2.m_Re) - (c1.m_Re * c2.m_Im)) / ((c2.m_Re * c2.m_Re) + (c2.m_Im * c2.m_Im)));
}



