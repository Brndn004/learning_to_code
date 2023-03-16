#include "std_lib_facilities.h"


// Notes:
// 1. I permit zero-valued areas, even though the text does not.
// 2. I "cout" errors instead of raising them so that the program can continue past them for demonstration purposes.
// 3. I didn't try too hard to catch /every/ error here. There are likely more not considered.


int area(int length, int width) {
  if (length < 0 || width < 0) cout << "ERROR: Non-positive area() arg(s).\n";
  return length*width;
}


int framed_area(int x, int y) {
  int frame_width{2};
  if (x - frame_width < 0 || y - frame_width < 0) cout << "ERROR: Framed area < 0\n"; 
  return area(x - frame_width, y - frame_width);
}

int f(int x, int y, int z) {
  cout << "X, Y, Z: " << x << ", " << y << ", " << z << "\n";
  int area1 = area(x, y);
  cout << "  area1: " << area1 << "\n";
  int area2 = framed_area(x, z);
  cout << "  area2: " << area2 << "\n";
  int area3 = framed_area(y, z);
  cout << "  area3: " << area3 << "\n";
  if (area3 == 0) cout << "ERROR: dividing by zero-valued arrea.\n";
  double ratio = double(area1)/area3;
  cout << "  ratio: " << ratio << "\n\n";
}


int main() {
  vector<int> x_vec{-1, 0, 1, 2, 3, 4};
  vector<int> y_vec{-1, 0, 1, 2, 3, 4};
  vector<int> z_vec{-1, 0, 1, 2, 3, 4};

  for (int xx : x_vec) {
    for (int yy : y_vec) {
      for (int zz : z_vec) {
        int res{f(xx, yy, zz)};
      }
    }
  }
  return 0;
}
