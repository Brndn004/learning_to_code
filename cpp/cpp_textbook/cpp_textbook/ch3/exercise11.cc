#include "std_lib_facilities.h"

int main() {
  cout << "Enter your coins in this order: pennies nickels dimes quarters half-dollars dollars\n";
  int np = 0;
  int nn = 0;
  int nd = 0;
  int nq = 0;
  int nhd = 0;
  int nfd = 0;
  cin >> np >> nn >> nd >> nq >> nhd >> nfd;
  
  int tot_cents = np + 5*nn + 10*nd + 25*nq + 50*nhd + 100*nfd;
  double tot_dollars = tot_cents / 100.0;

  string suffix = "";
  if (np == 1) {
    suffix = "y";
  } else {
    suffix = "ies";
  }
  cout << "  You have " << np << " penn" << suffix << ",\n";

  suffix = "s";
  if (nn == 1)
    suffix = "";
  cout << "           " << nn << " nickel" << suffix << ",\n";

  suffix = "s";
  if (nd == 1)
    suffix = "";
  cout << "           " << nd << " dime" << suffix << ",\n";
  
  suffix = "s";
  if (nq == 1)
    suffix = "";
  cout << "           " << nq << " quarter" << suffix << ",\n";
  
  suffix = "s";
  if (nhd == 1)
    suffix = "";
  cout << "           " << nhd << " half-dollar coin" << suffix << ",\n";
  
  suffix = "s";
  if (nfd == 1)
    suffix = "";
  cout << "       and " << nfd << " one-dollar coin" << suffix << ".\n"
       << "  The total value is: $" << tot_dollars << ".\n";
  return 0;
}
