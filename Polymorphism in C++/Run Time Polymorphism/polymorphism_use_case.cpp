//one of the best and most popular uses of Polymorphism is to have an array of pointers of base class type
//but in that array we could also store objects of derived class type allocating the memory dynamically
//in this array we could call a method function declared as virtual in the base class and overridden in the derived class
//hence reducing code duplication when inherited

#include <iostream>

using std::string; using std::cout; using std::endl;

class Student
{
    public:
        string name;

        Student(string name)
        {
            this->name = name;
        }

        virtual void print()
        {
            cout << name << endl;
        }
};

class EngineeringStudent : public Student
{
    public:
        string speciality;

        //constructor delegation
        EngineeringStudent(string name, string speciality) : Student(name)
        {
            this->speciality = speciality;
        }

        void print()
        {
            cout << name << " : " << speciality << endl;
        }
};

int main()
{
    //an array of pointers to Student objects
    //this array of base class pointer objects can have pointers to derived class objects too
    //owing to Polymorphism
    Student *students[] =
    {
       new Student("Aryan"),
       new Student("Lisa"),
       new EngineeringStudent("Haydon", "Data Science"),
       new EngineeringStudent("Ray", "Machine Learning")
    };

    for (int i = 0; i < 4; i++)
    {
        students[i]->print();
    }

    for (int i = 0; i < 4; i++)
    {
        delete students[i];
    }

    return 0;
}
