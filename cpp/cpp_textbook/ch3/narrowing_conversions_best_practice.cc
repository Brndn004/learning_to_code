#include "std_lib_facilities.h"

int main() {
  double d = 0;
  cout << "Enter doubles followed by the Enter key. CTRL+D to quit.\n";
  while (cin>>d) {
    int i {d};
    char c {i};
    int i2 {c};
    cout << "as double:          " << d  << "\n"
         << "as int:             " << i  << "\n"
         << "int val of as char: " << i2 << "\n"
         << "as char:            " << c  << "\n\n";
  }
  return 0;
}
