//this code used the concept of bit manipulation to flip the binary equivalent of a number taken as input from the user (source)
//to the binary equivalent of another number also taken as input from the user (target)
//the program should return the total number of bits which had to flipped to convert the source to target as output
//eg, if source = 21, which is 10101 in binary and target = 25, which is 11001 in binary
//then we can see that we had to flip 2 bits in binary of 21 to get binary of 25
//the program should return 2 in this case as the output

#include <stdio.h>

//function to calculate the binary equivalent of a number
void binaryConvertor(int binary_source, int decimal_source, int target);

//function to perform bitwise xor operation on decimal two numbers
void xorPerformer(int source, int target);

//function to calculate the number of set bits in a binary number
//set bits = number of ones in the binary representation of a number
int setBitsCalculator(int xor_converted[], int length);

int main()
{
    int source, target;

    printf("\nEnter the value of the first number (source) - ");
    scanf("%d", &source);

    printf("Enter the value of the second number (target) - ");
    scanf("%d", &target);

    xorPerformer(source, target); //function call to perform bitwise xor operation

    return 0;
}

//function definition to perform bitwise xor operation
void xorPerformer(int source, int target)
{
    int xorResult;
    
    xorResult = source ^ target;

    binaryConvertor(xorResult, source, target); //function call to calculate the binary of the xor result
    
}

//function definition to find binary equivalent
void binaryConvertor(int binary_source, int decimal_source, int target)
{
    int remainder;
    int binary[32];
    int i = 0;
    int array_length, result;

    while (binary_source != 0)
    {
        remainder = binary_source%2;
        binary_source = binary_source/2;
        binary[i] = remainder;
        i++;
    }

    //storing the length of the array to use later in calculating the set bits
    //array length gets recorded in i as a result of termination of the while loop, which is kept in array_length variable
    array_length = i;

    //function call to calculate the set bits in the xor performed number
    //the number of set bits is stored in result
    result = setBitsCalculator(binary, array_length);

    printf("\nThe number of bits to be flipped to convert %d to %d is %d", decimal_source, target, result);
    printf("\n\n");
}

//function definition to actually calculate the number of set bits in the binary of the xor operation result
//the number of ones or the number of set bits is our output because essentially when the bitwise xor operation is performed
//it results in 1 only when both the bits converted are having complementary values
//and it results in 0 when both the bits are same
//example 1^1 = 0, 0^0 = 0, 1^0 = 1, 0^1 = 1
//technically in order to flip the bits this is what we are doing
int setBitsCalculator(int xor_converted[], int length)
{
    int setBits = 0;

    for (int i = 0; i < length; i++)
    {
        if (xor_converted[i] & 1) //performing bitwise and operation to check for true condition (value of 1 is true)
        {
            setBits++;
        }
        xor_converted[i] = xor_converted[i] >> 1;
    }

    return setBits;
}