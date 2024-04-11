//this code will demonstrate how to perform operator overloading using friend functions and its need
//well the need to perform operator overloading through friend functions is pretty straightforward
//when we perform operator overloading using member function there is an assumption that the member function
//is being called for the left operand for that operation and the right operand is the one which is getting passed to the function
//but that may not be the case every time, say you want to perform 5 + object or say 5 * object
//to perform such operations we have to compulsorily overload the operators using friend functions


#include <iostream>

using namespace std;

class Counter
{
    //performing operator + overloading using friend function
    friend Counter operator + (Counter obj1, Counter obj2);
    friend Counter operator * (int num, Counter obj);

    private:
        int count;

    public:
        Counter(int aCount)    
        {
            count = aCount;
        }

        void printCount()
        {
            cout << count << endl;
        }

        void incrementCount()
        {
            count++;
        }
};

Counter operator + (Counter obj1, Counter obj2) 
{
    Counter result = obj1.count + obj2.count;
    return Counter(result);
}

Counter operator * (int num, Counter obj)
{
    return Counter(num * obj.count);
}

int main()
{
    Counter c1(5);
    c1.incrementCount();

    Counter c2(4);

    Counter c3(c1+c2);
    c3.printCount();

    Counter c4(10 * c2);
    c4.printCount();

    return 0;
}

//There are some situations in which we MUST use either a friend function 
//or member function to implement operator overloading

//We cannot use a member function for operator overloading when the left 
//member is not a class OR it is a class we can't modify

//Notably, we cannot overload the << stream insertion operator as a member 
//function because doing so requires a function with << as the left operand!

//C++ does not allow these operators to be overloaded using a friend function:
//  assignment: =
//  function call: ()
//  member selection (arrow): ->
//So we must use a member function instead!

//-----------------Summary----------------------
//in the below few lines I have taken example of + operator just for instance
//same will hold true for *, / and so on...

//c1 = c2 + c3; will work when overloaded with or without friend function
//c1 = c2 + 5; will work when overloaded with or without friend function
//c1 = 5 + c2; will work only when overloaded with friend function