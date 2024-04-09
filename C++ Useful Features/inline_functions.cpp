//inline functions are just like regular functions but help in increasing the optimization of your code
//basically when you create an inline function, the compiler automatically copies
//all the code statements within that inline function into the main and executes them directly then and there itself
//this hence increases code optimization by reducing processing time
//since the control is not transferred from main to the calling function

#include <iostream>

using namespace std;

int regular_triple(int num) //regular function
{
    cout << "Regular Function Executing!" << endl;
    return 3*num;
}

inline int inline_triple(int num) //inline function
{
    cout << "Inline Function Executing!" << endl;
    return 3*num;
}

int main()
{
    cout << regular_triple(5) << endl;
    cout << inline_triple(5) << endl;

    return 0;
}