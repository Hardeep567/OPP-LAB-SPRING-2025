#include<iostream>
using namespace std;

class Book{
    public:
    int id;
    string name;
    Book(){

    }
    Book(int i,string n){
        id = i;
        name = n;
    }
    void showDetail(){
        cout << " The Book ID is : " << id << endl;
        cout << " Name of Book : " << name << endl;
    }
};

class Library{
    private:
    Book *booklist;
    Book *borrowedBooks;
    int availableBooks = 0;
    bool signal = false;
    public:
    Library(){
        booklist = nullptr;
        borrowedBooks = nullptr;
    }
    void addbook(Book b){
        availableBooks++;
        Book *newBookList = new Book[availableBooks ];
        for(int i=0;i<availableBooks -1;i++){
            newBookList[i] = booklist[i];
        }
        delete[] booklist;
        newBookList[availableBooks - 1] =b;
        booklist = newBookList;
    }
    void lendBook(int b){
        int j=0;
        Book *newBookList = new Book[availableBooks];
        for(int i=0;i<availableBooks;i++){
            if(booklist[i].id == b){
                j++;
                signal = true;
            }
            newBookList[i] = booklist[j];
            j++;
        }
        delete[] booklist;
        if (signal == true)
        {
            availableBooks--;
        }
        
        booklist = newBookList;
    }
    void showbook(){
        for(int i=0;i<availableBooks;i++){
            booklist[i].showDetail();
        }
    }
    bool returnsignal(){
        return signal;
    }
};



int main(){
    Library s1;
    int i;

    while (1)
    {
        cout << " Enter \n 1. Add Book \n 2. Lend Book \n 3. Watch Book \n 4.Exist";
        cin >> i;
        if(i == 1){
            int id;
            string name;
            cout << " Enter the id : " ;
            cin >> id;
            cin.ignore();
            cout << " Enter the name : ";
            getline(cin,name);


            Book b1(id,name);
            s1.addbook(b1);
        }
        else if(i == 2){
            int id;
            cout << " Enter the ID the of book : ";
            cin >> id;
            s1.lendBook(id);
            if (s1.returnsignal() == false){
                cout << " Book is not found" << endl;
            }
        }
        else if(i == 3){
            s1.showbook();
        }
        else{
            return 0;
        }
    }
    
    return 0;
}
