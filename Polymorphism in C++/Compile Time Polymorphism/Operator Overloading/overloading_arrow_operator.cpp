//this code will demonstrate how we could overload -> operator using non-static member function
//we cannot overload it using friend function since -> is a special operator in C++

#include <iostream>

class Mark
{
    private:
        int mark;

    public:
        Mark()
        {
            mark = 0;
        }

        Mark(int aMark)
        {
            mark = aMark;
        }

        void showMark()
        {
            std::cout << "Your Mark is - " << mark << std::endl;
        }

        //overloading -> using non-static member function
        Mark* operator -> ()
        {
            return this;
        }
};

int main()
{
    Mark m1(60);
    m1.showMark();

    m1->showMark(); //overloading required to access showMark() method this way

    return 0;
}
