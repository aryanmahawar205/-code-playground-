#include <stdio.h>
#include <math.h>

void weightSum(int *weights, int n);
void weightMean(int sum, int n);
void standardDeviation();

int main()
{
    int n;
    printf("\nEnter the number of people for which Mr. Joe is a dietician - ");
    scanf("%d", &n);

    int weights[n];

    printf("\nEnter the weights in Kilograms for each person...\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    weightSum(weights, n);

    return 0;
}

void weightSum(int *weights, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + *(weights + i);
    }

    printf("\nSum of the weights is -  %d\n", sum);

    weightMean(sum, n);
}

void weightMean(int sum, int n)
{
    float mean;

    mean = sum / n;

    printf("\nThe mean of the weights is - %.2f\n", mean);
}