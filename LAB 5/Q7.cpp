#include<iostream>
using namespace std;

class product{
    private:
    string id,name;
    double quantity;
    public:
    product(string n,string i,double q){
        id = i;
        name = n;
        quantity = q;
    }
    void display(){
        cout << " Name is " << name<< endl;
        cout << " Id is " << id << endl;
        cout << " Quantity is " << quantity << endl;
    }
    string getName(){
        return name;
    }
};

class warehouse{
    private:
    string name;
    product **Product;
    public:
    int countproduct;
    warehouse(string n){
        name =n;
    }
    void addproduct(product *p){
        countproduct++;
        product **p1= new product*[countproduct];
        for(int i=0;i<countproduct -1;i++){
            p1[i] = Product[i];
        }
        p1[countproduct -1] = new product(*p);
        Product = p1;
    }
    product *s1;
    void sorting(){
        for(int i=0;i<countproduct;i++){
            for(int j=i;j<countproduct;j++){
                if(Product[i]->getName()[0] <Product[j]->getName()[0] ||  Product[i]->getName()[0] ==Product[j]->getName()[0]){
                    if(Product[i]->getName()[0] == Product[j]->getName()[0]){
                        if(Product[i]->getName()[1] <Product[j]->getName()[1]){
                            s1 = Product[i];
                            Product[i] = Product[j];
                            Product[j] = s1;
                        }
                    }
                }
                else {
                            s1 = Product[i];
                            Product[i] = Product[j];
                            Product[j] = s1;
                }
            }
        }
    }
    void display(){
        sorting();
        cout << " Name of warehouse is " << name << endl;
        for(int i=0;i<countproduct;i++){
            Product[i]->display();
        }
    }
};

int main(){
    warehouse w1("Hardeep");
    product p1("burger","1023",34.5);
    product p2("apple","104",31.3);
    product p3("lays","109",41.3);

    w1.addproduct(&p1);
    w1.addproduct(&p2);
    w1.addproduct(&p3);
    w1.display();
    return 0;
}
