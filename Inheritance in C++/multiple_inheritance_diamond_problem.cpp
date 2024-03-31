// Diamond Problem Illustration
//
//
//                    CommonBaseClass
//                    /              \
//                   /                \
//                  /                  \
//              BaseClass1           BaseClass2
//                   \                /
//                    \              /
//                     \            /
//                      DerivedClass

#include <iostream>

using namespace std;

class CommonBaseClass
{
    public:
        int common_value;
};

class BaseClass1 : virtual public CommonBaseClass
{

};

class BaseClass2 : virtual public CommonBaseClass
{

};

class DerivedClass : public BaseClass1, BaseClass2
{

};

int main()
{
    DerivedClass derived;

    //derived.common_value = 20; - ambiguous statement
    //this ambiguity can be fixed by using the virtual keyword in each of the BaseClass (1 and 2)
    //so that they derived class only inherits one of the BaseClass (1 or 2) instead of two

    derived.common_value = 20;

    return 0;
}
