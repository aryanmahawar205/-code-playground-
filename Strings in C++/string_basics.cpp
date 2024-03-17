#include <iostream>
#include <string>

using namespace std;

int main()
{
    string test1 = "abcdefghi";

    cout << "Before modification - " << test1 << endl;

    cout << "size - " << test1.size() << endl; //to find length

    cout << "test1[0] - " << test1[0] << endl; //accessing individual elements by indices

    cout << "test1.at(0) - " << test1.at(0) << endl; //also can be used to access individual elements by indices

    cout << "length - " << test1.length() << endl; //also to find length

    test1[0] = 'A'; //valid modification

    cout << "After modification - " << test1;

    return 0;
}
