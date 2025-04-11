#include<iostream>
using namespace std;

class Manager;

class Account{
    private:
    int account_Number;
    double balance;
    public:
    Account(int a,double d){
        account_Number = a;
        balance = d;
    }
    friend class Manager;
    friend void transferFund(Account to,Account from, double bal);
};

class Manager{
    public:
    void displayAccount(Account &acc) {
        cout << "Account Number: " << acc.account_Number << endl;
        cout << "Balance: " << acc.balance << endl;
    }
    void deposit(Account &acc, double amount) {
        if (amount > 0) {
            acc.balance += amount;
            cout << "Deposited " << amount << " to Account " << acc.account_Number << endl;
        } else {
            cout << "Zero amount" << endl;
        }
    }
    void withdraw(Account &acc, double amount) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
            cout << "Withdrew " << amount << " from Account " << acc.account_Number << endl;
        } else {
            cout << "Balance not avaible " << endl;
        }
    }
};

void transferFund(Account to,Account from,double bal){
    if(from.balance >= bal){
        from.balance-=bal;
        to.balance+=bal;
        cout << "Transferred " << bal << " from Account " << from.account_Number << " to Account " << to.account_Number << endl;
    }
    else{
        cout << " Balance not avaible " << endl;
    }
}

int main(){
    Account acc1(1001, 500.0);
    Account acc2(1002, 300.0);
    Manager m;

    m.displayAccount(acc1);
    m.displayAccount(acc2);
    m.deposit(acc1, 150.0);
    m.withdraw(acc2, 50.0);
    m.displayAccount(acc1);
    m.displayAccount(acc2);
    transferFund(acc1, acc2, 200.0);
    m.displayAccount(acc1);
    m.displayAccount(acc2);

    return 0;
}
