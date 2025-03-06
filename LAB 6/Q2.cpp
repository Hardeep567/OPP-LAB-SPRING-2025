#include<iostream>
using namespace std;

class Vehicle{
    protected:
    string brand;
    int speed;
    public:
    Vehicle(string b,int a): brand(b),speed(a){}
    void display(){
        cout << " BRAND : " << brand << endl;
        cout << " SPEED : " << speed << endl;
    } 
};

class car : public Vehicle{
    protected:
    int seats;
    public:
    car(string a,int b, int s) : Vehicle(a,b) , seats(s){}

    void display(){
        Vehicle :: display();
        cout << " SEATS : "<< seats << endl;
    }
};
class electricCAR : public car{
    protected:
    int batteryLife;
    public:
    electricCAR(string a,int b,int s,int life) : car(a,b,s),batteryLife(life){}

    void display(){
        car::display();
        cout << " THE BATTERY LIFE OF CAR " << batteryLife << endl;
    }
};

int main(){
    electricCAR e1("New",23,3,4);
    e1.display();
    return 0;
}
