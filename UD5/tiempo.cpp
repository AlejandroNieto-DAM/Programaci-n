//
//  algoritmos_ordenacion_tiempos.cpp
//
//
//  Created by Jaime Matas Bustos on 24/01/16.
//
//

#define BLACK_COLOR "\033[1;30m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define PURPLE_COLOR "\033[1;35m"
#define CYAN_COLOR "\033[1;36m"
#define WHITE_COLOR "\033[1;39m"

#define RESTORE_DEFAULT_COLOR "\033[0m"

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using namespace std;

/**

* @brief Este procedimiento sirve para copiar un vector inicial con los valores aleatorios en otro que posteriormente vamos a manipular.
* @param v_copia[] que tiene almacenados valores aleatorios en su interios.
* @param util_v_copia que tiene el numero de componentes utilizados en el v_copia.
* @param v[] que será el vector en el que copiaremos el anterior.
* @param util_v que será igual que util_v_copia
* @pre v_copia[] debe de manterner ya valores en su interior.
* @pre util_v_copia > 0 && <= que la dimension anteriormente establecida.
* @return no devuelve nada.
* @post v[] almacenará los valores predeterminados de v_copia[]
* @post util_v será igual que util_v_copia.  

*/
void copiarVector( int v_copia[], int util_v_copia, int v[], int &util_v ){
    for (int i=0; i < util_v_copia; i++){
        v[i] = v_copia[i];
    }
    util_v = util_v_copia;
}

/**

* @brief Esta procedimiento sirve para generar un vector automaticamente con numeros aleatorios.
* @param v[] que almacenará los numeros aleatorios hasta llegar al máximo de su dimensión.
* @param util_v que nos almacenará el numero de componentes utilizados en el vector en el instante.
* @param DIM_V que nos establecerá el maximo de numeros que puede almacenar el vector.
* @pre DIM_V > 0
* @return no devuelce nada.
* @post v[] tendra almacenados numeros aleatorios en toda su dimension.

*/
void generarVector( int v[], int &util_v, int DIM_V){
    for (int i=0; i < DIM_V; i++){
        v[i] = rand();
        util_v++;
    }
}

/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector de color rojo.
* @param v[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre v[] debe de tener valores introducidos.
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimeVectorRojo(const int v[], int util_v){
    cout << RED_COLOR << "V = { ";
    for (int i=0; i < util_v; i++)
        cout << v[i] << " ";
    cout << "}" << endl;
    cout << RESTORE_DEFAULT_COLOR;
}


/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector de color verde.
* @param v[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre v[] debe de tener valores introducidos.
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimeVectorVerde(const int v[], int util_v){
    cout << GREEN_COLOR << "V = { ";
    for (int i=0; i < util_v; i++)
        cout << v[i] << " ";
    cout << "}" << endl;
    cout << RESTORE_DEFAULT_COLOR;
}

/**

*

*/
void algoritmoInsercion(int Vector[],int util){
    int izq=1,i,valor;
    
    for(izq=1;izq<util;izq++){
        
        valor=Vector[izq];
        
        for(i=izq;i>0 && valor<Vector[i-1];i--){
            Vector[i]=Vector[i-1];
        }
        Vector[i]=valor;
    }
}

int Posminimo(const int Vector[],int izq,int dcha){
    
    double minimo=Vector[izq];
    int posicion_minimo=izq;

    for(int i=izq+1;i<=dcha;i++){

        if(Vector[i]<minimo){
            minimo=Vector[i];
            posicion_minimo=i;
        }
        
    }
    
    return posicion_minimo;
}

void algoritmoSeleccion(int Vector[],int util){
    
    int pos_min,intercambiar;
    
    for(int i=0;i<util-1;i++){
        pos_min = Posminimo(Vector,i,util-1);
        
        intercambiar=Vector[i];
        Vector[i]=Vector[pos_min];
        Vector[pos_min]=intercambiar;
    }
    
}

/**

* @brief Ordena los elementos de un vector.
* @param v[] que tiene guardados unos elementos anteriormente guardados.
* @param util_v que nos indica el numero de componentes utilizados en vector.
* @pre util_v debe ser mayor que 0.
* @pre v[] debe tener guardados valores en su interior.
* @return no devuelve nada.
* @post el vector quedará ordenado después de ejecutar el bucle.

*/
void algoritmoOrdenacionBurbuja(int v[], int util_v){
    bool cambio = true; //para detectar una pasada sin cambios
    int aux;
    for (int izda = 0; izda < util_v && cambio; izda++){
        cambio = false;
        for (int i = util_v-1; i > izda; i--){
            if (v[i] < v[i-1]){
                cambio = true;
                //Intercambiamos
                aux = v[i];
                v[i] = v[i-1];
                v[i-1] = aux;
            }
        }
        //cout << "Iteración (" << izda << "): ";
        //imprimeVector(v, util_v);
    }
}

int main(){
    //VARIABLES PARA MEDIR TIEMPOS
    clock_t t_iniSelec, t_finSelec,t_iniInser,t_finInser,t_finBurbu,t_iniBurbu;
    double secsSelec,secsInser,secsBurbu;
    
    //VECTORES
    const int DIM_V = 1000000;
    int v[DIM_V] = {0};
    int util_v = 0;
    
    const int DIM_VCOPIA = 1000000;
    int v_copia[DIM_VCOPIA] = {0};
    int util_v_copia = 0;
    
    //Generamos el Vector Aleatorio
    generarVector( v_copia, util_v_copia, DIM_VCOPIA);
    
    //Algoritmo de Selección
    cout << endl << "********** ALGORITMO DE ORDENACIÓN POR SELECCIÓN *************" << endl;
    copiarVector( v_copia, util_v_copia, v, util_v );
    //cout << "Mi Vector Inicial es: ";
    //imprimeVectorRojo(v, util_v);
    
    t_iniSelec = clock();
    algoritmoSeleccion(v, util_v);
    t_finSelec = clock();
    
    //cout << "Mi Vector Final es: ";
     //imprimeVectorVerde(v, util_v);
    
    //Algoritmo de Inserción
    cout << endl << "********** ALGORITMO DE ORDENACIÓN POR INSERCIÓN *************" << endl;
    copiarVector( v_copia, util_v_copia, v, util_v );
    // cout << "Mi Vector Inicial es: ";
    //imprimeVectorRojo(v, util_v);
    
    t_iniInser = clock();
    algoritmoInsercion(v, util_v);
    t_finInser = clock();
    
   // cout << "Mi Vector Final es: ";
   // imprimeVectorVerde(v, util_v);
    
    //Algoritmo de la Burbuja
    cout << endl << "********** ALGORITMO DE ORDENACIÓN POR BURBUJA *************" << endl;
    copiarVector( v_copia, util_v_copia, v, util_v );
  //  cout << "Mi Vector Inicial es: ";
   // imprimeVectorRojo(v, util_v);
    
    t_iniBurbu = clock();
    algoritmoOrdenacionBurbuja(v, util_v);
    t_finBurbu = clock();
    
   // cout << "Mi Vector Final es: ";
  //  imprimeVectorVerde(v, util_v);
    
    cout << endl << "/************** MEDICIÓN DE TIEMPOS Y DIMENSIÓN ***********/" << endl;
    cout << "La Dimensión del Vector era de: " << BLUE_COLOR <<  DIM_V << endl;
    //Operación de conversión a mili segundos
    secsSelec = (double)(t_finSelec - t_iniSelec) / CLOCKS_PER_SEC;
    cout << RESTORE_DEFAULT_COLOR << "Tiempo de Selección:\t" << fixed << setprecision(16) << CYAN_COLOR << secsSelec << endl;
    
    //Operación de conversión a mili segundos
    secsInser = (double)(t_finInser - t_iniInser) / CLOCKS_PER_SEC;
    cout  << RESTORE_DEFAULT_COLOR << "Tiempo de Inserción:\t" << fixed << setprecision(16) << YELLOW_COLOR <<  secsInser  << endl;
    
    //Operación de conversión a mili segundos
    secsBurbu = (double)(t_finBurbu - t_iniBurbu) / CLOCKS_PER_SEC;
    cout << RESTORE_DEFAULT_COLOR << "Tiempo de Burbuja:\t" << fixed << setprecision(16) << PURPLE_COLOR << secsBurbu  << endl;
    
    cout << RESTORE_DEFAULT_COLOR << endl;
    
    return 0;
}