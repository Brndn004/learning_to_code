#include "std_lib_facilities.h"

int main () {
  cout << "Type words, pressing enter after each. Type CTRL+D to quit.\n";
  string prev = " ";
  string curr;
  while (cin >> curr) {
    if (prev == curr) {
      cout << "Repeated word: " << curr << "\n";
    }
    prev = curr;
  }
  return 0;
}
