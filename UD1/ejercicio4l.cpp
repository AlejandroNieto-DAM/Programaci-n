/* Algoritmo que muestra una operación aritmetica de dos variables. */

#include <iostream>
using namespace std;

int main() {
    
    //Declaración e inicialización de variables.
    double a, b;
    a=5, b=3;
    
    //Muestra la operación aritmetica.
    cout << 6 * (5-b) + a - b / (5-a) << endl;
    
    return 0;
}
