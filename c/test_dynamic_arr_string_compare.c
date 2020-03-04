#include <stdio.h>
# include <stdlib.h>

int main() {
    int num_rows = 9;
    char *** strings = malloc(num_rows * sizeof(char *));

    for (int i = 0; i < num_rows; i++) {
        sprintf(str[i], "%d", i);

        printf("%s\n", str[i]);
    }
    return 0;
}
