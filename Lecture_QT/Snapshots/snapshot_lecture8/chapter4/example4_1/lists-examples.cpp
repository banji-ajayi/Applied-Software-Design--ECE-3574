#include <QStringList>
#include <QTextStream>

QTextStream qtCout(stdout);

int main () {
  QString winter = "December, January, February";
  QString spring = "March, April, May";
  QString summer = "June, July, August";
  QString fall = "September, October, November";

  QStringList list;
  list << winter;
  list += spring;
  list.append(summer);
  list << fall;
  qtCout << "The Spring months are: " << list[1] << endl;
  qtCout << "The Fall months are: " << list[3] << endl;

  QString allmonths = list.join(", ");
  qtCout << "All months are: " << allmonths << endl; 

  QStringList list2 = allmonths.split(", ");
  /* split is the opposite of join */
  Q_ASSERT(list2.size() == 12);

/*
  foreach (const QString &str, list) {
    qtCout << QString(" [%1] ").arg(str) << endl;
  }

  for (QStringList::iterator it = list.begin();
       it != list.end();
       ++it) {
    QString current = *it;
    qtCout << "[[" << current << "]]" << endl;
  }

  QListIterator<QString> itr(list2);
  while (itr.hasNext()) {
    QString current =itr.next();
    qtCout << "{" << current << "}" << endl;
  }
*/

  return 0;
}

