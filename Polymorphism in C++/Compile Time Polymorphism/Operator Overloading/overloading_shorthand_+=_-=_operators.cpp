//this code will demonstrate how we can overload += and -= operators commonly known as short hand operators
//we will overload += using member function method and -= using friend function to give examples of both

#include <iostream>

class Mark
{
    friend void operator -= (Mark &obj1, int decrease); //friend function declaration

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
            std::cout << "Your Mark is - " << mark << std::endl;
        }

        //overloading += using member function
        void operator += (int increase)
        {
            this->mark = this->mark + increase;
        }
};

//overloading -= using friend function (here definition)
void operator -= (Mark &obj1, int decrease)
{
    obj1.mark = obj1.mark - decrease;
}

int main()
{
    Mark m1(20);
    m1 += 30; //means m1 = m1 + 30
    m1.displayMark();
    m1 -= 30; //means m1 = m1 - 30
    m1.displayMark();

    return 0;
}
