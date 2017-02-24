#include <string>
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

  cout << " years old." << endl;

  return 0;
}
