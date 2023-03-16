#include "std_lib_facilities.h"

int main() {
  cout << "Enter polynomial coefficients, a, b, and c, to represent ax^2 + bx + c:\n";
  double a{0};
  double b{0};
  double c{0};
  cin >> a >> b >> c;

  double root1{(-b + sqrt(b*b - 4*a*c)) / (2*a)};
  double root2{(-b - sqrt(b*b - 4*a*c)) / (2*a)};

  string poly_str{to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c)};
  cout << "  The roots of " << poly_str << " are: " << root1 << " and " << root2 << "\n";

  return 0;
}
