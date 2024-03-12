//this code used the concept of bit manipulation to flip the binary equivalent of a number taken as input from the user (source)
//to the binary equivalent of another number also taken as input from the user (target)
//the program should return the total number of bits which had to flipped to convert the source to target as output
//eg, if source = 21, which is 10101 is binary and target = 25, which is 11001 in binary
//then we can see that we had to flip 2 bits in binary of 21 to get binary of 25
//the program should return 2 in this case as the output

#include <stdio.h>

void binaryConvertor(int source);
void xorPerformer(int source, int target);
void setBitsCalculator(int xor_converted[], int length);

int main()
{
    int source = 21;
    int target = 25;

    xorPerformer(source, target);

    return 0;
}

void xorPerformer(int source, int target)
{
    int xorResult;
    
    xorResult = source ^ target;

    binaryConvertor(xorResult);
    
}

void binaryConvertor(int source)
{
    int remainder;
    int binary[100];
    int i = 0;
    int array_length;

    while (source != 0)
    {
        remainder = source%2;
        source = source/2;
        binary[i] = remainder;
        i++;
    }

    array_length = i;

    setBitsCalculator(binary, array_length);
}

void setBitsCalculator(int xor_converted[], int length)
{
    int setBits = 0;

    for (int i = 0; i < length; i++)
    {
        if (xor_converted[i] & 1)
        {
            setBits++;
        }
        xor_converted[i] = xor_converted[i] >> 1;
    }

    printf("%d", setBits);
}