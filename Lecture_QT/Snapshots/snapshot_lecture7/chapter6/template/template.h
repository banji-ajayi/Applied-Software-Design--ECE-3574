/*
 * fraction class was originally introduced in chapter2 example2_3to2_6
 */

#ifndef _FTEMPLATE_H_ 
#define _FTEMPLATE_H_ 

#include <sstream>
#include <string>

template <class T>
class Fraction {
public:
  void set(T numerator, T denominator);
/*  double toDouble() const;*/
  std::string toString() const;
  Fraction<T> square();

private:
  T m_Numerator;
  T m_Denominator;
};

template <class T>
void Fraction<T>::set(T nn, T dd) {
  m_Numerator = nn;
  m_Denominator = dd;
}

/*double Fraction::toDouble() const {
  return 1.0 * m_Numerator / m_Denominator;
}*/

template <class T>
std::string Fraction<T>::toString() const {
  std::ostringstream convert;
  convert << m_Numerator << "/" << m_Denominator;
  return convert.str();
}

template <class T>
Fraction<T> Fraction<T>::square () {
  Fraction<T> fract;
  fract.set(m_Numerator*m_Numerator, m_Denominator*m_Denominator);
  return fract;
}

#endif
