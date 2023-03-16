#include "std_lib_facilities.h"

int main() {
  cout << "Enter three integers:\n";
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
  cin >> val1 >> val2 >> val3;
  
  int min = val1;
  int mid = val2;
  int max = val3;
  int temp = 0;
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
