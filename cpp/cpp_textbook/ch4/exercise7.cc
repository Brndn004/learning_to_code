#include "std_lib_facilities.h"

double get_val_as_double(string val_str) {
  vector<string> as_words{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  double val{0};

  for (int ii = 0; ii < as_words.size(); ++ii) {
    if (val_str == to_string(ii) or val_str == as_words[ii]) return ii;
  }
  return -1;
}

int main() {
  string prompt{"Simple calculator, enter single-digits only as numbers or words (CTRL+D to quit): "};
  cout << prompt;
  
  string val1_str{""};
  string val2_str{""};
  char oper{0};
  double result{0};
  
  while (cin >> val1_str >> oper >> val2_str) {
    double val1 = get_val_as_double(val1_str);
    double val2 = get_val_as_double(val2_str);
    if (val1 == -1 or val2 == -1) {
      cout << "  Invalid input(s): " << val1_str << " and/or " << val2_str << "\n" << prompt;
      continue;
    }

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
