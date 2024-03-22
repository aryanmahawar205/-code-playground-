#include <iostream>

using namespace std;

class Counter
{
    private:
        int count;

    public:
        Counter()
        {
            count = 0;
        }

        void print()
        {
            cout << "Count - " << count << endl;
        }

        void increment()
        {
            count++;
        }    
};

//function accepting object instance as parameter
void increment_3X(Counter &counter)
{
    counter.increment();
    counter.increment();
    counter.increment();
}

int main()
{
    Counter counter;

    counter.print();
    increment_3X(counter);
    counter.print();

    //increment of value of counter in main will be seen due to pass by reference of object counter
    //address of object is passed and hence it is directly modified there and reflected in main

    return 0;
}