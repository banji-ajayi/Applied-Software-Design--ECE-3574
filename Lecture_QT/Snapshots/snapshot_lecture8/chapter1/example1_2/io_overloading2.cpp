#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
  const int THISYEAR(2016);
  
  string yourName;
  int birthYear;

  cout << "What is your name? " << flush;
  cin >> yourName;

  cout << "What year were you born? ";
  cin >> birthYear;

  cout << "Your name is " << yourName
       << " and you are ";

  cout.operator<<((THISYEAR - birthYear)); // .operator<< insertion operator

  /*cout << " years old." << endl;*/
// it is equivalent to:
  /*cout << " years old.";
  cout << endl;*/
// that is also equivalent to:
  cout.operator<<( &stringbuf(string(" years old.")) );
  cout.operator<<( endl );

  return 0;
}
