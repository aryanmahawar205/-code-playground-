//function overloading is using the same name for multiple functions
//as far as the number of parameters or types of parameters are different
//so that there is no such ambiguity as to which function has to be called in the calling statement

/*

-------------------------------------WITHOUT CLASS MEMBER FUNCTION EXAMPLE-----------------------------------

#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

double add(double x, double y, double z)
{
    return x + y + z;
}

int main()
{
    cout << add(10, 5) << endl;
    cout << add(10, 5, 5) << endl;
    cout << add(10.5, 20.5, 16.5) << endl;
    cout << add (10, 20.5, 16.5) << endl; //error statement as function call is ambigious

    return 0;
}

*/

//----------------------------------WITH CLASS MEMBER FUNCTIONS---------------------------------------------

#include <iostream>

using namespace std;

class Add
{
    public:
        int add(int x, int y)
        {
            return x + y;
        }

        double add(double x, double y)
        {
            return x + y;
        }
};

int main()
{
    Add a1, a2;

    cout << a1.add(10, 5) << endl;
    cout << a2.add(10.5, 4.5) << endl;

    return 0;
}
