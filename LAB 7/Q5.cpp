#include<iostream>
using namespace std;

class Character{
    protected:
    int characterId;
    string name;
    string level;
    int healthPoint;
    string weaponType;
    public:
    Character(int c,string n,string le,int hea,string weapon){
        characterId =c;
        name =n;
        level = le;
        healthPoint =hea;
        weaponType = weapon;
    }
    virtual void attack() {
        cout << name << " attacks " << endl;
    }

    virtual void defend() {
        cout << name << " defends " << endl;
    }

    virtual void displayStats() {
        cout << "Character ID: " << characterId << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoint << endl;
        cout << "Weapon Type: " << weaponType << endl;
    }
};

class Warrior : public Character{
    protected:
    int armorStrenght;
    int meleeDamage;
    public:
    Warrior(int c,string n,string le,int hea,string weapon,int ar,int me) : Character(c,n,le,hea,weapon){
        armorStrenght =ar;
        meleeDamage =me;
    }
    void attack(){
        cout << " MELEE COMBAT ATTACK " << endl;
    }
};

class Mage : public Character{
    protected:
    int manaPoints;
    float spellPower;
    public:
    Mage(int c,string n,string le,int hea,string weapon,int man,float sp) : Character(c,n,le,hea,weapon){
        manaPoints=man;
        spellPower =sp;
    }
    void defend(){
        cout << " Magical Barriers " << endl;
    }
};

class Archer : public Character{
    protected:
    int arrowCount;
    int rangedAccuracy;
    public:
    Archer(int c,string n,string le,int hea,string weapon,int arr,int ran): Character (c,n,le,hea,weapon){
        arrowCount = arr;
        rangedAccuracy = ran;
    }
    void attack(){
        cout << " Long Range Combat " << endl;
    }
};

class Rogue : public Character{
    protected:
    float stealLevel;
    string agility;
    public:
    Rogue(int c,string n,string le,int hea,string weapon,float st,string ab): Character(c,n,le,hea,weapon){
        stealLevel = st;
        agility = ab;
    }
    void displayStats(){
        Character::displayStats();
        cout << "Stealth Level: " << stealLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main(){
    Warrior warrior(1, "Thor", "10", 100, "Sword", 50, 20);
    Mage mage(2, "Merlin", "12", 80, "Staff", 100, 30);
    Archer archer(3, "Legolas", "15", 90, "Bow", 10, 85);
    Rogue rogue(4, "Shadow", "8", 70, "Dagger", 90, "95");

    warrior.displayStats();
    warrior.attack();
    cout << endl;

    mage.displayStats();
    mage.defend();
    cout << endl;

    archer.displayStats();
    archer.attack();
    cout << endl;

    rogue.displayStats();
    return 0;
}
