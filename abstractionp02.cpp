#include <iostream>
#include <string>
using namespace std;
class Shape{
    virtual void draw(){

    }
};
class circle{
    public:
    void draw(){
        cout << "drawing a circle" << endl;
    }
};
int main(){
    circle c1;
    c1.draw();
    return 0;
}