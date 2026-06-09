#include <iostream>
#include <string>
using namespace std;

class Patient;

class Doctor{
public:
    string name;

    Doctor(string n){
        name = n;
    }

    void checkpatient(Patient* p); // declaration only
};

class Patient{
public:
    string name;

    Patient(string n){
        name = n;
    }

    void visitdoctor(Doctor* d){
        cout << name
             << " is visiting Dr. "
            //  << d->name << endl;
             << (*d).name << endl;
    }
};

void Doctor::checkpatient(Patient* p){
    cout << "Dr. " << name
         << " is treating "
         << p->name << endl;
}

int main(){
    Doctor d1("Ahmad");
    Patient p1("Ali");

    p1.visitdoctor(&d1);
    d1.checkpatient(&p1);

    return 0;
}