#include<iostream>
using namespace std;

int** memoryAllocate(int n,int m){
    int ** ptr = new int *[n];
    for(int i=0;i<n;i++){
        ptr[i] = new int [m];
    }

    return ptr;
}

void input(int ** ptr, int n,int m){
    cout << "Enter element in matrices : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >>ptr[i][j];
        }
    }
}

void addition(int **ptr,int **ptr2,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ptr[i][j]+=ptr2[i][j];
        }
    }
    cout << "Result after addition is : " << endl ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ""<< ptr[i][j];
        }
    }
}

void subtraction(int **ptr,int **ptr2,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ptr[i][j]-=ptr2[i][j];
        }
    }
    cout << "Result after subtraction is : " << endl ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ""<< ptr[i][j];
        }
    }
}

int main (){
    int row ,col ;
    cout << "Enter the number of row";
    cin >> row;
    cout << "Enter the number of column";
    cin >> col;

    int **ptr = memoryAllocate(row,col);
    int **ptr2 = memoryAllocate(row,col);

    input(ptr,row,col);
    input(ptr2,row,col);

    addition(ptr,ptr2,row,col);
    subtraction(ptr,ptr2,row,col);

    for(int i=0;i<row;i++){
        delete[] ptr[i];
        delete[] ptr2[i];
    }
    delete[] ptr;
    delete[] ptr2;


    return 0;
}
