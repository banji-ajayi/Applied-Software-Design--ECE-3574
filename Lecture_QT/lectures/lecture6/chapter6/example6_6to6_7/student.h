#ifndef _STUDENT_H
#define _STUDENT_H

#include <QString>

class Student {
public:
  Student(QString nm, long id, QString major, int year = 1);
  virtual ~Student() { }		//NOTE this is now virtual
  virtual QString getClassName() const;	//NOTE this is now virtual
  //QString toString() const;
  virtual QString toString() const;
private:
  QString m_Name;
  QString m_Major;
  long m_StudentId;
protected:
  int m_Year;
  QString yearStr() const;
};
//////////////////////////////////////////////////////////////////////////////////////
class Undergrad: public Student {
public:
  Undergrad(QString name, long id, QString major, int year, int sat);
  QString getClassName() const;
  QString toString() const;
private:
  int m_SAT; // Scholastic Aptitude Test score total
};
//////////////////////////////////////////////////////////////////////////////////////

class GradStudent: public Student {
public:
  enum Support{ ta, ra, fellowship, other};
  GradStudent(QString nm, long id, QString major, int yr, Support support);
  QString getClassName() const;
  QString toString() const;
protected:
  static QString supportStr(Support sup);
private:
  Support m_Support;
};

#endif /* !_STUDENT_H */

