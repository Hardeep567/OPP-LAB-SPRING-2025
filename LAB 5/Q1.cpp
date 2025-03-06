#include<iostream>
using namespace std;

class Apartment{
    private:
    string id;
    string address;
    string *OnwerName;
    public:
    Apartment(string i,string address,string name){
        id = i;
        this->address=address;
        OnwerName = new string ;
        *OnwerName = name;
    }
    Apartment (Apartment *a){
        id = (a->id);
        address = a->address;
        OnwerName = a->OnwerName;
    }
    void display(){
        cout << " Id : " << id << endl;
        cout << " Address : " << address << endl;
        cout << " Name : " << *OnwerName << endl; 
    }
};

int main(){
    Apartment agent1("101","23 street", " hardeep");
    Apartment agent2(&agent1);
    agent1.display();
    agent2.display();

}
