//this code will demonstrate how we could overload the array subscript operator or the [] operator
//since this is a special operator in C++, the only way to overload it is using non-static member function
//it CANNOT be overloaded using friend function

#include <iostream>

class Mark
{
    private:
        int sub_marks[3];

    public:
        Mark(int sub1, int sub2, int sub3)
        {
            sub_marks[0] = sub1; sub_marks[1] = sub2; sub_marks[2] = sub3;
        }

        //overloading [] operator using non-static member function
        int operator [] (int position)
        {
            return sub_marks[position];
        }
};

int main()
{
    Mark test(90, 80, 95);

    std::cout << test[0] << std::endl; //90
    std::cout << test[2] << std::endl; //95
    std::cout << test[1] << std::endl; //80

    return 0;
}
