class Fraction {
public:
  Fraction(int n, int d) //constructor
    :m_Num(n), m_Den(d) {
    ++s_ctors;
  };
  Fraction(const Fraction& other); //copy constructor
  Fraction& operator=(const Fraction& other); //assignment operator

  Fraction multiply(Fraction f2);
  static std::string report(void);

private:
  int m_Num, m_Den;
  static int s_assigns;
  static int s_copies;
  static int s_ctors;
};
