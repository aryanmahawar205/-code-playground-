#include <iostream>

using namespace std;

class BaseClass1
{
    public:
        void function1()
        {
            cout << "BaseClass1 function1" << endl;
        }
};

class BaseClass2
{
    public:
        void function2()
        {
            cout << "BaseClass2 function2" << endl;
        }
};

class DerivedClass : public BaseClass1, public BaseClass2
{
    public:
        void function3()
        {
            cout << "DerivedClass function3" << endl;
        }
};

int main()
{
    DerivedClass derived;

    derived.function1();
    derived.function2();
    derived.function3();

    return 0;
}
