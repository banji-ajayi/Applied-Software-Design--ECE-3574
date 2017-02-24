#include <QDate>
#include "date.h"
#include <iostream>

using namespace std;

Date::Date(int d, int m, int y)
  : m_Day(d), m_Month(m), m_Year(y)
{
  static QDate currentDate = QDate::currentDate();

  if (m_Day == 0) m_Day = currentDate.day();
  if (m_Month == 0) m_Month = currentDate.month();
  if (m_Year == 0) m_Year = currentDate.year();
}

void Date::display(bool eoln) const
{
  cout << m_Year << "/" << m_Month << '/' << m_Day;
  if (eoln)
    cout << endl;
}
  
