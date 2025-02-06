#include<iostream>
using namespace std;

string *memoryAllocate(int n){
    string *b1= new string [n];
    return b1;
}

void input(string *b1,int n){
    for(int i=0;i<n;i++){
        cout << "Enter the string : " ;
        cin >> b1[i];
    }
}

void sorting(string *b1,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b1[i][0] > b1[j][0]){
                string b2 = b1[i];
                b1[i] = b1[j];
                b1[j] = b2;
            }
        }
    }
}

void display(string *b1,int n){
    for (int i = 0; i < n; i++)
    {
        cout << "" << b1[i];
    }
    
}

int main(){
    int n;
    cout << "Enter the number of string : " ;
    cin >> n;
    
    string *b1=memoryAllocate(n);
    input(b1,n);
    sorting(b1,n);
    display(b1,n);
    delete[] b1;
    return 0;
}
