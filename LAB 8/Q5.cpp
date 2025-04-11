#include<iostream>
using namespace std;

class MatrixHelper;

class Matrix2x2{
    private:
    int a,b,c,d;
    public:
    Matrix2x2(int x,int y,int z,int k){
        a=x;
        b=y;
        c=z;
        d=k;
    }
    Matrix2x2 operator+(Matrix2x2 m){
        a+=m.a;
        b+=m.b;
        c+=m.c;
        d+=m.d;
        return *this;
    }
    Matrix2x2 operator-(Matrix2x2 m){
        a-=m.a;
        b-=m.b;
        c-=m.c;
        d-=m.d;
        return *this;
    }
    Matrix2x2 operator*(Matrix2x2 m){
        a = a*m.a + b*m.c;
        b = a*m.b + b*m.d;
        c = c*m.a + d*m.c;
        d = c*m.b + d*m.d;
        return *this;
    }
    friend int determinant(Matrix2x2 m);

    friend class MatrixHelper;
    friend ostream& operator<<(ostream& os, Matrix2x2 m) {
        os << "a= " << m.a << " b=" << m.b << "\n "<< "c= " << m.c << " d= " << m.d ;
        return os;
    }
};

int determinant(Matrix2x2 m){
    return m.a * m.d - m.b * m.c;
}

class MatrixHelper {
    public:
        void updateElement(Matrix2x2 m, int row, int col, int value) {
            if (row == 0 && col == 0) m.a = value;
            else if (row == 0 && col == 1) m.b = value;
            else if (row == 1 && col == 0) m.c = value;
            else if (row == 1 && col == 1) m.d = value;
            else cout << "Invalid number of row or column" << endl;
        }
    };

int main(){
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1: " << m1 << endl;
    cout << "Matrix 2: " << m2 << endl;

    Matrix2x2 sum = m1 + m2;
    cout << "Sum: " << sum << endl;

    Matrix2x2 diff = m1 - m2;
    cout << "Difference: " << diff << endl;

    Matrix2x2 product = m1 * m2;
    cout << "Product: " << product << endl;

    cout << "Determinant of Matrix 1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 0, 9);
    cout << "Matrix 1: " << m1 << endl;;

    return 0;
}
