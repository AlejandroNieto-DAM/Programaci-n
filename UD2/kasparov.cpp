#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int abs1 = 0, abs2 = 0;
    int aux = 0;
    
    cout << "Programa que muestra si es válido un movimiento para la torre, la reina y el caballo teniendo en cuenta en el tablero su posición inicial y adonde lo quieres mover." << endl;
    
    cout << "8" << endl;
    cout << "7" << endl;
    cout << "6" << endl;
    cout << "5" << endl;
    cout << "4" << endl;
    cout << "3" << endl;
    cout << "2" << endl;
    cout << "1" << endl;
    cout << "   A  B  C  D  E  F  G  H" << endl;
    cout << "  (1  2  3  4  5  6  7  8)" << endl;
    cout << endl;
    
    
    cout << "Ahora vamos elegir una pieza. " << endl;
    cout << "Introduce el 1 para elegir la torre." << endl;
    cout << "Introduce el 2 para elegir la reina." << endl;
    cout << "Introduce el 3 para elegir el caballo." << endl;
    cin >> aux;
    
    
    if (aux == 1)
    {
        
        cout << "Dime la letra de la posición inicial de la pieza: ";
        cin >> x1;
        cout << "Dime el numero de la posicion incial de la pieza: ";
        cin >> y1;
        cout << "Dime la letra de la posición a la que quieres mover la pieza: ";
        cin >> x2;
        cout << "Dime el numero de la posición a la que quieres mover la pieza: ";
        cin >> y2;
        
        
        if (((y1 <= 8) && (y1 >= 1) && (x1 >= 1) && (x1 <= 8)) && ((y2 <= 8) && (y2 >= 1) && (x2 >= 1) && (x2 <=8)) && (((x2 == x1) && ((abs2 == (0|1|2|3|4)) || ((y2 == y1) && (abs1 == (0|1|2|3|4)))))))
        {
            cout << "El movimiento es correcto para la torre." << endl;
        }
        
        else if (((x1 < 1) || (x1 > 8)) || ((y1 > 8) || (y1 < 1)))
        {
            cout << "Has introducido el primer número erróneo!" << endl;
        }
        
        else if (((x2 < 1) || (x2 > 8)) || ((y2 > 8) || (y2 < 1)))
        {
            cout << "Has introducido el segundo número erróneo!" << endl;
        }
        
        else
        {
            cout << "Ese movimiento no es correcto para la torre." << endl;
        }
    }
    
    else if (aux == 2)
    {
        
        cout << "Dime la letra de la posición inicial de la pieza: ";
        cin >> x1;
        cout << "Dime el numero de la posicion incial de la pieza: ";
        cin >> y1;
        cout << "Dime la letra de la posición a la que quieres mover la pieza: ";
        cin >> x2;
        cout << "Dime el numero de la posición a la que quieres mover la pieza: ";
        cin >> y2;
        
        abs1 = abs(x2 - x1);
        abs2 = abs(y2 - y1);
        
        if ((((y1 <= 8) && (y1 >= 1) && (x1 >= 1) && (x1 <= 8)) && ((y2 <= 8) && (y2 >= 1) && (x2 >= 1) && (x2 <= 8)) && (((x2 == x1) && (abs2 == (0|1|2|3|4))) || ((y2 == y1) && (abs1 == (0|1|2|3|4))))) || (abs1 == abs2) || (((abs1 == 2) && (abs2 == 1)) || ((abs1 == 1) && (abs2 == 2))))
        {
            cout << "El movimiento es válido para la reina." << endl;
        }
        
        else if (((x1 < 1) || (x1 > 8)) || ((y1 > 8) || (y1 < 1)))
        {
            cout << "Has introducido el primer número erróneo!" << endl;
        }
        
        else if (((x2 < 1) || (x2 > 8)) || ((y2 > 8) || (y2 < 1)))
        {
            cout << "Has introducido el segundo número erróneo!" << endl;
        }
        
        else
        {
            cout << "El movimiento no es valido para la reina." << endl;
        }
    }
    
    else if (aux == 3)
    {
        
        cout << "Dime la letra de la posición inicial de la pieza: ";
        cin >> x1;
        cout << "Dime el numero de la posicion incial de la pieza: ";
        cin >> y1;
        cout << "Dime la letra de la posición a la que quieres mover la pieza: ";
        cin >> x2;
        cout << "Dime el numero de la posición a la que quieres mover la pieza: ";
        cin >> y2;
        
        abs1 = abs(x2 - x1);
        abs2 = abs(y2 - y1);
        
        if (((y1 <= 8) && (y1 >= 1) && (x1 >= 1) && (x1 <= 8)) && ((y2 <= 8) && (y2 >= 1) && (x2 >= 1) && (x2 <= 8)) && (((abs1 == 2) && (abs2 == 1)) || ((abs1 == 1) && (abs2 == 2))))
        {
            cout << "El movimiento es válido para el caballo." << endl;
        }
        
        else if (((x1 < 1) || (x1 > 8)) || ((y1 > 8) || (y1 < 1)))
        {
            cout << "Has introducido el primer número erróneo!" << endl;
        }
        
        else if (((x2 < 1) || (x2 > 8)) || ((y2 > 8) || (y2 < 1)))
        {
            cout << "Has introducido el segundo número erróneo!" << endl;
        }
        
        else
        {
            cout << "El movimiento no es valido para caballo." << endl;
        }
    }
    
    else if (aux != (1|2|3))
    {
        cout << "No has pulsado la letra correcta para elegir una pieza! :( " << endl;
    }
    
    
    
}


