#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    
    ofstream out("config.txt");
    

    out << "AAAAABBBBBCCCCC";
    out.close();

    fstream file("config.txt", ios::in | ios::out);

    file.seekp(5); 

    file << "XXXXX";

    file.close();
    cout << "Update complete\n";

    ifstream in("config.txt");

    string content;
    getline(in, content);
    cout << "Text of file : " << content << endl;

    in.close();

    return 0;
}
