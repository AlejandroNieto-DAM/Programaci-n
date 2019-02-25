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
** Definición del TIPO DE DATO Alumno **
****************************************/
struct Alumno{
    char nombre[31]; //nombre del alumno como máximo de 30 de caracteres
    unsigned int edad;
    char nombres_asignaturas[6][4];
    int notas[6]; //vector con las notas
};

/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Alumno **
 **********************************************************/
string getNombre(Alumno &a);
int getTamanioNombre(Alumno &a);
unsigned int getEdad(int edad);
void setNombre(Alumno &a, char nombre[]);
void setUtilNombre(Alumno &a, int util_nombre);
void setEdad(Alumno &a, unsigned int edad);
void setNotas(Alumno &a, int notas[]);
void setNombresAsignaturas(Alumno &a);
void printAlumno(const Alumno &a);
void intercambiarAlumnos(Alumno &a, Alumno &b);
void calcularMediaCalificacionesAlumno(Alumno &a);


/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Alumno **
 **************************************************************/
/**
 * @brief Devuelve por copia la cadena de caracteres de una variable estructurada de tipo Alumno.
 */
string getNombre(Alumno &a){
	string nombre;

	for(int i = 0; i < 31; i++){
		nombre += a.nombre[i];
	}

	return nombre;
}

/**
 * @brief Calcula el tamaño que tiene el nombre de una variable estructurada de tipo Alumno. Para ello contará el número de caracteres totales desde el primero hasta el carácter centinela.
 */
int getTamanioNombre(Alumno &a){

	int tamaño = 0;

	while(a.nombre[tamaño] != '\0'){

		tamaño++;

	}

	return tamaño;
}

/**
 * @brief Devuelve la edad una variable estructurada de tipo Alumno.
 */
unsigned int getEdad(int edad){
    return edad;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
 */
void setNombre(Alumno &a, char nombre[]){
    for(int i=0; i <= 31; i++){
        a.nombre[i] = nombre[i];
    }
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, la edad que se le pasa como parámetro.
 * @pre La edad debe de estar filtrada entre 0 y 120.
 */
void setEdad(Alumno &a, unsigned int edad){
	a.edad = edad;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, un vector con sus calificaciones en cada asignatura. El orden de las asignaturas será PRO, BD, ED, SI, FOL, LM.
 * @pre El tamaño del vector notas debe estar filtrado e incluir 6 notas (ni más ni menos).
 */
void setNotas(Alumno &a, int notas[]){
	
	for(int i = 0; i < 6; i++){
		a.notas[i] = notas[i];
	}
}

/**
 * @brief Establece en la matriz de nombres de asignaturas de una variable de tipo Alumno, los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
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
 * @brief Imprime por pantalla el contenido de una variable de tipo Alumno.
 */
void printAlumno(const Alumno &a){
    //OBSERVAR EL USO DE LOS MÓDULOS GET VS NO UTILIZARLOS...
    //¿QUÉ PASARÍA SI CAMBIÁSEMOS EL NOMBRE DEL VECTOR DE NOTAS?

    //Creo una variable nueva para pasar el miembro.
    Alumno copia = a;

    cout << "Nombre Alumno: " << getNombre(copia) << endl;
    cout << "Edad: " << getEdad(a.edad) << endl;
    cout << "-----Calificaciones-----" << endl;
    for(int i=0; i < 6; i++)
        cout << " - " << a.nombres_asignaturas[i] << ": " << a.notas[i] << endl;

    cout << endl;
}

/**
 * @brief Intercambia el contenido de dos variables de tipo Alumno.
 */
void intercambiarAlumnos(Alumno &a, Alumno &b){

	Alumno auxiliar;

	cout << "----- INTERCAMBIANDO ALUMNOS -----" << endl;

	auxiliar = a;
	a = b;
	b = auxiliar;
    
}

/**
 * @brief Calcula y devuelve la media de calificaciones de una variable de tipo Alumno.
 */
void calcularMediaCalificacionesAlumno(Alumno &a){

	float suma = 0;

	cout << "Calculando la media de las calificaciones de " << a.nombre << " : ";

	for(int i = 0; i < 6; i++){

		//cout << "debug a.notas: " << a.notas[i] << endl;
		suma += a.notas[i];

	}

	suma = suma/6;

	//cout << "debug suma: " << suma << endl;

	cout << suma << endl;

	cout << endl;
    
}

int main(){

    Alumno Berrios, Jaime, alumnocopiado;
    char nombreberrios[31] = {'B','e','r','r','i','o','s','\0'};
    int notasberrios[6] = {5,6,5,8,6,7};
    char nombrejaime[31] = {'J','a','i','m','e','\0'};
    int notasjaime[6] = {5,6,5,7,7,6};

    //Nombre alumno copiado
    char nombreAlumnoCopiado[31] = {'P','O','T','E','N','S','I','A','\0'};
    
    //Preparo los datos del Alumno Berrios
    setNombre(Berrios, nombreberrios);
    setEdad(Berrios, 22);
    setNombresAsignaturas(Berrios);
    setNotas(Berrios, notasberrios);
    printAlumno(Berrios);
    
    //Preparo los datos del Alumno Jaime
    setNombre(Jaime, nombrejaime);
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
    
    // 2) Probamos Calcular Calificación Media de los Alumnos y las mostramos por pantalla.
    calcularMediaCalificacionesAlumno(Jaime);
    calcularMediaCalificacionesAlumno(Berrios);
}