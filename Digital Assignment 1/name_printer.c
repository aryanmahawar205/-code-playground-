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
    gets(name); //taking input of name from user

    printf("\nYou have entered the name as - ");
    puts(name); //displaying to the user the name he/she has entered

    printf("\nThe name in the required format is as follows - ");

    //using the strrchr() functions, we look for the last instance of space in the name 
    //the function returns back a pointer to that location which I have stored in character pointer variable last
    char *last = strrchr(name, ' ');

    int last_len = strlen(last+1); //calculating the length of the last word in the name

    int length = strlen(name); //calculating the length of the total string name
    bool reading_word = false; //setting boolean variable to false initially
    
    //the for loop iterates not through the entire string, but only upto the last word in the name
    //thus i < (length - last_len) condition takes care of that
    for (int i = 0; i < (length - last_len) ; i++)
    {
        //this if statement is for reading and printing only the first character of each word
        //in the first iteration, both conditions are true and reading_word is set to true and first letter is printed
        //after this whenever the is brock is encountered, it will not run singe not of true is false and reading_word is set to false
        //this goes on until a white space is encountered in the name
        if (!reading_word && isalpha(name[i]))
        {
            reading_word = true;
            printf("%c.", name[i]);
        }
        //when a white space is encountered, this else if block produces a true result and reading_word is set to false
        //once again the if block is executed since this time around we actually have encountered a white space
        //which means that a new word is about to begin after that space
        //this process is continued for the entire string, expect for the last word
        //since we intend to print the last word as it is
        else if (reading_word && !isalpha(name[i]))
        {
            reading_word = false;
        }
    }

    printf("%s\n", last+1); //printing the last word as it is
    printf("\n");

    return 0;
}