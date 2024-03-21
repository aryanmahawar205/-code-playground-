#include <iostream>

using namespace std;

class Square
{
    private:
        int side_length;
        static int total_squares; //declaration of static member variable
        
    public:
        Square(int aLength) //constructor defined
        {
            side_length = aLength;
            total_squares++;
        }
        int area()
        {
            return side_length * side_length;
        }
        //this down below is only called the static member function
        //it works / deals with static member variables basically
        static int getTotalSquares()
        {
            return total_squares;
        }
};

int Square::total_squares = 0; //initializing static member variable outside the class to 0 using :: operator

int main()
{
    Square s1(5);

    cout << "Area - " << s1.area() << endl;

    cout << "Total Squares - " << s1.getTotalSquares() << endl; //either you can access the total_squares variable like this (METHOD 1)

    Square s2(10);
    
    cout << "Area - " << s2.area() << endl;

    cout << "Total Squares - " << Square::getTotalSquares() << endl; //or they can be accessed like this too (METHOD 2)

    return 0;
}