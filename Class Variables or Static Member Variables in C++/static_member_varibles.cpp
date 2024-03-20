//static member variables are defined in the class using the static keyword
//they are assigned to some default value outside of the class using :: operation along with class name in which they had been defined

#include <iostream>

using namespace std;

class Animal
{
    public:
        string animal_name;
        static int count;

        Animal(string aAnimalName) //constructor created
        {
            animal_name = aAnimalName;
            count++;
        }
};

int Animal::count = 0; //initializing count to zero outside the class

int main()
{
    Animal a1("Tiger");
    cout << "Animal - " << a1.animal_name << endl;
    cout << "Total count - " << a1.count << endl;
    Animal a2("Lion");
    cout << "Animal - " << a2.animal_name << endl;
    cout << "Total count - " << a2.count << endl;

    return 0;
}