//object function are such function defined in the class which each of the objects if wanted can access
//to perform a specific task or check for a particular condition

#include <iostream>

using namespace std;

class Student
{
    public:
        string name;
        string major;
        float gpa;

        Student(string aName, string aMajor, float aGpa) //constructor
        {
            name = aName;
            major = aMajor;
            gpa = aGpa;
        }

        bool hasHonours() //object function
        {
            if (gpa > 9.00)
            {
                return true;
            }
            return false;
        }
};

int main()
{
    Student s1("Jim", "Business", 8.97);
    Student s2("Pam", "Art", 9.67);

    cout << s1.hasHonours() << endl; //when s1 calls hasHonours, its corresponding attributes are passed, ie gpa = 8.97 is checked
    cout << s2.hasHonours() << endl; //when s2 calls hosHonours, its corresponding attributes are passed, ie gpa = 9.67 is checked

    return 0;
}