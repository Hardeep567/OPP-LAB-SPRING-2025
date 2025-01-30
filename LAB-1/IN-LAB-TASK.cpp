/*
NAME == HARDEEP NARESH
ROLL NUMBER == 24K-0653
SECTION == BCS-1C
*/
#include<iostream>
#include<string>
using namespace std;

void registerParticipants(string names[],int num){
    cin.ignore();
    for(int i=0;i<num;i++){
        cout << "Enter the name of Participant  "<< i+1 ;
        getline(cin,names[i]);
    }
} 

int checkEvents(string event[], string name ,int i){
    for(int j=0;j<i;j++){
        if (event[j] == name)
        {
            cout << "Found \n";
            return 0;
        }
    }
    return 1;
}

void attendenceChecker(string event1[],int choice1,int choice2,string event2[]){
    string name;
    int j;
    do {
        cout << "Enter the name for ATTENDENCE :  ";
    cin >> name;
    int i =checkEvents(event1,name,choice1);
    if (i==1)
    {
        i =checkEvents(event2,name,choice2);
    }
    if(i==1){
        cout<< "NOT FOUND\n";
    }
    cout << "Enter 0 to stop :  ";
    cin >> j;
    }while (j !=0);
}

void donation(string event1[],int i,int j,string event2[]){
    int s = i+j;
    s = s*10;

    cout << "\nTotal Donation: " << s<<"\n";
}

void displayNames(string event[],int i){
    for(int j=i-1;j>=0;j--){
        cout << " " << event[j] << " ";
    }
    cout << endl;
}

void barChart(string event1[],int i,int j,string event2[]){
    cout << "\nEvent Popularity Bar Chart:\n";
    cout << "Event 1: ";
    for (int z = 0; z < i; z++) {
        cout << "*";
    }
    cout << "\nEvent 2: ";
    for (int c = 0 ; c < j; c++) {
        cout << "*";
    }
    cout << endl;
}

int main(){
	// TASK 1
    int choice1,choice2 ;
    do{
        cout << "Enter the Number of Participants for Event 1:  ";
        cin >> choice1;
            if(choice1 > 5 ||choice1 < 0 ){
                cout <<"\nParticipants Should be less then 5\n";
            }
    }while(choice1 > 5 ||choice1 < 0 ); 
    string event1[choice1];

    registerParticipants(event1,choice1);
    do{
        cout << "Enter the Number of Participants for Event 2:  ";
        cin >> choice2;
            if(choice2 > 5 ||choice2 < 0 ){
                cout <<"\nParticipants Should be less then 5\n";
            }
    }while(choice2 > 5 ||choice2 < 0 ); 
    string event2[choice2];

    registerParticipants(event2,choice2);

	// TASK 2
    attendenceChecker(event1,choice1,choice2,event2);
    
    // TASK 3
    donation(event1,choice1,choice2,event2);
    
	// TASK 4
    displayNames(event1,choice1);
    displayNames(event2,choice2);
	
	// TASK 5
    barChart(event1,choice1,choice2,event2);
}
