#include <iostream>

using namespace std;

int isPrime(int n); //function to check if a number is prime

int main()
{
    int flag = 1;
    int n;
    cout << "Enter a number which you want to check if it could be expressed as a sum of two prime numbers - ";
    cin >> n;
    cout << endl;

    for (int i = 2; i <= n/2; i++)
    {
        if (isPrime(i) == 1 && isPrime(n-i) == 1)
            {
                flag = 0;
                break;
            }
    }

    if (flag == 1)
    {
        cout << "No " << n << " cannot be expressed as a sum of two prime numbers";
    }
    else
    {
        cout << "Yes " << n << " can be expressed as a sum of two prime numbers";
    }

    cout << endl;
    return 0;
}

int isPrime(int n)
{
    int checker = 1;

    for (int i = 2; i <= n/2; i++)
    {
        if (n%i == 0)
        {
            checker = 0;
            break;
        }
    }
    if (checker == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
