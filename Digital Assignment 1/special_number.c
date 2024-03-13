//this code de will check if a user-inputted 3 digit number is a special number of not
//a three digit special number is one which has the sum of its first two digits equal to the last digit
//eg, in 246, we see that 2 + 4 = 6, that is the sum of the first two digits is equal to the last digit, hence 246 is a special number
//but in 249, we see that 2 + 4 != 9, therefore 249 is not a special number

#include <stdio.h>

//declaring function of return type void to compute for a number being special number or not
void SPECIAL_NUMBER(int number);

int main()
{
    int num;
    printf("\nEnter a three digit number to check if it is a special number or not - ");
    scanf("%d", &num);

    SPECIAL_NUMBER(num); //call to SPECIAL_NUMBER function

    return 0;
}

//definition to SPECIAL_NUMBER function
void SPECIAL_NUMBER(int number)
{
    //declaring various variables, to store the first, second and last digit of the number
    int last_digit, second_digit, first_digit;

    //the last digit of a number can be calculated by using the modulus operator (%)
    last_digit = number % 10;

    //now to quotient when you first divide the number by 10, ie, number / 10 is stored in remainingDigits_quotient
    //essentially the digits held in remainingDigits_quotient is the first two digits of the number
    int remainingDigits_quotient;
    remainingDigits_quotient = number / 10;

    //again in order to get the second digit, we perform % operation, but this time around its remainingDigits_quotient % 10
    //this gives the second digits, which for a matter of fact is the last digit of remainingDigits_quotient
    second_digit = remainingDigits_quotient % 10;

    //the first digit is found by performing / operation on remainingDigits_quotient
    first_digit = remainingDigits_quotient / 10;
    
    //checking if the first digit and second digit when summed give the third digit or not and printing the appropriate result
    if (first_digit + second_digit == last_digit)
    {
        printf("\n%d is a SPECIAL NUMBER!\n\n", number);
    }

    else
    {
        printf("\n%d is not a SPECIAL NUMBER!\n\n", number);
    }

}