//a pure virtual function is a function defined in base class and is redefined in derived classes
//but here the compiler forces all the derived classes of that particular base class to have their own implementation of the function otherwise error is shown
//also, a class which has a minimum of one pure virtual function in it is called an Abstract Class
//we CANNOT create objects of an ABSTRACT CLASS

#include <iostream>

using std::cout; using std::endl;

class MusicalInstrument
{
    public:
        virtual void makeSound() = 0; //this right here is the pure virtual function. Just equate the normal function with virtual keyword to 0 which you want to force all your derived classes to have their own implementation of

        //it could also be declared like this
        //just don't provide any function definition
        //virtual void makeSound()
        //{

        //}

};

class Piano : public MusicalInstrument
{
    public:
        void makeSound()
        {
            cout << "Piano Playing..." << endl;
        }
};

class Guitar : public MusicalInstrument
{
    public:
        void makeSound()
        {
            cout << "Guitar Playing..." << endl;
        }
};

int main()
{
    MusicalInstrument *m1; Piano p1;
    m1 = &p1;

    //when we add the keyword virtual in the base class function makeSound
    //we basically tell the compiler to execute the most derived version of the same function (if available)
    //in any of the derived classes. If not, then base implementation is done
    m1->makeSound();

    Guitar g1;
    m1 = &g1;

    m1->makeSound();

    //MusicalInstrument music; will give error because we cannot create objects of Abstract Classes

    return 0;
}
