#include "std_lib_facilities.h"

void find_with_binary_search(int lo, int hi) {
  if (lo == hi) {
    cout << "It's " << lo << "!\n";
    return;
  }

  int next_guess = (lo + hi) / 2;
  
  string prompt{"Is it <= " + num2str(next_guess) + "? (y/n): "};
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
  cout << "Think off an integer between 1 and 100. Is is <= 50? (y/n): ";
  bool affirmative{false};
  cin >> affirmative;
  if (affirmative) {
  
  } else {

  }
}
