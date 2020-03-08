#include "std_lib_facilities.h"

void find_with_binary_search(int lo, int hi) {
  if (lo == hi) {
    cout << "It's " << lo << "!\n";
    return;
  }

  int next_guess = (lo + hi) / 2;
  
  string prompt{"Is it <= " + to_string(next_guess) + "? (y/n): "};
  cout << prompt;
  char response{0};
  while (response != 'y' and response != 'n') {
    cin >> response;
    if (response != 'y' and response != 'n') cout << "I don't recognize that answer!\n" << prompt;
  }

  if (response == 'y') {
    find_with_binary_search(lo, next_guess);
  } else {
    find_with_binary_search(next_guess + 1, hi);
  }
}

int main() {
  cout << "Think off an integer between 1 and 100. Is it <= 50? (y/n): ";
  char response{0};
  cin >> response;
  if (response == 'y') {
    find_with_binary_search(1, 50);
  } else {
    find_with_binary_search(51, 100);
  }
  return 0;
}
