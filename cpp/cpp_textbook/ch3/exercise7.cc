#include "std_lib_facilities.h"

int main() {
  cout << "Enter three strings:\n";
  string val1 = "";
  string val2 = "";
  string val3 = "";
  cin >> val1 >> val2 >> val3;
  
  string min = val1;
  string mid = val2;
  string max = val3;
  string temp = "";
  int count = 0;
  while (min > mid || min > max || mid > max) {
    // Approach: "rotate" until in order since only 3 values
    if (count == 2) {
      // The numbers are in a bad order. Change the order and try again.
      temp = min;
      min = max;
      max = temp;
    }
    temp = min;
    min = mid;
    mid = max;
    max = temp;
    ++count;
  }

  cout << "In order:\n  " << min << " " <<  mid << " " << max << "\n";
  return 0;
}
