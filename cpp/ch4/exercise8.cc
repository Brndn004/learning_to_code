#include "std_lib_facilities.h"

int main() {
  int grains_total{0};
  bool found_thou{false};
  bool found_mil{false};
  bool found_bil{false};

  for (int ii = 0; ii < 64; ++ii) {
    int on_this_square{1};
    for (int jj = 0; jj < ii; ++jj) 
      on_this_square *= 2;
    grains_total += on_this_square;
    // cout << "  square " << ii << " has " << on_this_square << " grains, " << grains_total << " grains so far.\n";
    if (grains_total >= 1'000 && !found_thou) {
      cout << "  " << ii << " squares needed for at least 1,000 grains total.\n";
      found_thou = true;
    }
    if (grains_total >= 1'000'000 && !found_mil) {
      cout << "  " << ii << " squares needed for at least 1,000,000 grains total.\n";
      found_mil = true;
    }
    if (grains_total >= 1'000'000'000 && !found_bil) {
      cout << "  " << ii << " squares needed for at least 1,000,000,000 grains total.\n";
      found_bil = true;
    }
  }
  return 0;
}
