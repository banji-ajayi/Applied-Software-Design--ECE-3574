#include <sstream>
#include <iostream>
#include "complex1.h"

#define CTOR_PRINT std::cout << "ctor" << toString() << std::endl
#define DTOR_PRINT std::cout << "dtor" << toString() << std::endl;

Complex::Complex(double r, double i)
  : m_r(r), m_i(i) {
  CTOR_PRINT;
}

Complex::Complex(double r)
  : m_r(r), m_i(0.0) {
  CTOR_PRINT;
}

Complex::Complex() {
  m_r = 0.0;
  m_i = 0.0;
  CTOR_PRINT;
}

Complex::~Complex() {
  // de-allocate data structures
  DTOR_PRINT;
}

std::string Complex::toString() const {
  std::ostringstream strbuf;
  strbuf << '(' << m_r << ", i" << m_i << ')';
  return strbuf.str();
}

int main() {
  Complex C1;
  Complex C2(3.14);
  Complex C3(6.2, 10.23);
  std::cout << C1.toString() << std::endl
            << C2.toString() << std::endl
            << C3.toString() << std::endl;
}



