/*

------------------------------------EXAMPLE FOR DEFAULT COPY CONSTRUCTOR PROVIDED BY COMPILER-------------------------------------------

#include <iostream>

using namespace std;

class BasicNumber
{
    public:
        int n;

        BasicNumber(int set_n)
        {
            n = set_n;
        }
};

int main()
{
    BasicNumber num1(7);

    cout << "num1.n - " << num1.n << endl;

    here the constructor to set n is not called. instead the default copy constructor is called.
    every class has a default copy constructor when no copy constructor is explicitly defined
    basically here the num2 member variables are assigned to num1 member variables. 
    member wise assignment is taking place here which is the function of default copy constructor
    BasicNumber num2 = num1;

    cout << "num2.n - " << num2.n << endl;
    

    return 0;

}

*/

//---------------------------------------------EXAMPLE FOR USER-DEFINED COPY CONSTRUCTOR------------------------------------------------


#include <iostream>

using namespace std;

class BasicNumber
{
    public:
        int n;

        //default constructor
        BasicNumber(int set_n)
        {
            cout << "Default Constructor Called!" << endl;
            n = set_n;
        }

        //copy constructor defined by us (SYNTAX IMPORTANT)
        //Alternate Syntax - BasicNumber(const BasicNumber &obj_num)
        BasicNumber(BasicNumber &obj_num)
        {
            cout << "Copy Constructor Called!" << endl;
            n = 2 * obj_num.n;
        }
};

int main()
{
    BasicNumber num1(7);

    cout << "num1.n - " << num1.n << endl;

    //BasicNumber num2 = num1; if no copy constructor was defined in the class, default copy constructor would be invoked
    //invoking of default copy constructor would perform member wise member assignments of object num2 to object num1

    BasicNumber num3 = num1;

    cout << "num3.n - " << num3.n << endl;

    return 0;
}