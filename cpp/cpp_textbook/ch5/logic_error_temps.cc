#include "std_lib_facilities.h"

int main() {
  vector<double> temps;

  string prompt{"Enter all temperatures (CTRL+D to quit): \n"};
  cout << prompt;

  for (double temp; cin >> temp; ) temps.push_back(temp);

  double sum{0};
  double hi{NAN};
  double lo{NAN};
  bool got_first_value{false};

  for (int tt : temps) {
    if (got_first_value) {
      if (tt > hi) hi = tt;
      if (tt < lo) lo = tt;
    } else {
      hi = tt;
      lo = tt;
      got_first_value = true;
    }
    sum += tt;
  }

  cout << "High temp: " << hi << "\n";
  cout << "Low temp:  " << lo << "\n";
  cout << "Avg temp:  " << sum / temps.size() << "\n";

  return 0;
}
