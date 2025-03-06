#include<iostream>
using namespace std;

class Device{
    private:
    int deviceId;
    bool Status;
    public:
    Device(int n,string s){
        deviceId = n;
        Status ="s";
    }
    bool getstatus(){
        return Status;
    }
    void setStatus(string s){
        Status = "s";
    }
    void display(){
        cout << " Device ID : " << deviceId << endl;
        if(Status == true){
            cout << " STATUS : TRUE \n";
        }
        else {
            cout << " STATUS : FALSE \n";
        }
    }
};

class smartPhone : public Device{
    private:
    float screensize;
    public:
    smartPhone(int n,string s,float screen): Device(n,s),screensize(screen){}
    void display(){
        cout << "------------------------------------------------------------\n";
        Device :: display();
        cout << " SCREEN SIZE :" << screensize << endl;
    }
    void displayScreen(){
        cout << "------------------------------------------------------------\n";
        cout << " SCREEN SIZE : " << screensize << endl;
    }
};

class smartWatch : public Device{
    private:
    bool heartRateMonitor;
    public:
    smartWatch(int n,string s,string heart): Device(n,s){
        heartRateMonitor = "heart";
    }
    void display(){
        cout << "------------------------------------------------------------\n";
        Device:: display();
        if(heartRateMonitor == true){
            cout << " HEART RATE MONITOR : TURE" << endl;
        }
        else {
            cout << " HEART RATE MONITOR : FALSE " << endl;
        }
    }
};

class smartWeatable : public smartWatch , public smartPhone{
    private:
    int stepCounter;
    public:
    smartWeatable(int n,string s,float screen,string heart,int step): smartWatch(n,s,heart),smartPhone(n,s,screen) , stepCounter(step){}
    void display(){
        smartWatch :: display();
        smartPhone :: displayScreen();
        cout << " STEP COUNT : " << stepCounter << endl;
    }

};

int main(){
    smartWeatable s1(103,"true" , 10.3,"true" , 14000);
    s1.display();
    return 0;
}
