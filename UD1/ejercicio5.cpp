/* Algoritmo que muestra por pantalla el resultado de log de una variable entre otra. (valor/base) */

#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    
    //Declaración de variables.
    double valor, base;
    
    //Pide por pantalla un valor para las variables.
    cout << "Indique la base: ";
    cin >> base;
    cout << "Indique valor: ";
    cin >> valor;
    
    //Muestra por pantalla el resultado
    cout << (log(valor))/(log(base)) << endl;
    
    /*Podria ocurrir un error en tiempo de ejecución si no se introducen caracteres por lo demás ya estan corregidos todos los errores que no dejarian compilar el programa */
}
