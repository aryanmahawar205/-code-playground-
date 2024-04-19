//this code will serve as a simple and basic application for Cab Drivers
//in this we calculate the premium rate for each driver based on their state of residence (either TN for Tamil Nadu or KE for Kerala)
//the application displays Invalid Input if state of residence is anything other than TN or KE
//also the age of the driver should lie between 16 to 80 years (inclusive of both), else again it displays Invalid Input
//the application also uses static data members and static member function to return the total drivers (in this case 3) created and display the same
//it also destructs the objects once the task of premium calculation is completed

#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

//simple class to calculate the Premium for a driver
class AutoInsurance
{
    private:
        int insuranceID;

    public:
        int age; string name, state; static int numberOfDrivers;

        //default constructor setting the age of driver to 0
        AutoInsurance()
        {
            age = 0;
        }

        //parameterized constructor to set up members as the user provides
        AutoInsurance(int age, string name, string state, int insuranceID)
        {
            this->age = age; this->name = name; this->state = state; this->insuranceID = insuranceID;
            numberOfDrivers++;
        }

        //actual function which calculates the Premium based on state of residence and age factor checks
        void premiumCalculator()
        {
            if ((state.compare("KE") == 0 || state.compare("TN") == 0) && (age >= 16 && age <= 80))
            {
                if (state.compare("KE") == 0)
                {
                    int premium = (1000 + 2*(1000-age));
                    cout << "Driver 1 Premium - " << premium << " rupees" << endl;
                }

                else if (state.compare("TN") == 0)
                {
                    int premium = (500 + 2*(1000-age));
                    cout << "Driver 2 Premium - " << premium << " rupees" << endl;
                }

                else
                {
                    int premium = (2*(1000-age));
                    cout << "Driver 3 Premium - " << premium << " rupees" << endl;
                }
            }

            else
            {
                cout << "Invalid Input!" << endl;
            }
            
        }

        //static member function to just return back the total number of drivers created
        static int displayTotalDrivers()
        {
            return numberOfDrivers;
        }

        //destructor to finally destroy the objects created
        ~AutoInsurance()
        {
            cout << name << " is deleted!" << endl;
        }
};

//initializing static data member numberOfDrivers to zero outside the class using :: operator
int AutoInsurance :: numberOfDrivers = 0;

int main()
{
    int age1, age2, age3, id1, id2, id3; string name1, name2, name3, state1, state2, state3;
    cout << endl;

    cout << "Enter age of first Driver - "; cin >> age1;
    cout << "Enter name of first Driver - "; cin >> name1;
    cout << "Enter state of residence of first Driver (TN for Tamil Nadu and KE for Kerala) - "; cin >> state1;
    cout << "Enter Insurance ID of first Driver - "; cin >> id1;
    cout << endl;

    cout << "Enter age of second Driver - "; cin >> age2;
    cout << "Enter name of second Driver - "; cin >> name2;
    cout << "Enter state of residence of second Driver (TN for Tamil Nadu and KE for Kerala) - "; cin >> state2;
    cout << "Enter Insurance ID of second Driver - "; cin >> id2;
    cout << endl;

    cout << "Enter age of third Driver - "; cin >> age3;
    cout << "Enter name of third Driver - "; cin >> name3;
    cout << "Enter state of residence of third Driver (TN for Tamil Nadu and KE for Kerala) - "; cin >> state3;
    cout << "Enter Insurance ID of third Driver - "; cin >> id3;
    cout << endl;

    //creating 3 objects (as mentioned in the problem statement)
    AutoInsurance driver1(age1, name1, state1, id1);
    AutoInsurance driver2(age2, name2, state2, id2);
    AutoInsurance driver3(age3, name3, state3, id3);
    
    //calculating each driver object premium
    driver1.premiumCalculator(); driver2.premiumCalculator(); driver3.premiumCalculator();
    cout << endl;

    //displaying number of driver objects created using :: operator
    cout << "Number of Driver Objects - " << AutoInsurance :: numberOfDrivers << endl << endl;

    return 0;
}