
#include <iostream>
using namespace std;

int main ()
{
    double a = 0.0, b = 0.0;
    
    cout << "Programa que muestra de dos valores reales introducidos cual es mayor. " << endl;
    
    cout << "Introduce un numero: ";
    cin >> a;
    cout << "Introduce otro numero: ";
    cin >> b;
    
    if(a < b)
    {
        cout << "El numero mayor es: " << b << endl;
    }
    
    if(a > b)
    {
        cout << "El numero mayor es: " << a << endl;
    }
    
    if(a == b)
    {
        cout << "Los numeros son iguales." << endl;
    }

}
