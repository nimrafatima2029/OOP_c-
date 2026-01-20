/*#include <iostream>
using namespace std;
int main () 
{
    int a ;
    cout << "enter a : ";
    cin >> a;
    if (a>=0) {
    cout<<a<<" is a positive number" ;
    }else{
        cout<<a<<" is a negative number";
    }
    return 0 ;
}
*/

/*# include <iostream>
using namespace std ;
int main ()
{
    int age ;
    cout << "enter age : ";
    cin >>age ;
    if (age>=18)
    {
        cout << age << " = you can vote \n";
    }else{
        cout << age << " = you can not vote\n";
    }
   return 0;


}*/


#include <iostream>
using namespace std;
int main ()
{
    int n;
    cout << "enter n : " ;
    cin >> n;
    if (n%2==0)
    { /*also these braces are optional if we have one codition*/
        cout << n << " = even number\n";
     }else{    /*this else is optional we remove it no logical or syntax error if we have 
        one condition*/
        cout << n << " = odd number\n";
    }
}
