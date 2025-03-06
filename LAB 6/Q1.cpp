#include<iostream>
using namespace std;

class employee{
    protected:
    string name;
    float salary;
    public:
    employee(string a, float b) : name(a),salary(b){}
    void display(){
        cout << " Name " << name <<endl;
        cout << " Salary : " << salary << endl;
    }

};

class manager : public employee{
    protected:
    float bonus;
    public:
    manager(string a,float b,float s): employee(a,b),bonus(s){}

    void display(){
        employee :: display();
        cout << " Bonus of manager " << bonus << endl;
    }

};



int main(){
    manager m1(" HARDEEEP" , 2300.5,23.0);
    m1.display();
    return 0;
}
