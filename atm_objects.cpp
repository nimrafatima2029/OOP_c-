#include<iostream>
#include<string>
using namespace std;
class Costumer{
    public:
    int AccountNum;
    Costumer(int AccountNum){
        this->AccountNum = AccountNum ;
    }
    void authenticate(int InputPin){
        int CorrectPin = 1234;
        if (InputPin == CorrectPin){
            cout << "authentication sucessful" << endl;  
        }else{
            cout << "authentication failed" << endl;
        }
    }
};
class Account{
    public:
    double balance;
    Account(double balance){
        this->balance = balance;
    }
    void WithDraw(double amount){
        if(amount == balance){
            amount -= balance;
            cout << "withdrawn amount:" << amount << endl;
            cout << "remaining amount:" << balance << endl;
        }else{
            cout << "insufficient balance!" << endl;
        }
    }
};
class Card{
    public:
    int CardNumber;
    Card(int CardNumber){
        this->CardNumber = CardNumber;
    }
    void ValidatePin(int InputPin){
        int CorrectPin = 1234;
        if (InputPin=CorrectPin){
            cout << "valid pin " << endl;
        }else{
            cout << "invalid pin!" << endl;
        }
    }
};
class ATM{
    public:
    string location;
    ATM(string location){
        this -> location = location;
    }
    void display(){
        cout << "ATM location" << endl;
    }
};
int main(){
    Costumer c1(1234567);
    Account a1(45000);
    Card C1(012);
    ATM m1("Chakdara");
    c1.authenticate(1234);
    a1.WithDraw(500);
    C1.ValidatePin(1234);
    m1.display();


}