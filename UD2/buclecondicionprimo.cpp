#include <iostream>
using namespace std;

int main()
{
    int a = 0, i = 1;
    int d = 0, res = 0;
    
    cout << "Programa que muestra si un numero es primo o no. " << endl;
    cout << "Introduce un numero: ";
    cin >> a;
    
    while(i < 10)
    {
        
        res = (a%i);
        
        if(res == 0)
        {
            d++;
        }
        
        i++;
            
    }
    
   
    if ((a < 10) && (d == 2))
    {
        cout << "El numero " << a << " es primo." << endl;
    }
    else if(d == 1)
    {
        cout << "El numero " << a << " es primo." << endl;
    }
    else
    {
        cout << "El numero " << a << " no es primo." << endl;
    }
}
