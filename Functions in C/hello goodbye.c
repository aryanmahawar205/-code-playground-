// hello goodbye

#include <stdio.h>

// function declaration / prototype
void hello();
void goodBye();


int main()
{
    hello(); // function call
    goodBye(); // function call
    return 0;
}

// function definition
void hello()
{
    printf("Hello \n");
}

void goodBye()
{
    printf("Goodbye \n");
}