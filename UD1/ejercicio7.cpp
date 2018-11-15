/* Algoritmo que muestra suma, resta, producto y división de dos numeros. */

#include <iostream>
using namespace std;

int main ()
{
    
    //Declaración de variables.
    double a, b;
    
    //Pedimos por pantalla valores para las variables.
    cout << "Escriba el primer numero: ";
    cin >> a;
    cout << "Escribe el segundo numero: ";
    cin >> b;
    
    cout << "Ahora vamos a mostrar la suma, resta, producto y division de los números introducidos." << endl;
    
    //Mostramos por pantalla el resultado de cada operación.
    cout << a+b << endl;
    cout << a-b << endl;
    cout << a*b << endl;
    cout << a/b << endl;
    
    /*Si se puede tener un error en tiempo de ejercución si no introducimos números y en su lugar introducimos carácteres */
}
