#include <iostream>
using namespace std;
class a{
    public:
    int x;
};
class b : virtual public a{
    
};
class c :virtual public a{

};
class d : public b , public c{
    public:
    void setx(int value){
        x = value;
    }
};
int main(){
    d D1;
    D1.setx(10);
    cout << "value of x: " << D1.x << endl;
    return 0;
}