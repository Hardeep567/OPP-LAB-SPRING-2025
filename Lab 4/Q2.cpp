#include<iostream>
using namespace std;

class Car{
    private:
    string brand;
    string model;
    float rentalPrice;
    bool availability;
    public:
    Car(){
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        availability = true;
    }
    Car(string b,string m,float a,bool t){
        brand = b;
        model = m;
        rentalPrice = a;
        availability = t;
    }
    void updatadetail(){
        cout << " Enter the brand of car";
        cin >> brand;
        cout << " Enter the model of car";
        cin >> model;
        cout << " Enter the rental price of car";
        cin >> rentalPrice;
        string check;
        cout << " Enter true for car availabe of false for not (true/false): ";
        cin >> check;
        availability = "check";
    }
    void checkCar(){
        if(availability == true){
            cout <<"  Car is availible"<< endl;
        }
        else{
           cout << " Not availible for rent" << endl;
        }
    }
    void requestForrent(){
        if(availability == true){
            cout <<"  Car is availible and rent price is : " << rentalPrice << endl;
            availability = false;
        }
        else{
           cout << " Not availibe for rent" << endl;
        }
    }
    void applyDiscount(){
        if(availability == true){
            int i;
            cout << " Enter the days you want ";
            cin >> i;
            if(i >=5 && i<10) rentalPrice -=rentalPrice*0.05;
            if(i>=10 ) rentalPrice -=rentalPrice*0.10;
        }
    }
};

int main(){
    string brand,model;
    float rentalPrice;
    bool availability;
        cout << " Enter the brand of car";
        cin >> brand;
        cout << " Enter the model of car";
        cin >> model;
        cout << " Enter the rental price of car";
        cin >> rentalPrice;
        string check;
        cout << " Enter true for car availabe of false for not (true/false): ";
        cin >> check;
        availability = "check";
    Car c1(brand,model,rentalPrice,availability);
    int i;
    while(1){
    cout <<"  Enter the \n1. For update \n2. For rent Request \n3. For Exist" << endl;
    cin >> i;
    if(i == 1)c1.updatadetail();
    else if(i == 2){
        c1.applyDiscount();
        c1.requestForrent();
    }
    else {
        return 0;
    }
    }
    return 0;
}
