#include<iostream>
using namespace std;

class Student{
    private:
    string id;
    string *name;
    int nummarks;
    double *marks;
    public:
    int i=0;
    Student(string i,string a,int num){
        id = i;
        name = new string;
        *name=a;
        nummarks = num;
        marks = new double [num];
        
    }
    void addmarks(double sorces){
        if(i > nummarks){
            cout << " Marks is added completely";
            return ;
        }
        marks[i++] = sorces;
    }
    Student (Student *a){
        id = (a->id);
        name = new string(*a->name);
        nummarks = a->nummarks;
        marks = new double [nummarks];
        i = a->i;
        for(int j=0;j<i;j++){
            marks[j] = a->marks[j];
        }
    }
    void display(){
        cout << " Id : " << id << endl;
        cout << " Name : " << *name << endl;
        for(int j=0;j<i;j++){
        cout << " Marks : " << marks[j]<< endl; 
        }
    }
};

int main(){
    Student a1("101"," hardeep",2);
    a1.addmarks(23);
    Student a2(&a1);
    a1.display();
    a2.display();

}
