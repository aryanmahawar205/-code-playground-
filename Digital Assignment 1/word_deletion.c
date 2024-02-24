//this code will delete a word from a sentence, both the target word and the sentence are taken an inputs from the user
//the target word may repeat any number of times in the sentence

#include <stdio.h>
#include <string.h>

int main()
{
    //declaring sentence and target word arrays
    char sentence[500];
    char word[30];

    //inputting and printing the sentence and word from the user
    printf("\nEnter the sentence - ");
    gets(sentence);
    printf("\nYou have entered the original sentence as below...\n");
    puts(sentence);
    printf("\nEnter the target word which you want to delete from the above inputted sentence - ");
    gets(word);
    printf("\nThe target word which you wish to delete is as below...\n");
    puts(word);

    int sentence_length, word_length, i = 0;
    sentence_length = strlen(sentence); //calculating the length of the sentence
    word_length = strlen(word); //calculating length of the target word

    //loop to truncate all instances of target word
    while (i < sentence_length)
    {
        if (strstr(&sentence[i], word) == &sentence[i]) //function to check presence of target word in main string
        {
            sentence_length -= word_length;

            for (int j = i; j < sentence_length; j++)
            {
                sentence[j] = sentence[j + word_length]; //performing data shifting in order to remove the target word
            }
        }
        else
        {
            i++;
        }
    }
    sentence[i] = '\0'; //null terminator used to complete the string definition
    printf("\n");

    //displaying the finally modified string
    printf("\nThe final string after removal of the target word is as below...\n");
    puts(sentence);
    printf("\n");
    return 0;
}