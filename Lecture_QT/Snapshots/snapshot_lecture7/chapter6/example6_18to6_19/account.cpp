#include <QString>
#include <QTextStream>
#include <QDate>

#include "account.h"

QTextStream qtCout(stdout);

Account::Account(unsigned acctno, double bal, QString owner)
  :m_AcctNo(acctno), m_Balance(bal), m_Owner(owner) {
  qtCout << "Account::Account " << endl;
}

void Account::deposit(double amt) {
  m_AcctNo += amt;
  qtCout << "Account::deposit " << m_AcctNo << endl;
}

QString Account::toString() const {
  return QString("Account [%1] {%2} (%3)")
    .arg(m_AcctNo)
    .arg(m_Balance)
    .arg(m_Owner);
}
  
QString Account::toString(char delimiter) {
  return QString("Account %1%2%3%4%5")
    .arg(m_AcctNo).arg(delimiter)
    .arg(m_Balance).arg(delimiter)
    .arg(m_Owner);
}

InsecureAccount::InsecureAccount(unsigned acctno, double bal, QString owner)
//  :m_AcctNo(acctno), m_Balance(bal), m_Owner(owner) { //ERROR
//  :Account::m_AcctNo(acctno), Account::m_Balance(bal), Account::m_Owner(owner) {
  :Account(acctno, bal, owner) { //OK
//{ Account::Account(acctno, bal, owner); //ERROR the compiler wants the default constructur of Account (that we don't provide)
  qtCout << "InsecureAccount::InsecureAccount " << endl;
}

void InsecureAccount::deposit(double amt, QDate postdate) {
  m_AcctNo += amt;
  qtCout << "InsecureAccount::deposit " << m_AcctNo << endl;
}

QString InsecureAccount::toString() const {
  return QString("InsecureAccount [%1] {%2} (%3)")
    .arg(m_AcctNo)
    .arg(m_Balance)
    .arg(m_Owner);
}

