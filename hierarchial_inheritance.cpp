#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    string name;
    int age;
};
class Student : public Person
{
public:
    int rollNo;
};
class Teacher : public Person
{
public:
    string subject;
};
int main()
{
    Student t2;
    t2.name = "Nimra Fatima";
    t2.age = 20;
    t2.rollNo = 1;
    cout << "name : " << t2.name << endl;
    cout << "age : " << t2.age << endl;
    cout << "rollNo : " << t2.rollNo << endl;
    return 0;
}