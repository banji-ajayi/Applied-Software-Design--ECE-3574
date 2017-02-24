#include <string>
#include <sstream>

class Complex {
public:
  Complex(double re=0.0, double im=0.0);

  Complex& operator+= (const Complex& c);
  Complex& operator-= (const Complex& c);

  Complex operator+(const Complex& c2);

  std::string toString() const;
private:
  double m_Re, m_Im;
};

