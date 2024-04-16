//this code will help to calculate and display the monthly interest for a Bank Account user
//here we have the monthly interest rate as a static data member of the class
//each time the user invokes the function to calculate the total amount, we add up the interest amount to the previous recent amount
//thus incrementing the amount by the corresponding interest amount each time the call is made, just like in a normal everyday Bank

#include <iostream>

using std::cin; using std::cout; using std::endl;

class Account
{
    private:
        double amount; double incrementedAmount; static double interestRate; //declaring interestRate as static data member

    public:
        int accountNumber;

        Account()
        {
            amount = 0.0; accountNumber = 0; interestRate = 0.0;
        }

        Account(int set_AccountNumber, double set_Amount, double set_InterestRate)
        {
            amount = set_Amount; interestRate = set_InterestRate; accountNumber = set_AccountNumber;
        }

        //function to calculate the monthly interest and also return the new amount
        //the new amount is nothing but the sum of incrementedAmount and the previous amount
        double calculateMonthlyInterest()
        {
            double monthlyInterest = (amount * interestRate) / 12.0;
            incrementedAmount += monthlyInterest;
            return (incrementedAmount + amount);
        }

        //function to display the account details and also to change the previous amount to new amount
        void displayStats()
        {
            double finalAmount = calculateMonthlyInterest(); cout << endl;
            cout << "Your account number is - " << accountNumber << " and your interest rate is " << interestRate << " percent!" << endl;
            cout << "The amount deposited is - " << amount << " rupees " << "which after a month's interest will become - " << finalAmount << " rupees" << endl;
            cout << endl; amount += incrementedAmount;
        }

};

double Account :: interestRate = 0.0; //assigning interestRate to 0 outside the class since it is a static data member
 
int main()
{
    int accNum; double amt, intRate; cout << endl;
    cout << "Enter your Bank Account Number - "; cin >> accNum;
    cout << "Enter the Amount (in Rupees) you wish to deposit to your Account - "; cin >> amt;
    cout << "At what Interest Rate (monthly) do you wish to deposit the above said amount? - "; cin >> intRate;

    Account Bank(accNum, amt, intRate); Bank.displayStats(); cout << endl;
    
    //we could invoke the function Bank.displayStats(); multiple times with our object
    //to see how to monthly interest gets added to the amount each time the function is called as shown below

    //invoking Bank.displayStats() function one more time for demonstration to see how the monthly interest gets added to the amount each time

    cout << "Do you want to calculate monthly interest once again on your already incremented amount? (y/n) - "; char check; cin >> check;

    if (check == 'y')
    {
        Bank.displayStats();
    }

    return 0;
}