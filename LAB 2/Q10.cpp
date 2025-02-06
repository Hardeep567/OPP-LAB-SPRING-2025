#include<iostream>
using namespace std;

int ***memoryAllocation(int x,int y,int z){
    int ***ptr= new int **[x];
    for(int i=0;i<x;i++){
        ptr[i] = new int *[y];
        for (int j = 0; j < y; j++)
        {
            ptr[i][j] = new int [z];
        } 
    }
    return ptr;
}

void input(int ***ptr,int x,int y,int z){
    cout << "Enter the element " << endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cin >> ptr[i][j][k];
            }
        }
    }
}

void display(int ***ptr,int x,int y,int z){
    cout << "The 3D array : " << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << ptr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void free(int ***ptr,int x,int y,int z){
    for(int i =0 ;i < x ; i++){
        for(int j=0;j < y; j++){
            delete[] ptr[i][j];
        }
        delete[] ptr[i];
    }
    delete[] ptr;
}

int main(){
    int x, y, z;

    cout << "Enter the values for the 3D array x y z: ";
    cin >> x >> y >> z;

    int ***ptr=memoryAllocation(x,y,z);

    input(ptr,x,y,z);

    display(ptr,x,y,z);

    free(ptr,x,y,z);
    return 0;
}
