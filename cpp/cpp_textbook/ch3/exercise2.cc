#include "std_lib_facilities.h"

int main() {
  cout << "Enter a number of miles (then press Enter, CTRL+D to stop):\n";
  double miles = 0;
  while (cin >> miles)
    cout << "That's " << to_string(miles * 1.609) << " km.\n";
  return 0;
}
