#include <iostream>
#include <string>
using namespace std;
class student {
    public:
    string name;
    int rollNo;
};
class teacher{
    public:
    string subject;
    double salary;
};
class teachAssist : public student , public teacher {

};
int main(){
    teachAssist t1;
    t1.name = "Nimra Fatima";
    t1.subject = "Artificial Intelligence";
    cout << t1.name << endl;
    cout << t1.subject << endl;
}