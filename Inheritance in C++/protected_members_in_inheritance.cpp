#include <iostream>

using namespace std;

class BaseClass
{
    private:
        int private_member;
    public:
        int public_member;
    protected:
        int protected_member;
};

class DerivedClass : public BaseClass
{
    public:
        void set_getMembers()
        {
            //private_member = 20; the derived cannot access the private member of base class
            public_member = 30;
            protected_member = 40; //but it can access the protected member of the base class

            //cout << "Private Member - " << private__member << endl;
            cout << "Public Member - " << public_member << endl;
            cout << "Protected Member - " << protected_member << endl;
        }
};

int main()
{
    DerivedClass derived;

    derived.set_getMembers();

    cout << endl << "---------We are now in Main----------" << endl << endl;

    cout << "Public Member - " << derived.public_member << endl; //accessible
    //cout << "Protected Member - " << derived.protected_member << endl; not accessible
    //cout << "Private Member - " << derived.private_member << endl; //not accessible

    //NOTE that protected members behave like private members outside the class (for eg, in any function like main)

    return 0;
}
