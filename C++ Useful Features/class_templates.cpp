//just like function templates we can also create what is also known as class templates
//essentially class templates are like a blueprint to a generic class which could be again reused with multiple primitive data types
//the generic class would potentially represent a family of many classes

#include <iostream>

//the below classes IntArray and StringArray basically have repeated code in them
//this problem of code duplication can be fixed if we create a generic class as shown later on in the code
// class IntArray
// {
//     public:
//         int array[10];

//         void filler(int value)
//         {
//             for (int i = 0; i < 10; i++)
//             {
//                 array[i] = value;
//             }
//         }

//         int& at(int index)
//         {
//             return array[index];
//         }
// };

// class StringArray
// {
//     public:
//         string array[10];

//         void filler(string value)
//         {
//             for (int i = 0; i < 10; i++)
//             {
//                 array[i] = value;
//             }
//         }

//         string& at(int index)
//         {
//             return array[index];
//         }
// };

//creating a generic class
template <typename T, int length>
class Array
{
    public:
        T array[length];

        void filler(T value)
        {
            for (int i = 0; i < length; i++)
            {
                array[i] = value;
            }
        }

        T& at(int index)
        {
            return *(&array[index]);
        }
};

using namespace std;

int main()
{
    Array <int, 10> intArr; //all instances of T in the generic class will be replaced by int for intArr object

    intArr.filler(20);

    cout << "array[4] - " << intArr.at(4) << endl;

    Array <string, 5> strArr; //all instances of T in the generic class will be replaced by string for strArr object

    strArr.filler("Hello There!");

    cout << "array[4] - " << strArr.at(4) << endl;

    //ONE THING IS TO BE NOTED THAT WE CANNOT HAVE A VARIABLE ASSIGNED TO LENGTH
    //this is because the variable will be determined by the compiler at run time while the class will be created at compile time
    //hence the below statements will produce errors

    //int x; cin >> x; Array <int, x> int_x_Arr;


    return 0;
}