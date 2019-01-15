#include <iostream>
using namespace std;

/*

@brief Lee un numero de entrada.
@param @numeroIntroducido para calcular su cubo.
@pre @numeroIntroducido deberá ser un numero entero positivo.

*/
void leerNumero (int &numeroIntroducido){

    cout << "Introduce un numero entero para ver su cubo: ";

    cin >> numeroIntroducido;
    
}

/*

@brief Calcula el cubo del numero introducido anteriormente @n.
@param @n para calcular su cubo.
@pre @n > 0 y entero.ç
@return @suma que es el resultado del cubo de @n

*/
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


/*

@brief Imprime el resultado del cubo del número.
@param @resultado que es el cubo del numero introducido.

*/
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