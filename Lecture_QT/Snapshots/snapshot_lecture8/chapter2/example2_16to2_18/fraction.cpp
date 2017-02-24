#include <string>
#include <sstream>

#include "fraction.h"

int Fraction::s_assigns = 0;
int Fraction::s_copies = 0;
int Fraction::s_ctors = 0;

Fraction::Fraction(const Fraction& other)
  :m_Num(other.m_Num), m_Den(other.m_Den) {
  ++s_copies;
}

/* should always return *this for chaining */
Fraction& Fraction::operator=(const Fraction& other) {
  if (this != &other) { 
    m_Num = other.m_Num;
    m_Den = other.m_Den;
    ++s_assigns;
  }
  return *this;
}

Fraction Fraction::multiply(Fraction f2) {
  return Fraction(this->m_Num * f2.m_Num, 
                  this->m_Den * f2.m_Den);
}

std::string Fraction::report(void) {
  std::ostringstream os;
  os << "assigns: " << s_assigns
     << " copies: " << s_copies
     << " ctors: " << s_ctors;
  return os.str();
}

