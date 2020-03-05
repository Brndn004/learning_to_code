#include "std_lib_facilities.h"

int main() {
  cout << "Enter the first name of the person you want to write to (then press Enter):\n";
  string first_name;
  cin >> first_name;
  cout << "Enter the first name of a mutual friend (then press Enter):\n";
  string friend_name;
  cin >> friend_name; 
  cout << "Enter this friend's sex [m/f] (then press Enter):\n";
  char friend_sex = '0';
  cin >> friend_sex;
  string friend_pronoun = "them";
  if (friend_sex == 'm') {
    friend_pronoun = "him";
  } else if (friend_sex == 'f') {
    friend_pronoun = "her";
  }
  cout << "Enter your age (then press Enter):\n";
  int age = 0;
  cin >> age;
  if (age <= 0 || age >= 110)
    simple_error("You're kidding!");
  string final_note = "";
  if (age < 12)
    final_note = "Next year you will be " + to_string(age + 1) + ".";
  if (age == 17)
    final_note = "Next year you will be able to vote.";
  if (age > 70)
    final_note = "I hope you are enjoying retirement.";
  cout << "Dear " << first_name << ",\n"
       << "  I've missed you very very much since that last night we were together, "
       << "and will hold that night especially in my memories for years to come.\n"
       << "  Have you seen " << friend_name << " lately? If you see " << friend_pronoun
       << ", tell " << friend_pronoun << " to call me.\n  I heard you had a birthday "
       << "and are now " << age << " years old. " << final_note << "\n               "
       << "    Yours sincerely,\n                       Brandon\n";
  return 0;
}
