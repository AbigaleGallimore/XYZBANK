#include <iostream>
#include <iomanip> // For currency formatting

using namespace std;

// Account Class representing the UML Diagram 
class Account {
private:
    // Balance: double
    double balance;

public:
    // Constructor to initialize data member 
    Account(double init_balance) {
        // Validate initial balance >= $1000.00 
        if (init_balance >= 1000.00) {
            balance = init_balance;
        } else {
            // If not valid, set to 0 and display warning 
            balance = 0.0;
            cout << "Warning: Initial balance was invalid (must be >= $1000.00)." << endl;
        }
    }

    //  +setBalance(): void 
    // Included to match UML, though logic not specified in text. 
    void setBalance(double b) {
        balance = b;
    }

    // +getBalance(): double 
    // Return current balance 
    double getBalance() {
        return balance;
    }

    // +Deposit(amount: double): double 
    //  Add amount to current balance 
    double Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Credit successful." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
        return balance;
    }

   
    bool Withdraw(double amount) {
        if (amount > balance) {
            // Print specific error message if exceeded 
            cout << "Debit amount exceeded account balance." << endl;
            return false;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
            return false;
        } else {
            balance -= amount;
            cout << "Debit successful. Please take your cash." << endl;
            return true;
        }
    }
};

int main() {
    double startBalance;
    
    // Setup for XYZ Bank interface 
    cout << "Welcome to XYZ Bank" << endl;
    cout << "Please enter the initial opening balance for the account: $";
    cin >> startBalance;

    // Initialize object with user input
    Account myAccount(startBalance);

    int choice = 0;
    double amount;

    // Use while loop to keep program running 
    while (choice != 4) {
        cout << "\n-----------------------------" << endl;
        cout << "   XYZ BANK ATM INTERFACE    " << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Credit Account (Deposit)" << endl;
        cout << "3. Debit Account (Withdraw)" << endl;
        cout << "4. Exit" << endl;
        cout << "-----------------------------" << endl;
        cout << "Enter your option: ";
        cin >> choice;

        // Use switch statement for menu options
        switch (choice) {
            case 1: // Check Balance 
                cout << fixed << setprecision(2); // Format output to 2 decimal places
                cout << "Current Balance: $" << myAccount.getBalance() << endl;
                break;

            case 2: // Credit 
                cout << "Enter amount to Credit: $";
                cin >> amount;
                myAccount.Deposit(amount);
                break;

            case 3: // Debit 
                cout << "Enter amount to Debit: $";
                cin >> amount;
                myAccount.Withdraw(amount);
                break;

            case 4: // Exit
                cout << "Thank you for banking with XYZ Bank. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}