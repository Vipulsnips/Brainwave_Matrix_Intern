#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>  // For random account generation

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

    // Private method to generate a random account number
    string generateAccountNumber() {
        string accNo = to_string(rand() % 90000000 + 10000000);  // Generate an 8-digit number
        return accNo;
    }

public:
    BankAccount(string name, double initialDeposit) {
        accountNumber = generateAccountNumber();
        ownerName = name;
        balance = initialDeposit;
    }

    void displayAccountDetails() const {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Success! $" << fixed << setprecision(2) << amount
                 << " deposited. New balance: $" << balance << endl;
        } else {
            cout << "Error: Deposit amount must be greater than zero." << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal of $" << fixed << setprecision(2) << amount
                 << " successful. New balance: $" << balance << endl;
            return true;
        } else {
            cout << "Error: Invalid withdrawal amount or insufficient funds." << endl;
            return false;
        }
    }

    bool transferTo(BankAccount &recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            cout << "Transfer successful." << endl;
            return true;
        }
        return false;
    }

    string getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }
};

double getValidAmount() {
    double amount;
    while (true) {
        cin >> amount;
        if (cin.fail() || amount < 0) {
            cin.clear(); // Clear the error state of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid amount. Please enter a valid positive number: ";
        } else {
            return amount;
        }
    }
}

BankAccount* findAccount(vector<BankAccount> &accounts, const string &accNo) {
    for (auto &account : accounts) {
        if (account.getAccountNumber() == accNo) {
            return &account;
        }
    }
    return nullptr;
}

void createAccount(vector<BankAccount> &accounts) {
    string ownerName;
    double initialDeposit;

    cout << "Enter the account holder's name: ";
    cin.ignore();
    getline(cin, ownerName);
    cout << "Enter the initial deposit amount: ";
    initialDeposit = getValidAmount();

    accounts.push_back(BankAccount(ownerName, initialDeposit));
    cout << "Account created successfully!" << endl;
    accounts.back().displayAccountDetails();
}

void depositToAccount(vector<BankAccount> &accounts) {
    string accNo;
    cout << "Enter the account number: ";
    cin >> accNo;

    BankAccount* account = findAccount(accounts, accNo);
    if (account != nullptr) {
        cout << "Enter deposit amount: ";
        double amount = getValidAmount();
        account->deposit(amount);
    } else {
        cout << "Account not found!" << endl;
    }
}

void withdrawFromAccount(vector<BankAccount> &accounts) {
    string accNo;
    cout << "Enter the account number: ";
    cin >> accNo;

    BankAccount* account = findAccount(accounts, accNo);
    if (account != nullptr) {
        cout << "Enter withdrawal amount: ";
        double amount = getValidAmount();
        account->withdraw(amount);
    } else {
        cout << "Account not found!" << endl;
    }
}
void transferBetweenAccounts(vector<BankAccount> &accounts) {
    string senderAccNo, recipientAccNo;
    cout << "Enter the sender's account number: ";
    cin >> senderAccNo;
    cout << "Enter the recipient's account number: ";
    cin >> recipientAccNo;

    BankAccount* sender = findAccount(accounts, senderAccNo);
    BankAccount* recipient = findAccount(accounts, recipientAccNo);

    if (sender != nullptr && recipient != nullptr) {
        cout << "Enter transfer amount: ";
        double amount = getValidAmount();
        sender->transferTo(*recipient, amount);
    } else {
        cout << "One or both accounts not found!" << endl;
    }
}

void displayAllAccounts(const vector<BankAccount> &accounts) {
    cout << "\n--- List of Accounts ---" << endl;
    for (const auto &account : accounts) {
        account.displayAccountDetails();
        cout << "-------------------------" << endl;
    }
}

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n--- Welcome to the Online Banking System ---"<<endl;
        cout << "1. Create Account"<<endl;
        cout << "2. Deposit"<<endl;
        cout << "3. Withdraw"<<endl;
        cout << "4. Transfer"<<endl;
        cout << "5. Display All Accounts"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Please select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                depositToAccount(accounts);
                break;
            case 3:
                withdrawFromAccount(accounts);
                break;
            case 4:
                transferBetweenAccounts(accounts);
                break;
            case 5:
                displayAllAccounts(accounts);
                break;
            case 6:
                cout << "Thank you for using the Online Banking System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
