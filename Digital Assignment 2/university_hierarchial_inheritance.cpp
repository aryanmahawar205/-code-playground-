//this code will use HIERARCHIAL INHERITANCE to implement to the given problem statement where we will have a base class Person
//this base class Person will be used to inherit other classes such as Faculty, UG_Student, GradStudent
//Each of the derived classes will also have their own parameters as specified in the problem
//we will create of each class type to essentially implement the same using HIERARCHIAL INHERITANCE

#include <iostream>
#include <string>

using namespace std;

///defining the base class People
class People
{
    public:
        string name, uniID;
};

//class Faculty inheriting from People
class Faculty : public People
{
    public:
        string rank;

        //setter function to set members
        void setData(string aName, string a_uniID, string aRank)
        {
            name = aName; uniID = a_uniID; rank = aRank;
        }

        //display function to display the data
        void displayData()
        {
            cout << endl;
            cout << "You have chosen to access the data of Faculty derived class through Hierarchial Inheritance..." << endl;
            cout << "Faculty name is - " << name << " with ID number - " << uniID << " at rank of - " << rank << endl << endl;
        }
};

//class UG_Student inheriting from People
class UG_Student : public People
{
    public:
        int yearOfStudy;

        //setter function to set members
        void setData(string aName, string a_uniID, int aYEARofSTUDY)
        {
            name = aName; uniID = a_uniID; yearOfStudy = aYEARofSTUDY;
        }

        //display function to display the data
        void displayData()
        {
            cout << endl;
            cout << "You have chosen to access the data of UG_Student derived class through Hierarchial Inheritance..." << endl;

            if (yearOfStudy == 1)
            {
                cout << "UG Student name is - " << name << " with ID number - " << uniID << " in his/her - " << yearOfStudy << "st" << " year" << endl << endl;
            }

            else if (yearOfStudy == 2)
            {
                cout << "UG Student name is - " << name << " with ID number - " << uniID << " in his/her - " << yearOfStudy << "nd" << " year" << endl << endl;
            }

            else if (yearOfStudy == 3)
            {
                cout << "UG Student name is - " << name << " with ID number - " << uniID << " in his/her - " << yearOfStudy << "rd" << " year" << endl << endl;
            }

            else if (yearOfStudy == 4)
            {
                cout << "UG Student name is - " << name << " with ID number - " << uniID << " in his/her - " << yearOfStudy << "th" << " year" << endl << endl;
            }

            else
            {
                cout << "UG Student - " << name << " with ID number - " << uniID << "is having year of study > 4, which is NOT POSSIBLE for a course of 4 years!" << endl << endl;
            }
        }
};

//class GradStudent inheriting from People
class GradStudent : public People
{
    public:
        string supervisor_uniID;

        //setter function to set members
        void setData(string aName, string a_uniID, string aSupervisor_uniID)
        {
            name = aName; uniID = a_uniID; supervisor_uniID = aSupervisor_uniID;
        }

        //display function to display the data
        void displayData()
        {
            cout << endl;
            cout << "You have chosen to access the data of GradStudent derived class through Hierarchial Inheritance..." << endl;
            cout << "Graduate Student name is - " << name << " with ID number - " << uniID << " and Supervisor ID number - " << supervisor_uniID << endl << endl;
        }
};

int main()
{
    int check; cout << endl;
    cout << "Which type of University Person, ie. Faculty, UG Student or Graduate Student would you like to create an object for? (Enter 1 for Faculty, 2 for UG Student and 3 for Graduate Student) - ";
    cin >> check; cout << endl;
    cin.clear(); cin.sync(); //to clear the cin input stream for getline()

    if (check == 1)
    {
        Faculty fac; string name, id, rank;
        
        cout << "Enter the name of the Faculty member - ";
        getline(cin, name);

        cout << "Enter the University ID for the Faculty member - ";
        getline(cin, id);

        cout << "At what rank is the Faculty member? - ";
        getline(cin, rank);

        fac.setData(name, id, rank); fac.displayData();
    }

    else if (check == 2)
    {
        UG_Student ugSTU; string name, id; int year;

        cout << "Enter the name of the UG Student - ";
        getline(cin, name);

        cout << "Enter the University ID for the UG Student - ";
        getline(cin, id);

        cout << "Enter the year in which the UG Student is currently enrolled - ";
        cin >> year;

        ugSTU.setData(name, id, year); ugSTU.displayData();
    }

    else if (check == 3)
    {
        GradStudent gsSTU; string name, id, supID;
        
        cout << "Enter the name of the Graduate Student - ";
        getline(cin, name);

        cout << "Enter the University ID for the Graduate Student - ";
        getline(cin, id);

        cout << "Enter the Supervisor University ID for the Graduate Student - ";
        getline(cin, supID);

        gsSTU.setData(name, id, supID); gsSTU.displayData();
    }

    else
    {
        cout << "----Invalid Option Chosen!----Program Terminating!----Try Again!----" << endl << endl;
    }

    return 0;
}