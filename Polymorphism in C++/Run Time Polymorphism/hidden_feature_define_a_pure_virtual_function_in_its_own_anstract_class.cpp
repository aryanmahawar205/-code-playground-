#include <iostream>

using std::cout; using std::endl;

class Base
{
    public:
        //declaring func() of Base class as pure virtual function
        virtual void func() = 0;
        //{
            //cout << "Base func() running" << endl;
        //}
};

//STILL PROVIDING A DEFINITION TO func() WHICH IS A PURE VIRTUAL FUNCTION IN CLASS BASE
void Base :: func()
{
    cout << "Base func() running" << endl;
}

class Derived1 : public Base
{
    public:
        void func()
        {
            Base :: func(); //a call to the Base class func() which is defined outside class using ::
            cout << "Derived1 func() running" << endl;
        }
};

class Derived2 : public Base
{
    public:
        void func()
        {
            cout << "Derived2 func() running" << endl;
        }
};

int main()
{
    Base *different_ofjectArray[] =
    {
        //new Base(), we cannot have objects of type Base because it is now an Abstract class
        new Derived1(),
        new Derived2()
    };

    for (int i = 0; i < 2; i++)
    {
        different_ofjectArray[i]->func();
    }

    for (int i = 0; i < 2; i++)
    {
        delete different_ofjectArray[i];
    }

    return 0;
}
