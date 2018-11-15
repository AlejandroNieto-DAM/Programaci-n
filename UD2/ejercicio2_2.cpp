/* Programa que muestra si un numero es par o impar.
 */

#include <iostream>
using namespace std;

int main ()
{
    
    //Declaración de variables.
    int a = 0;
    
    //Mostramos al usuario para que sirve el programa.
    cout << "Programa que muestra si el numero introducido es par o impar. " << endl;
    
    //Pedimos valor para nuestras variables.
    cout << "Introduce un numero: ";
    cin >> a;
    
    //Condiciones.
    if (a%2 == 0)
    {
        cout << "El numero es par." << endl;
    }
    
    if (a%2 != 0)
    {
        cout << "El numero es impar." << endl;
    }
}
