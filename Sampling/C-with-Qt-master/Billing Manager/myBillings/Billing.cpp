// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 1
// 2/6/13

#include "Billing.h"
#include<cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// Static variables
QFile Billing::sm_fileData("mybillings.dat");
QTextStream Billing::sm_cout(stdout);

Billing::Billing()
{
    sm_fileData.open(QIODevice::ReadOnly);

    QTextStream readFile(&sm_fileData);

    // read line by line and insert into a QStringList
    while (!readFile.atEnd())
    {
        m_listBillingEntries << readFile.readLine();
    }

    sm_fileData.close();

}

Billing::~Billing()
{
    {
        sm_fileData.open(QIODevice::WriteOnly);

        QTextStream writeFile(&sm_fileData);

        // Write every line in the QStringList to the file sm_fileData by
        // reading and popping the top of the list each time.
        while ( !m_listBillingEntries.isEmpty() )
        {
            writeFile << m_listBillingEntries.front() << endl;
            m_listBillingEntries.pop_front();
        }

        sm_fileData.close();
    }
}

//Pareses list entries and returns data
void Billing::helpParseList(QStringList &list, int i, int &confirm, QString &name, QDate &date, QTime &time1, QTime &time2)
{

    //inputs billing entries
    QString element = list[i];
    //extracts date and time
    QString elem = element.split('"')[2];
    //extracts times
    QString elem2 = elem.split(" ")[2];

    //Confirmation number
    QString elem3 =  element.split('"')[0];
    confirm = elem3.toInt();

    //name
    name = element.split('"')[1];


    //Begin time
    time1 = QTime::fromString( elem2.split("-")[0], "hh:mm" );

    //End time
    time2 = QTime::fromString( elem2.split("-")[1], "hh:mm");

    //Date
    date = QDate::fromString( elem.split(" ")[1], "MM/dd/yy");

}

//This function adds a new billing entry to the private string list
void Billing::addBillingEntry( QString name, QString date, QString time1, QString time2 )
{
    //confrimation number
    int confirmNum = m_listBillingEntries.size() + 1000;

    // convert the QString date into a QDate
    QDate givenDate = QDate::fromString(date, "MM/dd/yy");
    givenDate = givenDate.addYears(100);
    date = givenDate.toString("MM/dd/yyyy");
    givenDate = givenDate.addYears(-100);

    //convert int to QString
    QString confirmNumS = QString::number( confirmNum );

    //converts QString to QTime1
    QTime time1Given = QTime::fromString(time1, "hh:mm");

    //converts QString to QTime2
    QTime time2Given = QTime::fromString(time2, "hh:mm");

    int i;

    //Check for overlapping billing times
    for ( i = 0; i < m_listBillingEntries.size(); i++)
    {
        int confirm;
        QString names;
        QTime time1List,time2List;
        QDate dateList;
        helpParseList(m_listBillingEntries, i, confirm, names, dateList, time1List, time2List);

        //Check for overlapping times
        if(givenDate == dateList && confirmNum != 1000 )
        {
            if(time1Given  <= time1List && ( time2Given >= time1List  && time2Given <= time2List ) ||
                    ( time1Given >= time1List && time1Given <= time2List ) && ( time2Given >= time1List && time2Given <= time2List ) ||
                    ( time1Given >= time1List && time1Given <= time2List ) &&  time2Given >= time2List ||
                    time1Given <= time1List && time2Given >= time2List)
            {
                sm_cout << "The time slot " << time1 <<'-' << time2 << " overlaps a current billing." << endl;
                break;
            }
        }
    }

    //inputs billing if no overlap exists
    if( i == ( m_listBillingEntries.size() ) )
    {
        //Stores and outputs final string
        QString newBillingEntry = confirmNumS + " " +'"' + name + '"' + " " + date + " " + time1 + '-' + time2;
        m_listBillingEntries.append(newBillingEntry );
        sm_cout << newBillingEntry << endl;
        confirmNum++;
    }

    //inputs 1st item
    if( confirmNum == 1000)
    {
        //Stores and outputs final string
        QString newBillingEntry = confirmNumS + " " +'"' + name + '"' + " " + date + " " + time1 + '-' + time2;
        m_listBillingEntries.append( newBillingEntry );
        sm_cout << newBillingEntry << endl;
        confirmNum++;
    }
}

void Billing::deleteBillingEntry(int confirmNum )
{
    if( ( confirmNum - 1000 ) > m_listBillingEntries.size() || confirmNum < 1000 )
    {
        sm_cout << "The Confirmation number " << confirmNum << " is invalid." << endl;
    }

    //traverses through list of billing entries
    for ( int i = 0; i < m_listBillingEntries.size(); i++)
    {
        int confirm;
        QString name;
        QDate date;
        QTime time1, time2;
        helpParseList( m_listBillingEntries, i, confirm, name, date, time1, time2);

        // deletes confrimation number if found
        if( confirm == confirmNum )
        {
            m_listBillingEntries.removeAt( i );
            break;
        }
    }
}

void Billing::printBillingDay( QString date )
{
    //traverses through list of billing entries
    for ( int i = 0; i < m_listBillingEntries.size(); i++)
    {
        int confirm;
        QString name;
        QDate dateList;
        QTime time1, time2;
        helpParseList( m_listBillingEntries, i, confirm, name, dateList, time1, time2);

        // outputs date if it matches date given
        if( dateList.toString( "MM/dd/yy" ) == date )
        {
            sm_cout << m_listBillingEntries[i] << endl;
        }
    }
}

void Billing::printBillingName(QString name)
{
    //traverses through list of billing entries
    for ( int i = 0; i < m_listBillingEntries.size(); i++)
    {

        QString element = m_listBillingEntries[i];

        //extract just the name
        QString elem = element.split('"')[1];

        // outputs name if it matches name given
        if( elem.toLower() == name.toLower() )
        {
            sm_cout << m_listBillingEntries[i] << endl;
        }
    }
}

void Billing::printBillingTotal()
{
    QStringList m_listBillingTemp = m_listBillingEntries;

    // Traverses through list
    for ( int i = 0; i < m_listBillingTemp.size(); i++)
    {
        int confirm;
        QString nameGiven;
        QDate date;
        QTime time1Given, time2Given;
        helpParseList( m_listBillingTemp, i, confirm, nameGiven, date, time1Given, time2Given );

        float time = time1Given.secsTo( time2Given );

        int j = i + 1;
        //compares list entries
        while( j < m_listBillingTemp.size())
        {
            int confirm1;
            QString nameList;
            QDate date;
            QTime time1List, time2List;
            helpParseList( m_listBillingTemp, j, confirm1, nameList, date, time1List, time2List );

            if( nameGiven.toLower() == nameList.toLower() )
            {

                //adds to indivduals billing time
                time += time1List.secsTo( time2List );
                m_listBillingTemp.removeAt( j );
            }
            else
            {
                j++;
            }
        }

        //Outputs total for each individual
        time /= 3600;

        cout.precision(2);
        cout << nameGiven.toStdString() << ": " <<  fixed << time << " hours" << endl;
    }
}
