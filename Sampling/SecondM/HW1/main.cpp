/////////////////////////////////////////
// Jacob Melton
// 905698368
// jmelton1@vt.edu
// ECE3574
// Homework 1
/////////////////////////////////////////

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QTextStream>
#include <QStringList>
#include <QRegExp>
#include <QDebug>
#include <QFile>
#include <vector>
#include <person.h>
#include <getopt.h>

// This function takes a filename and opens that file and then reads the
// data into a data structure in memory, namely a vector of Person objects
// and then returns that object.
std::vector<Person> readDatafile(QString filename) {
    QFile file(filename);
    try {
        if(!file.open(QIODevice::ReadOnly))
            throw 5;
    }
    catch (int exc) {
        qCritical() << "Caught exception while attemtpting to open file. Exception number: " << exc;
    }

    // Declare somevariables
    QTextStream inStream(&file);
    QStringList fields;
    QString name;
    QDate birthday;

    std::vector<Person> people;
    Person newPerson;

    // Read in from our stream line by line and build our vector of Person objects
    // until we hit the end of the file
    while(!inStream.atEnd()) {
        fields = inStream.readLine().split(",");

        name = fields[0];
        birthday = QDate::fromString(fields[1], "yyyy-MM-dd");
        newPerson = Person(name, birthday);

        people.push_back(newPerson);
    }
    // Return the completed object
    return people;
}

int main(int argc, char *argv[])
{
    // Initialize all our variables
    QCoreApplication myApplication(argc, argv);
    QString newName;
    QString delName;
    QString originName;
    QDate newBirthday;
    QDate delBirthday;
    int days;
    int c;

    // create a regex to do some checking of date formats
    QRegExp dateRegex("\\d{4}-\\d{2}-\\d{2}");

    // make a vector to store our people objects
    std::vector<Person> people;
    people = readDatafile("birthdays.dat");

    // Handle options a, n, d, m, and u
    while ((c = getopt(argc, argv, "a:n:d:m:u")) != EOF) {
        switch (c) {
        case 'a':
            // Check if we got an invalid date and throw an exception if so
            try {
                newBirthday = QDate::fromString(optarg, "yyyy-MM-dd");
                if (!newBirthday.isValid())
                    throw 1;
            }
            catch (int exc) {
                qCritical() << "Caught exception number " << exc << ". Invalid date provided.";
                break;
            }
            // Now just call the function to add entires
            newName = argv[optind];
            addEntry(people, newName, newBirthday);
            break;
        case 'n':
            // Get the day range were looking for and call the version of showBirthdays we need
            days = atoi(optarg);
            showBirthdays(people, days);
            break;
        case 'd':
            // First check if its event a date format
            if(dateRegex.indexIn(optarg) != -1) {
                // Then handle exceptions for invalid date format
                try {
                    delBirthday = QDate::fromString(optarg, "yyyy-MM-dd");
                    if (!delBirthday.isValid())
                        throw 1;
                }
                catch (int exc) {
                    qCritical() << "Caught exception number " << exc << ". Invalid date provided.";
                    break;
                }
                // Lastly delete the entry
                delEntry(people, delBirthday);
            }
            // If it wasnt a date then we're deleting a name so call that version of delete instead
            else {
                delName = optarg;
                delEntry(people, delName);
            }
            break;
        case 'm':
            // get the name we want to start at the date of and how many days in the future to go
            originName = optarg;
            days = atoi(argv[optind]);
            // and call the right version of showBirthdays
            showBirthdays(people, originName, days);
            break;
        case 'u':
            // we simply just call the updateBirthdays function
            updateBirthdays(people);
            break;
        }
    }

    // Handle a NAMESPEC option
    if (argc > 1 && optind == 1) {
        // Grab the namespec and call the right showBirthdays function
        QString namespec = argv[1];
        showBirthdays(people, namespec);
    }
    // Empty options with no NAMESPEC should call showBirthdays with defaults
    else if (optind == 1) {
        showBirthdays(people);
    }

    // Write our data when we're done making modifications
    writeDatafile("birthdays.dat", people);
    exit(1);
    return myApplication.exec();
}


// This function just re-serializes the Person vector and puts it in a file
void writeDatafile(QString filename, std::vector<Person> people) {
    // Open the file and declare variables
    QFile file(filename);
    try {
        if(!file.open(QIODevice::WriteOnly))
            throw 5;
    }
    catch (int exc) {
        qCritical() << "Caught exception while attemtpting to open file. Exception number: " << exc;
    }

    QTextStream outStream(&file);

    // Now proceed through all elements of the vector and write to the stream/file
    foreach (Person person, people) {
        outStream << person.getName() << ","
                  << person.getBirthday().toString("yyyy-MM-dd") << endl;
    }
    file.close();
}

// This function finds the QDate variable for the birthday of the person with the name
// originName
QDate findOriginDate(std::vector<Person> people, QString originName) {
    // We iterate through the vector looking for the element with the name we want
    for (std::vector<Person>::size_type i = 0; i != people.size(); i++) {
        Person originPerson = people.at(i);
        // When we find it we take and return the QDate variable we got
        if (originPerson.getName() == originName) {
            QDate originDate = originPerson.getBirthday();
            return originDate;
        }
    }
    // If we are unable to find a name matching originName we should throw an exception
    // This should be caught by the calling function
    throw 2;
}

// This function will add an entry to our datastructure, if the entry exists
// then it will update it instead.
int addEntry(std::vector<Person> &people, QString addName, QDate addBirthday) {
    Person newPerson;

    // Search for it to check if we should update
    for (std::vector<Person>::size_type i = 0; i != people.size(); i++) {
        Person tempPerson = people.at(i);
        if (tempPerson.getName() == addName) {
            people.at(i).setBirthday(addBirthday);
            // return 1 for an update operation
            return 1;
        }
    }
    newPerson = Person(addName, addBirthday);
    people.push_back(newPerson);
    // return 0 for an addition operation
    return 0;
}

// This function deletes an entry by name
void delEntry(std::vector<Person> &people, QString delName) {
    for (std::vector<Person>::size_type i = 0; i != people.size(); i++) {
        Person tempPerson = people.at(i);
        if (tempPerson.getName() == delName) {
            people.erase(people.begin() + i);
            break;
        }
    }
}

// This function deletes an entry by birthday
void delEntry(std::vector<Person> &people, QDate delDate) {
    for (std::vector<Person>::size_type i = 0; i != people.size(); i++) {
        Person tempPerson = people.at(i);
        if (tempPerson.getBirthday() == delDate) {
            people.erase(people.begin() + i);
            break;
        }
    }
}

// This is the default show people with a time span of 30 days.
void showBirthdays(std::vector<Person> people) {
    int days = 30;
    int timeFrame = 0;

    qDebug() << "Name\t\t\t Birthday" << endl
             << "====\t\t\t ========";
    // Go through the vector
    for (std::vector<Person>::size_type i = 0; i != people.size(); i++) {
        Person tempPerson = people.at(i);
        // get the time difference between the entry and now
        timeFrame = QDate::currentDate().daysTo(tempPerson.getBirthday());
        // does it fall in the right range?
        if (timeFrame <= days && timeFrame >= 0) {
            // if so we print it.
            qDebug() << qPrintable(tempPerson.getName()) << "\t\t"
                     << qPrintable(tempPerson.getBirthday().toString("yyyy-MM-dd"));
        }
    }
}

// This function behaves the same way as the previous but takes a
// parameter for the number of days
void showBirthdays(std::vector<Person> people, int days) {
    int timeFrame = 0;

    qDebug() << "Name\t\t\t Birthday" << endl
             << "====\t\t\t ========";
    for (std::vector<Person>::size_type i = 0; i != people.size(); i++) {
        Person tempPerson = people.at(i);
        timeFrame = QDate::currentDate().daysTo(tempPerson.getBirthday());
        if (timeFrame <= days && timeFrame >= 0) {
            qDebug() << qPrintable(tempPerson.getName()) << "\t\t"
                     << qPrintable(tempPerson.getBirthday().toString("yyyy-MM-dd"));
        }
    }
}

// This shows all entrys which have names which contain the namespec
// Uses the QString contains function
void showBirthdays(std::vector<Person> people, QString namespec) {
    qDebug() << "Name\t\t\t Birthday" << endl
             << "====\t\t\t ========";
    for (std::vector<Person>::size_type i = 0; i != people.size(); i++) {
        Person tempPerson = people.at(i);
        if(tempPerson.getName().contains(namespec, Qt::CaseInsensitive)) {
            qDebug() << qPrintable(tempPerson.getName()) << "\t\t"
                     << qPrintable(tempPerson.getBirthday().toString("yyyy-MM-dd"));
        }
    }
}

// This function uses the birthday of the entry with originName instead of the
// current date. it also must be given the days after that birthday to search in.
void showBirthdays(std::vector<Person> people, QString originName, int days) {
    int timeFrame = 0;
    QDate originDate;

    // Getting the origin date and handling a non-existant name
    try {
        originDate = findOriginDate(people, originName);
    }
    catch (int exc) {
        qCritical() << "Caught exception number " << exc << ". Name provided not found in database.";
    }

    qDebug() << "Name\t\t\t Birthday" << endl
             << "====\t\t\t ========";
    for (std::vector<Person>::size_type i = 0; i != people.size(); i++) {
        Person tempPerson = people.at(i);
        timeFrame = originDate.daysTo(tempPerson.getBirthday());
        if (timeFrame <= days && timeFrame >= 0) {
            qDebug() << qPrintable(tempPerson.getName()) << "\t\t"
                     << qPrintable(tempPerson.getBirthday().toString("yyyy-MM-dd"));
        }
    }
}

// This function updates the birthdays
void updateBirthdays(std::vector<Person> &people) {
    QDate oldBirthday;
    int oldYear;
    int currentYear = QDate::currentDate().year();

    // We iterate over all entries
    for (std::vector<Person>::size_type i = 0; i != people.size(); i++) {
        // Make all the dates have the same year.
        oldBirthday = people.at(i).getBirthday();
        oldYear = oldBirthday.year();
        people.at(i).setBirthday(oldBirthday.addYears(currentYear - oldYear));

        // Now check if the day has already passed this year.
        // If it has make that birthdays date 1 year in the futue
        oldBirthday = people.at(i).getBirthday();
        if (oldBirthday < QDate::currentDate())
            people.at(i).setBirthday(oldBirthday.addYears(1));
    }
}
