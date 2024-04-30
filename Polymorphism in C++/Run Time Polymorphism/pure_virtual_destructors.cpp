#include <iostream>

using std::cout; using std::endl;

class Base
{
    public:
        virtual void func()
        {
            cout << "Base func()" << endl;
        }

        //declaring a pure virtual destructor
        //but if we run the program now, just by making this a pure virtual destructor, we get an error
        //this is because, the objects when getting deleted call out for base class destructor
        //but here we have not provided any definition to it and thus the error
        //to solve this we have to provide a definition to it outside the class using ::
        //it is kind off an odd feature of C++ that we declare this destructor as pure virtual
        //but still have to provide an implementation to it
        virtual ~Base() = 0;
};

//providing definition to pure virtual destructor outside class
//(WEIRD BUT OKAY FEATURE, I WOULD SAY)
Base :: ~Base()
{
    cout << "Base Destructor" << endl;
}

class Derived1: public Base
{
    public:
        void func()
        {
            cout << "Derived1 Overriding func()" << endl;
        }

        ~Derived1()
        {
            cout << "Derived1 Destructor" << endl;
        }
};

class Derived2 : public Base
{
    public:
        void func()
        {
            cout << "Derived2 Overriding func()" << endl;
        }

        ~Derived2()
        {
            cout << "Derived2 Destructor" << endl;
        }
};

int main()
{
    //since now base is an abstract class, we cannot have or create object instances of it
    Base *different_objectArray[] =
    {
        //new Base(),
        new Derived1(),
        new Derived2()
    };

    for (int i = 0; i < 2; i++)
    {
        different_objectArray[i]->func();
    }

    for (int i = 0; i < 2; i++)
    {
        delete different_objectArray[i];
    }

    return 0;
}
