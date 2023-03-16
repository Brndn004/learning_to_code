#include "std_lib_facilities.h"

int main() {
  cout << "Enter an operator (+-*/ or plus, minus, mul, div) followed by two operands:\n";
  string oper = "";
  double val1 = 0;
  double val2 = 0;
  cin >> oper >> val1 >> val2;

  if (oper == "+" || oper == "plus") {
    cout << "  " << val1 << " + " << val2 << " == " << val1 + val2 << "\n";
  } else if (oper == "-" || oper == "minus") {
    cout << "  " << val1 << " - " << val2 << " == " << val1 - val2 << "\n";
  } else if (oper == "*" || oper == "mul") {
    cout << "  " << val1 << " * " << val2 << " == " << val1 * val2 << "\n";
  } else if (oper == "/" || oper == "div") {
    if (val2 == 0) {
      cout << "Sorry, can't divide by zero.\n";
    } else {
      cout << "  " << val1 << " / " << val2 << " == " << val1 / val2 << "\n";
    }
  } else {
    cout << "I don't recognize this operator: " << oper << "\n";
  }
  return 0;
}
