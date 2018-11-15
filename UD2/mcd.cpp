#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0, resto = 0;
    
    cin >> a >> b; //Obviamos presentación.
    resto  = a%b;
    
    while(resto != 0)
    {
        a = b;
        b = resto;
        resto = a % b;
    }
    
    cout << "El m.c.d. es: " << b << endl;
}
