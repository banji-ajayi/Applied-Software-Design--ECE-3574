#include <iostream>

using namespace std;

int main() {
  int* ip = 0;
/*  delete ip;
  if (ip) cout << "non-null" << endl;
  else  cout << "null" << endl; */

  ip = new int;
  int *jp = new int(13);

  *ip = 4;
  cout << "*ip = " << *ip << endl;
  cout << "*jp = " << *jp << endl;

  delete ip;
  delete jp;
  return 0;
}

  
