#include "std_lib_facilities.h"

double convert_to_meters(double dd, string units, double flag_val) {
  constexpr double cm2m{1.0/100};
  constexpr double in2cm{2.54};
  constexpr double ft2in{12.0};

  if (units == "m") return dd;
  if (units == "cm") return cm2m * dd;
  if (units == "in") return in2cm * cm2m * dd;
  if (units == "ft") return ft2in * in2cm * cm2m * dd;
  return flag_val;
}

int main() {
  string prompt{"Enter number and unit (cm, m, in, ft), e.g. 10 cm, (then press Enter): "};
  cout << prompt;
  
  double val{0};
  string units{""};
  double special_check{-0.123456789101112131415};  // Hopefully none of the answers are actually this
  double as_m{special_check};
  
  double sum_as_m{0};
  vector<double> v_as_m;

  double lo{0};
  double hi{0};
  bool first_iter{true};
  
  while (cin >> val >> units) {
    
    as_m = convert_to_meters(val, units, special_check);
    if (as_m == special_check) {
      cout << "  That's not a valid unit!\n" << prompt;
      continue;
    }
    v_as_m.push_back(as_m);

    sum_as_m += as_m;

    if (as_m > hi || first_iter) {
      hi = as_m;
      cout << "  The largest so far!\n";
    }
    if (as_m < lo || first_iter) {
      lo = as_m;
      cout << "  The smallest so far!\n";
    }

    if (first_iter) first_iter = false;
    cout << prompt;
  }

  sort(v_as_m);
  double prev_val{special_check};
  double curr_val{special_check};
  int max_occurrences{0};
  int num_this_val{0};
  double mode{special_check};
  for (int ii = 0; ii < v_as_m.size(); ++ii) {
    // get current value
    curr_val = v_as_m[ii];
    
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

  cout << "\nAll values entered:\n  ";
  for (double val : v_as_m) cout << val << " ";
  cout << "\n"
       << "Results:\n"
       << "  Largest:     " << hi << " m\n"
       << "  Smallest:    " << lo << " m\n"
       << "  Mode:        " << mode << " m\n"
       << "  Num Entered: " << v_as_m.size() << "\n"
       << "  Sum:         " << sum_as_m << " m\n";
  return 0;
}
