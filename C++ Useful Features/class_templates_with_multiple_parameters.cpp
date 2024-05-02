#include <iostream>

using std::cout; using std::cin; using std::string; using std::endl;

template <typename T1, typename T2>
class Book
{
    public:
        T1 pages;
        T2 name;

        Book(T1 pages, T2 name)
        {
            this->pages = pages; this->name = name;
        }

        void display()
        {
            cout << "Pages - " << pages << " and name - " << name << endl;
        }
};

int main()
{
    //template for int and string
    Book <int, string> b1(500, "Harry Potter"); b1.display();

    //template for float and character
    Book <float, char> b2(500.25, 'C'); b2.display();
    return 0;
}
