//this code with create 2 user inputted arrays, sort each of them and then merge them in a third array which will be sorted too

#include <stdio.h>

void sorter(int array[], int size); //function declared to sort arrays
void merger(int array1[], int size1, int array2[], int size2, int array3[]); //function declared to merge sorted arrays in sorted manner

int main()
{
    int num1, num2;
    printf("\nEnter the number of elements you want in the first array - ");
    scanf("%d", &num1);
    int nums1Arr[num1];
    
    //creating first array
    printf("\nEnter the first array elements - \n");
    for (int i = 0; i < num1; i++)
    {
        scanf("%d", &nums1Arr[i]);
    }
    printf("\n");
    printf("Enter the number of elements you want in the second array - ");
    scanf("%d", &num2);
    int nums2Arr[num2];

    //creating second array
    printf("\nEnter the second array elements - \n");
    for (int i = 0; i < num2; i++)
    {
        scanf("%d", &nums2Arr[i]);
    }
    printf("\n");
    printf("\n");

    //displaying first array
    printf("First array created as - ");
    for (int i = 0; i < num1; i++)
    {
        printf("%d ", nums1Arr[i]);
    }
    printf("\n");
    printf("\n");

    //displaying second array
    printf("Second array created as - ");
    for (int i = 0; i < num2; i++)
    {
        printf("%d ", nums2Arr[i]);
    }
    printf("\n");
    printf("\n");

    sorter(nums1Arr, num1); //sorting the first array

    //printing first sorted array
    printf("\nFirst array sorted as - \n");
    for (int i = 0; i < num1; i++)
    {
        printf("%d ", nums1Arr[i]);
    }
    printf("\n");

    sorter(nums2Arr, num2); //sorting the second array

    //printing second sorted array
    printf("\nSecond array sorted as - \n");
    for (int i = 0; i < num2; i++)
    {
        printf("%d ", nums2Arr[i]);
    }
    printf("\n");
    int nums3Size = num1+num2; //size of merged array
    int nums3Arr[nums3Size]; //declaring merged array
    merger(nums1Arr, num1, nums2Arr, num2, nums3Arr); //merging the arrays in sorted fashion

    //printing the final sorted and merger array
    printf("\nResultant array generated as - \n");
    for (int i = 0; i < nums3Size; i++)
    {
        printf("%d ", nums3Arr[i]);
    }
    printf("\n");
    printf("\n");
    return 0;
}

//function definition of sorter which sorts a passed array
void sorter(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

//function definition of merger which merges two sorted arrays into a third resultant array in sorted manner
void merger(int nums1Arr[], int num1, int nums2Arr[], int num2, int nums3Arr[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < num1 && j < num2)
    {
        if (nums1Arr[i] < nums2Arr[j])
        {
            nums3Arr[k] = nums1Arr[i];
            i++;
            k++;
        }
        else
        {
            nums3Arr[k] = nums2Arr[j];
            j++;
            k++;
        }
    }
    while (i < num1)
    {
        nums3Arr[k] = nums1Arr[i];
        i++;
        k++;
    }
    while (j < num2)
    {
        nums3Arr[k] = nums2Arr[j];
        j++;
        k++;
    }
}