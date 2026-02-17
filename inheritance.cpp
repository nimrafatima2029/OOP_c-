#include <iostream>
#include <string>
using namespace std;

class person{
    public:
    string name;
    int age;
    person(){
        cout<< "parent constructor..." << endl;
    }
};

class student : public person{
    public:
    int rollNo ;
    student (){
        cout << "child constructor..." << endl;
    }
    void getInfo(){
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollNo : " << rollNo << endl;
    }
};

int main (){
    student s1;
    s1.name = "Nimra Fatima";
    s1.age = 20;
    s1.rollNo = 123;
    s1.getInfo();

}