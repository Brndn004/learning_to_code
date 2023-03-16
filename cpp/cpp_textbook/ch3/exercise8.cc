#include "std_lib_facilities.h"

int main() {
  cout << "Enter an integer:\n";
  int val = 0;
  cin >> val;

  string res = "odd";
  if (val % 2 == 0)
    res = "even";

  cout << val << " is " << res << ".\n";
  return 0;
}
