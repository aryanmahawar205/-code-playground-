//overloading assignment (=) operator comes under binary operator overloading
//when we need deep copy, assignment (=) operator has to be overloaded
//we should also create our own copy constructor when overloading assignment operator and vice versa

//check self assignment because it is dangerous
//assignment operator (=) can be overloaded using non-static member function only

//generally need to overload assignment operator (=) occurs when we have pointer type variables in our classes

#include <iostream>

using std::cout; using std::endl;

class Test
{
    private:
        int *x;

    public:
        Test()
        {
            x = new int(0);
        }

        void setX(int set_X)
        {
            *x = set_X;
        }

        void print()
        {
            cout << "Output - " << *x << endl;
        }

        ~Test()
        {
            delete x;
        }

        //overloading assignment (=) operator
        Test& operator = (const Test &rhs)
        {
            if (this != &rhs) //checking self assignment case (what if we do t1 = t1)
            {
                *(this->x) = *rhs.x;
            }

            return *this;
        }
};

int main()
{
    Test t1; Test t2;

    t1.setX(10);

    //t1.print(); t2.print();

    t2 = t1; //here the compiler performs a shallow copy and not deep copy which is why we see the issue in line 55 (if overloading not done)

    t1.print(); t2.print();

    t1.setX(20);

    t1.print(); t2.print(); //the problem arises here when both t1 and t2 print the value 20 when we had only assigned 20 to t1 above (if overloading not done)

    return 0;
}