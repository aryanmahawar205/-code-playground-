//static binding in C++ means that all of the information required to perform the association is available
//at compile time itself. It is also called Early Binding or Compiler Time Binding
//can be achieved by function overloading, operator overloading - Compile Time Polymorphism

//demonstration using Function Overloading

#include <iostream>

using std::cout;  using std::endl;

int sumNumbers(int a, int b)
{
    return (a+b);
}

int sumNumbers(int a, int b, int c)
{
    return (a+b+c);
}

int main()
{
    cout << "Sum is - " << sumNumbers(1, 2) << endl;
    cout << "Sum is - " << sumNumbers(1, 2, 3) << endl;

    return 0;
}
