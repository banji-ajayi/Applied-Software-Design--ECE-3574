#include <iostream>

using namespace std;

int main() {
  try {
    throw 20;
  }
  catch (int e)
  {
    cout << "Exception number " << e << endl;
  }
  return 0;
}
