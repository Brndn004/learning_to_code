#include "std_lib_facilities.h"

char get_computer_choice(double ii) {
  vector<char> choices{'r', 'p', 's'};
  int pretend_random = abs(int(1.0 + (ii * ii) / 2.0  + (ii * ii * ii) / 3.0) % 3);
  return choices[pretend_random];
}

int main() {
  cout << "Enter 5 numbers: ";
  vector<double> seeds;
  for (int ii = 0; ii < 5; ++ii) {
    double val{0}; 
    cin >> val;
    seeds.push_back(val);
  }

  string tie_msg{"  It's a tie.\n"};
  string win_msg{"  You won!\n"};
  string lose_msg{"  You lost.\n"};

  int rounds_played{0};
  string prompt{"Enter your choice (r = rock, p = paper, s = scizzors, CTRL+D to quit): "};
  cout << prompt;

  for (char player_choice; cin >> player_choice; ) {

    char computer_choice = get_computer_choice(seeds[rounds_played++ % seeds.size()]);
    cout << "  You played " << player_choice << " and the computer played " << computer_choice << ".\n";
    
    switch (player_choice) {
    case 'r':
      if (computer_choice == 'r') cout << tie_msg;
      if (computer_choice == 'p') cout << lose_msg;
      if (computer_choice == 's') cout << win_msg;
      break;
    case 'p':
      if (computer_choice == 'r') cout << win_msg;
      if (computer_choice == 'p') cout << tie_msg;
      if (computer_choice == 's') cout << lose_msg;
      break;
    case 's':
      if (computer_choice == 'r') cout << lose_msg;
      if (computer_choice == 'p') cout << win_msg;
      if (computer_choice == 's') cout << tie_msg;
      break;
    default:
      cout << "  I don't recognize " << player_choice << ".\n";
    }
    
    cout << "\n" << prompt;
  }
  
  cout << "\n";
  return 0;
}
