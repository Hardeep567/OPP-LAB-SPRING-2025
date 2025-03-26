#include <iostream>
using namespace std;

class Patient; // Forward declaration

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string c, string ad) : name(n), age(a), contactNumber(c), address(ad) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Address: " << address << endl;
    }

    virtual void updateData(string n, int a, string c, string ad) {
        name = n;
        age = a;
        contactNumber = c;
        address = ad;
    }

};

class Doctor : public Person {
protected:
    string specialization;
    float consultationFee;
    Patient** patientList;

public:
    int patientCount;
    Doctor(string n, int a, string c, string ad, string s, float fee) : Person(n, a, c, ad), specialization(s), consultationFee(fee), patientCount(0) {
        patientList = nullptr;
    }

    void displayInfo();

    void addPatient(Patient* p);

};

class Patient : public Person {
protected:
    int patientID;
    string medicalHistory;
    Doctor* doctorAssigned;

public:
    Patient(string n, int a, string c, string ad, int i, string med, Doctor* doc) : Person(n, a, c, ad), patientID(i), medicalHistory(med), doctorAssigned(doc) {
            doctorAssigned->addPatient(this);
        }

    void displayInfo(){
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
    }
};

void Doctor::addPatient(Patient* p) {
    patientCount++;
    Patient** temp = new Patient*[patientCount];
    for (int j = 0; j < patientCount - 1; j++) {
        temp[j] = patientList[j];
    }
    temp[patientCount - 1] = p;
    patientList = temp;
}

void Doctor::displayInfo(){
    Person::displayInfo();
    cout << "Specialization: " << specialization << endl;
    cout << "Consultation Fee: " << consultationFee << endl;
    cout << "Patients Assigned: " << patientCount << endl;
    for (int j = 0; j < patientCount; j++) {
        patientList[j]->displayInfo();
    }
}

class Nurse : public Person {
protected:
    string assignedWard;
    string shiftTiming;

public:
    Nurse(string n, int a, string c, string ad, string ass, string shift) : Person(n, a, c, ad), assignedWard(ass), shiftTiming(shift) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timing: " << shiftTiming << endl;
    }
};

class Administrator : public Person {
protected:
    string department;
    float salary;

public:
    Administrator(string n, int a, string c, string ad, string dep, float s) : Person(n, a, c, ad), department(dep), salary(s) {}

    void updateData(string n, int a, string c, string ad, string dep, float s) {
        Person::updateData(n, a, c, ad);
        department = dep;
        salary = s;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};
int main(){
    Doctor doc("Hardeep", 45, "9876", "Lahore", "Cardiology", 200.0);
    
    Patient pat("Ansh", 30, "123456", "Karachi", 101, "High BP", &doc);

    Nurse nurse("Abdulah", 28, "55512", "Karachi", "ICU", "Night Shift");
    
    Administrator admin("Manav", 50, "44498", "Hyderbad", "HR", 70000.0);
    
    cout << "--- Doctor Info ---" << endl;
    doc.displayInfo();
    
    cout << "--- Patient Info ---" << endl;
    pat.displayInfo();
    
    cout << "--- Nurse Info ---" << endl;
    nurse.displayInfo();
    
    cout << "--- Administrator Info ---" << endl;
    admin.displayInfo();
    return 0;
}
