#include <stdio.h>

int main() {
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);

    return 0;
}

void guessNumber(int guess) {
    // TODO: write your code here
    int correct_val = 555;
    if (guess > correct_val) {
        printf("Your guess is too high\n");
    } else if (guess < correct_val) {
        printf("Your guess is too low\n");
    } else {
        printf("Correct. You guessed it!\n");
    }
}
