#include <iostream>

using namespace std;

int main()
{
    int number; string sentence;

    cout << "Enter a number - ";
    cin >> number;

    cin.clear(); cin.sync(); //clearing the input buffer

    cout << "Enter a sentence - ";
    getline(cin, sentence);

    cout << endl;
    cout << "The number you have entered is - " << number << endl;
    cout << "The sentence is - " << sentence << endl;

    return 0;
}
