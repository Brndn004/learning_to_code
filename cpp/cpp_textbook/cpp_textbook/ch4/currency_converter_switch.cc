#include "std_lib_facilities.h"

int main() {
  constexpr double dol2dol = 1;  // dollar per dollar
  constexpr double yen2dol = 2;  // dollar per yen
  constexpr double eur2dol = 3;  // dollar per euro
  constexpr double pnd2dol = 4;  // dollar per pound
  constexpr double yun2dol = 5;  // dollar per yuan
  constexpr double krn2dol = 6;  // dollar per kroner

  cout << "Enter an amount followed by a currency, where:\n"
       << "  'd' = dollar\n"
       << "  'y' = yen\n"
       << "  'e' = euro\n"
       << "  'p' = pound\n"
       << "  'n' = yuan\n"
       << "  'k' = kroner\n";
  double value {0};
  char currency {0};
  cin >> value >> currency;
  switch (currency) {
  case 'd':
    cout << "That's " << dol2dol * value << " dollars.\n";
    break;
  case 'y':
    cout << "That's " << yen2dol * value << " dollars.\n";
    break;
  case 'e':
    cout << "That's " << eur2dol * value << " dollars.\n";
    break;
  case 'p':
    cout << "That's " << pnd2dol * value << " dollars.\n";
    break;
  case 'n':
    cout << "That's " << yun2dol * value << " dollars.\n";
    break;
  case 'k':
    cout << "That's " << krn2dol * value << " dollars.\n";
    break;
  default:
    cout << "I don't recognize the currency '" << currency << "'.\n";
    break;
  }

  return 0;
}
