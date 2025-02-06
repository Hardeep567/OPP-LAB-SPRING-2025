#include<iostream>
using namespace std;
struct employee
{
    string name;
    int hoursworked;
    int hourlyrate;
    int total;
};


struct employee *memoryAllocate(int n){
    struct employee *b1= new struct employee [n];
    return b1;
}

void input(struct employee * b1,int n){
    for(int i=0;i<n; i++){
        cout << " Enter the name of employee :";
        getline(cin, b1[i].name);
        
        cout << "Enter hours of work : " ;
        cin >> b1[i].hoursworked;

        cout << "Enter hourly rate of employee : " ;
        cin >> b1[i].hourlyrate;
        cin.ignore();
    }
}

void display(struct employee * b1,int n){
    for(int i=0;i<n;i++){
        b1[i].total = b1[i].hoursworked * b1[i].hourlyrate;
    }
    for(int i=0;i<n;i++){
        cout << " " << b1[i].name << " SALARY " << b1[i].total;
    }
}

int main(){
    int n;
    cout << "ENTER THE NUMBER OF EMPLOYEES :";
    cin >> n;
    struct employee *b1 = memoryAllocate(n);
    input(b1,n);
    display(b1,n);

    delete[] b1;
    return 0;
}
