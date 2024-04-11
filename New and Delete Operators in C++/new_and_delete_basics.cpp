#include <iostream>

using namespace std;

class StudentNoConstructor
{
    public:
        string name;

        void setName(string aName)
        {
            name = aName;
        }

        void getName()
        {
            cout << "Calling class without a constructor..." << endl;
            cout << "The name of the student is - " << name << endl;
        }
};

class StudentWithConstructor
{
    public:
        string name;

        StudentWithConstructor(string aName)
        {
            name = aName;
        }

        void getName()
        {
            cout << "Calling class with a constructor..." << endl;
            cout << "The name of the student is - " << name << endl;
        }
};

int main()
{
    //using DMA for regular int variable
    int *ptr = new int; //or we could also say int *ptr = new int(5)
    *ptr = 5;

    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;

    delete ptr; //free the DMA memory to prevent memory leak and to make it available for later use

    cout << endl;

    //using DMA for int array
    int *ptr_arr = new int[5]; //dynamically allocating integer array of size 5

    cout << "Enter the array elements..." << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> ptr_arr[i];
    }

    cout << "Array dynamically created as..." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << ptr_arr[i] << " ";
    }
    
    delete[] ptr_arr; //deletes the entire DMA array

    cout << endl << endl;

    //the new and delete operators behave differently when a constructor / destructor is present in a class
    //like for example, the new operator when used for an object of a class type, it automatically calls for the constructor associated
    //whereas the delete operator calls for the destructor

    //using DMA for class objects (for a class without a constructor)
    StudentNoConstructor *pointer_noConstruct = new StudentNoConstructor;
    
    pointer_noConstruct->setName("Aryan"); //or we could dereference the pointer this way - (*pointer_noConstruct)setName("Aryan");
    pointer_noConstruct->getName(); //or also we could dereference the pointer this way - (*pointer_noConstruct).getName();
    
    cout << endl;

    //this statement will give an error because we are trying to call for a class with new operator which has a constructor
    //the new operator by default invoked the corresponding constructor, therefore we will have to specify the name together the object declarator
    //StudentWithConstructor *pointer_withConstruct = new StudentWithConstructor;
    StudentWithConstructor *pointer_withConstruct = new StudentWithConstructor("Aryan");

    pointer_withConstruct->getName();
    
    return 0;
}