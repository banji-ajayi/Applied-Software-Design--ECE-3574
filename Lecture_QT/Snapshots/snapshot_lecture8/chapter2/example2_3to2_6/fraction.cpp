#include <sstream>
#include "fraction.h"

void Fraction::set(int nn, int dd) {
  m_Numerator = nn;
  m_Denominator = dd;
}

double Fraction::toDouble() const {
  return 1.0 * m_Numerator / m_Denominator;
}

std::string Fraction::toString() const {
  std::ostringstream convert;
  convert << m_Numerator << "/" << m_Denominator;
  return convert.str();
}

