#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

class University
{
    private:
        int dummyNumber, numberK, tempDummyNumber; string course;

    public:
        int year, inputsN;
        
        University (int dummyNumber)
        {
            this->dummyNumber = dummyNumber; this->tempDummyNumber = dummyNumber;
        }

        void year_inputsN_set()
        {
            cout << "Enter the year for which N courses is being considered - "; cin >> year; cout << endl;
            cout << "Enter the number of courses which can be taken for the year " << year << " (max 4 courses) - "; cin >> inputsN;
        }

        void numberK_set_and_checkValidity()
        {
            if (inputsN <= 4 && inputsN > 0)
            {
                for (int i = 0; i < inputsN; i++)
                {
                    cin.clear(); cin.sync(); cout << endl;
                    cout << "Choose your course - "; getline(cin, course);

                    if (course.compare("Information Technology") == 0)
                    
                    Generic_Check:
                    {
                        dummyNumber = tempDummyNumber;

                        cout << "Enter the K number for " << course << " - "; cin >> numberK;

                        int sum = 0; int numberOfDigits = 0;

                        while (dummyNumber != 0)
                        {
                            int lastDigit = dummyNumber % 10;
                            sum += lastDigit;
                            dummyNumber /= 10;
                            numberOfDigits++;
                        }

                        if ((inputsN == numberOfDigits && tempDummyNumber > 0) && (sum % 2 == 0 || sum % 3 == 0 || sum % 5 == 0) && (sum % numberK == 0))
                        {
                            cout << "Valid Dummy Number for " << course << "!" << " (course registered successfully)" << endl;
                        }

                        else
                        {
                            cout << "Invalid Dummy Number for " << course <<  "!" << " (course not registered)" << endl;
                        }
                    }    

                    else if (course.compare("Core Programming") == 0)
                    {
                        goto Generic_Check;
                    }

                    else if (course.compare("Compiler Designing") == 0)
                    {
                        goto Generic_Check;
                    }

                    else if (course.compare("Machine Learning") == 0)
                    {
                        goto Generic_Check;
                    }

                    else
                    {
                        cout << course << "not taught in University!" << endl;
                    }
                }
            }

            else
            {
                cout << "Enter valid number of courses for " << year << " !" << endl << endl;
            }    
        }

        ~University()
        {
            cout << "Deleting University courses for the year " << year << "!" << " (DESTRUCTOR CALLED)" << endl << endl;
        }
};

int main()
{
    cout << endl;
    cout << "                                  Welcome to the University of Computer Science!              " << endl;
    cout << "We offer multiple courses to choose from such as Information Technology, Core Programming, Compiler Designing and Machine Learning." << endl;
    cout << "                                  Choose your domain of interest to get started!" << endl << endl;

    int dummyNum;
    cout << "Enter a Dummy Number for University Accessing Courses - "; cin >> dummyNum;

    University univ(dummyNum); univ.year_inputsN_set(); univ.numberK_set_and_checkValidity(); cout << endl;

    return 0;
}