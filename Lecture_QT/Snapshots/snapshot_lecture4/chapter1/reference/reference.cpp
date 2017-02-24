#include <iostream>

using namespace std;

int main(){
  int a=10, b=20;
  //int& ra; //uncomment and compile -- error not initialized
  //int& ra; ra = a; //uncomment and compile -- same as before
  int& ra = a;
  cout << "a = " << a
       << " ra = " << ra
       << " b = " << b << endl;

  ra = b;
  cout << "ra = " << ra << endl;
  cout << "a = " << a << endl;

  return 0;
}

