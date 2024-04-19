//in this code we create a University clone system where we ask the user for a Dummy Number to access the courses offered by the University
//we also ask the user for the academic year in which they are applying for
//after that we ask for the number of courses which he/she wish to pursue in that academic year
//based on that a K number unique to each course is also asked and then based on certain checks as specified in the problem statement
//we check for the validity of the Dummy Number entered by the user
//if the Dummy Number if valid, the course is registered successfully otherwise it is not
//lastly once the entire process is complete the object along with all the courses is deleted by the implicit destructor call to complete the program


#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

//University class for performing the sequence of instructions as specified in the problem statement
class University
{
    private:
        int dummyNumber, numberK, tempDummyNumber; string course;

    public:
        int year, inputsN;
        
        //parameterized constructor
        University (int dummyNumber)
        {
            this->dummyNumber = dummyNumber; this->tempDummyNumber = dummyNumber;
        }

        //function to take inputs and set up the academic year and the number of courses the user wishes to opt for in that year
        void year_inputsN_set()
        {
            cout << "Enter the year for which N courses is being considered - "; cin >> year; cout << endl;
            cout << "Enter the number of courses which can be taken for the year " << year << " (max 4 courses) - "; cin >> inputsN;
        }

        //function to check for validity of the Dummy Number
        void numberK_set_and_checkValidity()
        {
            //a maximum of 4 courses and minimum of 1 course is permissible in the University (assumption)
            if (inputsN <= 4 && inputsN > 0)
            {
                for (int i = 0; i < inputsN; i++)
                {
                    cin.clear(); cin.sync(); cout << endl; //clearing input buffer followed by new line
                    cout << "Choose your course - "; getline(cin, course);

                    if (course.compare("Information Technology") == 0)
                    
                    //creating a label called Generic_Check to check for other courses
                    //essentially because the code is the same for each of the other courses 
                    //we could reuse this block under this label using the goto looping keyword
                    Generic_Check:
                    {
                        dummyNumber = tempDummyNumber;

                        cout << "Enter the K number for " << course << " - "; cin >> numberK;

                        int sum = 0; int numberOfDigits = 0;

                        //calculation of sum of digits of Dummy Number
                        while (dummyNumber != 0)
                        {
                            int lastDigit = dummyNumber % 10;
                            sum += lastDigit;
                            dummyNumber /= 10;
                            numberOfDigits++;
                        }

                        //actual check for a valid Dummy Number
                        if ((inputsN == numberOfDigits && tempDummyNumber > 0) && (sum % 2 == 0 || sum % 3 == 0 || sum % 5 == 0) && (sum % numberK == 0))
                        {
                            cout << "Valid Dummy Number for " << course << "!" << " (course registered successfully)" << endl;
                        }

                        else
                        {
                            cout << "Invalid Dummy Number for " << course <<  "!" << " (course not registered)" << endl;
                        }
                    }    

                    //else if statements for other courses in the University

                    else if (course.compare("Core Programming") == 0)
                    {
                        goto Generic_Check;  //goto loop to Generic_Check to repeat the same steps and statements again
                    }

                    else if (course.compare("Compiler Designing") == 0)
                    {
                        goto Generic_Check; //goto loop to Generic_Check to repeat the same steps and statements again
                    }

                    else if (course.compare("Machine Learning") == 0)
                    {
                        goto Generic_Check; //goto loop to Generic_Check to repeat the same steps and statements again
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

        //destructor
        ~University()
        {
            cout << "Deleting University courses for the year " << year << "!" << " (DESTRUCTOR CALLED)" << endl << endl;
        }
};

int main()
{
    //some cout statements to let the user know about the University and its offered courses
    cout << endl;
    cout << "                                  Welcome to the University of Computer Science!              " << endl;
    cout << "We offer multiple courses to choose from such as Information Technology, Core Programming, Compiler Designing and Machine Learning." << endl;
    cout << "                                  Choose your domain of interest to get started!" << endl << endl;

    int dummyNum;
    cout << "Enter a Dummy Number for University Accessing Courses - "; cin >> dummyNum;

    University univ(dummyNum); univ.year_inputsN_set(); univ.numberK_set_and_checkValidity(); cout << endl;

    return 0;
}