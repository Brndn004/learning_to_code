#include "std_lib_facilities.h"

int main() {
  cout << "Enter two integers:\n";
  int val1 = 0;
  int val2 = 0;
  cin >> val1 >> val2;
  
  int larger = 0;
  int smaller = 0;
  bool inputs_are_equal = false;
  if (val1 > val2) {
    larger = val1;
    smaller = val2;
  } else if (val2 > val1) {
    larger = val2;
    smaller = val1;
  } else {
    inputs_are_equal = true;
  }

  string larger_or_smaller = "";
  if (inputs_are_equal) {
    larger_or_smaller = to_string(val1) + " == " + to_string(val2);
  } else {
    larger_or_smaller = to_string(larger) + " > " + to_string(smaller);
  }

  int sum = val1 + val2;
  int diff = val1 - val2;
  int product = val1 * val2;
  double ratio = val1 / double(val2);

  cout << "Results:\n"
    << "  " << larger_or_smaller << "\n"
    << "  Sum: " << sum << "\n"
    << "  Difference: " << diff << "\n"
    << "  Product: " << product << "\n"
    << "  Ratio: " << ratio << "\n";

  return 0;
}
