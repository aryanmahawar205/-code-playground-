//this code will demonstrate how we can overload ++ and -- operators when they are used in postfix form i.e, i++ or i--
//we have implemented overloading of ++ using member function and of -- using friend function for clarity in both methods

#include <iostream>

class Mark
{
    //declaring operator function as friend to overload -- postfix operator
    friend Mark operator -- (Mark &obj, const int);

    private:
        int mark;

    public:
        Mark()
        {
            mark = 0;
        }

        Mark (int aMark)
        {
            mark = aMark;
        }

        void displayMark()
        {
            std::cout << "Your Mark is - " << mark << std::endl;
        }

        //overloading postfix ++ using member function
        Mark operator ++ (const int)
        {
            Mark duplicate(this->mark);
            this->mark = this->mark + 1;
            return duplicate;
        }
};

//function definition to overload -- operator as postfix
Mark operator -- (Mark &obj, const int)
{
    Mark duplicate(obj.mark);
    obj.mark = obj.mark - 1;
    return duplicate;
}

int main()
{
    Mark mark1(49);
    (mark1++).displayMark(); //abhi 49 hi rahega because of postfix incrementation
    mark1.displayMark(); //now its 50

    (mark1--).displayMark(); //abhi 50 hi rahega because of postfix decrementation
    mark1.displayMark(); //now its 49

    return 0;
}
