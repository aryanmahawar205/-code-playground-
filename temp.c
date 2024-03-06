#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* largest_word(char *s);

int main()
{
  char s[] = "A sentence with several words.";
  char *word = largest_word(s);
  printf("%s\n", word);
  
  free(word);
  
  return 0;
}

char* largest_word(char *s)
{
  int len = strlen(s);

  int count = 0;

  int max = -1;
  char temp_buffer[256];

  char max_word[256];

  char nonwords[] = " .,;\n\t";
  
  int i = 0;
  while (i < len)
  {
    count = 0;
    while (i < len)
    {
      if (strchr(nonwords, s[i]) != NULL)
      {
          break;
      }
      
      else
      {
          temp_buffer[count] = s[i];
          i++;
          count++;
      }
    }
    temp_buffer[count] = '\0';
    if (count > max)
    {
      max = count;
      strcpy(max_word, temp_buffer);
    }
    
    while (i < len)
    {
      if (strchr(nonwords, s[i]) == NULL)
      {
        break;
      }
      else
      {
        i++;
      }
    }
  }
  char *word = malloc(sizeof(char) * (max + 1));
  strcpy(word, max_word);
  return word;
}