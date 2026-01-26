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
    t1.name = "Nimra Fatima";
    cout << t1.name<<endl;

    return 0;

}/*In C++, class members are private by default,
 so they cannot be accessed directly outside the class unless declared public.*/