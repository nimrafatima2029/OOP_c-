#include <iostream>
using namespace std;
class Number{
    public:
    int x;
    Number(int xi){
        this -> x = xi ;
    }
    Number operator+(Number obj){
        return Number(this -> x + obj.x );
    }
};
int main(){
    Number n1(10);
    Number n2(30);
    Number n3 = n1+n2; 
//  cout << n2.x;
}