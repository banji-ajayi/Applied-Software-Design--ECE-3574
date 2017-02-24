///////////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 1
///////////////////////////////////

#include "birthdays_class.h"

//Displays the list of birthdays
void birthdays::displayList(QList<bdayNode> list) {
    QTextStream cout(stdout);
    cout.setFieldWidth(16);
    cout << "Name" << "Birthday" << endl;
    cout << "====" << "========" << endl;

    if (list.isEmpty()){
        cout << "There are no birthdays in the list" << endl;
        return;
    }
    for (int i = 0; i <list.size(); ++i){
        cout << list.at(i).name << list.at(i).date.toString("yyyy-MM-dd") << endl;
    }
    return;
}

//Displays the time left until the birthdays
void birthdays::displayTimeLeft(QList<bdayNode> list){
    QDate current;
    current = current.currentDate();
    QTextStream cout(stdout);
    cout.setFieldWidth(10);
    cout << "Name";
    cout.setFieldWidth(20);
    cout << "Birthday";
    cout.setFieldWidth(25);
    cout << "Time until birthday" << endl;
    cout.setFieldWidth(10);
    cout << "====";
    cout.setFieldWidth(20);
    cout << "========";
    cout.setFieldWidth(25);
    cout << "===================" << endl;

    if (list.isEmpty()){
        cout << "There are no birthdays in the list" << endl;
        return;
    }

    for (int i = 0; i <list.size(); ++i){
        int days = current.daysTo(list.at(i).date);
        int month = days/30;
        days = days % 30;
        int weeks = days/7;
        days = days % 7;
        cout.setFieldWidth(15);
        cout << list.at(i).name << list.at(i).date.toString("yyyy-MM-dd");
        cout.setFieldWidth(2);
        cout << "  ";
        if (month!=0)
            cout << month << " months, ";
        if (weeks!=0)
            cout << weeks << " weeks, ";
        if (days!=0)
            cout << days << " days.";
        cout << endl;
    }
    return;
}

//Lists birthdays within the next 30 days according to the current system clock
void birthdays::listNext30Days(QList<bdayNode> list) {
    QTextStream cout(stdout);
    QDate current;
    current = current.currentDate();
    bool dateCheck = false;
    for (int i = 0; i <list.size(); ++i){
        if (current.daysTo(list.at(i).date) <= 30 && current.daysTo(list.at(i).date) > 0){
            dateCheck = true;
        }
    }

    if (!dateCheck) {
        cout << "There are no birthdays within the next 30 days" << endl;
        return;
    }
    cout.setFieldWidth(16);
    cout << "Name" << "Birthday" << endl;
    cout << "===" << "========" << endl;

    for (int i = 0; i <list.size(); ++i){
        if (current.daysTo(list.at(i).date) <= 30 && current.daysTo(list.at(i).date) > 0){
            cout << list.at(i).name << list.at(i).date.toString("yyyy-MM-dd") << endl;
        }
    }
}

//Sorts the list of birthdays in chronological order
void birthdays::sortBirthdays(QList<bdayNode> &list) {
    bool swap = true;
    for (int i = 0; i <list.size() && swap; ++i){
        swap = false;
        for (int j=0; j<list.size()-1; ++j){
            if (list.at(j).date > list.at(j+1).date){
                list.swap(j, j+1);
                swap = true;
            }
        }
    }
    return;
}

//Sorts the list of birthdays alphabetically by first name
void birthdays::sortBirthdaysAlphabetically(QList<bdayNode>& list) {
    bool swap = true;
    bool kLoopFlag = false;
    for (int i = 0; i <list.size() && swap; ++i){
        swap = false;
        for (int j=0; j<list.size()-1; ++j){
            kLoopFlag = false;
            for (int k=0; k<list.at(j).name.size() && !kLoopFlag; ++k) {
                if (list.at(j).name[k].toLower().toAscii() != list.at(j+1).name[k].toLower().toAscii()){
                    if (list.at(j).name[k].toLower().toAscii() > list.at(j+1).name[k].toLower().toAscii()){
                        list.swap(j, j+1);
                        swap = true;
                        kLoopFlag = true;
                    }
                    else {
                        kLoopFlag = true;
                    }
                }
            }
        }
    }
    return;
}

//Set the birthday given the name and date
void birthdays::setBirthday(QList<bdayNode>& list, QString name, QString sDate) {
    bool nameCheck = false;
    int namePosition = 0;
    for (int i = 0; i <list.size(); ++i){
        if (list.at(i).name == name){
            nameCheck = true;
            namePosition = i;
        }
    }

    bdayNode a;
    QString year;
    for(int i=0; i<4; ++i){
        year+=sDate[i];
    }
    QString month;
    month = sDate[5];
    month += sDate[6];
    QString day;
    day = sDate[8];
    day += sDate[9];
    int intYear = year.toInt();
    int intMonth = month.toInt();
    int intDay = day.toInt();
    a.date.setDate(intYear, intMonth, intDay);
    if (!a.date.isValid()){
        throw "The date entered is invalid";
    }
    //case when name is already in list and only birthdate needs to be updated
    if (nameCheck) {
        list.removeAt(namePosition);
    }
    a.name = name;
    list.append(a);
    return;
}

//Lists birthdays within the number of days entered according to the current system clock
void birthdays::listNextXDays(QList<bdayNode> list, int days) {
    QTextStream cout(stdout);
    QDate current;
    current = current.currentDate();
    bool dateCheck = false;

    for (int i = 0; i <list.size(); ++i){
        if (current.daysTo(list.at(i).date) <= days && current.daysTo(list.at(i).date) > 0){
            dateCheck = true;
        }
    }

    if (!dateCheck) {
        cout << "There are no birthdays in the next " << days << " days" << endl;
        return;
    }

    cout.setFieldWidth(16);
    cout << "Name" << "Birthday" << endl;
    cout << "===" << "========" << endl;

    for (int i = 0; i <list.size(); ++i){
        if (current.daysTo(list.at(i).date) <= days && current.daysTo(list.at(i).date) > 0){
            cout << list.at(i).name << list.at(i).date.toString("yyyy-MM-dd") << endl;
        }
    }
}

//Displays all birthdays that contain the substring entered on the command line
void birthdays::findBirthdaysWith(QList<bdayNode> list, QString name) {
    QTextStream cout(stdout);
    bool stringCheck = false;
    //check if namespec can be found before displaying headers
    for (int i = 0; i <list.size(); ++i){
        if (list.at(i).name.contains(name)){
            stringCheck = true;
        }
    }

    if (!stringCheck) {
        cout << "No names were found matching the namespec entered" << endl;
        return;
    }

    cout.setFieldWidth(16);
    cout << "Name" << "Birthday" << endl;
    cout << "===" << "========" << endl;

    if (list.isEmpty()){
        cout << "There are no birthdays in the list" << endl;
        return;
    }
    for (int i = 0; i <list.size(); ++i){
        if (list.at(i).name.contains(name)){
            cout << list.at(i).name << list.at(i).date.toString("yyyy-MM-dd") << endl;
            stringCheck = true;
        }
    }
    return;
}

//Delete any entry with the same birthday as the one entered on the command line
void birthdays::deleteByDate(QList<bdayNode>& list, QDate date) {
    bool dateCheck = false;
    for (int i = 0; i <list.size(); ++i){
        if (list.at(i).date == date){
            list.removeAt(i);
            dateCheck = true;
            i--; // move i back after removal since items shift after deletion
        }
    }

    if (!dateCheck) {
        throw "The date entered for deletion was not found";
    }
    return;
}

//Delete the entry with the same name as the one entered on the command line
void birthdays::deleteByName(QList<bdayNode>& list, QString name) {
    bool nameCheck = false;
    for (int i = 0; i <list.size(); ++i){
        if (list.at(i).name == name){
            list.removeAt(i);
            nameCheck = true;
        }
    }
    if (!nameCheck) {
        throw "The name entered for deletion was not found";
    }
    return;
}

//Lists birthdays X amount of days after the person entered on the command lines birthday
void birthdays::listNextXDaysAfterPerson(QList<bdayNode> list, QString name, int days) {
    QDate date;
    bool nameCheck = false;
    for (int i = 0; i <list.size(); ++i){
        if (list.at(i).name == name){
            date = list.at(i).date;
            nameCheck = true;
        }
    }
    if (nameCheck == false) {
        throw "The name entered was not found";
    }
    QTextStream cout(stdout);
    bool dateCheck = false;
    for (int i = 0; i <list.size(); ++i){
        if (date.daysTo(list.at(i).date) <= days && date.daysTo(list.at(i).date) > 0){
            dateCheck = true;
        }
    }

    if (!dateCheck) {
        cout << "There are no birthdays " << days << " days after " << name << "'s birthday." << endl;
        return;
    }
    cout.setFieldWidth(16);
    cout << "Name" << "Birthday" << endl;
    cout << "===" << "========" << endl;

    for (int i = 0; i <list.size(); ++i){
        if (date.daysTo(list.at(i).date) <= days && date.daysTo(list.at(i).date) > 0){
            cout << list.at(i).name << list.at(i).date.toString("yyyy-MM-dd") << endl;
        }
    }
    return;
}

//Updates birthdays to within one year
QList<bdayNode> birthdays::updateBirthdays(QList<bdayNode>& list) {
    QDate current;
    QList<bdayNode> updatedList;
    current = current.currentDate();
    for (int i = 0; i <list.size(); ++i){
        //Handle leap year case
        if (list.at(i).date.month()==02 && list.at(i).date.day()==29) {
            if (current.daysTo(list.at(i).date) > 1461) {
                int updateYear = current.year() - list.at(i).date.year();
                QDate tempDate(list.at(i).date.year()+updateYear, list.at(i).date.month(), list.at(i).date.day());
                QString tempName = list.at(i).name;
                bdayNode tempNode;
                tempNode.date = tempDate;
                tempNode.name = tempName;
                list.removeAt(i);
                list.insert(i, tempNode);
                updatedList.append(tempNode);
            }

            else if (current.daysTo(list.at(i).date) < 0) {
                int updateYear = (list.at(i).date.daysTo(current)/365)+4;
                QDate tempDate(list.at(i).date.year()+updateYear, list.at(i).date.month(), list.at(i).date.day());
                QString tempName = list.at(i).name;
                bdayNode tempNode;
                tempNode.date = tempDate;
                tempNode.name = tempName;
                list.removeAt(i);
                list.insert(i, tempNode);
                updatedList.append(tempNode);
            }
        }

        else if (current.daysTo(list.at(i).date) > 365){
            int updateYear = current.year() - list.at(i).date.year();
            QDate tempDate(list.at(i).date.year()+updateYear, list.at(i).date.month(), list.at(i).date.day());
            QString tempName = list.at(i).name;
            bdayNode tempNode;
            tempNode.date = tempDate;
            tempNode.name = tempName;
            list.removeAt(i);
            list.insert(i, tempNode);
            updatedList.append(tempNode);
        }
        else if (current.daysTo(list.at(i).date) < 0) {
            int updateYear = (list.at(i).date.daysTo(current)/365) +1;
            QDate tempDate(list.at(i).date.year()+updateYear, list.at(i).date.month(), list.at(i).date.day());
            QString tempName = list.at(i).name;
            bdayNode tempNode;
            tempNode.date = tempDate;
            tempNode.name = tempName;
            list.removeAt(i);
            list.insert(i, tempNode);
            updatedList.append(tempNode);
        }

    }
    return updatedList;
}
