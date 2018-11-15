/* ALgoritmo para calcular tu sueldo neto y ahorros. */

#include <iostream>
using namespace std;

int main()
{
    
    //Declaración de variables.
    double sueldo_bruto=0.0;
    double sueldo_neto=0.0;
    double contingencias=2.5;
    double formacion=1.5;
    double retencion1, retencion2, retencion3;
    double retenciones;
    int IRPF = 17;
    double hipoteca, luz, agua, tlfInt, gasolina, comida, ocio, tabaco, gastosCom;
    double ahorros;
    
    //Pedimos al usuario su sueldo bruto.
    cout << "Introduce tu sueldo bruto: ";
    cin >> sueldo_bruto;
    
    //Operaciones para obntener sueldo neto a partir de unos porcentajes fijados.
    retencion1 = ((IRPF*sueldo_bruto)/100);
    retencion2 = ((contingencias*sueldo_bruto)/100);
    retencion3 = ((sueldo_bruto*formacion)/100);
    
    retenciones = retencion1+retencion2+retencion3;
    
    sueldo_neto = (sueldo_bruto-retenciones);
    
    //Mostramos el resultado de sueldo neto por pantalla.
    cout << "Tu sueldo neto es: " << sueldo_neto << endl;
    
    //Introducimos gastos para restarselo al sueldo neto.
    cout << "Ahora introduce todos los gastos que tienes al mes: " << endl;
    cout << "Hipoteca: ";
    cin >> hipoteca;
    cout << "Luz: ";
    cin >> luz;
    cout << "Agua: ";
    cin >> agua;
    cout << "Telefono e Internet: ";
    cin >> tlfInt;
    cout << "Gasolina: ";
    cin >> gasolina;
    cout << "Comida: ";
    cin >> comida;
    cout << "Ocio: ";
    cin >> ocio;
    cout << "Tabaco: ";
    cin >> tabaco;
    cout << "Gastos comunitarios: ";
    cin >> gastosCom;
    
    //Operación para calcular cuanto dinero le sobra a final de mes.
    ahorros = sueldo_neto - (hipoteca + luz + agua + tlfInt + gasolina + comida + ocio + tabaco + gastosCom);
    
    //Mostramos por pantalla el dinero ahorrado.
    cout << "Al final del mes quitando todos los gastos te quedan: " << ahorros << "€ " << endl;
    
}
