#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main() {
  Stack<int> intstack1, intstack2;
  int val;
  for (val =0; val <4; ++val) {
    intstack1.push(val);
    intstack2.push(2 * val);
  }
  while (intstack1.count()) {
    val = intstack1.pop();
    cout << val << endl;
  }
  Stack<string> stringstack;
  stringstack.push("First on");
  stringstack.push("Second on");
  stringstack.push("First off");
  string val2;
  while(stringstack.count()) {
    val2 = stringstack.pop();
    cout << val2 << endl;
  }
  cout << endl;
  return 0;
}
