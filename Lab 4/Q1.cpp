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
           cout << " Not availible for rent" << endl;
        }
    }
};

int main(){
    Car c1;
    int i;
    while(1){
    cout <<"  Enter the \n1. For update \n2. For rent Request \n3. For Exist" << endl;
    cin >> i;
    if(i == 1)c1.updatadetail();
    else if(i == 2)c1.requestForrent();
    else {
        return 0;
    }
    }
    return 0;
}
