
#include <iostream>

#include "mystring.h"

using namespace std;

void passByValue(MyString sv) {
  cout << "sv @ " << &sv << endl;
  sv = "somethingelse";
  cout << "sv @ " << &sv << endl;
}

int main() { 
  MyString s = "Hello";
  passByValue(s); 
  cout << "s @ " << &s << endl;
}

/* NOTE
 * All memory handling has been taken care inside the class methods,
 * but this doesn't stop the developer/user to have multiple copies 
 * of the same variables sitting around.
 */
