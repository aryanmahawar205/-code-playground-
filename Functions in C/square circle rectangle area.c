// area of square, circle and rectangle

#include <stdio.h>

float areaCircle(float radius);
float areaSquare(float side);
float areaRectangle(float length, float breadth);

int main()
{
    char ch;
    printf("Enter c to calculate circle area, s for square and r for rectangle - ");
    scanf("%c", &ch);
    
    if (ch == 'c')
    {
        float radius;
        printf("Enter the radius of the circle - ");
        scanf("%f", &radius);
        printf("The area of the circle with radius %f is %f \n", radius, areaCircle(radius));
    }
    
    else if (ch == 's')
    {
        float side;
        printf("Enter the side of the square - ");
        scanf("%f", &side);
        printf("The area of the square with side %f is %f \n", side, areaSquare(side));
    }
    
    else if (ch == 'r')
    {
        float length, breadth;
        printf("Enter the length of the rectangle - ");
        scanf("%f", &length);
        printf("Enter the breadth of the rectangle - ");
        scanf("%f", &breadth);
        printf("The area of the rectangle with length %f and breadth %f is %f \n", length, breadth, areaRectangle(length, breadth));
        
    }
    
    else
    {
        printf("Invalid Characted Inputted! \n");
    }
    
    return 0;
}

float areaCircle(float radius)
{
    return 3.14*radius*radius;
}

float areaSquare(float side)
{
    return side*side;
}

float areaRectangle(float length, float breadth)
{
    return length*breadth;
}