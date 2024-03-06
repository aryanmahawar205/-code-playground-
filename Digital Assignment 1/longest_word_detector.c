//this code will ask the user to enter a sentence which will be passed to a function that detects and prints out the longest word in
//that sentence
//eg, if sentence is - "This is real mesmerization", then the output should be "mesmerization" is the longest word

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* largestWord(char *s);

int main()
{
    char sentence[1000];

    printf("\nEnter a sentence - ");

    gets(sentence);

    printf("\nThe sentence you have entered is - \n");
    
    puts(sentence);

    printf("\n");

    char *word = largestWord(sentence);

    printf("The longest word in your sentence is - %s\n", word);

    printf("\n");
  
    free(word);
  
    return 0;
}

char* largestWord(char *s)
{
    int len = strlen(s);
    int count = 0;
    int max = 0;

    char buffer_word[300];
    char max_word[300];

    char delimiters[] = " .,;\n\t";
  
    int i = 0;
    while (i < len)
    {
      count = 0;
      while (i < len)
      {
        if (strchr(delimiters, s[i]) != NULL)
        {
            break;
        }
      
        else
        {
            buffer_word[count] = s[i];
            i++;
            count++;
        }
      }

      buffer_word[count] = '\0';

      if (count > max)
      {
        max = count;
        strcpy(max_word, buffer_word);
      }
    
      while (i < len)
      {
        if (strchr(delimiters, s[i]) == NULL)
        {
          break;
        }
        else
        {
          i++;
        }
      }
    }

    char *word;
    word = (char *)malloc(sizeof(char)*(max + 1));
    strcpy(word, max_word);

    return word;
}