//this code will accept a an array of names (strings) and sort the same in alphabetical order
//the sorting algorithm implemented here is selection sort
//the sorting is done with the help of pointers throughout

#include <stdio.h>
#include <string.h>

typedef struct strings
{
	char var[50];
}str;

void sorter(str ss[], int n)
{
	char t[50];
	for (int i = 0; i < (n - 1); i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(ss[j].var, ss[min].var) < 0)
            {
                min = j;
            }
        }

        if (min != i)
        {
            strcpy(t, ss[i].var);
            strcpy(ss[i].var, ss[min].var);
            strcpy(ss[min].var, t);
        }
    }
}

int main()
{	
    int n;
	printf("Enter the number of elements - ");
	scanf("%d", &n);
	str s[n], *s1[n];
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i].var);
		s1[i] = &s[i];
	}

	sorter(s, n);
	
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", s1[i]->var);
    }

    return 0;
}
