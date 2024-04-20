//there is no need to typecast implicit operators, compiler knows how to do that
//user defined data types need this overloading

#include <iostream>

using std::cout; using std::endl;

double dollarToRupeeExchangeRate()
{
    return 71.5;
}

class Rupee
{
    private:
        double rupee;

    public:
        Rupee()
        {
            rupee = 0;
        }

        Rupee(double rupee)
        {
            this->rupee = rupee;
        }

        void print()
        {
            cout << "Rupees - " << rupee << endl;
        }
};

class Dollar
{
    private:
        double dollar;

    public:
        Dollar()
        {
            dollar = 0;
        }

        Dollar(double dollar)
        {
            this->dollar = dollar;
        }

        void print()
        {
            cout << "Dollars - " << dollar << endl;
        }

        //overloading typecast operator (IMPORTANT SPECIAL SYNTAX)
        operator Rupee()
        {
            return Rupee(dollar * dollarToRupeeExchangeRate());
        }
};

int main()
{
    Dollar d(10); Rupee r;

    //just a typecast statement like double x = a; (where a is an integer)
    r = d;

    //d = r; this will require another overloaded function in the Rupee class

    d.print(); r.print();

    return 0;
}