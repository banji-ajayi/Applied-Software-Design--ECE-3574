#include <QTextStream>
#include "student.h"

QTextStream qtCout(stdout);


/* Student */

Student::Student(QString nm, long id, QString major, int year)
  :m_Name(nm), m_Major(major), m_StudentId(id), m_Year(year) {
  qtCout << "Student Constructor" << endl;
}

QString Student::getClassName() const {
  return "Student";
}

QString Student::toString() const {
  QString retval;
  QTextStream os(&retval);
  os << "[" << getClassName() << "]"
     << " name: " << m_Name
     << "; Id: " << m_StudentId
     << "; Year: " << yearStr()
     << "; Major: " << m_Major;
  return retval;
}

QString Student::yearStr() const {
  return QString("%1").arg(m_Year);
}

/* Undergrad */

Undergrad::Undergrad(QString name, long id, QString major, int year, int sat)
  :Student(name, id, major, year), m_SAT(sat) {
  qtCout << "Undergrad Constructor" << endl;
}

QString Undergrad::getClassName() const {
  return "Undergrad";
}

QString Undergrad::toString() const {
  QString result;
  QTextStream os(&result);
  os << Student::toString()
     << "\n [SAT: "
     << m_SAT
     << " ]\n";
  return result;
}

/* GradStudent */

GradStudent::GradStudent(QString nm, long id, QString major, int yr, Support support)
  :Student(nm, id, major, yr), m_Support(support) {
  qtCout << "GradStudent Constructor" << endl;
}

QString GradStudent::getClassName() const {
  return "GradStudent";
}

QString GradStudent::toString() const {
  return QString("%1%2%3 ]\n")
    .arg(Student::toString())
    .arg("\n [Support: ")
    .arg(supportStr(m_Support));
}

QString GradStudent::supportStr(Support sup) {
  switch(sup) {
  case ta:
    return QString("Teaching Assistant");
    break;
  case ra:
    return QString("Research Assistant");
    break;
  case fellowship:
    return QString("Fellowship");
    break;
  case other:
    return QString("Other");
    break;
  default:
    return NULL;
  }
}



