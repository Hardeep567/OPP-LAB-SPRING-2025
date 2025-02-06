#include<iostream>
using namespace std;

struct student
{
    string name;
    int rollNumber;
    int marks[3];
    int average;
};

struct student * memoryAllocation(int n){
    struct student *ptr = new struct student [n];
    return ptr;
}

void input(struct student * b1, int n){
    for(int i=0;i<n;i++){
        cout << "Enter the name : ";
        cin.ignore();   
        getline(cin, b1[i].name);


        cout << "Enter the roll number : " ;
        cin >> b1[i].rollNumber;
        

        cout << "Enter the marks of subject 1 : " ;
        cin >> b1[i].marks[0];
        

        cout << "Enter the marks of subject 2 : " ;
        cin >> b1[i].marks[1];
        

        cout << "Enter the marks of subject 3 : " ;
        cin >> b1[i].marks[2];
        
    }
}

void average(struct student * b1, int n){
    for(int i=0;i<n;i++){
        b1[i].average=0;
        b1[i].average+=(b1[i].marks[0] + b1[i].marks[1] + b1[i].marks[2])/3;
    }
}

void display(struct student * b1, int n){
    for(int i=0;i<n;i++){
        cout << "NAME :  " <<b1[i].name << endl << "ROLL NUMBER : " << b1[i].rollNumber << endl << "AVERAGE : " << b1[i].average; 
    }
}

int main(){
    int n;
    cout << "Enter the number of students : " ;
    cin >> n;
    
    struct student * ptr = memoryAllocation(n);
    input(ptr,n);

    average(ptr,n);

    display(ptr,n);
    
    return 0;
}
