#include <stdio.h>

int main() {
    char name[100];
    int is_first_word = 1;  // Flag to indicate if processing the first word

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    // Iterate through the name string
    for (int i = 0; name[i] != '\n'; i++) {
        char ch = name[i];

        // Print the first letter of the first name (or title if no space before)
        if (is_first_word && (ch >= 'A' && ch <= 'Z')) {
            printf("%c", ch);
            is_first_word = 0;
        } else if (is_first_word && (ch >= 'a' && ch <= 'z')) {
            printf("%c", ch - 32);  // Convert lowercase to uppercase
            is_first_word = 0;
        }

        // Print the first letter of each subsequent word (middle name)
        else if (ch != ' ' && name[i-1] == ' ') {
            if (ch >= 'A' && ch <= 'Z') {
                printf("%c", ch);
            } else if (ch >= 'a' && ch <= 'z') {
                printf("%c", ch - 32);  // Convert lowercase to uppercase
            }
        }

        // Print all other characters (including spaces)
        printf("%c", ch);
    }

    return 0;
}