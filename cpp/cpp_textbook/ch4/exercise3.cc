#include "std_lib_facilities.h"

int main() {
  cout << "Enter distances between consecutive cities (CTRL+D to quit):\n";
  vector<double> distances;
  double sum_dist{0};
  double smallest{0};
  double largest{0};
  bool first_iter{true};
  for (double dist; cin >> dist; ) {
    sum_dist += dist;
    distances.push_back(dist);
    if (first_iter) {
      first_iter = false;
      smallest = dist;
      largest = dist;
    } else {
      if (dist < smallest) smallest = dist;
      if (dist > largest) largest = dist;
    }
  }
  double mean_dist{sum_dist / distances.size()};

  cout << "Results:\n"
       << "  Total distance:    " << sum_dist << "\n"
       << "  Smallest distance: " << smallest << "\n"
       << "  Largest distance:  " << largest << "\n"
       << "  Average distance:  " << mean_dist << "\n";

  return 0;
}
