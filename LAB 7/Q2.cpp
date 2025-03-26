#include<iostream>
using namespace std;


class Product{
    protected:
    int productID;
    string productName;
    float price;
    float stockQuantity;
    public:
    Product(int i,string p,float pr,float s){
        productID =i;
        productName =p;
        price =pr;
        stockQuantity =s;
    }
    void applyDiscount(int discount){
        cout << " You get "<< discount <<" % Discount "<< endl;
        float i = discount/100;
        price = price -(price*i);
    }
    void calculateTotalPrice(int quatity){
        cout << " Total Price is : " << (price*quatity) << endl;
    }
    virtual void displayinfo(){
        cout << " Product ID : "<< productID << endl;
        cout << " Product Name : "<< productName << endl;
        cout << " Price : "<< price << endl;
    }
    Product operator+(const Product& other){
        return Product(102, "Bulk Purchase", price + other.price, stockQuantity + other.stockQuantity);
    }
    friend ostream& operator<<(ostream& os, const Product& product){
        os << "Product Name: " << product.productName << "\n Price: " << product.price;
        return os;
    }
};

class Electronic : public Product{
    protected:
    int warrenty;
    string brand;
    public:
    Electronic(int i,string p,float pr,float s,int w,string b): Product(i,p,pr,s){
        warrenty =w;
        brand =b;
    }
    void displayinfo(){
        Product::displayinfo();
        cout << " Warrenty : " << warrenty << endl;
        cout << " Brand : "<< brand << endl;
    }
};

class Clothing : public Product{
    protected:
    string size;
    string color;
    string fabriMaterial;
    public:
    Clothing(int i,string p,float pr,float s,string size,string c,string f) : Product(i,p,pr,s){
        this->size = size;
        color =c;
        fabriMaterial =f;
    }
    void applyDiscount(int q){
        if(q>10){
            Product::applyDiscount(18);
            Product::calculateTotalPrice(10);
        }
        else{
            Product::applyDiscount(10);
            Product::calculateTotalPrice(10);
        }
    }
    void display(){
        Product::displayinfo();
        cout << " Size : " << size << endl;
        cout << " Color : "<< color << endl;
        cout << " Fabri Material : "<< fabriMaterial << endl;
    }

};

class Fooditem : public Product{
    protected:
    string expirationDate;
    float calories;
    public:
    Fooditem(int i,string p,float pr,float s,string e,float ca) : Product(i,p,pr,s){
        expirationDate = e;
        calories = ca;
    }
    void CalculateTotalPrice(int q){
        if(q>10){
            Product::applyDiscount(18);
            Product::calculateTotalPrice(10);
        }
        else{
            Product::applyDiscount(10);
            Product::calculateTotalPrice(10);
        }
    }
    void display(){
        Product::displayinfo();
        cout << " Expiration Date "<< expirationDate << endl;
        cout << " Calories " << calories  << endl;
    }
};

class Book : public Product{
    protected:
    string author;
    string genre;
    public:
    Book(int i,string p,float pr,float s,string a,string ge) : Product(i,p,pr,s){
        author = a;
        genre = ge;
    }
    void displayinfo(){
        Product::displayinfo();
        cout << " Author : "<< author << endl;
        cout << " Genre : "<< genre << endl;
    }
};



int main(){
    Electronic laptop(101, "Laptop", 1200.0, 10, 2, "Dell");
    Clothing shirt(201,"T-Shirt", 20.0, 50, "M", "Blue", "Cotton");
    Fooditem apple(301, "Apple", 2.5, 100, "2025-01-01", 95);
    Book novel(401, "The Great Gatsby", 15.0, 20, "F. Scott Fitzgerald", "Classic");
    
    cout << "Product Information:\n";
    laptop.displayinfo();
    shirt.displayinfo();
    apple.displayinfo();
    novel.displayinfo();
    
    cout << "Applying Discounts:\n";
    shirt.applyDiscount(60);
    shirt.displayinfo();
    
    Product bulkPurchase = laptop + novel;
    cout << "Bulk Purchase:\n" << bulkPurchase << endl;
    return 0;
}
