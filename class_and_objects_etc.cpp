#include <iostream>
#include <string>
using namespace std;

class teacher{
private:
double salary;//data hiding or encapsulation    
public:
//constructor
/*teacher(){
    cout << "Hi, i am constructor\n";
}*/
//non-parameterized constructor->type of constructor
teacher(){
    cout << "Computer Science"<< endl;
}
//Parameteried constructor
teacher(string n, string d, string s, double sal){
    name = n ;
    dept = d ;
    salary = sal;
    subject = s ;

}
//atributes or properties
string name;
string dept;
string subject;
//methods or member functions
void changeDept(string newDept){
    dept = newDept;
}
//setter
void setSalary(double s){
    salary = s;
}
//getter
double getSalary(){
    return salary;
}
};

int main (){
    teacher t1;//constructor call -> automatically by compiler ->used for object initialization
    //teacher t2; //for every object constructor is called either by compiler or us, as we have created 
    t1.name = "Nimra";
    t1.subject = "c++";
    t1.setSalary(25000);
    cout << t1.name << endl;
    cout << t1.subject << endl;
    cout << t1.getSalary() << endl;
    cout << t1.dept << endl;

    return 0;
}