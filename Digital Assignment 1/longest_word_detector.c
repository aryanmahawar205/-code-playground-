//this code will ask the user to enter a sentence which will be passed to a function that detects and prints out the longest word in
//that sentence
//eg, if sentence is - "that is real mesmerization", then the output should be "mesmerization" is the longest word

#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[10000];

    printf("\nEnter a sentence - ");
    fgets(sentence, 10000, stdin);

    printf("\n");
    puts(sentence);


    char *words = strtok(sentence, " ");

    int longest;

    while (words != NULL)
    {
        printf("%s\n", words);
        words = strtok(NULL, " ");
        longest = strlen(words);
        
    }



    return 0;
}