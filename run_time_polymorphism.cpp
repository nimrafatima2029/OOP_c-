#include <iostream>
#include <string>
using namespace std;
class Parent{
    public:
    void getInfo(){
        cout <<"parent class" << endl;
    }
    
};                                          //function overriding
class child{
    public:
    void getInfo(){
        cout << "child class" << endl;
    }
};
int main(){
    child c1;
    c1.getInfo();
    return 0;
}