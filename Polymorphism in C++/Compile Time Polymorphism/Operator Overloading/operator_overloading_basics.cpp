//this code will demonstrate the use of operator overloading by overloading some of the most common operators like '+' and '=='

#include <iostream>

using namespace std;

class Number
{
    public:
        int n, x;

        Number(int set_n)
        {
            n = set_n;
        }
        //overloading '+' operator (SYNTAX IMPORTANT)
        //breakdown of syntax
        //first off we have the return type of the function on overloading
        //after that use the operator keyword along with the operator you wish to overload
        //the entire function definition accepts a constant (const) reference (&) to a number object
        //for this case of binary addition, it return the addition of the this pointer ka n member variable sum with the num_obj ka n member variable
        Number operator + (const Number &num_obj)
        {
            //let us output what this -> n and num_obj.n actually are for better clarity
            cout << "First Number to be added (essentially this -> n) - " << this -> n << endl;
            cout << "Second Number to be added (essentially num_obj.n) - " << num_obj.n << endl;
            return (this -> n + num_obj.n);
        }

        //overloading '==' operator
        bool operator == (const Number &num_obj)
        {
            cout << "First Number to be compared (essentially this -> n) - " << this -> n << endl;
            cout << "Second Number to be compared (essentially num_obj.n) - " << num_obj.n << endl;
            
            if (this -> n == num_obj.n)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main()
{
    Number a(10); Number b(20);

    //this below line gives an error because the unary operator '+' in this case cannot conventionally be used with Number objects
    //therefore we will have to overload it in the class and define its behaviour there as we wish to
    //Number c = a + b;

    //after overloading '+' in the class we get no error cause we have defined '+' to act with Number objects as we wish to accordingly
    Number c = a + b;

    cout << "Sum is - " << c.n << endl;

    Number d(30);

    //we expect this to run
    if (c == d)
    {
        cout << "Numbers are equal!" << endl;
    }

    if (c == a)
    {
        cout << "Numbers are equal!" << endl;
    }
    
    //we expect this to run
    else
    {
        cout << "Numbers are not equal!" << endl;
    }

    return 0;
}