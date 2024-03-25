//a friend function is one which can access the private members of a particular class
//it is not in the scope of the class
//since it is not in the scope of the class, it called be called from the object of that class
//can be invoked without the help of an object
//usually contains objects are arguments -- POINT TO BE NOTED (1)
//can be declared as friend in public or private section of the class
//cannot access members directly by their names and needs object_name.member_name to access members, hence POINT TO BE NOTED (1) is worthy of mention 


#include <iostream>

using namespace std;

class Complex
{
    private:
        int a, b;

    public:
        void setNumber(int aNumber, int bNumber)
        {
            a = aNumber;
            b = bNumber;
        }

        //this right here is the friend function
        friend Complex addComplex(Complex o1, Complex o2);

        void printNumber()
        {
            cout << "The number is - " << a << " + " << b << "i" << endl;
        }
};

Complex addComplex(Complex o1, Complex o2)
{
    Complex o3;

    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));

    return o3;
}

int main()
{
    Complex c1, c2, sum;

    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(5, 8);
    c2.printNumber();

    sum = addComplex(c1, c2);
    sum.printNumber();

    return 0;
}