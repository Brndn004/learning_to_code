#include "std_lib_facilities.h"

int main() {
  // This is not meant to compile, but instead to show what names are legal / illegal.
  int j = 0;
  int _j = 0;
  int j_ = 0;
  int 1j = 0;
  int j1 = 0;
  int $j = 0;
  int j$ = 0;
  int ja = 0;
  int aj = 0;
  int j a = 0;
  int a j = 0;
  int j!a = 0;
  int j@a = 0;
  int j#a = 0;
}
