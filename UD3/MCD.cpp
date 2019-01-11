#include <iostream>
using namespace std;

void leerNumero (int &numeroIntroducido1, int &numeroIntroducido2){

    cout << "Programa que muestra el MCD de un intervalo." << endl;

    cout << "Introduce los numeros del intervalo separados por un espacio: ";

    cin >> numeroIntroducido1 >> numeroIntroducido2; 

}

int calcularMCD (int &numero1, int &numero2){

    int resto = 0;

    resto  = numero1 % numero2;
        
        while(resto != 0)
        {
            numero1 = numero2;
            numero2 = resto;
            resto = numero1 % numero2;
        }

    return numero2;

}

void imprimirResultado (int &resultado){

    cout << "El m.c.d. es: " << resultado << endl;

}

int main()
{
    int a = 0, b = 0, resultado = 0;
    
    
    leerNumero(a,b);

    resultado = calcularMCD(a,b);

    imprimirResultado(resultado);
    
    
}