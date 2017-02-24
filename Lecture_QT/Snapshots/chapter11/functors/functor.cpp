
#include <iostream>
#include <assert.h>

using namespace std;

class add_x {
public:
  add_x(int x)
    : x(x) { }
  int operator() (int y) const
  { return (x + y); }
private:
  int x;
};

int main () {
  add_x add42(42);
  int i = add42(8);
  assert(i == 50);
  cout << "i: " << i << endl;

  add_x add27(27);
  int l = add27(3);
  assert(l == 30);
  cout << "l: " << l << endl;

  return 0;
}

/* NOTE
 * Despite regular functions, functors can contain state.
 */
