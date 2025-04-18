#include<iostream>
using namespace std;

class MenuItem{
    protected:
    string dishName;
    double price;
    public:
    MenuItem(string n ,double p) : dishName(n) , price(p){}
    virtual void showDetail()=0;
    virtual void prepare() = 0;
};

class Appetizer : public MenuItem{
    public:
    Appetizer (string n,double p) : MenuItem(n,p){}
    void showDetail(){
        cout <<" Dish name : " << dishName << endl;
        cout << " Price : " << price << endl;
    }
    void prepare(){
        cout << " It is preparing " << endl;
    }
};

class mainCourse : public MenuItem{
    public:
    mainCourse(string n,double p) : MenuItem(n,p){}
    void showDetail(){
        cout <<" Dish name : " << dishName << endl;
        cout << " Price : " << price << endl;
    }
    void prepare(){
        cout << " It is preparing " << endl;
    }
}; 

int main(){
    Appetizer a1("Burger" , 450.0) ;
    a1.showDetail();
    a1.prepare();

    mainCourse m1("Pizza" ,1450.0);
    m1.showDetail();
    m1.showDetail();
}
