///////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 2 Problem 2
///////////////////////////////

#include "film.h"

int main() {
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    enum options {Add =1, Find, Remove, Quit};
    FilmList allFilms;

    //continue to process options until quit is selected
    bool quit = true;
    while (quit) {
        cout << "Please select an option to perform" << endl;
        cout << Add << " Add a film to the list of films" << endl;
        cout << Find << " Find a film in the list of films" << endl;
        cout << Remove << " Remove a film from the list of films" << endl;
        cout << Quit << " Exit" << endl;

        QString selection = cin.readLine();
        int iSelection = selection.toInt();

        if (iSelection == Add) {
            cout << "You have selected to add a film. Would you like to: " << endl;
            enum option2 {EducationalFilm =1, EntertainmentFilm, Back};
            cout << EducationalFilm << " Add an Educational Film" << endl;
            cout << EntertainmentFilm << " Add an Entertainment Film" << endl;
            cout << Back << " Return to the previous screen" << endl;

            QString selection2 = cin.readLine();
            int iSelection2 = selection2.toInt();
            Film* pFilm;
            QStringList informationList;

            if(iSelection2 == EducationalFilm) {
                cout << "You have selected to add an Educational film" << endl;
                QString id, title, dir, length, rDate, subject, gLevel;
                cout << "Enter the id: " << flush;
                id = cin.readLine();
                cout << "Enter the Title: " << flush;
                title = cin.readLine();
                cout << "Enter the Director: " << flush;
                dir = cin.readLine();
                cout << "Enter the length of the movie: " << flush;
                length = cin.readLine();
                cout << "Enter the release date of the movie(yyyy-mm-dd): " << flush;
                rDate = cin.readLine();
                cout << "Enter the subject of the movie: " << flush;
                subject = cin.readLine();
                cout << "Enter the grade level for the movie: " << flush;
                gLevel = cin.readLine();
                informationList.append(id);
                informationList.append(title);
                informationList.append(dir);
                informationList.append(length);
                informationList.append(rDate);
                informationList.append(subject);
                informationList.append(gLevel);
                pFilm = new Educational(informationList);
             }

            if(iSelection2 == EntertainmentFilm) {
                cout << "You have selected to add an Entertainment film." << endl;
                QString id, title, dir, length, rDate, genre, rating;
                cout << "Enter the id: " << flush;
                id = cin.readLine();
                cout << "Enter the Title: " << flush;
                title = cin.readLine();
                cout << "Enter the Director: " << flush;
                dir = cin.readLine();
                cout << "Enter the length of the movie: " << flush;
                length = cin.readLine();
                cout << "Enter the release date of the movie(yyyy-mm-dd): " << flush;
                rDate = cin.readLine();
                cout << "For Genre, enter 1 for Action, 2 for Comedy, 3 for SciFi, 4 for Romance" << endl;
                cout << "5 for Suspense, and 6 for Horror: " << flush;
                genre = cin.readLine();
                cout << "For the MPAA rating, enter 1 for G, 2 for PG, 3 for PG-12, 4 for R and 5 for NC-17: " << flush;
                rating = cin.readLine();
                informationList.append(id);
                informationList.append(title);
                informationList.append(dir);
                informationList.append(length);
                informationList.append(rDate);
                informationList.append(genre);
                informationList.append(rating);
                pFilm = new Entertainment(informationList);
            }

            if(iSelection2 == Back) {
                continue; //go back to the start of the program
            }

            bool filmCheck = allFilms.addFilm(pFilm);

            if (filmCheck)
                cout << "The Film was added. You will now return to the main menu." << endl;

        } //End case Add

        if (iSelection == Find) {
            cout << "You have selected to find a film." << endl;
            cout << "Enter the ID of the film you would like to find." << endl;
            cout << "Or if you would like to go back to the main menu, press b." << endl;
            QString selection2 = cin.readLine();

            if (selection2 == "b")
                continue;

            QString id = selection2;
            Film* pFilm = allFilms.findFilm(id);

            if (pFilm == 0)
                cout << "The film was not found. You will now be returned to the main menu." << endl;
            else {
                QString sepChar;
                QString foundFilm = pFilm->toString(true, " ");
                cout << foundFilm << endl;
                cout << "You will now be returned to the main menu" << endl;
            }
        }

        if (iSelection == Remove) {
            cout << "You have selected to remove a film." << endl;
            cout << "Enter the ID of the film you would like to remove." << endl;
            cout << "Or if you would like to go back to the main menu, press b." << endl;
            QString selection2 = cin.readLine();

            if (selection2 == "b")
                continue;

            QString id = selection2;
            bool filmCheck = allFilms.removeFilm(id);

            if (filmCheck)
                cout << "The film you selected was deleted successfully." << endl;
            else
                cout << "The film was not found, so nothing was deleted" << endl;

            cout << "You will now be returned to the main menu." << endl;
        } //End case Remove

        if (iSelection == Quit) {
            quit = false;
        }
    } //End while loop
    return 0;
}//End main

