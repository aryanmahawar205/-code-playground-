//in this code we will be creating a base class called Book and will inherit it to 2 other derived classes called Reference_Book and Magazine
//the base class Book will have a function called display which essentially displays the details of the book
//each of the derived classes will have the same function too but in the derived classes, the function will perform slightly
//different tasks thus achieving the concept of function overriding in C++ inheritance

#include <iostream>

using namespace std;

class Book
{
    public:
        string name, author;

        void getData(string aName, string aAuthor)
        {
            name = aName;
            author = aAuthor;
        }

        void display()
        {
            cout << "display function of the base class Book has been invoked" << endl;
        }
};

class Reference_Book : public Book
{
    public:
        void display()
        {
            cout << "display function of the derived class Reference_Book has been invoked (function overriding)" << endl << endl;
            cout << "Your book is " << name << " by " << author << endl << endl;
        }
};

class Magazine : public Book
{
    public:
        void display()
        {
            cout << "display function of the derived class Magazine has been invoked (function overriding)" << endl << endl;
            cout << "Your book is " << name << " by " << author << endl << endl;
        }
};

int main()
{
    int type;
    cout << endl;
    cout << "What type of Book object you wish to create? (Enter 1 for a Reference Book or 2 for a Magazine) - ";
    cin >> type;
    cin.clear(); cin.sync();
    cout << endl;

    if (type == 1)
    {
        Reference_Book rb;
        string referenceBookName, referenceBookAuthor;

        cout << "Enter the name of your Reference Book - ";
        getline(cin, referenceBookName);

        cout << "Enter the name of the Reference Book author - ";
        getline(cin, referenceBookAuthor);

        cout << endl;

        rb.getData(referenceBookName, referenceBookAuthor); rb.display();
    }

    else if (type == 2)
    {
        Magazine m; string magazineName, magazineAuthor;

        cout << "Enter the name of your Magazine - ";
        getline(cin, magazineName);

        cout << "Enter the name of the Magazine author - ";
        getline(cin, magazineAuthor);

        cout << endl;

        m.getData(magazineName, magazineAuthor); m.display();
    }

    else
    {
        cout << "----Invalid Input!----Program Terminating!----Try Again!----" << endl << endl;
    }
    
    return 0;
}