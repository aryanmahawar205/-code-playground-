#include <iostream>

using namespace std;

class Square
{
    public:
        int side_length;
        string colour;

        Square() //default constructor with zero arguments
        {
            side_length = 0;
            colour = "black";
        }

        Square (int aSide_Length) //constructor with one argument
        {
            side_length = aSide_Length;
        }

        Square (int aSide_Length, string aColour) //constructor with two arguments
        {
            side_length = aSide_Length;
            colour = aColour;
        }

        void printData()
        {
            cout << "Side Length - " << side_length << " Colour - " << colour << endl;
        }
};

int main()
{
    Square squares_array1[3]; //declaring array of objects without arguments

    for (int i = 0; i < 3; i++)
    {
        squares_array1[i].printData();
    }

    cout << endl << endl;

    Square squares_array2[3] = {Square(10, "Red"), Square(20, "Green"), Square(30, "Yellow")}; //array of objects with arguments to constructor

    for (int i = 0; i < 3; i++)
    {
        squares_array2[i].printData();
    }

    return 0;
}