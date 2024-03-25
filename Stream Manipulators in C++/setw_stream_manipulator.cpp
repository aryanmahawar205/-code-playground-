//setw() stream manipulator can be used to beautifully manipulate our output strings using cout statement
//it is defined in the <iomanip> header file
//it helps us to output data in streams of a specified width
//we mostly use it to decorate out c++ program outputs, like for example - to display information in tabular format

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int area = 123;

    cout << setw(4) << endl; //setw(4) - fill of 4 white spaces by default;
    cout << setw(4) << area << endl; //setw(4) - fill of 4 white spaces, here only 1 is seen cuz 123 numbers use up the rest
    cout << 12345 << endl;
    cout << endl;

    //we can use setfill() method to modify the fill character also. it is set to ' ' by default
    cout << setfill('*') << left; //for left alignment. by default - alignment (of the area / variable) is to the right
    cout << setw(5) << area << endl;
    cout << 12345 << endl;


    return 0;
}
