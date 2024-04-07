#include <iostream>
#include <utility> //has to be included to use inbuilt swap() function

using namespace std;

class Data
{
    public:
        int value;
};

int main()
{
    //swapping with integers first (you can swap with any primitive type essentially, like a double or a char)
    int a = 5; int b = 10;
    cout << "Before Swap -> a = " << a << " and b = " << b << endl;
    swap(a, b);
    cout << "After Swap -> a = " << a << " and b = " << b << endl << endl;

    //swapping arrays now
    int array1[] = {1, 2, 3}; int array2[] = {4, 5, 6};
    cout << "Before Swap -> array1 elements are - " << array1[0] << ", " << array1[1] << ", " << array1[2] << endl;
    cout << "Before Swap -> array2 elements are - " << array2[0] << ", " << array2[1] << ", " << array2[2] << endl;
    swap(array1, array2);
    cout << "After Swap -> array1 elements are - " << array1[0] << ", " << array1[1] << ", " << array1[2] << endl;
    cout << "After Swap -> array2 elements are - " << array2[0] << ", " << array2[1] << ", " << array2[2] << endl << endl;

    //swapping class objects now
    Data dataX, dataY;
    dataX.value = 10; dataY.value = 20;
    cout << "Before Swap -> dataX.value - " << dataX.value << " and dataY.value - " << dataY.value << endl;
    swap(dataX, dataY);
    cout << "After Swap -> dataX.value - " << dataX.value << " and dataY.value - " << dataY.value << endl;

    return 0;
}
