//this code will explain in basic terms what is meant by function templates in C++

#include <iostream>

using namespace std;

//here we are defining a function template
//essentially a reusable function which can change its parameters and return type as and how you wish as seen in the main function
template <typename T>
T sum (T a, T b)
{
    return (a + b);
}

//function templates could also be used with various types of typenames as depicted
template <typename T1, typename T2>
void findGreat(T1 a, T2 b)
{
    if (a > b)
    {
        cout << a << " is greater" << endl;
    }
    else
    {
        cout << b << " is greater" << endl;
    }
}

int main()
{
    //either of the below two lines can be used
    //in the first line we leave it to the complier to decide the type to the template based on the nature and type of parameters we pass
    //in the second line we explicitly want an integer value as the result
    cout << sum(1, 2) << endl;
    cout << sum <int> (1, 2) << endl;

    cout << sum(1.5, 2.0) << endl;
    cout << sum <double> (1.5, 2.0) << endl; //sum will result in a double value
    cout << sum <int> (1.5, 2.0) << endl; //sum will now result in an integer

    cout << endl << endl;

    findGreat(1, 2.5);
    findGreat(3.6, 2.5);
    findGreat(2.6, 20);

    return 0;
}