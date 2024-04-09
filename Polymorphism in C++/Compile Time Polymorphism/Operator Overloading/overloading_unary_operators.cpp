// Number operator + (const Number &num_obj)
//         {
//             let us output what this -> n and num_obj.n actually are for better clarity
//             cout << "First Number to be added (essentially this -> n) - " << this -> n << endl;
//             cout << "Second Number to be added (essentially num_obj.n) - " << num_obj.n << endl;
//             return (this -> n + num_obj.n);
//         }

#include <iostream>

using namespace std;

class Weight
{
    public:
        int kg;

        Weight()
        {
            kg = 0;
        }

        void printWeight()
        {
            cout << "The Weight in kg is - " << kg << endl;
        }

        //overloading pre-increment operator
        void operator ++ ()
        {
            ++kg;
        }

        //overloading post-increment operator
        void operator ++ (int)
        {
            kg++;
        }

        //overloading pre-decrement operator
        void operator -- ()
        {
            --kg;
        }

        //overloading post-decrement operator
        void operator -- (int)
        {
            kg--;
        }
};

int main()
{
    Weight w1;
    w1.printWeight();

    ++w1; w1.printWeight();
    w1++; w1.printWeight();

    --w1; w1.printWeight();
    w1--; w1.printWeight();

    return 0;
}