#ifndef _FRACTION_H_ 
#define _FRACTION_H_ 

#include <string>

class Fraction {
public:
  Fraction (int n=0, int d=0)
    : m_Numerator(n), m_Denominator(d)
  {}
  void set(int numerator, int denominator);
  double toDouble() const;
  std::string toString() const;

  Fraction& operator*= (Fraction f);

private:
  int m_Numerator;
  int m_Denominator;
};

#endif
