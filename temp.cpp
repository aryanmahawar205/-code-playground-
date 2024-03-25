//place to test out logic for code

#include <iostream>
#include <iomanip>

using namespace std;

inline void rhombus(int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        cout << setw(i+n) << "*****" << endl;
    }
}

int main()
{
    rhombus(5);

    return 0;
}