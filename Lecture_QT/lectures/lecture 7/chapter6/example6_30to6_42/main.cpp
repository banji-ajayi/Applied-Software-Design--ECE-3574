#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QDate>

#include "library.h"

QTextStream qtCout(stdout);
QTextStream qtCin(stdin);

enum Choices {READ=1, ADD, FIND, REMOVE, SAVE, LIST, QUIT};
enum Types {BOOK, REFERENCEBOOK, TEXTBOOK, DVD, FILM, DATADVD};
const QStringList TYPES = (QStringList() << "BOOK" << "REFERENCEBOOK" << "TEXTBOOK" << "DVD" << "FILM" << "DATADVD");

bool saved(false);

Choices nextTask() {
    int choice;
    QString response;
    do {
        qtCout << READ << ". Read data from a file.\n"
             << ADD << ". Add items to the Library.\n"
             << FIND << ". Find and dispaly an item.\n"
             << REMOVE << ". Remove an item from the Library.\n"
             << SAVE << ". Save the Library list to a file.\n"
             << LIST << ". Brief listing of Library items.\n"
             << QUIT << ". Exit from this program.\n"
             << "Your choice: " << flush;
        response = qtCin.readLine();
        choice = response.toInt();
    } while (choice < READ or choice > QUIT);
    return  static_cast<Choices>(choice);
}

void add(Library& lib, QStringList objdata) {
    qtCout << objdata.join("[::]") << endl;
    QString type = objdata.first();
    RefItem* ref;
    switch(static_cast<Types>(TYPES.indexOf(type))) {
    case BOOK:
        ref = new Book(objdata);
        lib.addRefItem(ref);
        break;
    case REFERENCEBOOK:
        ref = new ReferenceBook(objdata);
        lib.addRefItem(ref);
        break;
    default:
        qDebug() << "Bad type in add() function";
    }
}

void save(Library& lib) {
    QFile outf("libfile");
    outf.open(QIODevice::WriteOnly);
    QTextStream outstr(&outf);

    outstr << lib.toString(); //serilizer pattern
    outf.close();
}

void read(Library& lib) {
    const QString sep("[::]");
    const int BADLIMIT(5); //max number of bad lines
    QString line, type;
    QStringList objdata;
    QFile inf("libfile");
    inf.open(QIODevice::ReadOnly);
    QTextStream instr(&inf);
    int badlines(0);

    while(not instr.atEnd()) {
        if(badlines >= BADLIMIT) {
            qDebug() << "Too many bad lines! Aborting.";
            return;
        }
        line = instr.readLine();
        objdata = line.split(sep);
        if (objdata.isEmpty()) {
            qDebug() << "Empty line in file!";
            ++badlines;
        }
        else if (not TYPES.contains(objdata.first())) {
            qDebug() << "Bad type in line: " << objdata.join(";;;");
            ++badlines;
        }
        else
            add(lib, objdata);
    }
}

QStringList promptRefItem() {
    const int MAXOPIES(10);
    const int ISBNLEN(13);
    int copies;
    QString str;
    QStringList retval;
    while(1) {
        qtCout << "ISBN(" << ISBNLEN << " digits): " << flush;
        str = qtCin.readLine();
        if (str.length() == ISBNLEN) {
             retval << str;
             break;
        }
    }
    qtCout << "Title: " << flush;
    retval << qtCin.readLine();
    while(1) {
        qtCout << "Number of copies: " << flush;
        copies = qtCin.readLine().toInt();
        if (copies > 0 and copies <= MAXOPIES) {
            str.setNum(copies);
            break;
        }
    }
    retval << str;
    return retval;
}

QStringList promptBook() {
    static const int MINYEAR(!900), MAXYEAR(QDate::currentDate().year());
    int year;
    QStringList retval(promptRefItem());
    QString str;
    qtCout << "Author: " << flush;
    retval << qtCin.readLine();
    qtCout << "Publisher: " << flush;
    retval << qtCin.readLine();
    while (1) {
        qtCout << "Copyright year: " << flush;
        year = qtCin.readLine().toInt();
        if (year >= MINYEAR and year <= MAXYEAR) {
            str.setNum(year);
            break;
        }
    }
    retval << str;
    return retval;
}

QStringList promptReferenceBook() {
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(promptBook());
    QStringList cats(ReferenceBook::getRefCategories());
    while (1) {
        qtCout << "Enter the index of the correct Reference Category: ";
        for (int i=0; i< cats.size(); ++i)
            qtCout << "\n\t(" << i << ") " << cats.at(i);
        qtCout << "\n\t(-1)None of these\t:::" << flush;
        idx = qtCin.readLine().toInt(&ok);
        if (ok) {
            retval << str.setNum(idx);
            break;
        }
    }
    return retval;
}


void enterData(Library& lib) {
    QString typestr;
    while (1) {
        qtCout << "Library item type: " << flush;
        typestr = qtCin.readLine();
        if (not TYPES.contains(typestr)) {
            qtCout << "Please enter one of the following types:\n" << TYPES.join(", ") << endl;
            continue;
        }
        break;
    }
    QStringList objdata;
    switch (TYPES.indexOf(typestr)) {
    case BOOK:
        objdata = promptBook();
        break;
    case REFERENCEBOOK:
        objdata = promptReferenceBook();
        break;
    default:
        qDebug() << "Bad type in enterData()";
    }
    objdata.prepend(typestr);
    add(lib, objdata);
}

void list(Library& lib) {
    qtCout << lib.toString() << endl;
}

void prepareToQuit(Library& lib) {
    QString ans;
    if (not saved) {
        qtCout << "Save data first (Y/N)? " << flush;
        ans = qtCin.readLine().toUpper();
        if(ans.startsWith("Y")) {
            save(lib);
            exit(EXIT_SUCCESS);
        }
    }
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Library lib;
    while (1) {
        switch (nextTask()) {
        case READ:
            read(lib);
            saved = false;
            break;
        case ADD:
            enterData(lib);
            saved = false;
            break;
        case FIND:
            //find(lib);
            break;
        case REMOVE:
            //remove(lib);
            saved = false;
            break;
        case SAVE:
            save(lib);
            saved = true;
            break;
        case LIST:
            list(lib);
            break;
        case QUIT:
            prepareToQuit(lib);
            break;
        default:
            break;
        }
    }

    return EXIT_SUCCESS;
}

