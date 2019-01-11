#include <iostream>
using namespace std;

void leerNumero (int &numeroIntroducido){

    cout << "Introduce un numero entero para ver su cubo: ";

    cin >> numeroIntroducido;
    
}

int cubo (int &n){
    
    int suma = 0;
    int numero2;
    int numeroComienzo;
    
    numero2 = n;
    numeroComienzo = (numero2 * (numero2 - 1)) + 1;

    for(int i = 0; i < n; i++)
    {
        suma = suma + numeroComienzo;
        numeroComienzo += 2;
    }
    
    return suma;
    
}

void imprimirResultado (int &resultado){

    cout << "El cubo del numero introducido es: " << resultado << endl;

}


int main()
{
    
    int numeroIntroducido = 0, valor = 0;


    leerNumero(numeroIntroducido);
    
    valor = cubo(numeroIntroducido);
    
    imprimirResultado(valor);
    
    
}