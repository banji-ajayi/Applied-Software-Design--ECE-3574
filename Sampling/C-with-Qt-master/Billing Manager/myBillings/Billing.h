#ifndef BILLING_H
#define BILLING_H

#include <QDate>
#include <QTime>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>

using namespace std;

class Billing
{
private:
    //file which the constructor reads and destructor writes to
    static QFile sm_fileData;
    //directs all output streamed into here, to stdout
    static QTextStream sm_cout;
    //keeps a list of all entries read from the sm_fileData
    QStringList	m_listBillingEntries;
   // line formater
    void helpParseList( QStringList& list, int i, int& confirm, QString& name, QDate& date, QTime& time1, QTime& time2);

public:
    //constructor
    Billing();

    //destructor
    ~Billing();

    void addBillingEntry(QString name, QString date, QString time1, QString time2);
    void deleteBillingEntry(int confirmNum);

    void printBillingDay(QString date);
    void printBillingName( QString name );
    void printBillingTotal();
};

#endif
