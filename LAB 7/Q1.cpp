#include<iostream>
using namespace std;

class Device{
    protected:
    int deviceID;
    string deviceName;
    bool status;
    public:
    Device(int id,string  name,bool s){
        deviceID = id;
        deviceName =name;
        status =s;
    }
    void turnOn(){
        status = true;
    }
    virtual void turnof(){
        status = false;
    }
    bool getstatus(){
        return status;
    }
    virtual void getinfo(){
        cout << " Device is : "<< deviceName << endl;
        cout << " Device ID : "<< deviceID << endl;
        if(status == true){
            cout << " Device is on" << endl;
        }
        else {
            cout << " Device is off" << endl;
        }
    }
};

class Light : public Device{
    protected:
    float brightlevel;
    string colorMode;
    public:
    Light(float a,string c,int id,string  name,bool s) : Device(id,name,s) , brightlevel(a) , colorMode(c){}
    void getinfo(){
        Device::getinfo();
        cout << " Brightnees Level : "<< brightlevel << endl;
        cout << " Color Mode is " << colorMode <<  endl;

    }
};

class Thermostat : public Device{
    protected:
    float tempearture;
    string mode;
    float targetTemperature;
    public:
    Thermostat(float t,string m,float target,int id,string  name,bool s) : Device(id,name,s){
        tempearture = t;
        mode = m;
        targetTemperature = target;
    }
    void getinfo(){
        Device::getinfo();
        cout << " Temperature : "<< tempearture << endl;
        cout << " Mode : " << mode << endl;
        cout << " Target Temperature : "<< targetTemperature << endl;
    }
};

class SecurityCamera : public Device{
    protected:
    string resolution;
    bool recordStatus;
    bool nightVisionEnable;
    public:
    SecurityCamera(string r,bool record,bool n,int id,string  name,bool s) : Device(id,name,s){
        resolution = r;
        recordStatus = record;
        nightVisionEnable = n;
    }
    void getinfo(){
        Device::getinfo();
        cout << " Resolution " << resolution << endl;
        if(recordStatus == true){
            cout << " Record Status is true" << endl;
        }
        else {
            cout << " Record Status is false" << endl;
        }
        if(nightVisionEnable == true){
            cout << " Night Vision Enable is ON" << endl; 
        }
        else{
            cout << " Night Vision Enable is OFF" << endl;
        }
    }
};

class SmartPlug : public Device{
    protected:
    float powerConsumption;
    int timeSetting;
    public:
    SmartPlug(float p,float t,int id,string  name,bool s) : Device(id,name,s){
        powerConsumption =p;
        timeSetting = t;
    }
    void getinfo(){
        Device::getinfo();
        cout << " Power Consumption : " << powerConsumption << endl;
        cout << " Time Setting : "<< timeSetting << endl;
    }
    void turnof(){
        cout << "Power usage before turning off: " << powerConsumption << "W\n";
        status = false;
    }
};

int main(){
    Light light(75, "Warm White", 1, "Living Room Light", true);
    Thermostat thermostat(22.5, "Cooling", 24.0, 2, "Thermostat", true);
    SecurityCamera camera("1080p", true, true, 3, "Front Door Camera", true);
    SmartPlug plug(120.5, 60, 4, "Smart Plug", true);

    light.turnOn();
    thermostat.turnOn();
    camera.turnOn();
    plug.turnOn();
    
    cout << "Device Information:" << endl;
    light.getinfo();
    thermostat.getinfo();
    camera.getinfo();
    plug.getinfo();
    plug.turnof();
    return 0;
}
