#include <iostream>
#include <string>
using namespace std;

class Book{
    public:
    string title;
    string author;
    float price;
    Book(string tit ,string aut , float pri ){
        title = tit;
        author = aut;
        price = pri;

    }
    void display(){
        cout << "Title =  " << title << endl;
        cout << "Author =  "<< author << endl;
        cout << "Price = " << price << endl; 
    }
};
int main(){
    Book b1("AI guide","Nimra" ,500);
    Book b2("Biology guide", "Fatima ", 800);
    b1.display();
    b2.display();
    return 0;
}

