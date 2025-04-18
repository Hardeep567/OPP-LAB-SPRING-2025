#include<iostream>
using namespace std;

class Patient{
    protected:
    string name;
    string id;
    public:
    Patient(string n,string id) : name(n) , id(id){}
    virtual void displayTreatment(string s) =0;
    virtual void calculateCost(double cost) =0;
};

class Inpatient : public Patient{
    public:
    Inpatient(string n,string i) : Patient(n,i){}

    void displayTreatment(string s){
        cout << " The " << s << " treatment of patient is on going " << endl;
    }
    void calculateCost(double cost){
        cout << " The Cost of treatment is :" << cost << endl;
    }
};

class OutPatient : public Patient{
    public:
    OutPatient(string n,string i) : Patient(n,i){}
    void displayTreatment(string s){
        cout << " The " << s << " treatment of out patient is on going " << endl;
    }
    void calculateCost(double cost){
        cout << " The Cost of treatment is :" << cost << endl;
    }
};

int main(){
    Inpatient p1("xyz" , "23");
    p1.displayTreatment("lungs");
    p1.calculateCost(1000.0);

    OutPatient o1("abc","24");
    o1.displayTreatment("lung");
    o1.calculateCost(234.7);
    
    return 0;
}
