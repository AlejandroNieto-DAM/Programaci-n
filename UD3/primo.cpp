#include <iostream>
using namespace std;

void texto (){
    
    cout << "Has introducido una variable incorrecta!. Prueba otra vez: ";
    
}

void texto2 (){
    
    cout << "El numero seleccionado es: ";
    
}


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

void noPrimo (){
    
    cout << "Es un numero par." << endl;
}

void esPrimo (){
    
    cout << "Es un numero primo." << endl;
}

 void primo (int n) {
    
    bool primo = false;
    
    if(n%2 == 0) {
        
        noPrimo();
        primo = false;
        
    } else {
        
        esPrimo();
        primo = true;
        
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
