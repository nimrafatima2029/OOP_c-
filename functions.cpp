#include<iostream>
using namespace std;


// function definition
void printHello(){
    cout << " hello\n" ;
}
int main()
{
// function call / function invoke
printHello() ;
printHello() ;
printHello() ;
printHello() ;
printHello() ;
    return 0 ;
}



/*#include <iostream>
using namespace std;

int printHello() {
    cout << " hello \n " ; // \n hello and value = 3 in seperate lines
    return 3 ;
}
int main ()
{
   int value = printHello();
   cout << " value = " << value << endl;
   return 0 ;
}*/


/*#include <iostream>
using namespace std ;
int printHello() {
    cout << " hello \n " ;
    return 3 ;
}
int main ()
{
    
    cout << printHello() << endl;
    return 0 ;  
}*/


/*#include <iostream>
using namespace std ;
 int sum(int a , int b){
    int sum = a + b ;
    
    return sum ;
}
int main ()
{
    cout << sum(10,5) << endl;
    return 0 ;
}*/

// sum of two numbers
/*#include <iostream>
using namespace std ;
double sum(double a , double b) {
    double sum = a + b ;
    return sum ;
}
int main ()
{
    cout << " sum = " << sum(10.99 , 11.44) << endl;
    return 0 ;
}*/



/*#include <iostream>
using namespace std;
int minOfTwo (int a , int b){ 
    if(a < b){
         return a ;
    }else {
        return b ;
    }
}
int main (){
    cout << " minimum = " << minOfTwo(5 , 3) << endl;
    return 0;
}


   /*Parameters are the variables written in the function definition.
Think of them as empty boxes inside a function waiting to receive values.
Arguments are the actual values you pass to the function when calling it.
Think of arguments as the real items that fill the empty boxes.
Parameters belong to the function definition.

Arguments belong to the function call. arguments are described as literals
as they are fixed values and do not change*/



/*#include <iostream>
using namespace std ;
int sumN(int n){
int sum = 0 ; we always initialize sum with 0 b/c whatever we add with zero , we get the 
answer of 2nd value
for(int i = 1 ; i <= n ; i++){
   sum += i  ;
}
return sum ;
    
}

int main(){
    cout << " sumN = " << sumN(7) << endl;
    cout << " sumN = " << sumN(10) << endl;
    return 0 ;
}*/


/*#include <iostream>
using namespace std ;
int sumN(int a , int b){
    int sum = 0 ;

    for(int i = 1; i >= 1 ; i++){
        i += 1 ;
        return sum ;                 ??????????????????????????????
    }  
                                     
}
int main (){
    cout << " sumN = " << sumN(5 , 3 ) << endl;
    return 0 ;
}*/




/*#include <iostream>
using namespace std ;
int factorialN(int n){
    int fact = 1 ;
    for(int i = 1 ; i <= n ; i++){
        fact *= i;
        
    }
    return fact ;
}
    int main (){
        cout << " fact = " << factorialN(10) << endl;
        return 0; 
    }*/


   /* #include <iostream>
    using namespace std;
    void fun(){
    int x = 25 ;
    cout << "x = " << x << endl;
    }
    int main (){
        fun(); // function invoke
        return 0 ;
    }*/


    /*#include <iostream>
    using namespace std;
    int sum(int a , int b){
       a = a + 10 ;
       b = b + 10 ;
        return a + b ;
    }
    int main(){
        int a = 5 , b = 4 ;
        cout << "sum = " << sum(a , b) << endl;
        return 0 ;
    }*/


    /*#include <iostream>
    using namespace std;
    void changeX(int x){
        x = 2*x ;
        cout << " x = " << x << endl ;
    } 
    int main (){
        int x = 5 ;
        changeX(x);
        cout << " x = " << x << endl ;
        return 0 ;
    }*/


/* #include <iostream>
using namespace std ;
int sumOfDigits(int num){
    int digSum = 0 ;

    while(num > 0){
        int lastDig = num % 10 ;
        num /= 10 ;
        digSum += lastDig ;
    }
    return digSum ;
}
int main(){
    cout << " sum = " << sumOfDigits(2356) << endl;
    return 0 ;
}*/

/*#include<iostream>
using namespace std ;
int factorial(int n){
    int fact = 1 ;
    for (int i = 1 ; i <= n ; i++){
        fact *= i ;
    }
    return fact ;
}
int nCr(int n , int r){
    int fact_n = factorial(n) ;
    int fact_r = factorial(r) ;
    int fact_nmr = factorial(n - r) ;
    return fact_n/(fact_r * fact_nmr) ;
}
int main(){
    int n= 6 , r = 3 ;
    cout << nCr(n , r) << endl;
    return 0 ;
}*/


/*#include <iostream>
using namespace std ;
int decToBinary(int decNum){
    int ans = 0 , pow = 1 ;

    while()
}*/