//a virtual function is a function defined in base class and is redefined in derived classes
//but this virtual function has a very specific purpose of providing ability of giving you one time POLYMORPHISM

#include <iostream>

using std::cout; using std::endl;

class MusicalInstrument
{
    public:
        virtual void makeSound()
        {
            cout << "Instrument Playing..." << endl;
        }
};

class Piano : public MusicalInstrument
{
    public:
        void makeSound()
        {
            cout << "Piano Playing..." << endl;
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

    return 0;
}
