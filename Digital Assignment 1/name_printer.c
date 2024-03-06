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
    char name[] = "High Definition Multimedia Interface";

    int length = strlen(name);
    bool reading_word = false;

    for (int i = 0; i < length; i++)
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

    return 0;
}