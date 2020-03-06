#include "std_lib_facilities.h"

int square(int val) {
  if (val < 0) val *= -1;
  int res = 0;
  for (int ii = 0; ii < val; ++ii) res += val;
  return res;
}

int main() {
  cout << "Enter an integer (then press Enter):\n";
  int value = 0;
  cin >> value;
  cout << "  " << value << " * " << value << " == " << square(value) << "\n";
  return 0;
}
