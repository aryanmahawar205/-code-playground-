#include <stdio.h>

/*
Enumeration technique or the use of "enums" in C is just a way of making your code more readable to others
Basically its again a user-defined set of values with are taken within curly braces --> {} and what the C compiler
automatically does is that it assigns integers in increasing order starting from 0 automatically to each of those
say objects you type within the braces separated by comma.
We can also manually assign integers of our choice to these elements ... as explained later in this code.
Also, enums can be declared in the main() function or even outside of it. They do follow the scope properties.
They also can be aliased using the typedef keyword.
*/

enum Days {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

enum Processors {intel, amd, appleSilicon = 4, samsungEzynos, mediaTek}; //manually assigning values


int main()
{
    printf("Monday - %d", Monday);

    enum Days sun = Sunday;

    printf("\nSunday - %d", sun);

    printf("\n-------Enumeration manually reassigned--------");

    printf("\nAppleSilicon - %d", appleSilicon);

    enum Processors last = mediaTek;

    printf("\nMediaTek - %d", last);

    return 0;
}
