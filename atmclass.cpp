class atm {
private:
    string username;
    string name;
    double balance;
    int accountno;
    int pin;

public:
    atm(string name,string username,int accountno, int pin,int balance) {
        this->name=name;
        this->username=username;
        this->accountno=accountno;
        this->pin = pin;
        this->balance = balance;
    }

    bool authenticate(int enteredPin) {
        if (enteredPin == pin) {
            cout << "Authentication successful!"<<endl;
            return true;
        } 
        else {
            cout << "Invalid PIN. Try again."<<endl;

            return false;
        }
    }

    void showBalance() {
        cout << "Your current balance is: Rs" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Rs" << amount << " deposited successfully."<<endl;
            showBalance();
        } else {
            cout << "Invalid amount. Please try again."<<endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive value."<<endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "Rs" << amount << " withdrawn successfully."<<endl;
            showBalance();
        }
    }
};