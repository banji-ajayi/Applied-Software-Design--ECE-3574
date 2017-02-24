class SignatureDemo {
public:
  SignatureDemo(int val) : m_Val(val)
    {}
  void demo(int n)
    { cout << ++m_Val << "\tdemo(int)" << endl; }
/*  int demo(int n)
    { cout << ++m_Val << "\tdemo(int)" << endl;
      return m_Val; } */ //ERROR You cannot declare two methods with same arguments and different return type
  void demo(int n) const
    { cout << m_Val << "\tdemo(int) const" << endl; } 
/*  void demo(const int& n) 
    { cout << ++m_Val << "\tdemo(const int&)" << endl; } */ //WRONG on the book! This clashes with "void demo(int n)" not the previous one
  void demo(short s)
    { cout << ++m_Val << "\tdemo(short)" << endl; }
  void demo(float f)
    { cout << ++m_Val << "\tdemo(float)" << endl; }
  void demo(float f) const
    { cout << m_Val << "\tdemo(float) const" << endl; }
  void demo(double d) 
    { cout << ++m_Val << "\tdemo(double)" << endl; }
private:
  int m_Val;
};
