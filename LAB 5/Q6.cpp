#include<iostream>
using namespace std;

class level{
    private:
    string name;
    string detail;
    public:
    level(){

    }
    level(string n,string de){
        name = n;
        detail = de;
    }
    void display(){
        cout << " Name is " << name << endl;
        cout << " Detail of level " << detail << endl;
    }
};

class game{
    private:
    string name;
    level Levels[10];
    public:
    int countLevel = 0;
    game(string n){
        name = n;
    }
    void addlevel(level l){
        Levels[countLevel++] = l;
    }
    void displayGane(){
        cout << " Name of game " << name;
        for(int i=0;i<countLevel;i++){
            Levels[i].display();
        }
    }
};


int main(){
    level l1("LEVEL 1","It is essay");
    game g1("GAME 1");
    g1.addlevel(l1);
    g1.displayGane();
    return 0;
}
