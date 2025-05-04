#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("sensor_log.txt");

    out << "25.5 C\n";
    streampos pos1 = out.tellp(); 
    cout << "Pointer is at: " << pos1 << endl;

    out << "98.1 %RH\n";
    streampos pos2 = out.tellp();
    cout << "Pointer is at: " << pos2 << endl;


    out.close();

    return 0;
}
