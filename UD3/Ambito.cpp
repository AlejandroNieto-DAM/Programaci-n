#include <iostream>
using namespace std;

/*

@brief Es una funcion que dados dos numeros @x y @y sirve como ejemplo para ver el ambito de las variables.
@param @x e @y numeros para ver el ambito de las variables.
@pre x e y sean double. 
@return devuelve @j para ver el cambio ocurrido dentro de la función.
@post el resultado puede ser cualquier tipo de numero que se ajuste a un double.

*/

double f1(double x, double y){
  
    double i, j;
    
    for(double i = x; i < y; i++){
        double z;
        z = (i - x);
        j = z / (y - x);
        cout << j << endl;
    }
    
    return j;
}

int main(){
    
    double a = 0, b = 0;
    
    cout << "\nIntroduce un numero: ";
    cin >> a;
    cout << "\nIntroduce otro numero: ";
    cin >> b;
    
    cout << f1(a,b) << endl;
    
    cout << "\nPrograma finalizado." << endl;
    
}
