#include <iostream>
using namespace std;


/*

@brief Frase necesaria en la funcion FiltroAntiJaime.
@pre debe estar activa la salida por pantalla.
@return no devuelve nada.

*/
void texto (){
    
    cout << "Has introducido una variable incorrecta!. Prueba otra vez: ";
    
}


/*

@brief Frase necesaria en la funcion FiltroAntiJaime.
@pre debe estar activa la salida por pantalla.
@return no devuelve nada.

*/
void texto2 (){
    
    cout << "El numero seleccionado es: ";
    
}

/*

@brief Filtro para evitar letras o numeros decimales en la variable @n.
@param double n siendo un double para determinar si es correcto.
@pre n > 0 siendo este un numero entero.
@return retorna un valor correcto de Int para seguir con las operaciones.
@post n será un numero mayor que 0 y entero.

*/
double filtroAntiJaime(double n) {
    
    bool entero = false;
    int numeroEntero = 0;

    
    do
    {
        
        numeroEntero = n;
        
        if((cin.fail()) || (numeroEntero != n) || (n == 0)) {
            
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

@brief Frase necesaria en la funcion primo.
@pre debe estar activa la salida por pantalla.
@return no devuelve nada.

*/
void noPrimo (){
    
    cout << "No es un numero primo." << endl;
}


/*

@brief Frase necesaria en la funcion primo.
@pre debe estar activa la salida por pantalla.
@return no devuelve nada.

*/
void esPrimo (){
    
    cout << "Es un numero primo." << endl;
}


/*

@brief muestra si el numero introducido es primo o no.
@param int n para ver si es primo o no.
@pre n > 0 siendo este un numero entero.
@return no devuelve nada.

*/
void primo (int n) {
    
    
    if(n%2 == 0) {
        
        noPrimo();  
        
    } else {
        
        esPrimo();
        
    }
    
    
}



int main() {
    
    double numero = 0.0;
    int numeroFinal = 0;
    
    
    cout << "\nPrograma que muestra si un numero es primo o no." << endl;
    cout << "\nIntroduce un numero: ";
    cin >> numero;
    
    numeroFinal = filtroAntiJaime(numero);
    
    primo(numeroFinal);
    
}
