#include<iostream>
using namespace std;

class person{
    protected:
    string name;
    int age;
    public:
    person(string a,int b): name(a) ,age(b){}

    void display(){
        cout << " NAME : " << name << endl;
        cout << " AGE : " << age << endl;
    }
};

class teacher : public person{
    protected:
    string subject;
    public:
    teacher(string a,int b,string s) : person(a,b),subject(s){}

    void display(){
        person :: display();
        cout << " SUBJECT : " << subject << endl;
    }
};

class researcher : public person{
    protected:
    string researchArea;
    public:
    researcher(string a,int b,string r) : person(a,b) , researchArea(r){}

    void display(){
        person :: display();
        cout  << " RESEARCH AREA : " << researchArea <<endl;
    } 
};

class professor : public teacher , public researcher{
    protected:
    int publication;
    public:
    professor(string a,int b,string s,string r,int p) : teacher(a,b,s) ,researcher(a,b,r) , publication(p){}

    void display(){
        teacher :: display();
        cout  << " RESEARCH AREA : " <<  researcher::researchArea << endl;
        cout << " PUBLICATION : " << publication << endl;
    }
};

int main(){
    professor p1("Hardeep", 19 , "OPP","HAS A" , 19);
    p1.display();
    return 0;
}
