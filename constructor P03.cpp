#include <iostream>
#include <string>
using namespace std;

class Employee{
    public:
    int id;
    string name;
    float salary;
    Employee(){
        id = 0;
        name = "NA";
        salary = 0;
    }
    Employee(int i ,string n ,float s){
        id = i;
        name = n;
        salary = s;   
    }
    void display(){
        cout << "id = "<< id <<endl;
        cout << "Name = "<< name <<endl;
        cout << "salary = "<< salary  <<endl;
    }
};
int main (){
    Employee e1;
    Employee e2(12 ,"Nimra" , 25000);
    e1.display();
    e2.display();
    return 0;
}