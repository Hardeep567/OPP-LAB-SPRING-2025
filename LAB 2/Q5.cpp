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

void traverse(int **ptr,int row , int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            for (int z = i+1; z < row; z++)
            {
                int ptr2 = *(* (ptr+z) + j);
                *(* (ptr+z) + j) = *(* (ptr+j) + z);
                *(* (ptr+j) + z) = ptr2;
            }
            
        }
    }
    return ;
}

void sum(int **ptr,int row,int col){
    int sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sum +=ptr[i][j];
        }
    } 
    cout << " Sum of array is :" << sum << endl;
}

void display(int **ptr,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << " " << ptr[i][j] ;
        }
        cout << endl;
    }
}

int main(){
    int row ,col ;
    cout << "Enter the number of row";
    cin >> row;
    cout << "Enter the number of column";
    cin >> col;

    int **ptr = memoryAllocate(row,col);

    input(ptr,row,col);

    traverse(ptr,row,col);

    sum(ptr,row,col);

    display(ptr,row,col);

    return 0;
}
