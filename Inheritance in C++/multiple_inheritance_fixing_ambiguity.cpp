//say we have all the function names as function1
//now when we make this DerivedClass object instance and call for function1, which function1 definition will get executed?
//well when the call for function1 is made from the derived class object, it OVER-WRITES the definition of the other function1 present in the base classes
//hence finally the function1 definition in DerivedClass object instance itself in executed as shown...

#include <iostream>

using namespace std;

class BaseClass1
{
    public:
        int value;

        void function1()
        {
            cout << "BaseClass1 function1" << endl;
        }
};

class BaseClass2
{
    public:
        int value;

        void function1()
        {
            cout << "BaseClass2 function1" << endl;
        }
};

//but if we comment out the function1 of the derived class and then try to run the program, we get an error
//this is happening because there are multiple function1 definitions in BaseClasses (1 and 2)
//and thus there is an ambiguity which one to choose

//HENCE, REMEMBER - FUNCTION GETS OVERWRITTEN ONLY WHEN THAT SAME FUNCTION NAME IS PRESENT IN THE DERIVED CLASS WHOSE OBJECT IS BEING MADE

class DerivedClass : public BaseClass1, public BaseClass2
{
    /*
    public:
        void function1()
        {
            cout << "DerivedClass function1" << endl;
        }
    */
};

//to fix this ambiguity issue, we can specify the name of the BaseClass (1 or 2) whose function1 we wish to access by the :: operator
//the same ambiguity could occur with member variables too as demonstrated
int main()
{
    DerivedClass derived;

    //derived.value = 20; - ambiguous statement

    derived.BaseClass1 :: value = 20;
    derived.BaseClass2 :: value = 50;

    derived.BaseClass1 :: function1();
    derived.BaseClass2 :: function1();

    return 0;
}
