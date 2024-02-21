/*
Program to check if the entered character by the user is upper case, lower case, digit or special character
*/

int main()
{
    char ch;
    printf("Enter character - ");
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z')
    {
        printf("Lower case character");
    }

    else if (ch >= 'A' && ch <= 'Z')
    {
        printf("Upper case character");
    }

    else if (ch >= '0' && ch <= '9')
    {
        printf("Digit");
    }

    else
    {
        printf("Special character");
    }
    
    return 0;
}