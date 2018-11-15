/* Algoritmo que hace la suma de dos variables. */

#include <iostream>
using namespace std;

int main ()
{
    
    //Declaración de variables.
    double a, b, res;
    
    //Decimos al usuario que hace el programa.
    cout << "Algoritmo que realiza la suma de dos numeros." << endl;
    
    //Pedimos por pantalla un valor para nuestras variables.
    cout << "Introduce un numero: ";
    cin >> a;
    cout << "Introduce otro numero: ";
    cin >> b;
    
    //Operación suma.
    res = a+b;
    
    //Mostramos por pantalla el resultado.
    cout << "El resultado de la suma de los numeros es: " << res << endl;
}
