//this code explains the very basic need of this keyword / this pointer is general through a simple example

#include <iostream>

using namespace std;

class Number
{
    private:
        int a, b;

    public:
        Number(int num1, int num2)
        {
            a = num1; b = num2;
        }

        void showDetails()
        {
            //in the below lines we are able to access the address of objects with the class even when no such Number object is present within the class
            //this is made possible by the this pointer which is a reference to memory address to the object whose invoking it (calling it)
            cout << "Object address is - " << this << endl;
            cout << "Through object of address - " << this << " value of a - " << this ->  a << endl;
            cout << "Through object of address - " << this << " value of b - " << this ->  b << endl;
        }

};

int main()
{
    Number n1(5, 10);
    n1.showDetails();

    Number n2(20, 25);
    n2.showDetails();

    return 0;
}