#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception {};

template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15) {
        throw InvalidTemperatureException();
    }
    return (celsius * 9/5) + 32;
}

int main() {
    try {
        double tempCelsius = -300;  
        cout << "Attempting to convert " << tempCelsius << "C." << endl;
        double fahrenheit = convertToFahrenheit(tempCelsius); 
        cout << tempCelsius << "C is " << fahrenheit << "F." << endl;
    }
    catch (InvalidTemperatureException& e) {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    return 0;
}
