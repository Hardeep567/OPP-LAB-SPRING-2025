#include<iostream>
using namespace std;

typedef struct product{
	int productId;
	int quantity;
	float price;
	string name;
	float total;
}product;

product *memoryAllocation(int n){
	product *b1=new product [n];
	return b1;
}

void input(product *b1,int n){
	for(int i=0;i<n;i++){
		cout << "Enter the product id : ";
		cin >> b1[i].productId;

		cout << "Enter the price : ";
		cin >> b1[i].price;

		cout << "Enter the name : ";
		cin.ignore();
		getline(cin,b1[i].name);

		cout << "Enter the quatity : ";
		cin >> b1[i].quantity;
	}
}

void total(product *b1,int n){
	for(int i=0;i<n;i++){
		b1[i].total=b1[i].quantity*b1[i].price;
	}
}

void display(product *b1,int n){
	for(int i=0;i<n;i++){
		cout << " " <<b1[i].name << " " <<b1[i].productId << " " << b1[i].price << " " << b1[i].total << endl;
	}
}

int main(){
	int n;
	cout << "Enter the number of product: ";
	cin >> n;
	product *b1=memoryAllocation(n);

	input(b1,n);;

	total(b1,n);

	display(b1,n);

	delete[] b1;
}
