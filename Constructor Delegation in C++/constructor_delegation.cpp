//constructor delegation is a concept using to reduce duplicated code lines in out program
//suppose a constructor A perform x and y tasks and constructor B performs x, y and z tasks
//essentially constructor B perform all whats A does and in addition to that also performs z task
//when we individually write code to define each of the constructors A and B, we essentially duplicate code in B from A to perform x and y tasks
//after that we have the unique code to perform task z in constructor B
//the code will work perfectly fine, but this makes debugging harder as changes in one section of the code will have to be 2 times (in our example)
//hence constructor delegation comes into picture where we can make a constructor perform specific tasks which are not intended to be done by it
//by moving to control to that constructor which is meant to do so
//after that the remaining tasks can be performed as usual

/*

---------------------------------------------WITHOUT USING CONSTRUCTOR DELEGATION-------------------------------------------------------

#include <iostream>

using namespace std;

class Rectangle
{
    public:
        int length;
        int breadth;
        int area;
        string colour;

        CONSTRUCTOR 1
        Rectangle(int aLength, int aBreadth) //constructor accepting only length and breadth and setting them. also computed and sets area
        {
            length = aLength;
            breadth = aBreadth;
            area = length * breadth;
        }

        constructor accepting all three arguments and setting them. also computes and sets area
        basically this constructor does all what the above constructor does but also sets the colour in addition
        we see that a lot of code is duplicated here in contrast to the above constructor
        this is where constructor delegation in used
        the code will work just fine for this case too...
        constructor delegation explained in this file only, but after commenting this entire file block
        CONSTRUCTOR 2
        Rectangle(int aLength, int aBreadth, string aColour)
        {
            length = aLength;
            breadth = aBreadth;
            area = length * breadth;
            colour = aColour;
        }

        void printData()
        {
            cout << "Length - " << length << endl;
            cout << "Breadth - " << breadth << endl;
            cout << "Area - " << area << endl;
            cout << "Colour - " << colour << endl;
        }
};

int main()
{
    Rectangle r1(5, 10); //when this object is created CONSTRUCTOR 1 is called
    r1.printData();

    Rectangle r2(10, 100, "Brown"); //when this object is created CONSTRUCTOR 2 is called
    r2.printData();

    return 0;
}

*/

//--------------------------------------------------USING CONSTRUCTOR DELEGATION--------------------------------------------------------

#include <iostream>

using namespace std;

class Rectangle
{
    public:
        int length;
        int breadth;
        int area;
        string colour;

        //CONSTRUCTOR 1
        Rectangle(int aLength, int aBreadth) //constructor accepting only length and breadth and setting them. also computed and sets area
        {
            length = aLength;
            breadth = aBreadth;
            area = length * breadth;
        }

        //CONSTRUCTOR 2
        //this right here is constructor delegation where CONSTRUCTOR 2 is performing what CONSTRUCTOR 1 does and that what it is unique to it
        Rectangle(int aLength, int aBreadth, string aColour) : Rectangle(aLength, aBreadth) //constructor delegation
        {
            colour = aColour;
        }

        void printData()
        {
            cout << "Length - " << length << endl;
            cout << "Breadth - " << breadth << endl;
            cout << "Area - " << area << endl;
            cout << "Colour - " << colour << endl;
        }
};

int main()
{
    Rectangle r1(5, 10); //when this object is created CONSTRUCTOR 1 is called
    r1.printData();

    Rectangle r2(10, 100, "Brown"); //when this object is created CONSTRUCTOR 2 is called (using DELEGATION)
    r2.printData();

    return 0;
}