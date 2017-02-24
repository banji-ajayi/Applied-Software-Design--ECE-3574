// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 1
// 2/6/13

#include "Billing.h"

#include <QTextStream>
#include <QCoreApplication>
#include <QStringList>

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);
    QStringList arglst = app.arguments();

    enum POS { none = 0, total = 2, del =3, nameDate =4,  add = 10, name = 11, date = 12};
    POS state = none;

    Billing myBill;

    QTextStream cout(stdout);


    //Parses through input for invalid entry
    switch (argc)
    {

    case total:

        //Checks for correct arglst on total
        if( argc == 2 && arglst[1] == "-total" )
        {
            state = total;
            break;
        }

    case del:

        //Checks for correct arglst on delete
        if( argc == 3)
        {

            //converts arglst into int
            QString num = arglst[2];
            int givenConf = num.toInt();


            if( arglst[1] == "-del" && givenConf >= 1000 )
            {
                state = del;
                break;
            }
        }

    case nameDate:

        //Checks for correct arglst on date and name lists
        if( argc == 4 && arglst[1] == "-list" )
        {
            //Checks for valid date arglst
            if( arglst[2] == "-d" )
            {
                // convert the QString date into a QDate
                QDate newDate = QDate::fromString(arglst[3], "MM/dd/yy");

                // Invalid arglst checking

                // 1. If the date entered is of valid year/month/date
                if (!newDate.isValid())
                {
                    cout << "The date " << date << " is invalid." << endl
                         << "Data should be entered as follows: MM/DD/YY" << endl;
                    break;
                }

                // 2. Check to confirm date given is not a future date
                if( newDate > QDate::currentDate())
                {
                    cout << "The date " << date << "is a future date." << endl
                         << "Enter a current of past date." << endl;
                    break;
                }

                state = date;
                break;
            }

            // Checks for valid namespec
            if( arglst[2] == "-n" )
            {
                state = name;
                break;
            }

            break;
        }

    case add:

        //Checks valid add
        if( argc == 10 && arglst[1] == "-add" && arglst[2] == "-n" && arglst[4] == "-d" && arglst[6] == "-s" && arglst[8] == "-e" )
        {

            // convert the QString date into a QDate
            QDate newDate = QDate::fromString(arglst[5], "MM/dd/yy");


            // Invalid arglst checking
            // 1. If the date entered is of valid year/month/date
            if (!newDate.isValid())
            {
                cout << "The date " << arglst[5] << " is invalid." << endl
                     << "Data should be entered as follows: MM/DD/YY" << endl;
                break;
            }
            // 2. Check to confirm date given is not a future date
            if( newDate > QDate::currentDate() || newDate.year() > 1913 )
            {
                cout << "The date " << arglst[5] << "is an invalid." << endl
                     << "Enter a valid date." << endl;
                break;
            }
            if( newDate.year() == 1913)
            {
                if( newDate.month() > QDate::currentDate().month() )
                {
                    cout << "The date " << arglst[5] << "is an invalid." << endl
                         << "Enter a valid date." << endl;
                    break;
                }

                if( newDate.month() == QDate::currentDate().month() )
                {
                    if( newDate.day() > QDate::currentDate().month() )
                    {
                        cout << "The date " << arglst[5] << "is an invalid." << endl
                             << "Enter a valid date." << endl;
                        break;
                    }
                }
            }

            //Checks for a valid time
            if( arglst[6] == "-s" && arglst[8] == "-e" )
            {
                //Converts QString time into QTime
                QTime newTime1 = QTime::fromString( arglst[7], "hh:mm" );

                //Invalid arglst checking
                // 1. Check for correct format of time hh:mm
                if( !newTime1.isValid() )
                {
                    cout << "The time " << arglst[7] << " is invalid." << endl
                         << "Time should be entered on a 24 hour scale as follows: HH:MM" << endl;
                    break;
                }
                // 2. Checks to confirm date is not in the future
                if( newDate == QDate::currentDate() && newTime1 > QTime::currentTime() )   //use QTime newTime1
                {
                    cout << "The time " << arglst[7] << "is a future time." << endl
                         << "Enter a time that is before the present time." << endl;
                    break;
                }

                //Converts QString time into QTime
                QTime newTime2 = QTime::fromString( arglst[9], "hh:mm" );

                //Invalid arglst checking
                // 3. Check for correct format of time hh:mm
                if( !newTime2.isValid() )
                {
                    cout << "The time " << arglst[7] << " is invalid." << endl
                         << "Time should be entered on a 24 hour scale as follows: HH:MM" << endl;
                    break;
                }
                // 4. Check for valid time period
                if( newTime2 <= newTime1 )
                {
                    cout << "The time period " << arglst[7] << "-" << arglst[9] << " is invalid." << endl
                         << "Enter a valid time period." << endl;    //Use Strings time 1
                    break;
                }
            }

            state = add;
            break;
        }
        else
        {
            //if input parameters are invalid
            cout << "Input is invalid.  Enter one of the following" << endl;
            cout << "ADD: ./myBillings_-add_-n_NAME_-d_DATE_-s_STARTTIME_-e_ENDTIME" << endl;
            cout << "LIST BILLINGS ON DATE GIVEN: ./myBIllings_-list_-d_DATE" << endl;
            cout << "LIST BILLINGS BY NAME GIVEN: ./myBIllings_-list_-n_-NAME" << endl;
            cout << "DELETE BY CONFIRMATION NUMBER GIVEN: ./myBillings_-del_CONFIRMATIONNUMBER" << endl;
            cout << "TOTAL HOURS OF BILLING FOR EACH INDIVIDUAL: ./myBillings_-total" << endl;
        }
    }

    switch (state)
    {

    case none:
        break;

    case nameDate:
        break;

    case add:
    {
        myBill.addBillingEntry( arglst[3], arglst[5], arglst[7], arglst[9] );
        state = none;

        break;
    }
    case date:
    {
        myBill.printBillingDay( arglst[3] );

        state = none;
        break;
    }
    case name:
    {
        myBill.printBillingName( arglst[3]);
        state = none;
        break;
    }
    case del:
    {
        //converts given confrimation number from string to int
        QString num = arglst[2];
        int givenConf = num.toInt();

        myBill.deleteBillingEntry( givenConf );
        state = none;
        break;
    }

    case total:
    {
        myBill.printBillingTotal();
        state = none;
        break;
    }
    }

    return 0;

}
