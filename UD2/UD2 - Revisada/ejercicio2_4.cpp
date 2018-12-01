/* Programa que muestra el área y perímetro a partir de un radio introducido.
 */

#include <iostream>
using namespace std;

int main ()
{
    
    //Declaración de variables.
    double radio = 0.0;
    double area = 0.0, per = 0.0;
    
    //Mostramos al usuario para que sirve el programa.
    cout << "Programa que muestra el radio, el área y el perímetro del circulo." << endl;
    
    //Pedimos un valor para nuestra variable.
    cout << "Introduce el radio: ";
    cin >> radio;
    
    if(radio > 0.0)
    {
        
        //Operaciones.
        area = (3.14 * (radio * radio));
        per = (2.0 * 3.14 * radio);
        
        //Solución.
        cout << "A partir del radio introducido " << radio << " tiene un área " << area << " y un perimetro " << per << endl;
    }
    
    if(radio <= 0.0)
    {
        cout << "El radio es negativo." << endl;
    }
    
}
