#include<iostream>
using namespace std;

class Student{
    private:
    string id;
    string *name;
    double *marks;
    public:
    Student(string i,string a,double m){
        id = i;
        name = new string;
        *name=a;
        marks = new double ;
        *marks = m;
    }
    Student (Student *a){
        id = (a->id);
        name = new string(*a->name);
        marks = new double(*a->marks);
    }
    void display(){
        cout << " Id : " << id << endl;
        cout << " Name : " << *name << endl;
        cout << " Marks : " << *marks<< endl; 
    }
};

int main(){
    Student a1("101"," hardeep",23.5 );
    Student a2(&a1);
    a1.display();
    a2.display();

}
