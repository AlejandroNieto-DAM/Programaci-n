/* Simulación pes
 */

#include <iostream>
using namespace std;

int main()
{
    
    //Declaración de variables.
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int a = 0, b = 0;
    int aux;
    
    //Explicamos al usuario como funciona el programa.
    cout << "Simulacion del pes que hace una porteria a partir de dos puntos dados por el usuario y después introduce otro punto que dice si es gol." << endl;
    
    //Pedimos valores para la porteria.
    do
    {
    cout << "Introduce la x del primer punto: ";
    cin >> x1;
    cout << "Introduce la y del primer punto: ";
    cin >> y1;
    cout << "Introduce la x del segundo punto: ";
    cin >> x2;
    cout << "Introduce la y del segundo punto: ";
    cin >> y2;
    }
    while(((x1 < 0) || (y1 < 0)) || ((x2 < 0) || (y2 < 0)));
    
    //Pedimos valores para el gol.
    cout << "La porteria ya ha sido generada." << endl;
    cout << "Introduce un x para lanzar a gol: ";
    cin >> a;
    cout << "Introduce una y para lanzar a gol: ";
    cin >> b;
    
    
    
    //Condiciones gol, palo, escuadra, fuera y tiros por debajo de la porteria.
    
    if(x1 > x2)
    {
        aux = x1;
        x1 = x2;
        x2 = aux;
    }
    
    else if (y1 > y2)
    {
        aux = y1;
        y1 = y2;
        x2 = aux;
    }
    
    
    
    if (((a < x2) && (a > x1)) && (b < y2))
    {
        cout << "Vaya golazo has marcado crack, menudo fiera." << endl;
    }
        
    else if (((a == x2) && (b == y2)) || ((a == x2) && (b == y1)))
    {
            cout << "Casi! Menudo escuadrazo." << endl;
    }
        
    else if (((b == y1) || (b == y2)) && ((a < x2) && (a > x1)))
    {
        cout << "Casi! Vaya palo! " << endl;
    }
        
    else if ((a == x2) && ((b < y2) && (b > y1)))
    {
        cout << "Vaya larguerazo!" << endl;
    }
        
    else if (a < x1)
    {
        cout << "Vaya pata palo tienes colega! Le has dado al suelo! " << endl;
    }
        
    else
    {
        cout << "El balón ha ido fuera!" << endl;
    }
}
