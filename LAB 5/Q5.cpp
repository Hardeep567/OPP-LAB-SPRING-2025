#include<iostream>
using namespace std;

class doctor{
    private:
    string name;
    string specialization;
    string experience;
    public:
    doctor(){

    }
    doctor(string n,string s,string e){
        name = n;
        specialization = s;
        experience = e;
    }
    void display(){
        cout << " NAME IS " << name << endl;
        cout << " SPECIALIZATION IN " << specialization << endl;
        cout << " EXPERIENCE OF " << experience << endl;
    }

};

class hospital{
    private:
    string name;
    doctor **Doctor;
    public:
    int countDoctor = 0;
    hospital(string n){
        name =n;
    }
    void addDoctor(doctor *d){
        countDoctor++;
        doctor **temp = new doctor*[countDoctor];
        for(int i=0;i<countDoctor -1 ;i++){
            temp[i] = new doctor( *Doctor[i]);
        }
        temp[countDoctor - 1] = new doctor(*d);
        Doctor = temp;
    }
    void displayHospital(){
        cout << " NAME OF HOSPITAL IS " << name << endl;
        for(int i=0;i<countDoctor;i++){
            Doctor[i]->display();
        }
    }

};

int main(){
    doctor d1("Hardeep","dentist","4-year");
    hospital h1("Karachi city");
    h1.addDoctor(&d1);
    h1.displayHospital();


    return 0;
}
