//this code is basically an application for a Fun Event in a College
//we will be asking the user of the application to create items they wish to exhibit in the fair and display the attributes of the same

#include <iostream>

//including required packages from standard (std) namespace
using std::cout; using std::cin; using std::endl; using std::string;

class ItemType
{
    private:
        string name; int deposit; int costPerDay;
        
    public:
        void setterMethod(string name, int deposit, int costPerDay)
        {
            this->name = name; this->deposit = deposit; this->costPerDay = costPerDay;
        }

        void displayMethod()
        {
            cout << "Item created - " << name << " with a deposit of Rs. " << deposit << " and cost per day of Rs. " << costPerDay << endl;
        }
};

int main()
{
    int itemNumbers; cout << endl;
    cout << "How many number of items you wish to create for the Fair? - "; cin >> itemNumbers;
    cout << endl; cin.clear(); cin.sync(); //clearing the input buffer

    ItemType iType[itemNumbers]; //creating the array of objects

    //taking input from the user for each object and creating the same in the object array using setterMethod()
    for (int i = 0; i < itemNumbers; i++)
    {
        string tempName; int tempDeposit; int tempCostPerDay;
        cout << "Enter the name of the item you wish to create - "; getline(cin, tempName);
        cout << "Enter the deposit for the said item (in Rupees) - "; cin >> tempDeposit;
        cout << "Enter the corresponding cost per day for the item (in Rupees) - "; cin >> tempCostPerDay;
        cin.clear(); cin.sync(); //clearing the input buffer
        iType[i].setterMethod(tempName, tempDeposit, tempCostPerDay); cout << endl;
    }

    //displaying the objects using displayMethod() once each of them is created successfully
    cout << "Your Items created successfully with entries as..." << endl << endl;
    for (int i = 0; i < itemNumbers; i++)
    {
        iType[i].displayMethod();
    }

    return 0;
}