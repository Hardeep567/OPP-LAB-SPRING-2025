#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream out("data_records.txt");

        out << "Record 1\n";
        out << "Record 2\n";
        out << "Record 3\n";
        out << "Record 4\n";
        out.close();

    ifstream in("data_records.txt", ios::in);

    in.seekg(20, ios::beg);

    string record;
    getline(in, record);

    cout << "String : " << record << endl;

    in.close();
    return 0;
}
