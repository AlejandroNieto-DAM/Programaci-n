/* ALgoritmo para calcular una calificación mediante unos porcentajes. */

#include <iostream>
using namespace std;

int main ()
{
    
    //Declaración de variables.
    double nota1,nota2,nota3;
    double notafinal;
    
    //Pedimos por pantalla las notas.
    cout << "Este es un programa para calcular el resultado de tu calificacion. La primera nota que deber introducir es la de teoría, la segunda la de prácticas y por último la de problemas. " << endl;
    cin >> nota1 >> nota2 >> nota3;
    
    //Operacion para calcular la calificación.
    notafinal = (nota1*0.7)+(nota2*0.2)+(nota3*0.1);
    
    //Mostramos por pantalla el resultado obtenido.
    cout << "Tu nota final es: " << notafinal << endl;
    
    
}
