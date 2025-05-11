#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what(){
        return "Matrices must have same dimensions" ;
    }
};

template <typename T>
class Matrix {
private:
    T** data;
    int rows, cols;

    void allocate() {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols]{};
    }

    void deallocate() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        allocate();
    }

    ~Matrix() {
        deallocate();
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocate();
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            deallocate();
            rows = other.rows;
            cols = other.cols;
            allocate();
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    data[i][j] = other.data[i][j];
        }
        return *this;
    }

    void set(int r, int c, T value) {
        data[r][c] = value;
    }

    T get(int r, int c) const {
        return data[r][c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException();
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
                cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        A.set(0, 0, 1); A.set(0, 1, 2);
        A.set(1, 0, 3); A.set(1, 1, 4);

        B.set(0, 0, 5); B.set(0, 1, 6); B.set(0, 2, 7);
        B.set(1, 0, 8); B.set(1, 1, 9); B.set(1, 2, 10);
        B.set(2, 0, 11); B.set(2, 1, 12); B.set(2, 2, 13);

        Matrix<int> C = A + B;
        C.print();
    }
    catch (DimensionMismatchException& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
