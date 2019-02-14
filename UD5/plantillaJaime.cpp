//
//  ejemplovectoresmodulos.cpp
//
//
//  Created by Jaime Matas Bustos on 11/1/17.
//
//

#include <iostream>
#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
using namespace std;

/**
 * @brief Módulo que agrega un nuevo número entero en el vector de enteros, al final de las componentes utilizadas.
 *EJEMPLO:
 *ENTRADA v = { 4 2 7 ? ? ? ? ... ? } util = 3 DIM_VECTOR = 2000 entero = 3
 *SALIDA  v = { 4 2 7 3 ? ? ? ... ? } util = 4 DIM_VECTOR = 2000 entero = 3

 * @pre El número entero que queremos insertar está filtrado.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por REFERENCIA porque SÍ se va a cambiar el número de componentes utilizadas en el vector.
 * @param DIM_VECTOR Es la constante que me indica la DIMENSIÓN del vector, esto es el número máximo de componentes que podré utilizar. Es fijo y no se puede alterar.
 * @param entero Es el nuevo número entero que quiero insertar en el vector.
 * @return no devuelve nada.
 * @ post solo se puede introducir un numero que se agregará despues de añadir un valor mas al util_vector y se guardará en la posición anterior.
 */
void agregarNuevoEnteroenVectorEnteros(int vector[], int &util_vector, const int DIM_VECTOR, int entero){

    cout << USER << "Vamos a introducir en el vector un nuevo número, si se puede..." << RESTORE << endl;

    if(util_vector < DIM_VECTOR && util_vector >= 0 ){

        vector[util_vector] = entero;
        //cout << DEBUG << "Numero de componentes utilizados antes de agregar el nuevo entero: " << util_vector << RESTORE << endl;
        util_vector++;
        //cout << DEBUG << "Numero de componentes utilizados después de agregar el nuevo entero: " << util_vector << RESTORE << endl;
        cout << USER << "Se introdujo correctamente el nuevo entero... Lo comprobará cuando vuelva a imprimirlo..." << RESTORE << endl;

    }else{

        cout << "No se puede añadir O.o " << endl;//El vector esta completamente lleno y no se puede añadir nada más.

    }
}


/**
 * @brief Módulo que imprimirá por pantalla un vector de enteros.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de sólo lectura del vector, lo paso como referencia constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por COPIA porque NO se va a cambiar el número de componentes utilizadas en el vector.
 * @post Se imprimirá por la pantalla de la consola el contenido del vector.
 */
void imprimeVectorEnteros(const int vector[], int util_vector){
    cout << "Vector Enteros = { ";
    for (int i=0; i < util_vector; i++){
        cout << vector[i] << " ";
    }
    cout << "}" << endl;
}

/**
 * @brief Módulo que dobla el valor de cada componente del vector de enteros.
 *    Ejemplo: ENTRADA: v = { 4 2 7 } SALIDA: v = { 8 4 14 }
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por COPIA porque NO se va a cambiar el número de componentes utilizadas en el vector.
 * @pre util_vector deberá ser >=0 y < DIM_VECTOR
 * @post El vector cambiará sus valores y serán el doble.
 * @author
 * @version
 */
void doblarValoresDelVectorEnteros(int vector[], int util_vector){
    cout << USER << "Doblando el valor del contenido de las componentes del vector, por favor tenga paciencia..." << RESTORE << endl;
    //cout << DEBUG << "debug: El valor de las utiles antes del bucle es: " << util_vector << RESTORE <<  endl;
    for (int i=0; i < util_vector; i++){
        //cout << DEBUG << "debug: Entrada en el bucle para doblar valores del vector..." << RESTORE << endl;
        vector[i]  = 2 * vector[i];
    }
    cout << USER << "Se dobló correctamente el vector... Lo comprobará cuando vuelva a imprimirlo..." << RESTORE << endl;
}

int main(){
    const int DIM_VECTOR = 3;
    int vector[DIM_VECTOR] = {4,2,7}; //se inicializan las tres primeras componentes y el resto a 0
    int util_vector = 3; //inicializo a 3 porque he llenado el vector en la inicialización
    
    cout << USER << "****** EJEMPLO DE VECTORES Y MODULARIZACIÓN ********" << RESTORE << endl;
    imprimeVectorEnteros(vector, util_vector); //{4,2,7}
    doblarValoresDelVectorEnteros(vector, util_vector);
    imprimeVectorEnteros(vector, util_vector); //{8,4,14}
    agregarNuevoEnteroenVectorEnteros(vector,util_vector, DIM_VECTOR, -1);
    imprimeVectorEnteros(vector, util_vector);
    
}