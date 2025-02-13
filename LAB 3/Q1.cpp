#include<iostream>
using namespace std;

class transaction{
    public:
    string date;
    double amount;
    double currentAmount;
    void display(){
        cout << " Date of Transaction : " << date << endl;
        cout << " Amount of Transaction : " << amount << endl;
        cout << " Amount after transaction : " << currentAmount << endl;
    }
};

class wallet{
    private:
    string ownerName;
    double totalBalance;
    transaction *transactionHistory;
    int i = 0;
    public:
    wallet(string name,double i){
        ownerName = name;
        totalBalance = i;
    }
    void addmoney(double x){
        totalBalance +=x;
        i++;
        transaction *t = new transaction[i];
        for(int j=0;j<i-1;j++){
            t[j] = transactionHistory[j] ; 
        }
        cout << " Enter the date " ;
        cin >> t[i-1].date;
        t[i-1].amount = x;
        t[i-1].currentAmount = totalBalance;
        transactionHistory = t;
    }
    void spendMoney(double x){
        totalBalance -=x;
        i++;
        transaction *t = new transaction[i];
        for(int j=0;j<i-1;j++){
            t[j] = transactionHistory[j]; 
        }
        cout << " Enter the date " ;
        cin >> t[i-1].date;
        t[i-1].amount = x;
        t[i-1].currentAmount = totalBalance;
        transactionHistory = t;
    }
    void displayTransaction(){
        for (int j = 0; j < i; j++)
        {
            transactionHistory[j].display();
        }
    }
};



int main(){
    string name;
    double balance;
    cout << " Enter the name of owner : ";
    cin.ignore();
    getline(cin,name);
    cout << " Enter the current balance : ";
    cin >> balance;
    wallet s1(name,balance);

    int n;
    while(1){
        cout << " Enter \n 1.ADD MONEY \n 2.SPEED MONEY \n 3.DISPLAY TRANSACTION \n 4. EXIST ";
        cin >> n ;
        if(n == 1){
            double x;
            cout << " Enter the amount : " ;
            cin >> x;
            s1.addmoney(x);
        }
        else if(n == 2){
            double x;
            cout << " Enter the amount : " ;
            cin >> x;
            s1.spendMoney(x);
        }
        else if(n == 3){
            s1.displayTransaction();
        }
        else{
            return 0;
        }
    }

}
