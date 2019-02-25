#include <iostream>
using namespace std;

//Definición de la Estructura
struct Tiempo{
    int hora;
    bool am;
    int minutos;
    int segundos;
};

/**
 * @brief Módulo que introduce una hora a una variable de tipo Tiempo
 * @param Tiempo untiempo Una variable de tipo Tiempo por referencia (E/S)
 * @param int hora Una variable de tipo int que contiene la hora que quiero asignarle
 *      a mi variable de tipo tiempo.
 * @post El valor del miembro hora de la variable tipo Tiempo, será modificado.
 */
void setHora(Tiempo &untiempo, int hora){
    untiempo.hora = hora;
}

/**
 * @brief Módulo que introduce minutos a una variable de tipo Tiempo
 * @param Tiempo untiempo Una variable de tipo Tiempo por referencia (E/S)
 * @param int minutos Una variable de tipo int que contiene los minutos que quiero asignarle
 *      a mi variable de tipo tiempo.
 * @post El valor del miembro hora de la variable tipo Tiempo, será modificado.
 */
void setMinutos(Tiempo &untiempo, int minutos){
    untiempo.minutos = minutos;
}

/**
 * @brief Módulo que introduce am a una variable de tipo Tiempo
 * @param Tiempo untiempo Una variable de tipo Tiempo por referencia (E/S)
 * @param bool am Una variable de tipo bool que contiene true o false para representar
 *      si es una hora AM o PM.
 * @post El valor del miembro AM de la variable tipo Tiempo, será modificado.
 */
void setAM(Tiempo &untiempo, bool am){
    untiempo.am = am;
}

/**
 * @brief Módulo que introduce segundos a una variable de tipo Tiempo
 * @param Tiempo untiempo Una variable de tipo Tiempo por referencia (E/S)
 * @param int segundos Una variable de tipo int que contiene los segundos que quiero asignarle
 *      a mi variable de tipo tiempo.
 * @post El valor del miembro segundos de la variable tipo Tiempo, será modificado.
 */
void setSegundos(Tiempo &untiempo, int segundos){
    untiempo.segundos = segundos;
}

/**
 * @brief Módulo que introduce valores a una variable de tipo Tiempo
 * @param Tiempo untiempo Una variable de tipo Tiempo por referencia (E/S)
 * @param int hora Una variable de tipo int que contiene la hora que quiero asignarle
 *      a mi variable de tipo tiempo.
 * @param bool am Una variable de tipo bool que contiene true o false para representar 
 *      si es una hora AM o PM.
 * @param int minutos Una variable de tipo int que contiene los minutos que quiero asignarle
 *      a mi variable de tipo tiempo.
 * @param int segundos Una variable de tipo int que contiene los segundos que quiero asignarle
 *      a mi variable de tipo tiempo.
 * @post Tras la ejecución del módulo la variable de tipo Tiempo tendrá almacenada en
 *      los valores que se han pasado como parámetros. 
 **/
void inicializarTiempo(Tiempo &untiempo, int hora, bool am, int minutos, int segundos){
    setHora(untiempo, hora); //untiempo.hora = hora;
    setAM(untiempo, am); //untiempo.am = am;
    setMinutos(untiempo, minutos); //untiempo.minutos = minutos;
    setSegundos(untiempo, segundos); //untiempo.segundos = segundos;
}

/**

* @brief Devuelve un valor de la hora de una variable tipo Tiempo.
* @param untiempo que pasamos por referencia constante.
* @pre la estructura Tiempo deberá de haber sido definida anteriormente.
* @return devuelve el miembro hora de una variable tipo Tiempo.
* @post se mostrará por pantalla el valor pertinente dentro del miembro hora.

**/
int getHora(const Tiempo &untiempo){
    return untiempo.hora;
}

//Ejemplo de Definición de Módulo Pasándole una Variable Estructura por Referencia
void printTiempo(const Tiempo &untiempo){
    cout << "Hora: " << getHora(untiempo) <<":"<< untiempo.minutos <<":"<< untiempo.segundos;
    if (untiempo.am == true) 
        cout << " AM" << endl;
    else
        cout << " PM" << endl;
}

int main(){
    //Declaración de Variables de Tipo Estructura
    Tiempo ahora = {8,true,30,33}, alarma;
    
    //Diferentes formas de Asignación de Valores a los Miembros de una Estructura
    //1ª Forma: Acceso directo mediante el operador punto
    alarma.am = true;
    alarma.hora = 8;
    alarma.minutos = ahora.minutos;
    alarma.segundos = 0;
    
    //2ª Forma: Utilización metodológica de los módulos SET y GET (USAREMOS ESTA)
    setAM(alarma, false);
    setHora(alarma, 12);
    setMinutos(alarma, 15);
    setSegundos(alarma, 23);
    
    cout << "VARIABLE DE TIPO TIEMPO ALARMA INICIALIZADA EMPLEANDO SETS: ";
    printTiempo(alarma);

    cout << "VARIABLE DE TIPO TIEMPO AHORA INICIALIZADA EN LA DECLARACIÓN: ";
    printTiempo(ahora);

    inicializarTiempo(alarma, 10, true, 35, 15);
    
    //LLamada a módulo usando una variable estructura
    cout << "VARIABLE DE TIPO TIEMPO ALARMA TRAS INICIALIZARLA : ";
    printTiempo(alarma);

    cout << "VARIABLE DE TIPO TIEMPO AHORA: ";
    printTiempo(ahora);

    //Asignación directa de Variables Estructura
    //La asignación se hace miembro a miembro automáticamente...
    alarma = ahora;

    cout << "VARIABLE DE TIPO TIEMPO ALARMA TRAS ASIGNARLE AHORA : ";
    printTiempo(alarma);
}