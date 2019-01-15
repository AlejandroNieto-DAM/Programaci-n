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

@brief Filtro para evitar letras en la variable @n.
@param @n para determinar si es correcto.
@pre @n > 0 siendo este un numero entero.
@return retorna un valor correcto de Int para seguir con las operaciones.
@post @n será un numero mayor que 0 y entero.

*/
double filtroAntiJaime(double n) {
    
    bool entero = false;
    
    do
    {
        
        while(cin.fail()) {
            
            cin.clear();
            cin.ignore(256, '\n');
            texto();
            cin >> n;
            entero = false;
            
        }
        
        texto2();
        cout << n << endl;
        entero = true;
        
        
    }
    while(entero == false);
    
    return  n;
}


/*

@brief Calcula la media de 3 numeros introducidos @n1, @n2 y @n3.
@param @n1, @n2 y @n3 para calcular su media.
@pre @n1, @n2 y @n3 siendo numeros enteros.
@return retorna @m que es el resultado de la media.
@post @m será la media de los 3 numeros introducidos.

*/
double media (double n1, double n2, double n3) {
    
    double m = 0.0;
    
    m = ((n1 + n2 + n3) / 3 );
    
    return m;
    
}



int main() {
    
    double v1 = 0.0, v2 = 0.0, v3 = 0.0;
    double numeroV1 = 0.0, numeroV2 = 0.0, numeroV3 = 0.0;
    double mediaNumeros = 0.0;
    bool entero = false;
    
    cout << "\nPrograma que muestra la media de 3 numeros introducidos. " << endl;
    cout << endl;
    
    cout << "Introduce el valor 1: ";
    cin >> v1;
    numeroV1 = filtroAntiJaime(v1);
    
    cout << "Introduce el valor 2: ";
    cin >> v2;
    numeroV2 = filtroAntiJaime(v2);
    
    cout << "Introduce el valor 3: ";
    cin >> v3;
    numeroV3 = filtroAntiJaime(v3);
    
    mediaNumeros = media(numeroV1, numeroV2, numeroV3);
    
    cout << "La media de los numeros introducidos es: " << mediaNumeros << endl;
    
    
    
    
}
