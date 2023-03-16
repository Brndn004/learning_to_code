#include "std_lib_facilities.h"

int main() {
  cout << "Please enter an integer value: ";
  int n;
  cin >> n;
  double n_for_sqrt = n;
  cout << "  n == " << n << "\n"
    << "  n+1 == " << n+1 << "\n"
    << "  3*n == " << 3*n << "\n"
    << "  n+n == " << n+n << "\n"
    << "  n*n == " << n*n << "\n"
    << "  n/2 == " << n/2 << "\n"
    << "  n%3 == " << n%3 << "\n"
    << "  sqrt(n as double) == " << sqrt(n_for_sqrt) << "\n";
  return 0;
}
