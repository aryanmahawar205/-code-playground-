//
//

#include <iostream>

using namespace std;

class BasicNumber
{
    public:
        int n;

        BasicNumber(int set_n)
        {
            n = set_n-2;
        }

        BasicNumber(BasicNumber& set_n)
        {
            n = 2 * set_n.n;
        }
};

int main()
{
    BasicNumber num1(7);

    cout << "num1.n - " << num1.n << endl;

    //here the constructor to set n is not called. instead the default copy constructor is called.
    //every class has a default copy constructor
    //basically here the num2 member variables are assigned to num1 member variables. 
    //member wise assignment is taking place here which is the function of default copy constructor
    BasicNumber num2 = num1;

    cout << "num2.n - " << num2.n << endl;
    

    return 0;

}