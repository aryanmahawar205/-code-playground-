//class member function are those functions that are only declared in the class
//their definition is provided outside of the class using the scope resolution (::) operator

#include <iostream>

using namespace std;

class Rectangle
{
    private:
        double length, breadth;

    public:
        void setDimensions(double aLength, double aBreadth)
        {
            length = aLength;
            breadth = aBreadth;
        }

        double perimeter(); //now this right here is a class member function (DECLARATION)
};

double Rectangle :: perimeter() //(DEFINITION) of the member function using :: operator
{
    return 2 * (length + breadth);
}

int main()
{
    Rectangle r1;

    r1.setDimensions(10, 20);

    cout << "Perimeter - " << r1.perimeter() << endl;
    
    return 0;
}