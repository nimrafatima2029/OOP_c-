#include <iostream>
#include <string>
using namespace std;

class bankAccount{
    private:// access specifier
    int accountNumber;
    double balance;// concept of Encapsulation...
    double lastDeposit;
    double lastWithdraw;
    string accountHolderName;//bcoz if i didn't made it private anyone could have changed it, against encapsulation rules
    public:// access specifier
    void setAccountHolderName(string n){
        accountHolderName = n ;

    }
    string getAccountHolderName(){
        return accountHolderName ;
    }
    //setter
    void setBalance(double b){
        if (b >= 0){
        balance = b;
        }else{
        cout << "invalid balance" << endl;
    }
        
    }
    //getter
    double getBalance(){
        return balance;
    }
    void setDepositBalance(double b){
        if(b>=0){
        lastDeposit = b;
        balance = balance + b;
        }else{
        cout << "invalid balance" << endl;
    }

    }
    double getDepositBalance(){
        return lastDeposit;
    }
    void setWithdrawBalance(double b){
        if(b >= 0){
            lastWithdraw = b;
            balance = balance - b;
        }else{
            cout << "invalid amount" << endl;
        }
        

    }
    double getWithdrawBalance(){
        return lastWithdraw;
    }
    

};

int main(){
    bankAccount b1;
    b1.setAccountHolderName("Nimra Fatima") ;
    b1.setBalance(52000);
    b1.setDepositBalance(30000);
    b1.setWithdrawBalance(2000);
    cout <<"Account Holder Name = "<<b1.getAccountHolderName()<< endl;
    cout <<"Deposited Balance = "<<b1.getDepositBalance()<< endl;
    cout <<"Current Balance = " <<b1.getBalance()<< endl;
    cout << "Withdrawl amount = "<< b1.getWithdrawBalance()<< endl;
    


    return 0;
}