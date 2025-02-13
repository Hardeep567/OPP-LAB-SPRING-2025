#include<iostream>
using namespace std;

class fitnessTracker{
    private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    float caloriesBurned;
    public :
    fitnessTracker(string name,int daily){
        userName = name;
        dailyStepGoal = daily;
        caloriesBurned = 0.0;
        stepsTaken = 0;
    }
    void steps(){
        int x;
        cout << " Enter the number of steps taken by you : " << endl;
        cin >> x;
        stepsTaken += x;
    }
    void displayCalories(){
        caloriesBurned = (float)stepsTaken/7;
        cout << " The Number of calories burned is : "<< caloriesBurned << endl;
    }

};


int main(){
    string name;
    int goal;
    cout << " Enter the name of user : ";
    cin.ignore();
    getline(cin,name);
    cout << " Enter the daily goal : ";
    cin >> goal;
    fitnessTracker s1(name,goal);
    int n;
    while (1)
    {
        cout << " Enter \n 1. ADD STEPS \n 2. DISPLAY CALORIES BURNED \n 3.EXIST ";
        cin >> n;
        if( n == 1){
            s1.steps();
        }
        else if (n == 2){
            s1.displayCalories();
        }
        else{
            return 0;
        }
    }
    
}
