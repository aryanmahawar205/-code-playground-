//getters and setters in classes allow you to control the access to different attributes and elements in the class
//public keyword in class --> means any code in any class or main function can access it
//private keyword in class --> only code in that particular class can access it

#include <iostream>

using namespace std;

class Movie
{
    private:
        string rating;
    public:
        string title;
        string director;

        Movie(string aTitle, string aDirector, string aRating)
        {
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        }

        //setter function
        void setRating(string aRating)
        {
            if (aRating == "G" || aRating == "PG-13" || aRating == "PG" || aRating == "R" || aRating == "NR")
            {
                rating = aRating;
            }
            else
            {
                rating = "NR";
            }
        }

        //getter function
        string getRating()
        {
            return rating;
        }
};

int main()
{
    Movie avengers("The Avengers", "Joss Wanton", "PG-13");
    cout << avengers.getRating() << endl;
    avengers.setRating("Dog");
    cout << avengers.getRating() << endl;

    return 0;
}