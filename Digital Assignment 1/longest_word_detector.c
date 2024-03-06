//this code will ask the user to enter a sentence which will be passed to a function that detects and prints out the longest word in
//that sentence
//eg, if sentence is - "This is real mesmerization", then the output should be "mesmerization" is the longest word

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* largestWord(char *s); //function declared which calculates and returns the largest word in the sentence

int main()
{
    char sentence[1000];

    printf("\nEnter a sentence - ");

    gets(sentence); //taking sentence input from the user

    printf("\nThe sentence you have entered is - \n");
    
    puts(sentence); //displaying to user his/her inputted sentence

    printf("\n");

    char *word = largestWord(sentence); //function called and result stored in character array word

    printf("The longest word in your sentence is - %s\n", word); //printing the result

    printf("\n");
  
    free(word); //freeing the dynamically allocated memory for result word
  
    return 0;
}

//function definition which calculates the largest word in the sentence passed as an argument
char* largestWord(char *s)
{
    int len = strlen(s); //calculating length of sentence
    int count = 0;
    int max = 0;

    char buffer_word[300]; //temporarily created an array to store each word
    char max_word[300]; //the longest word will be copied to max_word from buffer_word

    //creating a character array of elements which are not considered to be words
    //essentially these are kind of delimiters which separate words
    char delimiters[] = " .,;\n\t";
  
    int i = 0;

    //nested while loops to check for required longest word
    while (i < len)
    {
      count = 0;

      //this while checks for each of the word and breaks off when any of the delimiters
      //mentioned above in delimiters array occurs
      //also track of max and count are kept here
      while (i < len)
      {
        if (strchr(delimiters, s[i]) != NULL)
        {
            break; //breaking when delimiter occurs
        }
      
        else
        {
            buffer_word[count] = s[i];
            i++;
            count++;
        }
      }

      buffer_word[count] = '\0'; //addition of null terminator to buffer_word

      if (count > max)
      {
        max = count; //updating max
        strcpy(max_word, buffer_word); //copying buffer_word to max_word
      }
    
      //this while loop checks for the characters instead
      //when a character not defined in delimiters occurs, it breaks off
      //the control then goes off to the previous while loop
      //this process is continued till the end of string length
      while (i < len)
      {
        if (strchr(delimiters, s[i]) == NULL)
        {
          break; //breaking the loop when a character not in delimiters occurs
        }
        else
        {
          i++;
        }
      }
    }

    char *word; //creating a character pointer to store the result
    word = (char *)malloc(sizeof(char)*(max + 1)); //dynamically allocating just enough memory to store the result
    strcpy(word, max_word); //copying the result to the dynamically allocated memory

    return word;
}