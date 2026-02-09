#include <iostream>
#include <string>
using namespace std;
class Student{
    private:
    int marks = 0;
    string name ;
    public:
    void setMarks(int m){
        if(m >= 0 && m <= 100){
        marks = m;
    }
    }
    int getMarks(){
        return marks;
    }
};
int main (){
    Student m1;
    m1.setMarks(40);
    cout <<m1.getMarks() << endl;
}