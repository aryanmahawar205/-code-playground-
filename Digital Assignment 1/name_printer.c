//this code will ask the user to enter a name and then will print out the first letter of the first name and middle name (if any)
//the title of the name is to be printed as it is
//example, if the name is Daniel Christopher White, then we expect output as D.C.White
//and if the name is Nathan Paul, then we expect N.Paul

#include <stdio.h>
#include <string.h>

void namePrinter();

int main()
{
    char name[100];
    
    printf("\nEnter your name - ");
    fgets(name, 100, stdin);
    printf("\n");

    puts(name);

    //printf("\n%s", strtok(name, " ")); first name
    
    
    //printf("\n%s", strtok(NULL, " "));  middle name


    //printf("\n%s", strtok(NULL, " ")); last name

    char *first[100];
    char *middle[100];
    char *last[100];

    *first = strtok(name, " ");
    *middle = strtok(NULL, " ");
    *last = strtok(NULL, " ");

    printf("\n%s", *first);
    printf("\n%s", *middle);
    printf("\n%s", *last);

    printf("\n\n\n\n");

    char firstChar;
    
    firstChar = *first[0];

    char twoName[3];
    
    twoName[0] = firstChar;
    twoName[1] = '.';
    twoName[2] = '\0';
    
    char *createName2 = strcat(twoName, middle[0]);
    char *createName3 = strcat(createName2, ".");
    char *createName4 = strcat(createName3, *last);

    printf("---------");
    
    printf("\n%s", twoName);

    

    return 0;
}