//this code will demonstrate how we could overload the new and delete operators for DMA

#include <iostream>
#include <cstdlib>

using std::cout; using std::endl; using std::string;

class Student
{
    private:
        string name; int age;

    public:
        Student()
        {
            name = "Not Specified"; age = 0;
        }

        Student(string aName, int aAge)
        {
            name = aName; age = aAge;
        }

        void displayDetails()
        {
            cout << "My name is - " << name << " and my age is - " << age << endl;
        }

        //overloading new operator
        void* operator new (size_t Obj_size) //size_t type variables will allocate the maximum size in bytes as per your requirement at run-time
        {
            void *pointer; //declaring void pointer for malloc because this is a custom object, we don't really know/have a primitive type for this one
            cout << "The size (bytes) which is being allocated on the heap for your object is - " << Obj_size << endl;
            pointer = malloc(Obj_size);
            return pointer;
        }

        void operator delete (void *objectPointer)
        {
            free(objectPointer);
        }
};

int main()
{
    Student *stu_ptr;

    stu_ptr = new Student("Aryan", 19);

    stu_ptr->displayDetails();

    delete stu_ptr;

    return 0;
}
