#include "std_lib_facilities.h"

bool should_be_censored(string ss) {
  if (ss == "broccoli") return true;
  if (ss == "dang") return true;
  if (ss == "shoot") return true;
  if (ss == "dagnabbit") return true;
  return false;
}

int main() {
  cout << "Enter some words. CTRL+D to quit.\n";
  for (string in_str; cin >> in_str;) {
    if (should_be_censored(in_str)) {
      cout << "  You can't just say that!\n";
    } else {
      cout << "  " << in_str << "\n";
    }
  }
  return 0;
}
