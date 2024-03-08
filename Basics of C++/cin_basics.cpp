#include <iostream>

using namespace std;

int main()
{
    /*
    int x;
    cout << "Enter the value of x - ";
    cin >> x;
    cout << "You have entered x as - " << x << endl;

    //multiple inputs in one cin statement
    int height, width, area;
    cout << "Enter the height and width separated by a space - ";
    cin >> height >> width;
    area = height*width;
    cout << "The area computed is - " << area << endl;

    //cin holds true and false basically. If successful input has taken place it is true, else false
    //eg in above code if we try to enter a string for var x, cin goes into false state and we can have
    //a check for that as shown below

    int y;
    cout << "Enter the value of y - ";
    //checker code
    if (cin >> y)
    {
        cout << "Value of y - " << y << endl;
    }
    else
    {
        cin.clear(); //to clear the error state of cin
        cout << "Invalid Input!";
    }

    //string name; //strings exist in C++! Hurray!
    //cout << "Enter your name (only first name will be displayed) - ";
    //cin >> name;
    //cout << "Hello " << name << "!" << endl;
    //same problem here also as we encountered in scanf to take string input
    //cin does not take space with space
    //in c we had gets() and fgets() to solve the issue
    //here we have getline() function in C++
    //getline(cin, string variable name)
    */

    string name2;
    cout << "Enter your name - ";
    getline(cin, name2);
    cout << "Hello " << name2 << "!";

    return 0;
}
