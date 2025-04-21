#include <iostream>
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string trackingNum, double w) : trackingNumber(trackingNum), weight(w) {}
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
};

class AirFreight : public Shipment {
public:
    AirFreight(string trackingNum, double w) : Shipment(trackingNum, w) {}

    void estimateDeliveryTime(){
        cout << "AirFreight " << trackingNumber << ": Estimated delivery in 1-2 days." << endl;
    }

    void showDetails(){
        cout << "AirFreight - Tracking: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string trackingNum, double w) : Shipment(trackingNum, w) {}

    void estimateDeliveryTime(){
        cout << "GroundShipment " << trackingNumber << ": Estimated delivery in 3-5 days." << endl;
    }

    void showDetails(){
        cout << "GroundShipment - Tracking: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main() {
    Shipment* shipments[2];


    shipments[0] = new AirFreight("AIR123", 12.5);
    shipments[1] = new GroundShipment("GRD456", 20.0);

    for (int i = 0; i < 2; ++i) {
        shipments[i]->showDetails();
        shipments[i]->estimateDeliveryTime();
    }

    for (int i = 0; i < 2; ++i) {
        delete shipments[i];
    }

    return 0;
}
