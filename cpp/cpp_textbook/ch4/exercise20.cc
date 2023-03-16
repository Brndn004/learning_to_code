#include "std_lib_facilities.h"

int main() {
  string prompt{"Enter a name and a score (e.g. Brandon 4). Do not repeat a name.\n  "};
  cout << prompt;
  vector<string> names;
  vector<int> scores;
  string name_in{""};
  int score_in{0};
  while (cin >> name_in >> score_in) {
    bool name_already_entered{false};
    if (name_in == "NoName" && score_in == 0) break;
    for (int ii = 0; ii < names.size(); ++ii ) {
      if (name_in == names[ii]) {
        name_already_entered = true;
        cout << "  " << name_in << " already has a score of " << scores[ii] << ".\n";
      }
    }
    if (!name_already_entered) {
      names.push_back(name_in);
      scores.push_back(score_in);
    }
    cout << prompt << "Enter \"NoName 0\" to quit.\n  ";
  }

  cout << "\nYou entered:\n";
  for (int ii = 0; ii < names.size(); ++ii) {
    cout << "  " << names[ii] << " : " << scores[ii] << "\n";
  }

  return 0;
}
