#include "std_lib_facilities.h"

int main() {
  cout << "Enter the maximum integer (>=2) for which you want to search: ";
  int max_val{0};
  while (max_val < 2) {
    cin >> max_val;
    if (max_val < 2) cout << "  I need a maximum integer that is >= 2: ";
  }

  vector<int> primes{2};
  for (int ii = 3; ii <= max_val; ++ii) {
    bool is_prime{true};
    for (int jj = 0; jj < primes.size(); ++jj) {
      if (ii % primes[jj] == 0) is_prime = false;
    }
    if (is_prime) primes.push_back(ii);
  }

  cout << "The primes between 1 and " << max_val << " are:\n";
  for (int pp : primes) cout << "  " << pp;
  
  cout << "\n";
  return 0;
}
