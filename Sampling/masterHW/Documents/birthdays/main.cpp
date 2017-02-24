///////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 1
///////////////////////////////

#include "birthdays_class.h"

int main(int argc, char* argv[]) {
    try {
        QString fileName1, fileName2, fileDate;
        QTextStream cout(stdout);

        QList<bdayNode> bdayList;

        bdayNode fileNode;
        birthdays bdayObject;

        /***************************Process Command line arguments********************************/
        QCoreApplication app(argc, argv);
        QStringList argList = app.arguments(); //argList holds all arguements from the command line
        /*****************************************************************************************/

        /***********************Read in File line by line, store in bdayList**********************/
        QFile bdayFile("/home/thomas/Documents/birthdays/birthdayData.dat");
        QTextStream bdayFileIn(&bdayFile);

        if (!bdayFile.open(QIODevice::ReadOnly)){
            cout << "The file was not opened. Check to see that the file exists" << endl;
        }

        while (!bdayFileIn.atEnd()){
            bdayFileIn >> fileName1 >> fileName2 >> fileDate;
            fileNode.name = fileName1 + " " + fileName2;
            if (fileNode.name == " "){
                continue;
            }
            QString year;
            for(int i=0; i<4; ++i){
                year+=fileDate[i];
            }
            QString month;
            month = fileDate[5];
            month += fileDate[6];
            QString day;
            day = fileDate[8];
            day += fileDate[9];
            int intYear = year.toInt();
            int intMonth = month.toInt();
            int intDay = day.toInt();
            fileNode.date.setDate(intYear, intMonth, intDay);
            if (!fileNode.date.isValid()) {
                throw "An invalid date was entered in the file, it has been removed";
            }
            bdayList.append(fileNode);
        }
        /***************************************************************************************/

        /**************************Handle cases for each arguement******************************/
        bdayObject.sortBirthdays(bdayList); //sort current list from file chronologically before doing anything else

        //birthdays was the only argument entered
        if (argc==2 && argList[1]=="birthdays"){
            bdayObject.sortBirthdays(bdayList);
            bdayObject.listNext30Days(bdayList);
        }

        //sets the birthday for the person entered at the date entered
        else if (argc==5 && argList[1]=="birthdays" && argList[2]=="-a"){
            bdayObject.setBirthday(bdayList,argList[4], argList[3]);
            bdayObject.sortBirthdays(bdayList);
            cout << "The birthday " << argList[3] << " has been set for " << argList[4] << "." << endl;
        }

        //shows birthdays coming up within the number of days entered, based on system time
        else if (argc==4 && argList[1]=="birthdays" && argList[2]=="-n"){
            bdayObject.sortBirthdays(bdayList);
            bdayObject.listNextXDays(bdayList, argList[3].toInt());
        }

        //updates birthdays to within one year
        else if (argc==3 && argList[1]=="birthdays" && argList[2]=="-u") {
            QList<bdayNode> updatedList = bdayObject.updateBirthdays(bdayList);
            bdayObject.sortBirthdays(bdayList);
            if (updatedList.isEmpty())
                cout << "All birthdays are up to date" << endl;
            else {
                cout << "The following birthdays were updated" << endl;
                bdayObject.displayTimeLeft(updatedList);
            }
        }

        //shows all birthdays of people whose names contain the substring entered
        else if (argc==3 && argList[1]=="birthdays"){
            QString namespec = argList[2];;
            for (int i=0; i < argList[2].size(); ++i) {
                if (argList[2][i].isDigit()){
                    throw "A digit was entered, you must enter a name, partial name, or a letter";
                }
                if (argList[2][i].isPunct() || argList[2][i] == '$' || argList[2][i] == '^' ||
                        argList[2][i] == '=' || argList[2][i] == '+' || argList[2][i] == '~' || argList[2][i] == '|') {

                    if (argList[2][i] == '\'' || argList[2][i] == '-') {
                    }
                    else {
                        throw "A special character was entered, you must enter a name, partial name, or a "
                            "letter. You are however allowed to use a ' or a -";
                    }
                }
            }
            bdayObject.sortBirthdaysAlphabetically(bdayList);
            bdayObject.findBirthdaysWith(bdayList, namespec);
        }

        //deletes birthday depending on whether or not the name or date was entered
        else if (argc==4 && argList[1]=="birthdays" && argList[2]=="-d") {
            if (argList[3][4]=='-') {
                QString year;
                for(int i=0; i<4; ++i){
                    year+=argList[3][i];
                }
                QString month;
                month = argList[3][5];
                month += argList[3][6];
                QString day;
                day = argList[3][8];
                day += argList[3][9];
                int intYear = year.toInt();
                int intMonth = month.toInt();
                int intDay = day.toInt();
                bdayObject.deleteByDate(bdayList, QDate(intYear, intMonth, intDay));
            }

            else {
                bdayObject.deleteByName(bdayList, argList[3]);
            }
            bdayObject.displayList(bdayList);
        }

        //Lists all birthdays following the person entered by an x amount of days also entered
        else if (argc==5 && argList[1]=="birthdays" && argList[2]=="-m") {
            bdayObject.sortBirthdays(bdayList);
            bdayObject.listNextXDaysAfterPerson(bdayList, argList[3], argList[4].toInt());
        }

        else {
            throw "The command you entered was invalid. Check to make sure you entered the command correctly then try again.";
        }
        /**************************************************************************************/

        /*************************Rewrite new data to the initial file*************************/
        bdayFile.resize(0); //clear the file
        bdayFile.close();
        bdayFile.open(QIODevice::WriteOnly);
        QTextStream bdayFileOut(&bdayFile);

        for (int i =0; i < bdayList.length(); i++) {
            bdayFileOut << bdayList[i].name << " " << bdayList[i].date.toString("yyyy-MM-dd") << endl;
        }
        /**************************************************************************************/
    }
    catch (const char *err){
        qDebug() << err;
    }
    return 0;
}

