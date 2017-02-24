class Date {
public:
  Date(int d=0, int m=0, int y=0);
  void display(bool eoln=true) const;
private:
  int m_Day, m_Month, m_Year;
};


