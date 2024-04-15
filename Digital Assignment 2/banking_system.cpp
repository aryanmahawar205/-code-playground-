//this code will implement a simple banking system for account management based on the guideline specified in the problem statement
//such as that the account balance must be >= 0 and account ID must be between 100 and 999 (inclusive of both)
//we also display credit() of the account after transaction take place

#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class BankAccount
{
    //friend function declaration to access private members AccountID and AccountBalance
    friend void getAccount(BankAccount &obj);

    private:
        int AccountID, AccountBalance;
        
    public:
        string HolderName;

        //parameterized constructor to set BankAccount members up based on certain conditions mentioned in problem statement
        BankAccount(int aAccountID, int aAccountBalance, string aHolderName)
        {
            if (aAccountBalance >= 0)
            {
                AccountBalance = aAccountBalance;
            }

            else
            {
                AccountBalance = 0;
            }

            if (aAccountID >= 100 && aAccountID <= 999)
            {
                AccountID = aAccountID;
            }

            else
            {
                AccountID = -1; //invalid Account ID
            }

            HolderName = aHolderName;
        }

        //function to modify account balance (taking care of Money Withdrawal)
        int setAccountBalance(int withdrawal)
        {
            AccountBalance -= withdrawal;
            return AccountBalance;
        }

        //function to modify account balance (taking care of Money Deposition
        int credit(int deposit)
        {
            AccountBalance += deposit;
            return AccountBalance;
        }

        //function to display the final status of the Account after Withdrawal and Deposition
        void displayFinalStatus()
        {
            cout << "Holder - " << HolderName << " having Bank Account ID - " << AccountID << " has " << AccountBalance << " Rupees in their Account" << endl << endl;
        }

};

//function definition to enable Withdrawal and Deposition based on certain checks
void getAccount(BankAccount &obj)
{
    int depositing, withdrawal; char check;

    //checking for an invalid Account ID
    if (obj.AccountID != -1)
    {
        cout << "Do you wish to deposit money to the Account? (y/n) - "; cin >> check;
        if (check == 'y')
        {
            cout << "Enter the amount (in Rupees) you wish to deposit - "; cin >> depositing;
            cout << "New balance is (in Rupees) - " << obj.credit(depositing) << endl << endl;
        }

        cout << "Do you wish to withdraw money to the Account? (y/n) - "; cin >> check;
        if (check == 'y' && obj.AccountBalance != 0)
        {
            cout << "Enter the amount (in Rupees) you wish to withdraw - "; cin >> withdrawal;
            
            if (obj.AccountBalance < withdrawal)
            {
                cout << "Balance in Account less than amount requested to be withdrawn! Please deposit more money!" << endl << endl;
            }
            
            else
            {
                cout << "New balance is (in Rupees) - " << obj.setAccountBalance(withdrawal) << endl << endl;
            }
        }

        else if (check == 'y' && obj.AccountBalance == 0)
        {
            cout << "Balance in Account is 0 Rupees! Cannot withdraw money! Please deposit to withdraw first!" << endl << endl;
        }

        cout << "After transaction of withdrawal and deposition, final account status is as follows..." << endl << endl;
        obj.displayFinalStatus();
    }

    else
    {
        cout << "-----INVALID ACCOUNT!" << "-----UNABLE TO FETCH DETAILS!-----" << endl << endl;
    }
}

int main()
{
    string name; int id, balance; cout << endl;

    cout << "Enter Account Holder name - "; getline(cin, name);
    cout << "Enter Account ID -  "; cin >> id;
    cout << "Enter current Account Balance (in Rupees) - "; cin >> balance;
    cout << endl;

    BankAccount BAcc(id, balance, name); getAccount(BAcc);

    return 0;
}