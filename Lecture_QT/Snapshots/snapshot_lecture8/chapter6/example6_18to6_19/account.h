class Account { 
public:
  Account(unsigned acctno, double bal, QString owner);
  virtual ~Account() 
  { };
  virtual void deposit(double amt);
  virtual QString toString() const;
  virtual QString toString(char delimiter);

protected:
  unsigned m_AcctNo;
  double m_Balance;
  QString m_Owner;
};

class InsecureAccount: public Account {
public:
  InsecureAccount(unsigned acctno, double bal, QString owner);
  void deposit(double amt, QDate postDate); //NOTE deposit(double a) is hidden
  QString toString() const; //NOTE toString(char d) is not accessible anymore
};


