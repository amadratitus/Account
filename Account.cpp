#include <iostream>
#include <cstring>
#include<cctype>
#include<conio.h>
using namespace std;

const double sav_minbalance=5000;
const double curr_minbalance=1000;
const double interestRate=0.05;

class Account {
	protected:
    string depositorName;
    string accountType;
    long accountNumber;
    double balance=0;
public:
    //constructor
    Account(const string& name, long accNumber, double balance)
    {
        depositorName = name;
        this ->accountNumber = accNumber;
        this ->balance=balance;
    }
    //accept deposit
    void deposit()
    {
        double amount;
        cout<<"Enter amount to deposit: "<<endl;
        cin>>amount;
        balance +=amount;
        cout<<"You successfully deposited $ "<<amount<<endl;
    }
       //account details
    void display()
    {
        cout<<"=================== Account Details ======================="<<endl;
        cout<<"Holder's Name: "<<depositorName<<endl;
        cout<<"Account No: "<<accountNumber<<endl;
        cout<<"Balance: $ "<<balance<<endl;
    }
    //permit withdrawal and update balance
    void permitWithdraw()
    {
        int n;
        cout<<"Enter 1 to confirm or 2 to cancel."<<endl;
        cin>>n;
        if(n==1)
        {
            cout<<"Transaction has been successful"<<endl<<endl;
        }else if(n==2)
        {
            cout<<"Transaction cancelled."<<endl;
        }else
        {
        cout<<"Wrong entry try again."<<endl;
        }
    }
    //Check minimum balance, impose penalty and update balance
    void penalty()
    {
        if(balance < sav_minbalance)
        {
            double penalty=balance*0.1;
            balance -=penalty;
            cout<<"A fine of $ "<<penalty<<" has been imposed on your account."<<endl;
        }else if(balance < curr_minbalance)
        {
            double penalty=balance*0.05;
            balance -=penalty;
            cout<<"A fine of $ "<<penalty<<" has been imposed on your account."<<endl;
        }else
        {
        	cout<<"You have $ "<<balance<<" in your account. Thanks"<<endl;
		}
    }

};
class Curr_Account: public Account
{
public:
	Curr_Account(const string& name, long accNumber, double balance): Account(name, accNumber, balance){}
         //withdraw
    void withdraw()
    {
        double amount;
        cout<<"Enter amount to withdraw: ";
        cin>>amount;
        if(((balance - amount) > 0) && (balance > curr_minbalance))
        {
        	balance -=amount;
        	permitWithdraw();
        }else
        {
            cout<<"Insufficent balance"<<endl;
        }
    }
};
class Sav_Account: public Account
{
public:
	Sav_Account(const string& name, long accNumber, double balance): Account(name, accNumber, balance){}
         //withdraw
    void withdraw()
    {
        double amount;
        cout<<"Enter amount to withdraw: ";
        cin>>amount;
        if(((balance - amount) > 0) && (balance > sav_minbalance))
        {
        	balance -=amount;
        	permitWithdraw();
        }else
        {
            cout<<"Insufficent balance"<<endl<<endl;
        }
    }
     //interest computation
    void compInterest()
    {
        int t;
        double interest;
        cout<<"Enter the number of years: ";
        cin>>t;
        interest = balance*interestRate*t;
        balance +=interest;
        cout<<"Interest of $ "<<interest<<" has been added to your account"<<endl;
    }
};


int main() {
    Curr_Account c("John",253534,60000.0);
    Sav_Account s("Doe",7357634,80000.0);
    do
    {
        int option1;
    cout<<"=================== WELCOME TO DFCU BANK ========================"<<endl;
    cout<<endl;
    cout<<"Select Account Type. "<<endl;
    cout<<"1. Saving Account "<<endl;
    cout<<"2. Current Account "<<endl;
    cout<<endl;
    cin>>option1;
    switch(option1)
    {
        case 1:

             int options;
    cout<<"=========== SAVING ACCOUNT ==============="<<endl;
    cout<<"1. Withdraw "<<endl;
    cout<<"2. Compute Interest "<<endl;
    cout<<"3. Check Balance "<<endl;
    cout<<"4. Account Details "<<endl;
    cout<<"5. Exit program" ;
    cout<<endl;
    cout<<"Choose an option? "<<endl;
    cin>>options;
    switch(options)
    {
        case 1: s.withdraw();
        break;
        case 2: s.compInterest();
        break;
        case 3: s.penalty();
        break;
        case 4: s.display();
        break;
        case 5: main();
        break;
        
        default: cout<<"Wrong choice. Try again"<<endl;
    }
        case 2:
             int optionc;
    cout<<"================ CURRENT ACCOUNT ================"<<endl;
    cout<<"1. Withdraw "<<endl;
    cout<<"2. Check Balance "<<endl;
    cout<<"3. Account Details "<<endl;
    cout<<"4. Exit Program ";
    cout<<endl;
    cout<<"Choose an option? "<<endl;
    cin>>optionc;
    switch(optionc)
    {
        case 1: c.withdraw();
        break;
        case 2: c.penalty() ;
        break;
        case 3: c.display();
        break;
        case 4: main();
        break;
        default: cout<<"Wrong choice. Try again"<<endl;
    }

    }
	}while(1);


    return 0;
}