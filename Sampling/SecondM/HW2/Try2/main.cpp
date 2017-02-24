/////////////////////////////////////////
// Jacob Melton
// 905698368
// jmelton1@vt.edu
// ECE3574
// Homework 2
/////////////////////////////////////////

#include <QCoreApplication>
#include <QTextStream>
#include <film.h>
#include <entertainment.h>
#include <educational.h>
#include <filmlist.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream outStream(stdout);
    QTextStream inStream(stdin);
    FilmList filmList;
    int menuSelection;
    QString removeID, searchTitle, searchID;
    QString id, title, dir, subject;
    QStringList returnedIDs;
    quint32 len;
    QDate relDate;
    Grade grade;
    MPAARatings rtng;
    FilmTypes type;

    while(1) {
        outStream << "Choose a menu item:" << endl
                  << "1 - Add a Film object" << endl
                  << "2 - Add an Entertainment object" << endl
                  << "3 - Add an Educational object" << endl
                  << "4 - Remove a film" << endl
                  << "5 - Get film ID's' by Title" << endl
                  << "6 - Get film details by ID" << endl
                  << "7 - Quit application" << endl;
        menuSelection = inStream.readLine().toInt();
        switch(menuSelection) {
        case 1: {
            outStream << "Enter the Films ID:" << endl;
            id = inStream.readLine();
            outStream << "Enter the Films Title:" << endl;
            title = inStream.readLine();
            outStream << "Enter the Films Director:" << endl;
            dir = inStream.readLine();
            outStream << "Enter the Films Length(numbers > 0):" << endl;
            len = inStream.readLine().toInt();
            while(len <= 0) {
                outStream << "Please enter a number greater than 0..." << endl;
                inStream >> len;
            }
            outStream << "Enter the Films Date (yyyy-MM-dd):" << endl;
            relDate = QDate::fromString(inStream.readLine(), "yyyy-MM-dd");
            while(!relDate.isValid()) {
                outStream << "Please enter a valid date in yyyy-MM-dd format" << endl;
                relDate = QDate::fromString(inStream.readLine(), "yyyy-MM-dd");
            }
            Film newFilm(id, title, dir, len, relDate);
            filmList.addFilm(&newFilm);
        }
            break;
        case 2: {
            outStream << "Enter the Films ID:" << endl;
            id = inStream.readLine();
            outStream << "Enter the Films Title:" << endl;
            title = inStream.readLine();
            outStream << "Enter the Films Director:" << endl;
            dir = inStream.readLine();
            outStream << "Enter the Films Length(numbers > 0):" << endl;
            len = inStream.readLine().toInt();
            while(len <= 0) {
                outStream << "Please enter a number greater than 0..." << endl;
                inStream >> len;
            }
            outStream << "Enter the Films Date (yyyy-MM-dd):" << endl;
            relDate = QDate::fromString(inStream.readLine(), "yyyy-MM-dd");
            while(!relDate.isValid()) {
                outStream << "Please enter a valid date in yyyy-MM-dd format" << endl;
                relDate = QDate::fromString(inStream.readLine(), "yyyy-MM-dd");
            }
            outStream << "Enter the Films type (1-Action, 2-Comedy, 3-SciFi, 4-Horror):" << endl;
            type = static_cast<FilmTypes>(inStream.readLine().toInt());
            outStream << "Enter the Films rating (1-G, 2-PG, 3-PG13, 4-R, 5-NC17):" << endl;
            rtng = static_cast<MPAARatings>(inStream.readLine().toInt());
            Entertainment newEnteraintment(id, title,dir,len, relDate, type, rtng);
            filmList.addFilm(&newEnteraintment);
        }
            break;
        case 3: {
            outStream << "Enter the Films ID:" << endl;
            id = inStream.readLine();
            outStream << "Enter the Films Title:" << endl;
            title = inStream.readLine();
            outStream << "Enter the Films Director:" << endl;
            dir = inStream.readLine();
            outStream << "Enter the Films Length(numbers > 0):" << endl;
            len = inStream.readLine().toInt();
            while(len <= 0) {
                outStream << "Please enter a number greater than 0..." << endl;
                inStream >> len;
            }
            outStream << "Enter the Films Date (yyyy-MM-dd):" << endl;
            relDate = QDate::fromString(inStream.readLine(), "yyyy-MM-dd");
            while(!relDate.isValid()) {
                outStream << "Please enter a valid date in yyyy-MM-dd format" << endl;
                relDate = QDate::fromString(inStream.readLine(), "yyyy-MM-dd");
            }
            outStream << "Enter the Films subjec" << endl;
            subject = inStream.readLine();
            outStream << "Enter the Films grade (A, B, C, D, F):" << endl;
            grade = static_cast<Grade>(inStream.readLine().toInt());
            Educational newEducational(id, title,dir,len, relDate, subject, grade);
            filmList.addFilm(&newEducational);
        }
            break;
        case 4: {
            outStream << "Enter the ID of the Film to remove:" << endl;
            removeID = inStream.readLine();
            filmList.removeFilm(removeID);
        }
            break;
        case 5: {
            outStream << "Enter the Title of the Film you want the ID of:" << endl;
            searchTitle = inStream.readLine();
            returnedIDs = filmList.getID(searchTitle);
            for(int i = 0; i < returnedIDs.size(); i++) {
                outStream << "ID: " << returnedIDs.at(i) << endl;
            }
        }
            break;
        case 6: {
            outStream << "Enter the Films ID to get details:" << endl;
            searchID = inStream.readLine();
            outStream << filmList.findFilm(searchID)->toString(true,"\n");
        }
            break;
        case 7: {
            outStream << "Goodbye." << endl;
            exit(0);
        }
        default: {
            outStream << "Bad menu input. Exiting." << endl;
            exit(0);
        }
        }
    }

    return a.exec();
}
