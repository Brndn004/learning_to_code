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
    for (string name : names) {
      if (name_in == name) {
        name_already_entered = true;
      }
    }
    if (name_already_entered) {
      cout << "  " << name_in << " already has a score.\n";
    } else {
      names.push_back(name_in);
      scores.push_back(score_in);
    }
    cout << prompt << "Enter \"NoName 0\" to quit.\n  ";
  }

  prompt = "\nEnter a score to search for who has that score: ";
  cout << prompt;
  for (int score_in; cin >> score_in; ) {
    bool found_score{false};
    for (int ii = 0; ii < names.size(); ++ii) {
      int score{scores[ii]};
      if (score == score_in) {
        found_score = true;
        cout << "  " << names[ii] << " has a score of " << score << "\n";
      }
    }
    if (!found_score) cout << "  Score not found.\n";
    cout << prompt;
  }

  cout << "\nAll name-score combinations:\n";
  for (int ii = 0; ii < names.size(); ++ii) {
    cout << "  " << names[ii] << " : " << scores[ii] << "\n";
  }

  return 0;
}
