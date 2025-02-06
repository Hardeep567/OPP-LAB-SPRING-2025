#include<iostream>
using namespace std;

int** memoryAllocate(int n){
    int ** ptr = new int *[n];
    for(int i=0;i<n;i++){
        ptr[i] = new int ;
    }

    return ptr;
}

void input(int **ptr,int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element : " ;
        cin >> *ptr[i];
    }
    
}

void display(int **ptr,int n){
    for(int i=0;i<n;i++){
        cout << "Output : "<< *ptr[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;  
    int **ptr=memoryAllocate(n);

    input(ptr,n);
    display(ptr,n);

    return 0;
}
