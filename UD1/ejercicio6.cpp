/* ALgoritmo que te calcula segun lo pagado y el precio del producto cuanto tendria que devolver. */

#include <iostream>
using namespace std;

int main()
{
    
    //Declaración de variables.
    double precio, pagado;
    double centimos;
    
    //Pide por pantalla el precio y el dinero entregado.
    cout << "Escriba precio y dinero entregado: ";
    cin >> precio >> pagado;
    
    //Operación.
    centimos = 100 * (pagado - precio);
    
    //Muestra por pantalla cuanto te tiene que devolver en céntimos.
    cout << "Hay que devolver: " << centimos << " centimos" << endl;
    
    /* En mi maquina da bien el precio, el problema que se da en el ejemplo es debido a la conversion de euros a centimos, o poniendolo todo en la misma unidad "double".*/
}
