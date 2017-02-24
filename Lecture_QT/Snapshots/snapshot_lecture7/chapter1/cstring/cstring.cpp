#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char *s1 = "This ", *s2 = "is a ", *s3 = "string.";
  cout << "s1 length is " << strlen(s1) << endl;
  cout << "s2 length is " << strlen(s2) << endl;
  cout << "s3 length is " << strlen(s3) << endl;
  
  char *concat = new char(strlen(s1) + strlen(s2) + strlen(s3) +1);
  strcpy(concat, s1);
  strcat(concat, s2);
  strcat(concat, s3);

  cout << "concat length is " << strlen(concat) << endl;
  cout << concat << endl;

  delete concat;
  return 0;
}
