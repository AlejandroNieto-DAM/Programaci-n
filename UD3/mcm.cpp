#include <iostream>
using namespace std;

/*

@brief Lee los numeros de entrada necesarios para el intervalo.
@param int numeroIntroducido1 e int numeroIntroducido2 que son valores respectivos para cada valor del intervalo.
@pre debe estar activa la entrada por teclado.
@return cambia el valor de numeroIntroducido1 y numeroIntroducido2.
@post numeroIntroducido1 < numeroIntroducido2.

*/
void leerNumero (int &numeroIntroducido1, int &numeroIntroducido2){

    cout << "Programa que muestra el MCM de un intervalo." << endl;

    cout << "Introduce los numeros separados por un espacio: ";

    cin >> numeroIntroducido1;
    cin >> numeroIntroducido2; 

}


/*

@brief Calcula el mcd de acuerdo al intervalo introducido.
@param int numero1 e int numero2.
@pre numero1 < numero2 siendo los dos distintos.
@return retorna numero2 que sera el resultado del mcd.
@post numero2 sera el resultado del mcd.

*/
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


/*

@brief Calcula el mcm de acuerdo al mcd calculado.
@param int a, int b, int resultado e int resultado2.
@pre a < b siendo los dos distintos.
@return cambia el valor de resultado2 que sera el resultado del mcm.
@post resultado2 sera el mcm.

*/
int calcularMCM (int a, int b, int resultado, int &resultado2){

    resultado2 = ((a * b) / resultado);

    return resultado2;

}

/*

@brief Imprime el resultado del mcm calculado anteriormente.
@param @resultado2 siendo este el resultado del m.c.m.
@pre debe estar activa la salida por pantalla.
@return no devuelve nada.
@post no tiene.

*/
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