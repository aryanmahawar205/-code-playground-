//how do constructors behave when it comes to multiple inheritance (diamond problem)

#include <iostream>

using namespace std;

class CommonBaseClass
{
    public:
        int common_value;

        CommonBaseClass()
        {
            common_value = 50;
        }

        CommonBaseClass(int aCommon_Value)
        {
            common_value = aCommon_Value;
        }
};

class BaseClass1 : virtual public CommonBaseClass
{
    public:
        int value;

        BaseClass1()
        {
            CommonBaseClass(100);
        }
};

class BaseClass2 : virtual public CommonBaseClass
{
    public:
        int value;

        BaseClass2()
        {
            CommonBaseClass(200);
        }

};

//so in the case of this derived class, we might think which of the default constructors are going to be used
//it it the default constructor of BaseClass1 or of BaseClass2 ? because essentially, DerivedClass is inheriting either of the BaseClass (1 or 2) as specified by the virtual keyword
class DerivedClass : public BaseClass1, public BaseClass2
{

};

int main()
{
    DerivedClass derived;

    cout << derived.common_value << endl; //the output to this line is 50

    //so now let's analyze what just happened
    //the DerivedClass did not call any of the default constructors of either BaseClass1 or BaseClass2 cause its internally inheriting from either of them by the virtual keyword
    //now the catch is there is always going to be this ambiguity which constructor to call and thus
    //it never calls any of the BaseClass (1 or 2) constructors, instead calls for the default constructor of the CommonBaseClass
    //hence common_value is set to 50

    //now remember, the BaseClass (1 or 2) constructors will be called when we are creating BaseClass (1 or 2) objects
    //they will not be called through the DerivedClass class object due to always prevailing ambiguity

    return 0;
}
