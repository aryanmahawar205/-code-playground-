#include <iostream>

using namespace std;

class Number
{
    private:
        double *number;
  
    public:
        Number(double num)
        {
            number = (double *) malloc(sizeof(double));
 
            *number = num;

            cout << "Constructor executing!" << endl;
            cout << "Number: " << *number << endl << endl;
        }

        ~Number()
        {
            cout << "Destructor executing!" << endl;
            cout << "Number: " << *number << endl << endl;
            free(number);
        }
};

void test()
{
    Number six(6);
}

int main()
{
    test();

    Number seven(7);

    return 0;
}