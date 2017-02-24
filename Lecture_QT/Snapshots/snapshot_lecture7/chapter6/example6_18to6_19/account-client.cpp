#include <QString>
#include <QTextStream>
#include <QDate>

#include "account.h"

int main() {
  InsecureAccount acct(12345, 321.98, "Luke Skywalker");
  //acct.deposit(6.23); //NOTE Hidden by deposit(double amt, QDate postDate)
  //acct.m_Balance += 6.23; //TRIVIAL m_Balance is protected (NOT PUBLIC!)
  acct.Account::deposit(6.23);

  // more client code here

  return 0;
}
