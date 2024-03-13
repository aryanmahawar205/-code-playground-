//this code de will check if a user-inputted 3 digit number is a special number of not
//a three digit special number is one which has the sum of its first two digits equal to the last digit
//eg, in 246, we see that 2 + 4 = 6, that is the sum of the first two digits is equal to the last digit, hence 246 is a special number
//but in 249, we see that 2 + 4 != 9, therefore 249 is not a special number

#include <stdio.h>

void SPECIAL_NUMBER(int number);

int main()
{
    int num;
    printf("\nEnter a three digit number to check if it is a special number or not - ");
    scanf("%d", &num);

    SPECIAL_NUMBER(num);

    return 0;
}

void SPECIAL_NUMBER(int number)
{
    int last_digit, remainingDigits_quotient, second_digit, first_digit;

    last_digit = number % 10;
    remainingDigits_quotient = number / 10;

    second_digit = remainingDigits_quotient % 10;
    first_digit = remainingDigits_quotient / 10;
    
    if (first_digit + second_digit == last_digit)
    {
        printf("\n%d is a SPECIAL NUMBER!\n\n", number);
    }

    else
    {
        printf("\n%d is not a SPECIAL NUMBER!\n\n", number);
    }

}