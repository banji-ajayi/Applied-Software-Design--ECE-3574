#include <sstream>
#include <iostream>
#include "complex.h"

Complex::Complex(double r, double i)
  : m_r(r), m_i(i) {
}

Complex::Complex(double r)
  : m_r(r), m_i(0.0) {
}

Complex::Complex() {
  m_r = 0.0;
  m_i = 0.0;
}

std::string Complex::toString() const {
  std::ostringstream strbuf;
  strbuf << '(' << m_r << ", i" << m_i << ')';
  return strbuf.str();
}

Complex& Complex::operator*= (Complex c) {
  m_r = (m_r * c.m_r) - (m_i * c.m_i);
  m_i = (m_r * c.m_r) + (m_i * c.m_i);
  return *this;
}

