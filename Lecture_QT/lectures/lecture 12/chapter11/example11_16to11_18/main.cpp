
#include <QCoreApplication>

#include <iostream>
#include "sstring.h"

using namespace std;

void passByValue(SString sv) {
  cout << "sv @ " << &sv << endl;
    cout << sv << " " << sv.refcount() << endl;
  sv = "somethingelse";
  cout << "sv @ " << &sv << endl;
    cout << sv << " " << sv.refcount() << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SString s = "Hello";
    passByValue(s);
    cout << "s @ " << &s << endl;
        cout << s << " " << s.refcount() << endl;

    return EXIT_SUCCESS; //a.exec();
}
