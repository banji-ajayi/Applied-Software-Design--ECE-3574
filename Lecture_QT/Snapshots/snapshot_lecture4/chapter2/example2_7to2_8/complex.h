#include <string>

class Complex {
public:
  Complex(double real, double im);
  Complex(double real);
  Complex();
  std::string toString() const;

private:
  double m_r, m_i;
};
