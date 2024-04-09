//refer to the concept of function overloading to understand template function overloading better

#include <iostream>

using namespace std;

//first template
template <typename T>
T sum(T a, T b)
{
    return (a + b);
}

//second template, OVERLOADING IT HERE
template <typename T>
T sum(T a, T b, T c)
{
    return (a + b + c);
}

int main()
{
    cout << sum(1, 2) << endl;
    cout << sum <int> (1, 2) << endl;

    cout << sum(5, 7, 10) << endl;
    cout << sum <double> (5, 7.2, 10) << endl;

    return 0;
}