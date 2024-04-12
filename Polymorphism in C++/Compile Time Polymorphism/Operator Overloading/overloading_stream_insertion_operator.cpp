//in this code we will be overloading the << operator, also called the stream insertion operator

#include <iostream>

using namespace std;

class YoutubeChannel
{
    //using friend function to overload << operator
    friend ostream& operator << (ostream &COUT, YoutubeChannel &ytch);

    private:
        string name; int subscriberCount;
    public:
        YoutubeChannel(string aName, int aSubscriberCount)
        {
            name = aName; subscriberCount = aSubscriberCount;
        }
};

//implementation of function to overload << operator
ostream& operator << (ostream &COUT, YoutubeChannel &ytch)
{
    COUT << "Name of Channel - " << ytch.name << endl;
    COUT << "Subscribers Count - " << ytch.subscriberCount << endl;
    return COUT;
}

int main()
{
    YoutubeChannel yt1("UnderDogs", 1500000);
    YoutubeChannel yt2("DogsUnder", 5000000);

    //cout << yt1;

    //this will give an error unless we change the return value of the overloading function from void
    //to a reference of ostream object because he we are kind of doing method chaining
    cout << yt1 << yt2;

    return 0;
}
