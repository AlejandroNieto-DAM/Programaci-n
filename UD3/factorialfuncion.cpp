#include <iostream>
using namespace std;

/*

@brief calcula el factorial del numero @n.
@param @n para calcular su factorial.
@pre @n debe ser un numero entero positivo.
@return @acumulador que es el resultado del factorial de acuerdo al numero @n.

*/

int factorialValor (int n) {
    
    int acumulador = 1;

    for(int i = 1; i <= n; i++)
    {
        acumulador *= i;
    }
    
    return acumulador;
}

int main() {
    
    int valorEntero = 0, numeroFinal = 0;
    double valor = 0.0;
    bool entero = false;
    
    
    cout << "Introduce un numero para calcular su factorial: ";
    cin >> valor;
    
    do
    {
        cin >> valor;
        
        valorEntero = valor;
        
        if((cin.fail() || (valorEntero != valor))) {
            
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Has introducido una variable incorrecta!. Prueba otra vez (Con un numero entero que este entre 1-100): ";
            entero = false;
            
        } else {
            
            cout << "Tu numero escogido es: " << valor << endl;
            entero = true;
            
        }
        
    }
    while(entero == false);
        
    
    numeroFinal = factorialValor(valorEntero);
    
    cout << "El factorial de " << valorEntero << " es: " << numeroFinal << endl;
    
}
