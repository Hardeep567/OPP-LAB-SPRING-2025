#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class InventoryItem{
    private:
    int id;
    char name[20];
    public:
    void input(){
        cout << " Enter the ID " << endl;
        cin >> id;
        cin.ignore();
        cout <<" Enter the Name " << endl;
        cin.getline(name,20);
    }
    void output(){
        cout << " ID : " << id << endl;
        cout << " Name : " << name << endl;
    }
};

int main(){

    InventoryItem s1,s2;

    s1.input();

    ofstream out("inventory.dat" , ios::binary);
    out.write((char*)&s1, sizeof(s1));

    out.close();

    ifstream in("inventory.dat" , ios::binary);
    in.read((char*)&s2,sizeof(s2));

    s2.output();

    in.close();

    return 0;
}
