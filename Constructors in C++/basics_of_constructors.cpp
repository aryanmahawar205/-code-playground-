//a constructor is a special member function that gets called when you create an object for a class
//remember that constructor function names are the same as the class name in which they are defined
//they generally do the set-up work for an object

#include <iostream>

using namespace std;

class Book
{
    public:
        string name;
        string author;
        int pages;

        Book(string aName, string aAuthor, int aPages) //constructor declared
        {
            name = aName;
            author = aAuthor;
            pages = aPages;
        }

        Book()
        {
            name = "No name declared";
            author = "No author declared";
            pages = 0;
        }
};

int main()
{
    Book b1("Harry Potter", "JK Rowling", 500);

    Book b2("Lord of the Rings", "Dan Brown", 700);

    cout << b2.author << endl;

    Book b3;

    cout << b3.name;

    return 0;
}