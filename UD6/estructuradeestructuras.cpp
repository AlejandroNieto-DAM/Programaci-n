#include <iostream>
#include <string>
using namespace std;

/*INCORPORO LA ESTRUCTURA QUE IRÁ DENTRO DE LA OTRA ESTRUCTURA*/
struct Fecha{
    unsigned short int dia;
    unsigned short int mes;
    unsigned short int anio;
};

/*FUNCIONALIDAD DE LA ESTRUCTURA FECHA*/
void setDia(Fecha &f, unsigned short int dia){
    f.dia = dia;
}

void setMes(Fecha &f, unsigned short int mes){
    f.mes = mes;
}

void setAnio(Fecha &f, unsigned short int anio){
    f.anio = anio;
}

void setFecha(Fecha &f, unsigned short int dia, unsigned short int mes, unsigned short int anio){
    setDia(f,dia);//esto mejor que f.dia = dia;
    setMes(f,mes);//esto mejor que f.mes = mes;
    setAnio(f,anio);//esto mejor que f.anio = anio;
}

unsigned short int getDia(const Fecha &f){
    return f.dia;
}

unsigned short int getMes(const Fecha &f){
    return f.mes;
}

unsigned short int getAnio(const Fecha &f){
    return f.anio;
}

void printFecha(const Fecha &f){
    //cout << "Fecha Nacimiento: " << f.dia << "/" << f.mes << "/" << f.anio << endl;
    cout << "Fecha Nacimiento: " << getDia(f) << "/" << getMes(f) << "/" << getAnio(f) << endl;
    
}


struct Alumno{
    string nombre; //nombre del alumno como máximo de 30 de caracteres
    unsigned int edad;
    Fecha fecha_nac;//está arriba definida la estructura Fecha, si no, no funciona
    char nombres_asignaturas[6][4];
    int notas[6]; //vector con las notas
};

/* FUNCIONALIDAD DEL ALUMNO */

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
 */
void setNombre(Alumno &a, string nombre){
    a.nombre = nombre;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, la edad que se le pasa como parámetro.
 * @pre La edad debe de estar filtrada entre 0 y 120.
 */
void setEdad(Alumno &a, unsigned int edad){
    a.edad = edad;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, la fecha de nacimiento que se pasa en forma de variable
 *        estructurada.
 */
void setFechaNacimiento(Alumno &a, const Fecha &f){
    a.fecha_nac = f; // QUE POTEEEEEEENSIIIIIAAAA Vuelvo a utilizar la asignación campo a campo!!!
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, un vector con sus calificaciones en cada asignatura.
 * El orden es PRO, BD, ED, SI, FOL, LM.
 * @pre El tamaño del vector notas debe estar filtrado e incluir 6 notas (ni más ni menos).
 */
void setNotas(Alumno &a, int notas[]){
    for(int i=0; i < 6; i++)
        a.notas[i] = notas[i];
}

/**
 * @brief Establece en la matriz de nombres de asignaturas los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
 */
void setNombresAsignaturas(Alumno &a){
    strcpy(a.nombres_asignaturas[0], "PRO");
    strcpy(a.nombres_asignaturas[1], "BD");
    strcpy(a.nombres_asignaturas[2], "ED");
    strcpy(a.nombres_asignaturas[3], "SI");
    strcpy(a.nombres_asignaturas[4], "FOL");
    strcpy(a.nombres_asignaturas[5], "LM");
}

/**
 * @brief Calcula y devuelve la media de calificaciones de una variable de tipo Alumno.
 */
float calcularMediaCalificacionesAlumno(const Alumno &a){

    float suma = 0;

    

    for(int i = 0; i < 6; i++){

        //cout << "debug a.notas: " << a.notas[i] << endl;
        suma += a.notas[i];

    }

    suma = suma/6;

    //cout << "debug suma: " << suma << endl;

    return suma;
    
}

/**
 * @brief Imprime por pantalla el contenido de una variable de tipo Alumno.
 */
void printAlumno(const Alumno &a){
    cout << "Nombre Alumno: " << a.nombre << endl;
    cout << "Edad: " << a.edad << endl;
    printFecha(a.fecha_nac); //USA EL MÓDULO QUE TIENES! REUTILIZAAAA LO QUE TIENES Y FUNCIONA!
    cout << "-----Calificaciones-----" << endl;
    for(int i=0; i < 6; i++)
        cout << " - " << a.nombres_asignaturas[i] << ": " << a.notas[i] << endl;

    cout << "Nota media: " << calcularMediaCalificacionesAlumno(a) << endl;
}

/**
 * @brief Agrego al vector de Alumnos, el alumno a que le paso por referencia
 */
void setAlumnoEnVector(Alumno v[], const int DIM_v, int &util_v, const Alumno &a){
    if (util_v < DIM_v){
        v[util_v] = a; //LA VIN QUE POTENSIA (Vuelvo la hacer automáticamente la asignación campo a campo)
        util_v++;
    }else
        cerr << "ERROR: NO HAY ESPACIO PARA EL ALUMNO QUE SE QUIERE INSERTAR" << endl;
}

/**
 * @brief Imprime el contenido del vector de alumnos
 */
void printVectorAlumno(const Alumno v[], int util_v){
    for(int i = 0; i < util_v; i++)
        printAlumno(v[i]);
}

/**

* @brief Muestra todos los alumnos hasta el momento contenidos en el vector para que el usuario pueda seleccionar la posicion a borrar.
* @param v[] que contiene alumnos.
* @param util_v que nos guarda el numero de componentes utilizados en el vector en el momento.
* @pre v[] debe de mantener alumnos en su interior, es decir que este inicializado con valores.
* @pre util_v > 0 && < DIM
* @return no devuelve nada.
* @post una posicion de vector sera borrada y el util se reducirá en 1.

*/
void deleteAlumnoVector(Alumno v[], int &util_v){

    int posicion_borrar = 0;

    cout << "Estos son todos los alumnos disponibles: " << endl;
    printVectorAlumno(v, util_v);
    cout << "En que posicion se encuentra el alumno que desea borrar? ";
    cin >> posicion_borrar;
    cout << endl;

    v[posicion_borrar] = v[util_v - 1];
    util_v --;

    printVectorAlumno(v, util_v);

}

/*+

* @brief Busca en el un vector un nombre previamente introducido por el usuario.
* @param v[] que contiene en su interior los alumnos.
* @param util_v que nos guarda el numero de componentes utilizados en el vector en el momento.
* @param nombreBuscado que guarda en su interior el nombre a buscar por el usuario.
* @pre v[] debe de mantener alumnos en su interior, es decir que este inicializado con valores.
* @pre util_v > 0 && < DIM
* @pre nombreBuscado debe de estar inicializado.
* @return no devuelve nada.
* @post Se mostrará la posicion en la que se encuentra el nombre si se ha encontrado y el alumno por completo por si hay mas de uno con el mismo nombre.

*/

void busquedaPorNombre(const Alumno v[], int util_v, string nombreBuscado){

    bool encontrado = false;

    for(int i = 0; i < util_v; i++){

        if(v[i].nombre == nombreBuscado){
            cout << "Hemos encontrado un alumno con ese parametro en la posición: " << i << endl;
            cout << "El alumno encontrado es: " << endl;
            printAlumno(v[i]);
            encontrado = true;

        }

    }

    if(encontrado == false){
        cout << "No se ha encontrado un alumno con ese nombre :(" << endl;
    }

}
/**

* @brief Busca en el un vector una edad previamente introducida por el usuario.
* @param v[] que contiene en su interior los alumnos.
* @param util_v que nos guarda el numero de componentes utilizados en el vector en el momento.
* @param edadBuscada que guarda en su interior la edad a buscar por el usuario.
* @pre v[] debe de mantener alumnos en su interior, es decir que este inicializado con valores.
* @pre util_v > 0 && < DIM
* @pre edadBuscada > 0 && < 120
* @return no devuelve nada.
* @post Se mostrará la posicion en la que se encuentra la edad si se ha encontrado y el alumno por completo por si hay mas de uno con la misma edad.

*/
void busquedaPorEdad(const Alumno v[], int util_v, int edadBuscada){

    bool encontrado = false;

    for(int i = 0; i < util_v; i++){

        if(v[i].edad == edadBuscada){
            cout << "Hemos encontrado un alumno con ese parametro en la posición: " << i << endl;
            cout << "El alumno encontrado es: " << endl;
            printAlumno(v[i]);
            encontrado = true;
        } 

    }

    if(encontrado == false){
        cout << "No se ha encontrado un alumno con ese nombre :(" << endl;
    }


}

/**

* @brief Switch que utilizaremos para buscar un parametro en concreto en el vector
* @param v[] que contiene en su interior los alumnos.
* @param util_v que nos guarda el numero de componentes utilizados en el vector en el momento.
* @pre v[] debe de mantener alumnos en su interior, es decir que este inicializado con valores.
* @pre util_v > 0 && < DIM
* @return no devuelve nada.
* @post se realizara una de las 3 acciones descritas en cada uno de los casos del switch. 

*/
void busquedaAlumno(const Alumno v[], int util_v){

    int opcion = 0;
    string nombreBuscado;
    cout << "Introduce [1] para buscar por NOMBRE, [2] para buscar por EDAD, [0] para no hacer NADA: ";
    cin >> opcion;

    switch(opcion){

        case 1: 

            
            cout << "Has elegido la opcion de buscar por nombre. Introduce el nombre: ";
            cin >> nombreBuscado;
            busquedaPorNombre(v, util_v, nombreBuscado);

            break;

        case 2: 

            int edadBuscada;
            cout << "Has elegido la opcion de buscar por edad. Introduce la edad: ";
            cin >> edadBuscada;
            busquedaPorEdad(v, util_v, edadBuscada);

            break;

        case 0:

            break;

    }
}

/**

* @brief Modulo que ordena por nota media el vector de alumnos.
* @param v[] que contiene en su interior los alumnos.
* @param util_v que nos guarda el numero de componentes utilizados en el vector en el momento.
* @pre v[] debe de mantener alumnos en su interior, es decir que este inicializado con valores.
* @pre util_v > 0 && < DIM
* @return no devuelve nada.
* @post el vector quedará ordenado de mayor a menor en notas medias de los alumnos.

*/
void ordenacionPorNotaMedia(Alumno v[], int util_v){

    float notaAlumno1 = 0;
    float notaAlumno2 = 0;
    Alumno auxiliar;

    for(int i = 0; i < util_v; i++){
        for(int j = 0; j < util_v; j++){

            notaAlumno1 = calcularMediaCalificacionesAlumno(v[i]);
            notaAlumno2 = calcularMediaCalificacionesAlumno(v[j]);

            if(notaAlumno1 > notaAlumno2){

                auxiliar = v[i];
                v[i] = v[j];
                v[j] = auxiliar;

            }

        }

    }
}

int main(){
    Alumno Berrios, Jaime, alumnocopiado;
    string nombreberrios = "Berrios";
    int notasberrios[6] = {5,6,5,8,6,7};
    string nombrejaime = "Jaime";
    int notasjaime[6] = {5,6,5,7,7,6};
    
    //Preparo los datos de Berrios
    setNombre(Berrios, nombreberrios);
    setEdad(Berrios, 22);
    setNombresAsignaturas(Berrios);
    setNotas(Berrios, notasberrios);
    printAlumno(Berrios);
    
    //Preparo los datos de Jaime
    setNombre(Jaime, nombrejaime);
    setEdad(Jaime, 23);
    setNombresAsignaturas(Jaime);
    setNotas(Jaime, notasjaime);
    printAlumno(Jaime);

    cout << "/** AGREGO ESTRUCTURA DENTRO DE OTRA ESTRUCTURA **/"<< endl;
    //Declaramos la Fecha
    Fecha cumpleBerrios = {2, 4, 1980}; //recordar que al declarar tb se puede inicializar
    Fecha cumpleJaime;
    setFecha(cumpleJaime, 31,12,1982); //usamos el método set para meterle valores a la variable fecha
    //pregunta Berrios que si puedo cambiar "a pelo" la fecha
    //respuesta: SI (pero no nos gusta, preferimos usar MÓDULOS.
    cumpleBerrios.dia = 3;
    setFechaNacimiento(Berrios, cumpleBerrios);
    setFechaNacimiento(Jaime, cumpleJaime);
    printAlumno(Berrios);
    printAlumno(Jaime);
    
    //Fijaros como la asignación de estructuras HACE LA COPIA DE VECTORES AUTOMÁTICAMENTE
    alumnocopiado = Berrios; //"QUÉ POTEEEEENSIAAAAAA QUE ME LO COPIA TÓ COMPAE VIEO SIN TENER QUE HASER UN FOR NI NÁ"
    setNombre(alumnocopiado,"POTENSIA");
    printAlumno(alumnocopiado);
    
    
    cout << "/** AMPLIAMOS EL CÓDIGO PARA INCORPORAR VECTORES DE ALUMNOS **/" << endl;
    //Declaro mi vector de Alumnos
    const int DIM_vectorAlumnosDAM = 22; //declaro las plazas disponibles
    int util_vectorAlumnosDAM = 0; //declaro las plazas ocupadas en la actualidad
    Alumno vectorAlumnosDAM[DIM_vectorAlumnosDAM];
    
    cout << "/** AGREGO ALUMNO AL VECTOR SIN MÓDULO **/"<< endl;
    //Agregamos un elemento al vector de Alumnos de DAM
    vectorAlumnosDAM[0] = Berrios; // LA VIN VIEOOO QUE POTENSIAAAA (RECUERDA SE ASIGNA CAMPO A CAMPO AUTOMÁTICAMENTE)
    printAlumno(vectorAlumnosDAM[0]); //Para incrédulos que no tienen FE, voy imprimir la primera posición del vector...
    util_vectorAlumnosDAM++; //aumento sus útiles como en cualquier vector de antes
    
    cout << "/** AGREGO ALUMNO AL VECTOR CON MÓDULO **/"<< endl;
    cout << "-!!! "<< util_vectorAlumnosDAM << endl;
    //Agregamos un elemento al vector de Alumnos de DAM USANDO MÓDULOS
    setAlumnoEnVector(vectorAlumnosDAM,DIM_vectorAlumnosDAM,util_vectorAlumnosDAM,Jaime);
    cout << "-!!! "<< util_vectorAlumnosDAM << endl;
    //Y ahora imprimo TOOOOODO el vector de Alumnos para incrédulos
    for(int i = 0; i < util_vectorAlumnosDAM; i++)
        printAlumno(vectorAlumnosDAM[i]);
    
    cout << "/** IMPRIMO AHORA CON EL MÓDULO IMPRIME VECTOR DE ALUMNOS **/"<< endl;
    setAlumnoEnVector(vectorAlumnosDAM,DIM_vectorAlumnosDAM,util_vectorAlumnosDAM,alumnocopiado);
    printVectorAlumno(vectorAlumnosDAM,util_vectorAlumnosDAM);

    cout << "/** AGREGO MÓDULO DE ORDENACION POR NOTA MEDIA **/" << endl;
    ordenacionPorNotaMedia(vectorAlumnosDAM, util_vectorAlumnosDAM);
    printVectorAlumno(vectorAlumnosDAM,util_vectorAlumnosDAM);

    cout << "/** AGREGO MÓDULO DE BUSQUEDA POR NOMBRE/EDAD **/"<< endl;
    busquedaAlumno(vectorAlumnosDAM, util_vectorAlumnosDAM);


    cout << "/** AGREGO MODULO PARA BORRAR ALUMNOS **/"<< endl;
    int borrar = 0;

    cout << "Desea borrar algun alumno? Introduce [1]: ";
    cin >> borrar;

    if(borrar == 1){

        deleteAlumnoVector(vectorAlumnosDAM, util_vectorAlumnosDAM);

    }

    
    
}