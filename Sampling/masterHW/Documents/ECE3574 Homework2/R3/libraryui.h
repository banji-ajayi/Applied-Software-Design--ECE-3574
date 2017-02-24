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
        Choices nextTask();
        void prepareToQuit(bool);

    private:
        Library* m_Lib;
};

class RefItemUI {

    public:
        QStringList prompt();
};

class BookUI : public RefItemUI{

    public:
        QStringList prompt();
};

class ReferenceBookUI : public BookUI {

    public:
        QStringList prompt();
};

class TextBookUI : public BookUI{

    public:
        QStringList prompt();
};

class DvdUI : public RefItemUI{

    public:
        QStringList prompt();
};

class FilmUI : public DvdUI{

    public:
        QStringList prompt();
};

class DataBaseUI : public DvdUI{

    public:
        QStringList prompt();
};

#endif // LIBRARYUI_H
