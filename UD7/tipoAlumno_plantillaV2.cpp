//
//  tipoalumno_plantilla1.cpp
//  
//
//  Created by Jaime Matas Bustos on 13/2/18.
//

#include <iostream>
#include <string.h>
using namespace std;
/***************************************
** Definición del TIPO DE DATO Fecha **
****************************************/

struct Fecha{

    unsigned short int dia;
    unsigned short int mes;
    unsigned short int anio;
    
};

/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Fecha **
 **********************************************************/
void setEdad(Fecha *a, unsigned short int dia);
void setMes(Fecha *a, unsigned short int mes);
void setAnio(Fecha *a, unsigned short int anio);
unsigned short int getDia(const Fecha *a);
unsigned short int getMes(const Fecha *a);
unsigned short int getAnio(const Fecha *a);


/***************************************
** Definición del TIPO DE DATO Alumno **
****************************************/
struct Alumno{
    char nombre[31]; //nombre del alumno como máximo de 30 de caracteres
    unsigned int edad;
    char nombres_asignaturas[6][4];
    int notas[6]; //vector con las notas
    Fecha *matricula;
};

/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Alumno **
 **********************************************************/
void getNombre(const Alumno *a, char cadena[]);
int getTamanioNombre(const Alumno *a);
unsigned int getEdad(const Alumno *a);
void setNombre(Alumno *a, char nombre[]);
void setUtilNombre(Alumno *a, int util_nombre);
void setEdad(Alumno *a, unsigned int edad);
void setNotas(Alumno *a, int notas[]);
void setNombresAsignaturas(Alumno *a);
void printAlumno(const Alumno *a);
void intercambiarAlumnos(Alumno *a, Alumno *b);
float calcularMediaCalificacionesAlumno(Alumno *a);
void setFechaAlumno(Alumno *a, unsigned short int dia, unsigned short int mes, unsigned short anio);
void getFecha(const Alumno *a);

/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Fecha **
 **************************************************************/

/**
 * @brief Asigna a la variable estructurada de tipo Fecha, el año que se le pasa como parámetro.
 * @pre El año debe de estar filtrado entre 1900 y 2019.
 */
void setAnio(Fecha *a, unsigned short int anio){
    a->anio = anio;
}

/**
 * @brief Asigna a la variable estructurada de tipo Fecha, el mes que se le pasa como parámetro.
 * @pre El mes debe de estar filtrado entre 1 y 12.
 */
void setMes(Fecha *a, unsigned short int mes){
    a->mes = mes;
}

/**
 * @brief Asigna a la variable estructurada de tipo Fecha, el dia que se le pasa como parámetro.
 * @pre El dia debe de estar filtrado entre 1 y 31.
 */
void setDia(Fecha *a, unsigned short int dia){
    a->dia = dia;
}


unsigned short int getDia(const Fecha *a){
    return a->dia;
}

unsigned short int getMes(const Fecha *a){
    return a->mes;
}

unsigned short int getAnio(const Fecha *a){
    return a->anio;
}

void getFecha(const Alumno *a){
    cout << getDia(a->matricula) << "/" << getMes(a->matricula) << "/" << getAnio(a->matricula);
}

/**

* @brief Elimina la fecha de un usuario poniendo todos los datos a 0 y borrando la direccion de memoria de la misma

*/
void eliminarFecha(Fecha *a){
	a->dia = 0;
	a->mes = 0;
	a->anio = 0;

	delete a;
	a = 0;
}




/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Alumno **
 **************************************************************/

void setFechaAlumno (Alumno *a, unsigned short int dia, unsigned short int mes, unsigned short anio){

	Fecha *b;
	b = new Fecha;

    setDia(b, dia);
    setMes(b, mes);
    setAnio(b, anio);

    a->matricula = b;
}

/**
 * @brief Devuelve por copia la cadena de caracteres de una variable estructurada de tipo Alumno.
 */
void getNombre(const Alumno *a, char cadena[]){

    for(int i = 0; i < 31; i++){
        cadena[i] = a->nombre[i];
    }

}

/**
 * @brief Calcula el tamaño que tiene el nombre de una variable estructurada de tipo Alumno. Para ello contará el número de caracteres totales desde el primero hasta el carácter centinela.
 */
int getTamanioNombre(Alumno *a){

	int tamanio = 0;

	while(a->nombre[tamanio] != '\0'){

		tamanio++;

	}

	return tamanio;
}

/**
 * @brief Devuelve la edad una variable estructurada de tipo Alumno.
 */
unsigned int getEdad(const Alumno *a){
    return a->edad;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
 */
void setNombre(Alumno *a, char nombre[]){
    for(int i=0; i <= 31; i++){
        a->nombre[i] = nombre[i];
    }
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, la edad que se le pasa como parámetro.
 * @pre La edad debe de estar filtrada entre 0 y 120.
 */
void setEdad(Alumno *a, unsigned int edad){
	a->edad = edad;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, un vector con sus calificaciones en cada asignatura. El orden de las asignaturas será PRO, BD, ED, SI, FOL, LM.
 * @pre El tamaño del vector notas debe estar filtrado e incluir 6 notas (ni más ni menos).
 */
void setNotas(Alumno *a, int notas[]){
	
	for(int i = 0; i < 6; i++){
		a->notas[i] = notas[i];
	}
}

/**
 * @brief Establece en la matriz de nombres de asignaturas de una variable de tipo Alumno, los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
 */
void setNombresAsignaturas(Alumno *a){
    strcpy(a->nombres_asignaturas[0], "PRO");
    strcpy(a->nombres_asignaturas[1], "BD");
    strcpy(a->nombres_asignaturas[2], "ED");
    strcpy(a->nombres_asignaturas[3], "SI");
    strcpy(a->nombres_asignaturas[4], "FOL");
    strcpy(a->nombres_asignaturas[5], "LM");
}

/**
 * @brief Imprime por pantalla el contenido de una variable de tipo Alumno.
 */
void printAlumno(const Alumno *a){
    //OBSERVAR EL USO DE LOS MÓDULOS GET VS NO UTILIZARLOS...
    //¿QUÉ PASARÍA SI CAMBIÁSEMOS EL NOMBRE DEL VECTOR DE NOTAS?

    //Creo una variable nueva para guardar el nombre.
    char cadena[31];
 
    getNombre(a, cadena);

    cout << "Nombre Alumno: " << cadena << endl;
    cout << "Fecha matricula: ";
    getFecha(a);
    cout << endl;
    cout << "Edad: " << getEdad(a) << endl;
    cout << "-----Calificaciones-----" << endl;
    for(int i=0; i < 6; i++)
        cout << " - " << a->nombres_asignaturas[i] << ": " << a->notas[i] << endl;

    cout << endl;
}

/**
 * @brief Intercambia el contenido de dos variables de tipo Alumno.
 */
void intercambiarAlumnos(Alumno *a, Alumno *b){

	Alumno *auxiliar;
	auxiliar = new Alumno;

	cout << "----- INTERCAMBIANDO ALUMNOS -----" << endl;

	auxiliar = a;
	a = b;
	b = auxiliar;
    
}

/**
 * @brief Calcula y devuelve la media de calificaciones de una variable de tipo Alumno.
 */
float calcularMediaCalificacionesAlumno(Alumno *a){

	float suma = 0;

	

	for(int i = 0; i < 6; i++){

		//cout << "debug a.notas: " << a.notas[i] << endl;
		suma += a->notas[i];

	}

	suma = suma/6;

	//cout << "debug suma: " << suma << endl;

	return suma;
    
}

/**

* @brief Devuelve una direccion de tipo alumno.

*/
Alumno* crearAlumno(){

	Alumno *a;
	a = new Alumno;

	return a;

}

/**

* brief Elimina un usuario poniendo todos sus datos a 0.

*/
void eliminarUsuario(Alumno *a){

	eliminarFecha(a->matricula);
	delete a;
	a = 0;

}



int main(){

    Alumno *Berrios, *Jaime, *alumnocopiado;

    Berrios = crearAlumno();
    Jaime = crearAlumno();
    alumnocopiado = crearAlumno();

    char nombreberrios[31] = {'B','e','r','r','i','o','s','\0'};
    int notasberrios[6] = {5,6,5,8,6,7};
    char nombrejaime[31] = {'J','a','i','m','e','\0'};
    int notasjaime[6] = {5,6,5,7,7,6};

    //Nombre alumno copiado
    char nombreAlumnoCopiado[31] = {'P','O','T','E','N','S','I','A','\0'};
    
    //Preparo los datos del Alumno Berrios
    setNombre(Berrios, nombreberrios);
    setFechaAlumno(Berrios, 12,2,2000);
    setEdad(Berrios, 22);
    setNombresAsignaturas(Berrios);
    setNotas(Berrios, notasberrios);
    printAlumno(Berrios);
    
    //Preparo los datos del Alumno Jaime
    setNombre(Jaime, nombrejaime);
    setFechaAlumno(Berrios, 13,9,2014);
    setEdad(Jaime, 23);
    setNombresAsignaturas(Jaime);
    setNotas(Jaime, notasjaime);
    printAlumno(Jaime);
    
    //Fijaros como la asignación de estructuras HACE LA COPIA DE VECTORES AUTOMÁTICAMENTE
    alumnocopiado = Berrios; //"QUÉ POTEEEEENSIAAAAAA QUE ME LO COPIA TÓ COMPAE VIEO SIN TENER QUE HASER UN FOR NI NÁ"
    setNombre(alumnocopiado, nombreAlumnoCopiado);
    printAlumno(alumnocopiado);
    
    /*Aquí habría que incluir el código para probar los módulos Intercambiar Alumnos y Calcular Calificaciones Medias*/
    
    // 1) Probamos Intercambiar Alumnos y mostramos por pantalla los alumnos intercambiados.
    intercambiarAlumnos(Berrios, Jaime);
    printAlumno(Berrios);
    printAlumno(Jaime);
    

    //Para volverlos a poner como estaban antes y que no estén cambiados.
    intercambiarAlumnos(Berrios, Jaime);
    

    char cadena[31];
    // 2) Probamos Calcular Calificación Media de los Alumnos y las mostramos por pantalla.

    getNombre(Jaime, cadena);
    cout << "Calculando la media de las calificaciones de " << cadena << " : " << calcularMediaCalificacionesAlumno(Jaime) << endl;

    getNombre(Berrios, cadena);
    cout << "Calculando la media de las calificaciones de " << cadena << " : " << calcularMediaCalificacionesAlumno(Berrios) << endl;


    eliminarUsuario(Jaime);
    eliminarUsuario(Berrios);
    eliminarUsuario(alumnocopiado);

}