#include <iostream>
#include <string>
using namespace std;

class teacher{
//properties OR attributes
public:
string name;
string subject;
string dept;
double salary;
//methods OR member function
void changeDept(string newDept){
    dept = newDept;
}
};

int main(){
    teacher t1; //object
    t1.name = "Nimra Fatima";//dot operator used to access the properties for the object
    t1.dept = "computer science";
    t1.changeDept("artificial intelligence") ;

    cout << t1.name<<endl;
    cout << t1.dept<< endl;

    return 0;

}/*In C++, class members are private by default,
 so they cannot be accessed directly outside the class unless declared public.*/