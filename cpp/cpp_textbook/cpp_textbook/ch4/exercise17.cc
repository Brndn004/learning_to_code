#include "std_lib_facilities.h"

int main() {
  string prompt{"Enter a string (CTRL+D to quit): "};
  cout << prompt;
  
  string lo{""};
  string hi{""};
  bool first_iter{true};
  vector<string> all_strings;
  
  for (string val; cin >> val; ) {
    all_strings.push_back(val);
    if (val > hi || first_iter) {
      hi = val;
      cout << "  The largest so far!\n";
    }
    if (val < lo || first_iter) {
      lo = val;
      cout << "  The smallest so far!\n";
    }
    if (first_iter) first_iter = false;
    cout << prompt;
  }

  sort(all_strings);
  string prev_val{""};
  string curr_val{""};
  int max_occurrences{0};
  int num_this_val{0};
  string mode{""};
  for (int ii = 0; ii < all_strings.size(); ++ii) {
    // get current value
    curr_val = all_strings[ii];
    
    // check if current value has been seen before (vector is sorted)
    if (curr_val == prev_val) {
      // if so, increment how many times we have seen this value
      ++num_this_val;
    } else {
      // if not, say that we've seen this value once
      num_this_val = 1;
    }

    // if we've seen this value more than the mode so far, set this value to the mode
    if (num_this_val > max_occurrences) {
        max_occurrences = num_this_val;
	mode = curr_val;
    }

    // prep the loop for the next iteration
    prev_val = curr_val;
  }

  cout << "\nAll values entered:\n";
  for (string val : all_strings) cout << "  " << val << "\n";
  cout << "\n"
       << "Results:\n"
       << "  Largest:     " << hi << "\n"
       << "  Smallest:    " << lo << "\n"
       << "  Mode:        " << mode << "\n"
       << "  Num Entered: " << all_strings.size() << "\n";
  return 0;
}
