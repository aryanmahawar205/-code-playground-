#include <iostream>

using namespace std;

class Cat
{
    private:
        string name;
        string colour;
        string toy;

    public:
        //default constructor, taking no argument
        Cat()
        {
            name = "Unknown";
            colour = "Unknown";
            toy = "Unknown";
        }

        //another constructor, taking name as argument
        Cat(string n)
        {
            name = n;
            colour = "Unknown";
            toy = "Unknown";
        }

        //another constructor, taking all three parameters as argument
        Cat(string n, string c, string t)
        {
            name = n;
            colour = c;
            toy = t;
        }

        void printCat()
        {
            cout << name << endl << colour << endl << toy << endl;
        }
};

int main()
{
    Cat c1;

    c1.printCat();

    Cat c2("Garfield");

    c2.printCat();

    Cat c3("Hendrix", "Orange", "Ball");

    c3.printCat();

    return 0;
}