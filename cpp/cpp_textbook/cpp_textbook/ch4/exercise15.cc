#include "std_lib_facilities.h"

int main() {
  cout << "How many primes do you want? (must be >0): ";
  int num_primes{0};
  while (num_primes < 1) {
    cin >> num_primes;
    if (num_primes <= 0) cout << "  I need an integer that is >0: ";
  }

  vector<int> primes{2};
  int ii{3};
  while (primes.size() < num_primes) {
    bool is_prime{true};
    for (int jj = 0; jj < primes.size(); ++jj) {
      if (ii % primes[jj] == 0) is_prime = false;
    }
    if (is_prime) primes.push_back(ii);
    ++ii;
  }

  cout << "The first " << num_primes << " primes are:\n";
  for (int pp : primes) cout << "  " << pp;
  
  cout << "\n";
  return 0;
}
