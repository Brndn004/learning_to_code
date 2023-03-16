#include "std_lib_facilities.h"

int main() {
  char current = 'a';
  while (current <= 'z') {
    cout << "  " << current << "\t" << int(current) << "\n";
    ++current;
  }
  return 0;
}
