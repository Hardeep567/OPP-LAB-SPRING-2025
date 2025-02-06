#include<iostream>
using namespace std;

int** memoryAllocate(int n, int m) {
    int** ptr = new int*[n];
    for (int i = 0; i < n; i++) {
        ptr[i] = new int[m];
    }
    return ptr;
}

void input(int** ptr, int n, int m) {
    cout << "Enter elements in the matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ptr[i][j];
        }
    }
}

void product(int** ptr1, int** ptr2, int row1, int col1, int row2, int col2) {
    int** result = memoryAllocate(row1, col2);

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += ptr1[i][k] * ptr2[k][j];
            }
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row1; i++) {
        delete[] result[i];
    }
    delete[] result;
}

void freeMemory(int** ptr, int row) {
    for (int i = 0; i < row; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

int main() {
    int row1, col1, row2, col2;

    cout << "Enter the number of rows and columns for the 1 matrix: ";
    cin >> row1 ;
    cin >> col1;

    cout << "Enter the number of rows and columns for the 2 matrix: ";
    cin >> row2 ;
    cin >> col2;

    if (col1 != row2) {
        cout << "Matrix multiplication is not possible" << endl;
        return 0;
    }

    int** ptr1 = memoryAllocate(row1, col1);
    int** ptr2 = memoryAllocate(row2, col2);

    input(ptr1, row1, col1);
    input(ptr2, row2, col2);

    product(ptr1, ptr2, row1, col1, row2, col2);

    freeMemory(ptr1, row1);
    freeMemory(ptr2, row2);

    return 0;
}
