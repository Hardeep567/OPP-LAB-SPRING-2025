#include<iostream>
using namespace std;

class InventoryManager;
class Car{
    private:
    string model;
    double price;

public:
    Car(string m , double p) {
        model = m;
        price = p;
    }
    friend class InventoryManager;
    friend void comparePrice(Car c1, Car c2);
};
void comparePrice(Car c1,Car c2) {
    if (c1.price > c2.price) {
        cout << c1.model << " is expensive "<< endl;
    }
    else if (c1.price < c2.price) {
        cout << c2.model << " is expensive "<< endl;
    } 
    else {
        cout << " Both are same " << endl;
    }
}

class InventoryManager {
    public:
        void updateprice(Car car, double newPrice) {
            car.price = newPrice;
        }
    
        void displaycardetail(Car car) {
            cout << "Model: " << car.model << endl;
            cout << " Price: " << car.price << endl;
        }
};

int main() {
    Car car1("Toyota", 25000.0);
    Car car2("Honda", 27000.0);

    InventoryManager m;
    m.displaycardetail(car1);
    m.displaycardetail(car2);
    m.updateprice(car1, 26510.0);
    m.updateprice(car2, 26530.0);
    m.displaycardetail(car1);
    m.displaycardetail(car2);
    comparePrice(car1, car2);

    return 0;
}
