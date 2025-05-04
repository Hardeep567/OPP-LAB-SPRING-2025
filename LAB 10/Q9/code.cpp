#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    ofstream out("large_log.txt" , ios::binary);
    out << "This is the first part of log.\n";
    out << "This is the second part of log.\n";
    out << "And the third part.\n";
    out.close();

    ifstream in("large_log.txt", ios::binary);

    char buffer[11]; 

    in.read(buffer, 10);
    buffer[10] = '\0';
    cout << "First 10 characters: " << buffer << endl;

    streampos pos = in.tellg();
    cout << "Current position : " << pos << endl;

    in.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Second 10 characters: " << buffer << endl;

    pos = in.tellg();
    cout << "Current position : " << pos << endl;

    in.close();
    return 0;
}
