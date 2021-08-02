#include <iostream>
using namespace std;

int main() {
    
    double velocidad = 0.0, mayor = 0.0;
    int numToros = 0;
    
    do {
    cout << "Programa que muestra a que velocidad debe ir el corredor para que no lo pille el toro en los San Fermines." << endl;
    
    cout << "Introduce el numero de toros que habrá corriendo por la calle en los San Fermines (Recuerda que no puede ser un numero negativo o igual a 0 y ha de ser entero)." << endl;
    cin >> numToros;
        
    } while(numToros <= 0);
    
    cout << "Ahora vamos a introducir la velocidad de cada uno de los toros." << endl;
    
    for(int i = 0; i < numToros; i++) {
        
        do {
            
            cout << "Introduce la velocidad del toro: ";
            cin >> velocidad;
            
        } while ((velocidad < 1) || (velocidad > 1000000000));
        
        
        if(velocidad > mayor) {
            
            mayor = velocidad;
            
        }
        
    }
    
    cout << "El corredor deberá de ir a una velocidad de " << mayor << " para que no lo pille el toro." << endl;
}
