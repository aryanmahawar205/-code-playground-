//this code will demonstrate how we could overload the << and >> operators using friend functions
//<< is of type ostream (output stream) and >> is of tyoe istream (input stream)

#include <iostream>

using std::cout; using std::endl; using std::string; using std::cin; using std::ostream; using std::istream;

class Person
{
    //declaring operator functions as friends
    friend void operator << (ostream &output, Person &p);
    friend void operator >> (istream &input, Person &p);

    private:
        string name; int age;

    public:
        Person()
        {
            name = "Not Specified"; age = 0;
        }

        Person(string aName, int aAge)
        {
            name = aName; age = aAge;
        }
};

void operator << (ostream &output, Person &p)
{
    output << "My name is - " << p.name << " and my age is - " << p.age << endl;
}

void operator >> (istream &input, Person &p)
{
    cout << "Enter your name - "; getline(input, p.name);
    cout << "Enter your age - "; input >> p.age;
}

int main()
{
    Person per;
    cin >> per; cout << per;

    return 0;
}
