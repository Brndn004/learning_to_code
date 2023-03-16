#include "std_lib_facilities.h"

int main() {
  cout << "Enter a bunch of temperatures (CTRL+D to quit):\n";
  vector<double> temps;
  for (double temp; cin>>temp;)
    temps.push_back(temp);
  cout << "\nResults:\n";

  double sum = 0;
  for (int x : temps) sum += x;
  cout << "  Average temperature: " << sum / temps.size() << '\n';
  
  sort(temps);
  double median{0};
  if (temps.size() % 2 == 1) {
    median = temps[temps.size() / 2];
  } else {
    double left  = temps[temps.size() / 2 - 1];
    double right = temps[temps.size() / 2];
    median = (left + right) / 2.0;
  }
  cout << "  Median temperature: " << median << '\n';
  return 0;
}
