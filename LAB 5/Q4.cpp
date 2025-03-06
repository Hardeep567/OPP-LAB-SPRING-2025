#include<iostream>
using namespace std;

class AlarmSystem{
    private:
    string Security_level;
    public:
    AlarmSystem(string n): Security_level(n){}
    void display(){
        cout << " " << Security_level;
    }
};

class SmartHome{
    private:
    string name;
    AlarmSystem &a;
    public:
    SmartHome(AlarmSystem &a,string n): name(n), a(a){}
    void display(){
        cout << " NAME : " << name << endl;
        a.display();
    }
};

int main(){
    AlarmSystem a1("high");
    SmartHome s1(a1,"hardeep");
     s1.display();
    return 0;

}
