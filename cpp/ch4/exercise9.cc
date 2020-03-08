#include "std_lib_facilities.h"

int main() {
  int grains_total_int{0};
  double grains_total_double{0};
  bool found_thou{false};
  bool found_mil{false};
  bool found_bil{false};

  for (int ii = 0; ii < 64; ++ii) {
    int on_this_square_int{1};
    double on_this_square_double{1};
    for (int jj = 0; jj < ii; ++jj) {
      on_this_square_int *= 2;
      on_this_square_double *= 2;
    }
    grains_total_int += on_this_square_int;
    grains_total_double += on_this_square_double;
    
    if (grains_total_int >= 1'000 && !found_thou) {
      cout << "  " << ii << " squares needed for at least 1,000 grains total.\n";
      found_thou = true;
    }
    if (grains_total_int >= 1'000'000 && !found_mil) {
      cout << "  " << ii << " squares needed for at least 1,000,000 grains total.\n";
      found_mil = true;
    }
    if (grains_total_int >= 1'000'000'000 && !found_bil) {
      cout << "  " << ii << " squares needed for at least 1,000,000,000 grains total.\n";
      found_bil = true;
    }

    cout << "\n  square: " << ii << "\n  tot int: " << grains_total_int << "\n  tot double: " << grains_total_double << "\n";
  }
  return 0;
}
