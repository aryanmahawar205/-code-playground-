//this code will demonstrate how we could overload ++ and -- operator when used as prefix, i.e ++i or --i
//we will overload ++ using member function and -- using friend function for better clarity

#include <iostream>

class Mark
{
    friend void operator -- (Mark &obj);

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

        void displayMark()
        {
            std::cout << "Your mark is - " << mark << std::endl;
        }

        void operator ++ ()
        {
            mark = mark + 1;
        }
};

void operator -- (Mark &obj)
{
    obj.mark = obj.mark - 1;
}

int main()
{
    Mark mark1(49);
    mark1.displayMark();

    ++mark1;
    mark1.displayMark();

    --mark1;
    mark1.displayMark();

    return 0;
}
