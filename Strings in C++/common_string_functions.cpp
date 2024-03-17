#include <iostream>
#include <string>

using namespace std;

int main()
{
    //concatenation in C++ strings

    string test1 = "Fam";
    string test2 = "ily";
    string test3;

    test3 = test1 + test2; //method 1

    cout << "Concatenation - " << test3 << endl;
    cout << "Concatenation - " << test1 + test2 << endl;

    test1.append(test2); //method 2 (now test1 definition is changed)

    cout << "Concatenation - " << test1 << endl;

    //.empty() and .clear() string functions in C++ strings
    //.empty() function checks if a string is empty or not
    //.clear() function clear the string and makes it empty

    test1 = "There is some data in here";

    test1.clear();

    if (test1.empty())
    {
        cout << "test1 string has been cleared using .clear() function" << endl;
    }
    else
    {
        cout << test1 << endl;
    }

    //type casting strings to int, double, float and vice versa using to_string() and stoi(), stod(), etc functions
    //to_string() - to convert integer, double, floats to string equivalent
    //stoi() - to convert string to integer
    //stod() - to convert string to double

    int number = 10;
    test1 = to_string(number);

    cout << "10 + 10 = 1010 (string concatenation) -----> " << test1 + "10" << endl;

    test1 = "100";
    number = stoi(test1);

    cout << "100 + 100 = 200 (integer addition) --------> " << number + 100 << endl;

    //.substr() function to pull out a substring from a string

    test1 = "A test string";
    string substring;

    //.substr() function takes 2 arguments
    //first argument is the starting index (from where you want to extract the string), here = 2
    //second argument is the number of characters you want to pull out from that starting index, here = 4 characters
    substring = test1.substr(2, 4);

    cout << "The substring extracted is - " << substring << endl;

    //.compare() function to compare two strings
    //s1.compare(s2) - will compare s1 string to s2 string
    //s2.compare(s1) - will compare s2 string to s1 string
    //first.compare(second) - general form where the first string is compared to the last string
    //if both first and last strings are equal, the function returns 0
    //if first string > second string, the function returns a value > 0
    //if first string < second string, the function returns a value < 0

    string s1, s2;

    s1 = "This is a sample string 1";
    s2 = "This is a sample string 2";

    cout << s1.compare(s2) << endl;
    cout << s2.compare(s1) << endl;

    s1 = s2;

    cout << s1.compare(s2) << endl;
    cout << s2.compare(s1) << endl;

    //.erase() function to delete a specific portion of a string

    s1 = "nincompoop";
    string erased;

    //.erase() function takes 2 arguments
    //first argument is the starting index from where you want to erase, here 3
    //the second argument is the number of characters you wish to erase from that starting index, here 3
    erased = s1.erase(3, 3);

    cout << "Erased string - " << erased << endl;

    //.find() function to find a substring in main string
    //.find() function returns the first index where it finds the substring in main string

    s1 = "nincompoop";
    string sub = "com";

    cout << s1.find(sub) << endl;

    //.insert() function to insert a specific string into the main string

    s1 = "nincompoop";

    //.insert() function takes 2 arguments
    //first argument is the index of the main string from where you want to start the insertion, here 2
    //second argument is the string which you want to insert from that index, here "lol"
    s1.insert(2, "lol");

    cout << "After insertion - " << s1;

    return 0;
}
