#include "std_lib_facilities.h"

int main() {
  cout << "Enter a spelled-out number (then press Enter):\n";
  string as_str = "";
  cin >> as_str;

  if (as_str == "zero") {
    cout << "That's a 0.\n";
  } else if (as_str == "one") {
    cout << "That's a 1.\n";
  } else if (as_str == "two") {
    cout << "That's a 2.\n";
  } else if (as_str == "three") {
    cout << "That's a 3.\n";
  } else if (as_str == "four") {
    cout << "That's a 4.\n";
  } else {
    cout << "That's not a number I know.\n";
  }
  return 0;
}
