#include<iostream>
using namespace std;
struct Book
{
    string title;
    string author;
    int year;
};


struct Book *memoryAllocate(int n){
    struct Book *b1= new struct Book [n];
    return b1;
}

void input(struct Book * b1,int n){
    for(int i=0;i<n; i++){
        cout << " Enter the title of book :";
        getline(cin, b1[i].title);
        
        cout << "Enter author for book : " ;
        getline(cin, b1[i].author);

        cout << "Enter publication year for book : " ;
        cin >> b1[i].year;
        cin.ignore();
    }
}

void display(struct Book * b1,int n,int year){
    for(int i=0;i<n;i++){
        if(b1[i].year == year){
            cout << " " << b1[i].author << " " << b1[i].title << " " << b1[i].year << endl;
        }
    }
}

int main(){
    int n;
    cout << "ENTER THE NUMBER OF BOOKS :";
    cin >> n;
    struct Book *b1 = memoryAllocate(n);
    input(b1,n);
    int year;
    cout << "Enter the specfic year" ;
    cin >> year;
    display(b1,n,year);

    delete[] b1;
    return 0;
}
