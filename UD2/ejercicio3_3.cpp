#include <iostream>
using namespace std;

int main()
{
    
    double a = 0.0, i = 0.0, mayor = 0.0;
    
    cout << "Programa que muestra de 100 numeros introducidos cual es el mayor." << endl;
    
    for(i = 1.0; i <= 100; i++)
    {
        cout << "Introduce el numero " << i << " : ";
        cin >> a;
        
        if(a > mayor)
        {
            mayor = a;
        }
    }
    
    cout << "El numero mayor es: " << mayor << endl;
}
