#include "std_lib_facilities.h"

int area(int length, int width);  // header to function that calculates the area of a rectangle

int main() {
  int x0 = arena(7);          // error: undeclared function
  int x1 = area(7);           // error: wrong number of args
  int x2 = area("seven", 2);  // error: wrong type
  return 0;
}
