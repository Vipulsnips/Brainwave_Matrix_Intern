#include <iostream>
using namespace std;
#include "atmclass.cpp"
void intro(){
        cout << "\nATM Menu:"<<endl;
        cout << "1. Check Balance:"<<endl;
        cout << "2. Deposit Money:"<<endl;
        cout << "3. Withdraw Money:"<<endl;
        cout << "4. Exit:"<<endl;
        cout << "Enter your choice: "; 
}
int main() {
    cout<<"---------------------------WELCOME TO THE ATM---------------------------"<<endl;
    cout<<"1. REGISTER \n2. EXIT"<<endl;
    int flg=0;cout<<"Enter Your Choice:";
    cin>>flg;
    if(flg==1){
        cout<<"Enter Your Name:";
        string name;cin>>name;
        cout<<"Enter Your Username:";
        string username;cin>>username;
        cout<<"Enter Your Account Number:";
        int acc;cin>>acc;
        cout<<"Enter Your pin:";
        int pin;cin>>pin;
        cout<<"Enter Your Balance:";
        int balance;cin>>balance;
        atm myATM(name,username,acc,pin,balance);
        cout<<"\nThank you for registering in our bank"<<endl;
        cout<<"1. Login\n2. Exit"<<endl;
        cin>>flg;
        if(flg==1){
                int choice=0, enteredPin;
    bool authenticated = false;

    cout << "Welcome to the ATM"<<endl;
    int cnt=0;
    while (!authenticated) {
        if(cnt==5){
            cout<<"Too many unsuccessful tries! \nAccount is now locked."<<endl;
            break;
        }        
        cout << "Please enter your PIN: ";
        cin >> enteredPin;
        authenticated = myATM.authenticate(enteredPin);
        cnt++;
    }
    cout<<"\n Welcome "<<name<<endl;
    while(choice!=4 && cnt!=5){
        intro();
        cin >> choice;
        if(choice==1){
            myATM.showBalance();
        }
        else if(choice==2){
            double depositAmount;
            cout << "Enter amount to deposit: Rs";
            cin >> depositAmount;
            myATM.deposit(depositAmount);
        }
        else if(choice==3){
            double withdrawAmount;
            cout << "Enter amount to withdraw: Rs";
            cin >> withdrawAmount;
            myATM.withdraw(withdrawAmount);
        }
        else if(choice==4){
            cout << "Thank you for using the ATM. Goodbye!"<<endl;
            break;
        }
        else{
            cout << "Invalid choice. Please try again."<<endl;
        }
    }
        }
        else{
            cout << "Thank you for using the ATM. Goodbye!"<<endl;
        }
    }
    else{
        cout << "Thank you for using the ATM. Goodbye!"<<endl;
    }

    return 0;
}





