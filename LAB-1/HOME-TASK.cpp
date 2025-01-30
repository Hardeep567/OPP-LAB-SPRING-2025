/*
NAME == HARDEEP NARESH
ROLL NUMBER == 24K-0653
SECTION == BCS-1C
*/
#include<iostream>
using namespace std;

void entryInformation(int arr[4][7]){
    cout << "Enter the Data :  "<< endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout <<"Enter the AQL of City "<<i+1 <<" in Day "<< j+1 <<":  ";
            cin >> arr[i][j];
        }
    }
    
}

void calculateAverageandHighest(int arr[4][7]){
    int sum[4]={0}; 
    for (int  i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            sum[i]+=arr[i][j];

        }
        sum[i]= sum[i]/7;
        cout << "The Average Of City "<< i+1 <<":  "<< sum[i] << endl; 
    }
    int high;
    high = sum[0];
    for (int  i = 0; i < 4; i++)
    {
        if(high < sum[i]){
            high = sum[i];
        }
    }
    
}

void criticalPollution(int arr[4][7]){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if(arr[i][j] > 150){
                cout << "This day "<< j <<" is CIRTICAL POLLUTION DAY of city"<< i;
                cout << endl;
            }
        }
    }
} 

void dataVisualization(int arr[4][7]){
    for (int i = 0; i < 4; i++)
    {
        int sum =0;
        for (int j = 0; j < 7; j++)
        {
            sum+=arr[i][j];
        }
        cout << "DATA VISUALIZATION OF CITY :" << i+1 ;
        for (int k = 0; k < sum/50 ; k++)
        {
            cout << " *";
        }
        cout << endl;

    }
}

void entryDatamonth(int arr2[4][28]){
    for(int i=0;i<4;i++){
    	for(int j=7;j<28;j++){
    		cout <<"ENTER THE DATA OF WEEK " << j/7+1 << " Of CITY "<< i+1 << " OF DAY "<< j+1 << "   :";
    		cin >>arr2[i][j];
		}
	}
} 

void highestDrop(int arr2[4][28]){
	int diff[4];
	for(int i=0;i<4;i++){
		int average1=0 ,average2=0 ;
		for(int j=0;j<7;i++){
			average1+=arr2[i][j];

		}
		average1/=7;
		for(int j=27 ; j > 27-7 ; j--){
			average2+=arr2[i][j];
			
		}
		average2/=7;
		diff[i]=average1 - average2;
		
	}
	int max = diff[0];
	int index = 0;
	for(int i=0;i<4;i++){
		if(max < diff[i]){
			max = diff[i];
			index =i;
		}
	}
	cout << "THE LARGEST IMPROVED IN AIR QUALITY OF CITY IS : " << index;
}

void monthlyAverage(int arr2[4][28]){
	int average;
	for(int i=0;i<4;i++){
		for(int j=0;j<28;j++){
			average +=arr2[i][j];
		}
		average/=28;
		cout<<" AVERAGE OF CITY " << i <<"IS " << average << endl;
	}
}

void weeklyaverage(int arr2[4][28]){
	int average;
	for(int i=0;i<4;i++){
		cout << "THE WEEKLY AVERAGE OF CITY " << i << endl;
		for(int j=0;j<28;j++){
			if(j%7==0){
				cout << "THE WEEK " << j/7 << "AVERAGE IS :" << average/7<< endl;
			}
		}
	}
}

void criticalPollution(int arr2[4][28]){
	int max;
	int index;
	for(int i=0;i<4;i++){
		max = arr2[i][0];
		for(int j=0;j<28;j++){
			if(max < arr2[i][j]){
				max = arr2[i][j];
				index = j;
			}
		}
		cout << "THE DAY " << index << "IS MOST POLLUTION DAY OF CITY "<<i << endl;
	}
}

void highestAndlowest(int arr2[4][28]){
	int lower = arr2[0][0];
	int highest = arr2[0][0];
	for(int i=0;i<4;i++){
		for(int j=0;j<28;j++){
			if(highest < arr2[i][i]){
				highest = arr2[i][j];
			}
			if(lower > arr2[i][j]){
				lower = arr2[i][j];
			}
		}
	}
	cout << "THE HIGHEST AQL IS " << highest << "LOWER AQL IS" << lower << endl; 
}

int main(){
    int arr[4][7];
    // TASK 1
    entryInformation(arr);

    calculateAverageandHighest(arr);
	// TASK 2
    criticalPollution(arr);
	// TASK 3
    dataVisualization(arr);

    // TASK 4
    int arr2[4][28];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            arr2[i][j] = arr[i][j];
        }
        
    }
    entryDatamonth(arr2);
    
    monthlyAverage(arr2);
    
    highestDrop(arr2);
    // TASK 5
    weeklyaverage(arr2);
	
	criticalPollution(arr2);

	highestAndlowest(arr2);
	
	return 0;
}
