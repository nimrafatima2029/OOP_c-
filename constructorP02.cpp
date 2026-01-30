#include <iostream>
#include <string>
using namespace std;
class student {
    public:
    string name;
    int rollNo;
    float marks;
    student(){
        name = "unknown";
        rollNo = 1;
        marks = 90;
    }
    void display(){
        cout << "Name = " << name << endl;
        cout << "rollNo = " << rollNo << endl;
        cout << "marks = " << marks << endl;
    }
};
int main(){
    student s1;
    s1.display();
    return 0;
}