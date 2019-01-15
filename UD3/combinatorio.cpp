#include <iostream>
using namespace std;


/*

@brief Frase necesaria en la funcion FiltroAntiJaime.

*/

void texto (){
    
    cout << "Has introducido una variable incorrecta!. Prueba otra vez: ";
    
}


/*

@brief Frase necesaria en la funcion FiltroAntiJaime.

*/

void texto2 (){
    
    cout << "El numero seleccionado es: ";
    
}


/*

@brief Filtro para evitar letras o numeros decimales en la variable @n.
@param @n siendo un double para determinar si es correcto.
@pre @n > 0 siendo este un numero entero.
@return retorna un valor correcto de Int para seguir con las operaciones.
@post @n será un numero mayor que 0 y entero.

*/

double filtroAntiJaime(double n) {
    
    bool entero = false;
    int numeroEntero = 0;
    
    do
    {
        numeroEntero = n;
        
        if((cin.fail()) || (numeroEntero != n)) {
            
            cin.clear();
            cin.ignore(256, '\n');
            texto();
            cin >> n;
            entero = false;
            
        } else {
        
            texto2();
            cout << n << endl;
            entero = true;
            
        }
        
        
    }
    while(entero == false);
    
    return  n;
}


/*

@brief Calcula el factorial de acuerdo al numero la variable @n.
@param @n siendo un entero para determinar el factorial.
@pre @n > 0 siendo este un numero entero.
@return retorna el factorial de @n.
@post @acu será un numero entero positivo.

*/

int factorial (int n) {
    
    int acu = 1;
    
    for(int i = 1; i <= n; i++)
    {
        acu = acu * i;
    }
    
    return acu;
}


/*

@brief Calcula el combinatorio de acuerdo a las variables @numero1 y @numero2.
@param @numero1 y @numero2 siendo enteros positivos para determinar el combinatorio.
@pre @numero1 y @numero2 > 0 siendo estos un numero entero.
@return retorna el resultado del combinatorio @resultado.

*/

double combinatorio (int numero1, int numero2) {
    
    double resultado = 0.0;
    
    resultado = (factorial(numero1) / (factorial(numero2) * factorial(numero1 - numero2)));
    
    return resultado;
    
}

int main() {
    
    double numeroPrimero = 0.0, numeroSegundo = 0.0;
    int numeroPrimeroFinal = 0, numeroSegundoFinal = 0;
    double valorFinal = 0.0;
    
    cout << "\nPrograma que muestra el combinatorio de 2 numeros introducidos." << endl;
    
    cout << "\nIntroduce el primer numero: ";
    cin >> numeroPrimero;
    
    numeroPrimeroFinal = filtroAntiJaime(numeroPrimero);
    
    cout << "\nIntroduce el segundo numero numero: ";
    cin >> numeroSegundo;
    
    numeroSegundoFinal = filtroAntiJaime(numeroSegundo);
    
    valorFinal = combinatorio(numeroPrimeroFinal,numeroSegundoFinal);
    
    cout << "El resultado del combinatorio de los numeros introducidos es: " << valorFinal << endl;
    
    
}
