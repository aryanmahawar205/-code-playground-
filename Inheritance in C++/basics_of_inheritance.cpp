//basically when you define a class with some xyz functionality and when you define another class inherited from that class
//the new class also will be able to perform the same xyz functions apart from what functions are unique to that class
//basically the original class is inherited by the new class
//the original class is called the super class
//the inherited class is called the sub class

#include <iostream>

using namespace std;

class Chef
{
    public:
        void makeChicken()
        {
            cout << "The chef makes chicken!" << endl;
        }
        
        void makeSalad()
        {
            cout << "The chef makes salad!" << endl;
        }

        void makeSpecialDish()
        {
            cout << "The chef makes a special dish!" << endl;
        }
};

class ItalianChef : public Chef //inheriting Chef class to italianChef class using : public Chef
{
    public:
        void makePasta()
        {
            cout << "The chef makes Pasta!" << endl;
        }
};

int main()
{
    Chef chef;
    chef.makeChicken();

    ItalianChef italianchef;
    italianchef.makeChicken(); //italian chef inherited functionality to make chicken

    //chef.makePasta();, chef has no function attribute to make pasta
    italianchef.makePasta(); //italian chef can make pasta

    return 0;
}