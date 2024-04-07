#include <iostream>

using namespace std;

class Grade
{
    private:
        double grade;

    public:
        Grade(double aGrade)
        {
            grade = aGrade;
        }

        // operator type() allows us to create a function that will return a value
        // of the specified type, defining how object instances will be converted to the type

        // In this case we define how to convert a Grade object to a double value by
        // simply return the grade member variable's value...
        operator double()
        {
            return grade;
        }


        // In the chase of converting a Grade object to a char, we return a "letter
        // grade" A,B,C,D or F depending on the range of the grade value...
        operator char()
        {
            if (grade >= 90)
            {
                return 'A';
            }

            else if (grade >= 80)
            {
                return 'B';
            }

            else if (grade >= 70)
            {
                return 'C';
            }

            else if (grade >= 60)
            {
                return 'D';
            }

            else
            {
                return 'F';
            }
        }
};

int main()
{
    Grade grd1(93.22);

    // assigning the Grade object instance to a double variable will cause the
    // type conversion to occur as we specified with operator, resulting in the
    // value 93.22
    double g1 = grd1;
    cout << "The double conversion of grd1 object is - " << g1 << endl;

    // assigning the Grade object instance to a char variable will cause the
    // type conversion to occur as we specified with operator, resulting in the
    // value 'A'
    char gg1 = grd1;
    cout << "The character conversion of grd1 object is - " << gg1 << endl;

    return 0;
}
