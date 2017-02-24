#include <QTextStream>
#include <QString>
#include <QDate>

QTextStream qtCin(stdin);
QTextStream qtCout(stdout);
QTextStream qtCerr(stderr);

int promptInt(int base = 10) {
  bool ok;
  QString ans;
  ans = qtCin.readLine();
  return ans.toInt(&ok, base);
}

int main() {
  QDate d1(2002, 4, 1), d2(QDate::currentDate());
  int days;

  qtCout << "The first data is: " << d1.toString() << endl
         << "Today's date is: " << d2.toString("ddd MMM d, yyyy") << endl;

  if (d1 < d2)
    qtCout << d1.toString("MM/dd/yy") << " is earlier than "
           << d2.toString("yyyyMMdd") << endl;

  qtCout << "There are " << d1.daysTo(d2)
         << " days between " << d1.toString("MMM dd, yyyy")
         << " and " << d2.toString(Qt::ISODate) << endl;

  qtCout << "Enter number of days to add to the first date: " << flush;
  days = promptInt();
  qtCout << "The first date was " << d1.toString() << endl
         << "The computed date is " << d1.addDays(days).toString() << endl;

  qtCout << "First date displayed in longer format: "
         << d1.toString("dddd, MMMM dd, yyyy") << endl;

  return 0;         
}


