#include <iostream>
using namespace std;

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
