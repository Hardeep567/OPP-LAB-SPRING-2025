#include<iostream>
using namespace std;

class Account{
    protected:
    int accountNumber;
    float balance;
    public:
    Account(int p,float f): accountNumber(p) , balance(f){}

    void display(){
        cout << " ACCOUNT NUMBER : " << accountNumber <<  endl;
        cout << " BALANCE : " << balance << endl;
    }
};

class savingAccount : public Account{
    protected:
    float interestrate;
    public:
    savingAccount(int a,float b,float i): Account(a,b) , interestrate(i){}

    void display(){
        cout << "------------------SAVING ACCOUNT-----------------------" <<  endl;
        Account:: display();
        cout << " INTEREST RATE : " << interestrate << endl;
    }
};

class checkAccount : public Account{
    protected:
    float overDraftLimit;
    public:
    checkAccount(int a,float b,float o) : Account(a,b) , overDraftLimit(o){}

    void display(){
        cout << "------------------CHECK ACCOUNT-----------------------" <<  endl;
        Account :: display();
        cout << " OVER DRAFT LIMIT : " << overDraftLimit << endl;
    }
};

int main(){
    savingAccount s1(9103,23456.8,3.5);
    checkAccount c1(9104,234567.8,345.6);
    s1.display();
    c1.display();
    return 0;
}
