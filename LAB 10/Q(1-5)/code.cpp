#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("vehicles.txt"); 
    if (!file) {
        cerr << "Error opening file.\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        istringstream Copyline(line);

        string type, id, name, yearStr, extraData, certification;

        getline(Copyline, type, ',');
        getline(Copyline, id, ',');
        getline(Copyline, name, ',');
        getline(Copyline, yearStr, ',');
        getline(Copyline, extraData, ',');
        getline(Copyline, certification, ',');

        // The function stoi converts a string to an integer.
        // Normally, if the string is not a valid integer, stoi throws an exception.
        // However, for this task, we have to assume the input string is always valid and perform direct conversion as writen in task. 
        int year = stoi(yearStr);

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        if (type == "AutonomousCar") {
            size_t pos = extraData.find(':'); 
            string vStr = extraData.substr(pos + 1); 
            float softwareVersion = stof(vStr); // Convert to float
            cout << " Software Version: " << softwareVersion << endl;
        }
        else if (type == "ElectricVehicle") {
            size_t pos = extraData.find(':');
            string cStr = extraData.substr(pos + 1);
            int batteryCapacity = stoi(cStr); // Convert to int
            cout << " Battery Capacity: " << batteryCapacity << endl;
        }
        else if(type == "HybridTruck"){
            size_t cpos = extraData.find(':');
            size_t spos = extraData.find('|');
            size_t bpos = extraData.find("Battery:");

            string cStr = extraData.substr(cpos + 1 , spos - cpos - 1);
            int cargo = stoi(cStr);

            string bStr = extraData.substr(bpos + 8);

            std::cout << " Cargo: " << cStr << ", Battery: " << bStr << endl;
        }
        cout << "Certification: " << certification << endl;
        
    }

    file.close();
    return 0;
}
