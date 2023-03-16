#include "std_lib_facilities.h"

int main() {
  constexpr double dol2dol = 1;  // dollar per dollar
  constexpr double yen2dol = 2;  // dollar per yen
  constexpr double eur2dol = 3;  // dollar per euro
  constexpr double pnd2dol = 4;  // dollar per pound

  cout << "Enter an amount followed by a currency, where:\n"
       << "  'd' = dollar\n"
       << "  'y' = yen\n"
       << "  'e' = euro\n"
       << "  'p' = pound\n";
  double value {0};
  char currency {0};
  cin >> value >> currency;

  if (currency == 'd') {
    cout << "That's " << dol2dol * value << " dollars.\n";
  } else if (currency == 'y') {
    cout << "That's " << yen2dol * value << " dollars.\n";
  } else if (currency == 'e') {
    cout << "That's " << eur2dol * value << " dollars.\n";
  } else if (currency == 'p') {
    cout << "That's " << pnd2dol * value << " dollars.\n";
  } else {
    cout << "I don't recognize the currency '" << currency << "'.\n";
  }

  return 0;
}
