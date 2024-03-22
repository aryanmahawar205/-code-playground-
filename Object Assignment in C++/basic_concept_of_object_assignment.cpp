/*

Object Assignment of class with normal member variables

#include <iostream>

using namespace std;

class Simple
{
    public:
        int x;
};

int main()
{
    Simple s1, s2;

    s1.x = 0;
    s2.x = 5;

    cout << "Before Assignment : s1.x - " << s1.x << " and s2.x - " << s2.x << endl;

    s1 = s2;
    
    cout << "After Assignment : s1.x - " << s1.x << " and s2.x - " << s2.x << endl;

    s2.x = 10;

    cout << "After Change only in s2.x : s1.x - " << s1.x << " and s2.x - " << s2.x << endl;

    return 0;
}

*/

//Object Assignment of class with objects of another class as member variables

#include <iostream>

using namespace std;

class Simple
{
    public:
        int x;
};

class Stack
{
    public:
        Simple s1;
};

int main()
{
    Stack stk1, stk2;

    stk1.s1.x = 0;
    stk2.s1.x = 5;

    cout << "Before Assignment : stk1.s1.x - " << stk1.s1.x << " and stk2.s2.x - " << stk2.s1.x << endl;

    stk1 = stk2;

    cout << "After Assignment : stk1.s1.x - " << stk1.s1.x << " and stk2.s2.x - " << stk2.s1.x << endl;

    stk2.s1.x = 10;

    cout << "After Change only in stk2.s1.x : stk1.s1.x - " << stk1.s1.x << " and stk2.s2.x - " << stk2.s1.x << endl;


    return 0;
}