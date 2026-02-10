#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    public:
    virtual void start() = 0;
};
class Bike : public Vehicle {
    public:
    void start(){
        cout << "bike is starting" << endl;
    }
};
int main(){
    Bike b1;
    b1.start();
    return 0;
}