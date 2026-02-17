#include <iostream>
#include <string>
using namespace std;
class print{
    public:
    void show(int x){
        cout << "int x : " << x << endl;
    }                                    //function overloading
    void show(char ch){
        cout << "char : " << ch << endl;
    }
};
int main(){
    print p1;
    // p1.show(157); first one function is called overhere
    p1.show('&');// 2nd fuction is called
    return 0;
}