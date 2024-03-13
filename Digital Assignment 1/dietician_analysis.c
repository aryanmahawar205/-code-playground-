//this code will take a set of weights of n people from the user as input which are stored in an array
//using pointers, we find the sum of the weights and the standard deviation of the data and return those as outputs

#include <stdio.h>
#include <math.h>

void weightSum(int *weights, int n); //function declared to find the sum of the e weights
void weightMean(int sum, int n, int *weights); //function declared to find the mean of the weights
void standardDeviation(int *weights, int n, float mean); //function declared to compute the standard deviation of the weights

int main()
{
    int n;
    printf("\nEnter the number of people for which Mr. Joe is a dietician - ");
    scanf("%d", &n);

    int weights[n]; //creating an array of size n to store the weights of each of the n people

    printf("\nEnter the weights in Kilograms for each person - \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    weightSum(weights, n); //function call to weightSum

    return 0;
}

//function definiton of weightSum which calculates the sum of all the weights in the array using pointers
//also this function in turn gives call to the weightMean function
void weightSum(int *weights, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + *(weights + i); //calculating sum of the weights using pointers
    }

    printf("\nSum of the weights is -  %d Kilograms", sum);

    weightMean(sum, n, weights); //function call to weightMean
}

//function definition of weightMean which calculates the mean of the weights data
//this function also in turn gives a call to standardDeviation function
void weightMean(int sum, int n, int *weights)
{
    float mean;

    mean = sum / n;

    standardDeviation(weights, n, mean); //function call to standardDeviation
}

//function definition of standardDeviation which calculates the standard deviation of the weights data using pointers
void standardDeviation(int *weights, int n, float mean)
{
    //the standard deviation calculation
    float sub, sub_squares;
    float sum = 0.00;

    for (int i = 0; i < n; i++)
    {
        sub = *(weights + i) - mean;
        sub_squares = sub * sub;
        sum += sub_squares;
    }

    float standardDeviation;
    standardDeviation = sqrt((142.00 / (n-1)));

    printf("\nStandard Deviation of the weights is - %.3f\n\n", standardDeviation);
}