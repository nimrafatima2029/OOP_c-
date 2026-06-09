#include <iostream>
using namespace std;
class Teacher{
    public:
    string name;
    string dept;
    double salary;
    int id;
    Teacher(string name, string dept, double salary, int id){
        this-> name = name;
        this-> dept = dept;
        this-> salary = salary;
        this-> id = id;
    }
    void displayinfo(){
        cout << "name: "<< name << endl;
        cout << "dept: "<< dept << endl;
        cout << "salary: "<< salary << endl;
        cout << "id: "<< id << endl;
    }
    //copy constructor
    Teacher(const Teacher&t1){
        this-> name = t1.name;
        this-> dept = t1.dept;
        this-> salary = t1.salary;
        this-> id = t1.id;

    }

};
int main(){
    Teacher t1("nimra", "computer science",1200.23, 12345 );
   // t1.displayinfo();
    Teacher t2(t1);//initialized with object -> copy constructor invoke
    t2.displayinfo();
    return 0;
}