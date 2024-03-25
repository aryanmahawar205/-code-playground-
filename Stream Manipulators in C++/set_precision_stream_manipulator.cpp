//setprecision() method in the <iomanip> library is another way of manipulating our output strings
//specifically they work with numbers having floating point values (like floats and doubles)
//setprecision(n) used alone gives n digits totally (including non-decimal and decimal parts) of the number
//setprecision(n) used with fixed gives n digits of the decimal part (Real Values)
//setprecision(n) used with scientific gives n digits of the decimal part (Imaginary Values)
//all three cases are illustrated as below

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double number = 42.123456;

    cout << "5 digits (totally) - " << setprecision(5) << number << endl;
    cout << "4 digits (totally) - " << setprecision(4) << number << endl;
    cout << "3 digits (totally) - " << setprecision(3) << number << endl;
    cout << "2 digits (totally) - " << setprecision(2) << number << endl;
    cout << "1 digit (totally) - " << setprecision(1) << number << endl;

    cout << endl;

    //fixed - fixed point notations
    cout << "5 digits (after decimal and real) - " << fixed << setprecision(5) << number << endl;
    cout << "4 digits (after decimal and real) - " << fixed << setprecision(4) << number << endl;
    cout << "3 digits (after decimal and real) - " << fixed << setprecision(3) << number << endl;
    cout << "2 digits (after decimal and real) - " << fixed << setprecision(2) << number << endl;
    cout << "1 digit (after decimal and real) - " << fixed << setprecision(1) << number << endl;

    cout << endl;

    //scientific - scientific point notations
    cout << "5 digits (after decimal and imaginary) - " << scientific << setprecision(5) << number << endl;
    cout << "4 digits (after decimal and imaginary) - " << scientific << setprecision(4) << number << endl;
    cout << "3 digits (after decimal and imaginary) - " << scientific << setprecision(3) << number << endl;
    cout << "2 digits (after decimal and imaginary) - " << scientific << setprecision(2) << number << endl;
    cout << "1 digit (after decimal and imaginary) - " << scientific << setprecision(1) << number << endl;

    return 0;
}
