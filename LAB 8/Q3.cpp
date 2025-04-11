#include<iostream>
using namespace std;

class Vector2D{
    private:
    double x,y;
    public:
    Vector2D(double x , double y ) {
        this->x = x;
        this->y = y;
    }
    Vector2D operator+(Vector2D v){
        this->x+=v.x;
        this->y+=v.y;
        return *this;
    }
    Vector2D operator-(Vector2D v){
        this->x-=v.x;
        this->y-=v.y;
        return *this;
    }
    Vector2D operator*(double v){
        this->x*=v;
        this->y*=v;
        return *this;
    }

    friend ostream& operator<<(ostream &s,Vector2D v){
        s << "( " << v.x << ", " << v.y << ")" ;
        return s;
    }

    friend double dotProduct(Vector2D v1,Vector2D v2);
};

double dotProduct(Vector2D v1,Vector2D v2){
    double x = v1.x * v2.x + v1.y * v2.y;
    return x;
}

int main(){
    Vector2D a(3, 4);
    Vector2D b(1, 2);
    Vector2D sum = a+b;
    Vector2D diff = a-b;
    Vector2D scaled = a*2.5;
    double dot = dotProduct(a, b);
    cout << "Vector a: " << a << endl;
    cout << "Vector b: " << b << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Scaled a by 2.5: " << scaled << endl;
    cout << "Dot Product of a and b: " << dot << endl;

    return 0;
}
