#ifndef LIBRARYUI_H
#define LIBRARYUI_H

#include "library.h"

class LibraryUI {

    public:
        enum Choices {Read =1, Add, Find, Remove, Save, List, Quit};
        LibraryUI(Library* lib);
        void add(QStringList);
        void read();
        void enterData();
        QString find();
        void remove();
        void save();
        void list();
        QStringList promptRefItem();
        QStringList promptBook();
        QStringList promptReferenceBook();
        QStringList promptTextBook();
        QStringList promptDVD();
        QStringList promptFilm();
        QStringList promptDataBase();
        Choices nextTask();
        void prepareToQuit(bool);

    private:
        Library* m_Lib;
};

#endif // LIBRARYUI_H
