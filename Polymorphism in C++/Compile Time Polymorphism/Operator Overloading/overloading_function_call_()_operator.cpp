//this code will demonstrate how we could overload the function call operator or the () operator
//since this too is a special operator in C++, we can only overload it using non-static member function
//no friend function can be used

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

        //overloading () operator using non-static member function
        int operator () (int setMark)
        {
            this->mark = setMark;
            return this->mark;
        }
};

int main()
{
    Mark m1(50); //constructor will be called
    m1.showMark();

    m1(60); //overloaded operator function will be called
    m1.showMark();

    return 0;
}
