#include<iostream>
using namespace std;

class Ticket{
    protected:
    int tricketId;
    string passengerName;
    float price;
    string date;
    string destination;
    bool book;
    public:
    Ticket(int t){
        tricketId =t;
    }
    void reserve(string p,float pri,string d,string des){
        passengerName =p;
        price =pri;
        date =d;
        destination =des;
        book = true;
        cout << " Seat Booked" << endl;
    }
    void cancel(){
        book = false;
        passengerName ="no";
        price =0.0;
        date ="0";
        destination = "0";
        cout << " Seat Cancel" << endl;
    }
    virtual void displayInfo(){
        cout << " Tricket ID : "<< tricketId << endl;
        cout << " Passager Name : "<< passengerName << endl;
        cout << " Price : "<<price << endl;
        cout << " Date : "<< date << endl;
        cout << " Destination : "<< destination << endl;
    }
};

class FlightTicket : public Ticket{
    protected:
    string airlineName;
    string flightNumber;
    int seatNumber;
    public:
    FlightTicket(int t,string a,string f,int s) : Ticket(t){
        airlineName =a;
        flightNumber =f;
        seatNumber =s;
    }
    void displayinfo(){
        Ticket::displayInfo();
        cout << " Airline Name : "<< airlineName << endl;
        cout <<" Flight Number : " << flightNumber << endl;
        cout <<" Seat Number : "<< seatNumber << endl;
    }
};

class TrainTicket : public Ticket{
    protected:
    int trainNumber;
    string coachType;
    string departureTime;
    public:
    TrainTicket(int i,int t,string c,string d) : Ticket(i){
        trainNumber = t;
        coachType = c;
        departureTime = d;
    }
    void reserve(string p,float pri,string d,string des){
        passengerName =p;
        price =pri;
        date =d;
        destination =des;
        book = true;
        cout << " Seat Booked " << endl;
        cout << " Seat Allocated automate " << endl;
    }
    void displayInfo(){
        Ticket::displayInfo();
        cout << " Train Number : "<< trainNumber << endl;
        cout << " Coach Type : " << coachType << endl;
        cout << " Departure Time : " << departureTime << endl;
    }
};

class ConcertTicket : public Ticket{
    protected:
    string artistName;
    string venue;
    string seatType;
    public:
    ConcertTicket(int i,string a,string v,string s) : Ticket(i){
        artistName =a;
        venue =v;
        seatType =s;
    }
    void displayInfo(){
        Ticket::displayInfo();
        cout << " Artist Name : "<< artistName << endl;
        cout << " Venue : "<< venue << endl;
        cout << " Seat Type : "<< seatType << endl;
    }

};

int main(){
    FlightTicket ft(101, "Emirates", "21", 12);
    ft.reserve("FASIH", 500.0, "2025.04.10", "New York");
    ft.displayInfo();


    TrainTicket tt(102, 7845, "Sleeper", "8");
    tt.reserve("Ansh", 150.0, "202.-04.11", "New York");
    tt.displayInfo();

    ConcertTicket ct(103, "Car", "Hyderbad", "VIP");
    ct.reserve("Hardeep", 300.0, "2025.06.15", "New York");
    ct.displayInfo();
    return 0;
}
