#include "std_lib_facilities.h"

int main() {
  for (char cc = 'a'; cc <= 'z'; ++cc) {
    cout << "  " << cc << "\t" << int(cc) << "\n";
  }
  return 0;
}
