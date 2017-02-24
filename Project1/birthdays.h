////////////////////////////////////////////////////////
// ECE 3574, Homework 1, Bowei Zhao
//
// File name: birthdays.h
// Description: birthday header file
// Date: 2/5/2016
//
// *-----------------------------------------------* //

#ifndef BIRTHDAYS_H
#define BIRTHDAYS_H

#include <QDate>
#include <QDateTime>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QList>
#include <QTextStream>
#include <QDebug>
#include <QLocale>
#include <QtAlgorithms>
#include <QChar>

#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>
#include <vector>
#include <exception>
#include <stdio.h>



using namespace std;

void initialAdd();

void FileaddTolist(QString nameF, QString birthdayF);

void AddNewBday(QString nameA, QString birthdayA);
 
void WriteContents();

void DeleteEntry(QString selection);

void WithinNumber(QString number);

int PersonWithinNumber(QString nameP, QString numberP);

void GetTodayDate();

void NamePartialSpec(QString nSpec);

void sortDate(int item);

void sortName(int item);

void updateApp();

int ValidInput(QString Nargument, QString Dargument);

// used to store my exception and do a const output
class defErrception: public exception
{
  virtual const char* what() const throw()
  {
    return "   ERROR      ";
  }
} defErr;




#endif // BIRTHDAYS_H
