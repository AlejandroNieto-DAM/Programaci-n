#include <iostream>
using namespace std;

void leerNumero (int &numeroIntroducido1, int &numeroIntroducido2){

    cout << "Programa que muestra el MCM de un intervalo." << endl;

    cout << "Introduce los numeros separados por un espacio: ";

    cin >> numeroIntroducido1;
    cin >> numeroIntroducido2; 

}

int calcularMCD (int numero1, int numero2){

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

int calcularMCM (int a, int b, int resultado, int &resultado2){

    resultado2 = ((a * b) / resultado);

    return resultado2;

}

void imprimirResultado (int resultado2){

    cout << "El m.c.m. es: " << resultado2 << endl;

}

int main()
{
    int a = 0, b = 0, resultado = 0, resultado2 = 0;
    
    
    leerNumero(a,b);

    resultado = calcularMCD(a,b);

    resultado2 = calcularMCM(a,b,resultado,resultado2);

    imprimirResultado(resultado2);
    
    
}