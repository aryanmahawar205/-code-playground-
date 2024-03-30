//run this program and you will see that first the BaseClass Constructor executes followed by the DerivedClass Constructor
//but they are destroyed in reverse order, this is -
//the DerivedClass Destructor executed first followed by the BaseClass Destructor

#include <iostream>

using namespace std;

class BaseClass
{
    public:

        BaseClass()
        {
            cout << "BaseClass Default Constructor Executing!" << endl;
        }

        ~BaseClass()
        {
            cout << "BaseClass Default Destructor Executing!" << endl;
        }
};

class DerivedClass : public BaseClass
{
    public:
        DerivedClass()
        {
            cout << "DerivedClass Default Constructor Executing!" << endl;
        }

        ~DerivedClass()
        {
            cout << "DerivedClass Default Destructor Executing!" << endl;
        }
};

//destructor will run when this function executes and is done
//the object used by it is temporary and gets destroyed
void func()
{
    DerivedClass example;

    cout << endl;
}

int main()
{
    func();
    cout << endl;

    return 0;
}
