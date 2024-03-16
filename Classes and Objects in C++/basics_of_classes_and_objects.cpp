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
    Book b1; //b1 is an object to class Book
    b1.name = "Harry Potter";
    b1.author = "JK Rowling";
    b1.pages = 500;

    cout << b1.name;

    return 0;
}

//class --> blueprint or specification of a new custom data type
//object --> instances to that class