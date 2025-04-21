#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor {
private:
    double temperature;
public:
    Thermometer() : temperature(0.0) {}
    
    void readData(){
        temperature = 21.5;
    }

    void displayReport(){
        cout << "Thermometer: " << temperature << "C" << endl;
    }
};

class Barometer : public WeatherSensor {
private:
    double pressure;
public:
    Barometer() : pressure(0.0) {}

    void readData(){
        pressure = 101.3;
    }

    void displayReport(){
        cout << "Barometer: " << pressure << " hPa" << endl;
    }
};


int main() {
    WeatherSensor* sensors[2];

    sensors[0] = new Thermometer();
    sensors[1] = new Barometer();


    for (int i = 0; i < 2; i++) {
        sensors[i]->readData();
        sensors[i]->displayReport();
    }

    for (int i = 0; i < 2; i++) {
        delete sensors[i];
    }

    return 0;
}
