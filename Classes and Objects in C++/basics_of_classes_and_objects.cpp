#include <iostream>

using namespace std;

class Book
{
    public:
        string name;
        string author;
        int pages;
    
};

int main()
{
    Book b1;
    b1.name = "Harry Potter";
    b1.author = "JK Rowling";
    b1.pages = 500;

    cout << b1.name;

    return 0;
}