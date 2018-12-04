#include <iostream>
using namespace std;

void texto (){
    
    cout << "Has introducido una variable incorrecta!. Prueba otra vez: ";
    
}

void texto2 (){
    
    cout << "El numero seleccionado es: ";
    
}

double media (double n1, double n2, double n3) {
    
    double m = 0.0;
    
    m = ((n1 + n2 + n3) / 3 );
    
    return m;
    
}

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
