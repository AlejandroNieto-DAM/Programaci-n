/* Algoritmo que muestra las expresiones booleanas de una variable dadas las condiciones del ejercicio 2.10 de la pag 58 del libro de programación. */

#include <iostream>
using namespace std;

int main ()
{
    
    //Declaración de variables 1 por cada condición en orden alfabético.
    int a = 0, e = 0;
    double b = 0.0, c = 0.0, d = 0.0, f = 0.0, g = 0.0;
    
    
    //Resultados de las condiciones.
    
    (1 <= a) && (a <= 6); //Primera condición.
    
    (b < -5.0) || (b > 5.0); //Segunda condición.
    // !((b > -5.0) && (b < 5.0)); //Segunda condición.
    
    (c < -5.0) || (c > 3.0); //Tercera condición.
    //!((c >= -5) && (c =< 3)); //Tercera condición.
    
    ((d == 1.0) || (d == 2.0) || (d == 3.0)) || ((d >= 10.0) && (d < 20.0)); //Cuarta condición.
    
    ((e%2 == 0) || (e%2 == 1)) && ((a >= 0) && (a <= 10)); //Quinta condición.
    
    ((f > 0.0) && (f < 10.0)) || ((f > 20.0) && (f < 30.0)); //Sexta condición.
    
    (((g >= 0.0) && (g < 10.0)) || ((g > 20.0) && (g <= 30.0))); //Septima condición.
    
    
    
    
}
