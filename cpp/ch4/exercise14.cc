#include "std_lib_facilities.h"

int main() {  
  cout << "Enter the maximum integer (>=2) for which you want to search: ";
  int max_val{0};
  while (max_val < 2) {
    cin >> max_val;
    if (max_val < 2) cout << "  I need a maximum integer that is >= 2: ";
  }

  vector<int> reduce_me;
  for (int ii = 2; ii <= max_val; ++ii) reduce_me.push_back(ii);

  vector<int> primes;
  while (reduce_me.size() > 0) {
    primes.push_back(reduce_me[0]);
    for (int ii = reduce_me.size() - 1; ii >= 0; --ii) {
      if (reduce_me[ii] % primes[primes.size() - 1] == 0) reduce_me.erase(reduce_me.begin() + ii);
    }
  }

  cout << "The primes between 1 and " << max_val << " are:\n";
  for (int pp : primes) cout << "  " << pp;
  
  cout << "\n";
  return 0;
}
