#include <iostream>
#include <string>
using namespace std;
void fun(){
    static int x = 0;// init statement - 1 run and then every time increment by one
    cout << "x : " << x << endl;
    x++;
}
int main(){
    fun();
    fun();
    fun();
    return 0 ;
}