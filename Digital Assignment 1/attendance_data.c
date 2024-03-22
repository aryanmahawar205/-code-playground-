//this code will perform various operations on the attendance data for a particular class of students as specified in the question

#include <stdio.h>
#include <string.h>

static char arr[100][100];

void calculate(int n, int m);

void check(char x, int n, int m);

int main() 
{
    int m, n; //m = number of students and n = number of days of attendance data

    printf("\nEnter the number of students - ");
    scanf("%d", &m);

    printf("Enter the number of days for which you want to generate attendance data - ");
    scanf("%d", &n);

    printf("\nEnter the attendance data (P for present and A for absent)...\n");
    
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", arr[i]);
    }

    printf("\n\n------------------ATTENDANCE DATA GENERATED AS--------------------\n\n");
    
    check('P', n, m);
    check('A', n, m);
    calculate(n,m);

    return 0;
}

void calculate(int n, int m)
{
    int P_count = 0;
    int A_count = 0;
    int equal = 0;

    int P_great[100];
    int pre = 0;

    int A_great[100];
    int abt = 0;

    int PA_equal[100];
    int eq = 0;
    
    for (int i = 0; i < n; i++)
    {
        P_count = A_count = equal = 0;
        for (int j = 0; j < m; j++) 
        {
            if (arr[i][j] == 'P') 
            {
                P_count++;
            }
            else if (arr[i][j] == 'A')
            {
                A_count++;
            }
            else
            {
                equal++;
            }
        }
        if (P_count > A_count)
        {
            P_great[pre] = i + 1;
            pre++;
        }
        else if (A_count > P_count)
        {
            A_great[abt] = i + 1;
            abt++;
        }
        else
        {
            PA_equal[eq] = i + 1;
            eq++;
        }
    }
    
    for (int i = 0; i < pre; i++)
    {
        printf("%d ", P_great[i]);
    }
    
    printf("\n");
    
    for (int i = 0; i < abt; i++)
    {
        printf("%d ", A_great[i]);
    }
    
    printf("\n");
    
    for (int i = 0; i < eq; i++)
    {
        printf("%d ",PA_equal[i]);
    }    
}

void check(char x, int n, int m) 
{
    int largest = 0;
    int day = 0;
    int P_days[n];
    int cons_day[n];
    int len = 0;
    int pre = 0;
    
    for (int i = 0; i < n; i++) 
    {
        int s = 0;
        for (int j = 0; j < m; j++) 
        {
            if (arr[i][j] == x) 
            {
                s++;
            }
        }

        if (s == m) 
        {
            day += 1;
            P_days[pre] = i + 1;
            pre++;
        } 
        
        else 
        {
            if (day > largest) 
            {
                largest = day;
                for (int a = 0; a < pre; a++) 
                {
                    cons_day[a] = P_days[a];
                }
                len = pre;
                pre  =0;
            }
            day = 0;
        }
    }
    
    printf("%d\n", largest);
    for (int a = 0; a < len; a++)
    {
        printf("%d ", cons_day[a]);
    }

    printf("\n");
}