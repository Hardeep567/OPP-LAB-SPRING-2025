#include<iostream>
using namespace std;
#include <cmath>

class Complex{
    private:
    int real;
    int imgainary;
    public:
    Complex(int r,int i){
        real =r;
        imgainary =i;
    }
    Complex operator+(Complex &c){
        imgainary +=c.imgainary;
        real+=c.real;
        return *this;
    }
    Complex operator-(Complex c){
        imgainary -=c.imgainary;
        real-=c.real;
        return *this;
    }
    Complex operator*(Complex c){
        imgainary = ((this->imgainary*c.imgainary) - (this->real*c.real));
        real = ((this->imgainary*c.real) + (this->real*c.imgainary));
        return *this;
    }
    Complex operator/(Complex c){
        imgainary = ((this->imgainary*c.imgainary) + (this->real*c.real))/ (c.imgainary*c.imgainary + c.real*c.real);
        real = ((this->real*c.imgainary) - (this->imgainary*c.real))/(c.imgainary*c.imgainary + c.real*c.real);
        return *this;
    }
    friend ostream& operator<<(ostream &s,Complex s1){
        s << " Real : " << s1.real  << " Imgainary : " << s1.imgainary ;
        return s;
    }
    friend double Magnitude(Complex C1);

};
double Magnitude(Complex c1){
    double i = pow(c1.real,2) + pow(c1.imgainary,2);
    return sqrt(i);
}

int main(){
    Complex c1(3, 4);
    Complex c2(1, -2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "Sum = " << sum << endl;
    cout << "Difference = " << diff << endl;
    cout << "Product = " << prod << endl;
    cout << "Quotient = " << quot << endl;
    cout << "Magnitude of c1 = " << Magnitude(c1) << endl;

    return 0;
}
