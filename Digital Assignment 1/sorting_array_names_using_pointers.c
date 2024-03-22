//this code will accept an array of names (strings) and sort the same in alphabetical order
//the sorting algorithm implemented here is selection sort
//the sorting is done with the help of pointers throughout along with pointers to structures in strcpy() function

#include <stdio.h>
#include <string.h>

typedef struct strings //declaring structure array of strings
{
	char var[50];
}str;

void sorter(str ss[], int n); //function declaration to perform string sorting (using selection sort algorithm)

int main()
{	
    int n;

	printf("\nEnter the number of strings you want to sort in alphabetical order - ");
	scanf("%d", &n);

    printf("\nEnter the strings...\n");
    
	str strings[n], *strings1[n];
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s", strings[i].var);
		strings1[i] = &strings[i];
	}

	sorter(strings, n); //call to function to sort the strings

    printf("\nThe strings are sorted in ascending order as...\n");
	
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", strings1[i]->var);
    }

    return 0;
}

//function definition to perform selection sort on strings taken as input
void sorter(str ss[], int n)
{
	char temp[50];
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
            strcpy(temp, ss[i].var);
            strcpy(ss[i].var, ss[min].var);
            strcpy(ss[min].var, temp);
        }
    }
}