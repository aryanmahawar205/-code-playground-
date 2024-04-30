#include <iostream>

using std::cin; using std::cout; using std::endl;

class BaseData
{
    public:
        int *data;

        BaseData(int length)
        {
            data = new int[length];
        }


        //in the destructor we free the dynamically allocated memory... it's
        //*essential* that the destructor run otherwise we would have a memory leak.
        //notice how we use the virtual keyword to create a virtual destructor, this
        //means that the destructor of any derived classes will be called using
        //dynamic binding at runtime IF we have a BaseData (base class) pointer to
        //that derived class instance on the heap.  Below we'll create a derived
        //class so we can observe this behaviour.
        virtual ~BaseData()
        {
            cout << "BaseData destructor running..." << endl;
            delete data;
        }
};

class DerivedData: public BaseData
{
    public:
        int *extra_data;

        //constructor delegation
        DerivedData(int length, int extra_length) : BaseData(length)
        {
            extra_data = new int[extra_length];
        }


        //the derived class constructor frees the memory pointed to by extra_data.
        //it does not free the memory allocated by the BaseData constructor, because
        //we expect the BaseData destructor to be called *after* the DerivedData
        //destructor.  This is the "default behaiour" to expect with destructors
        //and inheritance.  The issue is when we have a BaseData pointer to a
        //DerivedData object on the heap... in this case, unless we declare the
        //BaseData destructor using virtual as we have above, *only* the BaseData
        //destructor will run, and the memory allocated in DerivedData will never
        //be freed!  Which means we'll have a memory leak bug in our program.
        ~DerivedData()
        {
            cout << "DerivedData destructor running..." << endl;
            delete extra_data;
        }
};

int main()
{
    //create an array of BaseData pointers to BaseData and DerivedData objects
    //dynamically allocated on the heap
    BaseData *array_of_objects[] =
    {
        new BaseData(10),
        new DerivedData(10, 20)
    };


    //now when we're done working with the objects we'll want to free the
    //dynamically allocated memory, so again we use a loop to go through the
    //array of pointers and destroy each object.  The problem is if we *don't*
    //use the virtual keyword when defining the BaseData destructor then in
    //the case of the DerivedData object *only* the BaseData destructor will
    //be called and NOT the DerivedData destructor, leaving the dynamically
    //allocated data of that object (what extra_data is pointing to) still
    //allocated and not freed!  This would be a memory leak.  Try removing the
    //virtual keyword from the BaseData destructor to see the effect. This is
    //why it's important to use a virtual destructor when defining a class if
    //it is possible the class will be inherited by another class.
    for (int i = 0; i < 2; i++)
    {
        delete array_of_objects[i];
    }

    return 0;
}
