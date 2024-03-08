//this code will ask the user to enter a name and then will print out the first letter of the first name and middle name (if any)
//the title of the name is to be printed as it is
//example, if the name is Daniel Christopher White, then we expect output as D.C.White
//and if the name is Nathan Paul, then we expect N.Paul

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    char name[200];

    printf("\nEnter your name - ");
    gets(name);

    printf("\nYou have entered the name as - ");
    puts(name);

    printf("\nThe name in the required format is as follows - ");

    char *last = strrchr(name, ' ');

    int last_len = strlen(last+1);

    int length = strlen(name);
    bool reading_word = false;

    for (int i = 0; i < (length - last_len) ; i++)
    {
        if (!reading_word && isalpha(name[i]))
        {
            reading_word = true;
            printf("%c.", name[i]);
        }
        else if (reading_word && !isalpha(name[i]))
        {
            reading_word = false;
        }
    }

    printf("%s\n", last+1);
    printf("\n");

    return 0;
}