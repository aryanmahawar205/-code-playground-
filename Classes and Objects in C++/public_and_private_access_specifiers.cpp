//public access specifiers are available to all classes and functions in the program
//private access specifiers are only available to that particular class in which they are defined

#include <iostream>
#include <string>

using namespace std;

class Employee
{
    //private access specifier
    private:
        double salary;

    //public access specifier
    public:
        string name;

        //getter function
        double getSalary()
        {
            return salary;
        }

        //setter function
        void setSalary(double aSalary)
        {
            if (aSalary < 0)
            {
                salary = 0;
            }
            else
            {
                salary = aSalary;
            }
        }
};

int main()
{
    Employee emp1;

    emp1.name = "Aryan";

    emp1.setSalary(10000);

    cout << emp1.name << " has " << emp1.getSalary() << " dollars" << " as salary" << endl;

    return 0;
}