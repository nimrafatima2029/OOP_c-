#include <iostream>
#include <string>
using namespace std;
class student{
    private:
    int marks ;
    public:
    string name = "Nimra Fatima" ;
    void setMarks(int m){
        marks = m;
    }
    int getMarks(){
        return marks;
    }
};
int main (){
    student m1;
    m1.setMarks(40);
    cout <<m1.getMarks() << endl;
}