#include "std_lib_facilities.h"

int main() {
  string prompt{"Simple calculator (CTRL+D to quit): "};
  cout << prompt;
  
  double val1{0};
  double val2{0};
  char oper{0};
  double result{0};
  
  while (cin >> val1 >> oper >> val2) {
    if (oper == '+') {
      result = val1 + val2;
    } else if (oper == '-') {
      result = val1 - val2;
    } else if (oper == '*') {
      result = val1 * val2;
    } else if (oper == '/') {
      if (val2 == 0) {
        cout << "  Can't divide by zero.\n" << prompt;
	continue;
      } else {
        result = val1 / val2;
      }
    } else {
      cout << "  Sorry, " << oper << " is not a valid operation.\n" << prompt;
      continue;
    }

    cout << "  " << val1 << " " << oper << " " << val2 << " = " << result << "\n";
    cout << prompt;
  }
  cout << "\n";
  return 0;
}
