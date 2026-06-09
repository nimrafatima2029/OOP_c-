#include <iostream>
using namespace std;
class vehicle{
    public:
    virtual void startengine(){
        cout << "i am vehicle" << endl;
    }
};
class car :public vehicle{
    public:
    void startengine() override {
        cout << "i am car" << endl;
    }
};
class bike : public vehicle{
    void startengine() override {
        cout << "i am bike" << endl;
    }
};
int main(){
    vehicle* ptr;
    car c;
    ptr = &c;
    ptr-> startengine();

    bike b;
    ptr = &b;
    ptr->startengine();
    return 0;
}