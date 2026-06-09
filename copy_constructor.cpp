#include <iostream>
using namespace std;
class Student{
    public:
    string name;
    Student(string n){//parameterized constructor
    this -> name = n;
    //this keyword is optional, refers to the current object->object's property
    //in simple, used to differntiate between prameter's name and object's attribute/data
    }
    Student(const Student &s1){//copy constructor
     this -> name = s1.name;
    }
    //used to create a new object as an exact copy of an existing object of the same class.


};
int main(){
    Student s1("Nimra");
    Student s2 = s1;//copy constructors is invoked/call here
    cout <<"name: " << s2.name << endl;
    return 0;
}