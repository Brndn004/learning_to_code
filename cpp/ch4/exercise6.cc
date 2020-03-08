#include "std_lib_facilities.h"

int main() {
  vector<string> as_words{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  
  string prompt{"Enter an integer as a number or spelled out (CTRL+D to quit): "};
  cout << prompt;

  for (string val; cin >> val; ) {
    bool failed{true};
    for (int ii = 0; ii < as_words.size(); ++ii) {
      if (val == to_string(ii)) {
        cout << "  " << val << " is the same as " << as_words[ii] << ".\n";
	failed = false;  
      } else if (val == as_words[ii]) {
        cout << "  " << val << " is the same as " << to_string(ii) << ".\n";
	failed = false;
      }
    }
    
    if (failed) cout << "  I don't recognize that input.\n";
    cout << prompt;
  }
  cout << "\n";
  return 0;
}
