#include<iostream>
using namespace std;

class Car{
    private:
    string *brand;
    string *model;
    float *rentalPrice;
    bool availability;
    public:
    Car(){
        *brand = "Unknown";
        *model = "Generic";
        *rentalPrice = 0.0;
        availability = true;
    }
    Car(string b,string m,float a,bool t){
        brand = new string;
        *brand = b;
        model = new string;
        *model = m;
        rentalPrice = new float;
        *rentalPrice = a;

        availability = t;
    }
    Car(Car &obj){
        brand = new string;
        *brand =*(obj.brand);
        model = new string;
        *model =*(obj.model);
        rentalPrice = new float;
        *rentalPrice = *(obj.rentalPrice);
       
        availability = (obj.availability);
    }
    void updatadetail(){
        cout << " Enter the brand of car";
        cin >> *(brand);
        cout << " Enter the model of car";
        cin >> *(model);
        cout << " Enter the rental price of car";
        cin >> *(rentalPrice);
        string check;
        cout << " Enter true for car availabe of false for not (true/false): ";
        cin >> check;
        availability = "check";
    }
    void checkCar(){
        if(availability == true){
            cout <<"  Car is availible"<< endl;
        }
        else{
           cout << " Not availible for rent" << endl;
        }
    }
    void requestForrent(){
        if(availability == true){
            int i;
            cout << " Enter the days you want ";
            cin >> i;
            if(i >=5 && i<10) *rentalPrice -= (*rentalPrice * 0.05);
            if(i>=10 ) *rentalPrice -= (*rentalPrice * 0.10);
            cout <<"  Car is availible and rent price is : " << rentalPrice << endl;
            availability = false;
        }
        else{
           cout << " Not availibe for rent" << endl;
        }
    }
    void display(){
        cout <<" Brand :" << *(brand) << endl;
        cout <<" Model :" << *(model) << endl;
        cout <<" Rent Price :" << *(rentalPrice) << endl;
        cout <<" Availability :";
        if(availability == 1) cout << "true" << endl;
        else cout << "false" << endl;
    }
    
    ~Car(){
        delete brand;
        delete model;
        delete rentalPrice;
        cout <<" Car Object is removed from momeory" << endl;
    }
};

int main(){
    Car c1("car","2017",10.2,true);
    Car c2(c1);

    cout << " The original is : " << endl;
    c1.display();

    cout << " The copy one : " << endl;
    c2.display();

    c1.updatadetail();

    cout << " After the updating oraginal one " << endl;

    cout << " The original is : " << endl;
    c1.display();

    cout << " The copy one : " << endl;
    c2.display();
   
    return 0;
}
