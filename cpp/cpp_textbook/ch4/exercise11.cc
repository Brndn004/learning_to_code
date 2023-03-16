#include "std_lib_facilities.h"

int main() {
  vector<int> primes{2};
  for (int ii = 3; ii <= 100; ++ii) {
    bool is_prime{true};
    for (int jj = 0; jj < primes.size(); ++jj) {
      if (ii % primes[jj] == 0) is_prime = false;
    }
    if (is_prime) primes.push_back(ii);
  }

  cout << "The primes between 1 and 100 are:\n";
  for (int pp : primes) cout << "  " << pp;
  
  cout << "\n";
  return 0;
}
