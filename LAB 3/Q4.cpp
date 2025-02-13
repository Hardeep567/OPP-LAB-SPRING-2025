#include<iostream>
using namespace std;

class Car{
    private:
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;
    public:
    Car(string b,string m,double fuelC, double currentF){
        brand = b;
        model = m;
        fuelCapacity = fuelC;
        currentFuelLevel = currentF;
    }
    void reducing(double b){
        if(b <= currentFuelLevel){
        currentFuelLevel -=b;
        }
        else {
            cout << " Wrong Input";
        }
    }
    void refuelTank(double b){
        currentFuelLevel +=b;
    }
    void showDetail(){
        cout << " The Remaining Fuel in Tank" << currentFuelLevel;
    }
};

int main(){
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;

    cout << " Enter the car brand : " ;
    cin.ignore();
    getline(cin,brand);

    cout << " Enter the car model : ";
    cin.ignore();
    getline(cin,model);

    cout << " Enter the fuel Capacity : ";
    cin >> fuelCapacity;

    cout << " Enter the Current fuel : ";
    cin >> currentFuelLevel;

    Car s1(brand,model,fuelCapacity,currentFuelLevel);

    int i;
    double b;
    while(1){
        cout << " Enter \n 1. FUEL USED \n 2. REFUEL TANK \n 3. SHOW REAMINING FUEL \n 4. EXIST";
        cin >> i;
        if( i == 1){
            cout << " Enter the Quatity of fuel used : ";
            cin >> b;
            s1.reducing(b);
        }
        else if( i == 2){
            cout << " ENter the Quatity of fuel for refuel : ";
            cin >> b;
            s1.refuelTank(b);
        }
        else if( i == 3){
            s1.showDetail();
        }
        else {
            return 0;
        }
    }

    return 0;
}
