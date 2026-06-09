#include <iostream>
#include <string>
using namespace std;
class ABC{
    public:
    ABC(){
        cout << "it's me constructor\n";
    }
    ~ABC(){
        cout << "it's me destructor\n";
    }
};
int main(){
    if (true){
        ABC obj;
    }
    cout << "end of the main function\n";
}