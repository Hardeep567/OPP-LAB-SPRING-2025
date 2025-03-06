#include<iostream>
using namespace std;

class  Employee{
private:
string name;
string position;
public:
Employee(string name, string position) : name(name),position(position){}
void display(){
    cout << " Name : " << name << endl;
    cout << " Position : " << position << endl;
}
};

class project{
private:
string name;
string deadline;
Employee *e[5];
int count = 0;
public:
project(string n,string d): name(n),deadline(d){}
void add_employees(Employee *emp){
    e[count] = emp;
    count ++ ;
}
void display(){
    cout <<  " Name :: " << name << endl;
    cout << " Deadline :: " << deadline << endl;
    for(int i=0;i<count;i++){
        e[i]->display();
    }
}
};
int main(){
    Employee e1("hardeep","head") , e2("Ansh","Worker");
    project p1("Cp","20-Feb");
    p1.add_employees(&e1);
    p1.add_employees(&e2);
    p1.display();
    return 0;
}
