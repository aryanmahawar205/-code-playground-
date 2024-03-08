//place to test out logic for code

#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "The sun is yellow";

  char *last = strrchr(str, ' ');
  
  printf("%s\n", last+1);

  int length = strlen(last+1);

  printf("%d\n", length);

  return 0;
}