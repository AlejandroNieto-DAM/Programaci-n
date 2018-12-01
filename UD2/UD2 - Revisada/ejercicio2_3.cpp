/* Programa que muestra unos mensajes por pantalla segun los numeros introducidos.
 */

#include <iostream>
using namespace std;

int main()
{
    
    //Declaración de variables.
    int dato;
    
    //Pedimos un valor para nuestra variable
    cout << "Introduzca un valor entero distinto de cero. " << endl;
    cin >> dato;
    
    //Segun el valor de la variable muestra una cosa u otra.
    if( dato!=0 )
      {
        cout << "Ha escrito " << dato << " que es distinto de cero. " << endl;
        cout << "Es un alumno muy obediente. " << endl;
  	} else {
        cout << "Ups! que desobediente..." << endl;
	}
    
    
    /* Solo ejercutaria la primera sentencia y no mostraria el segundo cout. */
}
