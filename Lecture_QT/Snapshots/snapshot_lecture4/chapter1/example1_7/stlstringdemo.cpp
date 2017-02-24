#include <string>
#include <iostream>

using namespace std;

int main() {
  string s1("This "), s2("is a "), s3("string."); //initialization

  s1 += s2; //append

  string s4 = s1 + s3; //concatenation
  cout << s4 << endl;

  string s5("The length of that string is: "); //initialization
  cout << s5 << s4.length() << " chars." << endl; //len

  cout << "Enter a sentence: " << endl;
  getline(cin, s2); //read input from console (cin) 

  cout << "Your sentence: \n" << s2 << endl;
  cout << "The length of your string is: " << s2.length() << endl;
  return 0;
}
