#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*************************************
** Definición del TIPO DE DATO Foto **
**************************************/

struct Foto{

    string ruta; // /home/cristorey/Escritorio/nombreFoto.jpg
    string tipo; // jpg jpeg png
    unsigned long int tamanio; //Tamaño en bytes que ocupa.
    
};

/****************************************
** Definición del TIPO DE DATO Usuario **
*****************************************/

struct Usuario{

    string login; //Débe ser único.
    string nombre;
    string apellido;
    string perfil_usuario; //User o Admin
    Foto *v_fotos; //Vector tipo dinámico.
    int dim_vfotos;
    int totalFotosUsuario; //Utiles del vector.
    
};

/**********************************************
** Definición del TIPO DE DATO TablaUsuarios **
***********************************************/

struct TablaUsuarios{

    Usuario **punteroapuntero;//Vector dinámico de punteros.
    int totalTuplas; 
    
};

void setNombre(Usuario *a){
	cout << "Introduce el nombre: ";
	cin >> a->nombre;
	cout << endl;

}
void setApellido(Usuario *a){
	cout << "Introduce el apellido: ";
	cin >> a->apellido;
	cout << endl;
}
void setLogin(Usuario *a){
	cout << "Introduce el login: ";
	cin >> a->login;
	cout << endl;
}
void setPerfil(Usuario *a){

	
	cout << "Introduce el perfil_usuario [Admin] o [User]: ";
	cin >> a->perfil_usuario;
	cout << endl;
	
}

void setUsuario(Usuario *a){

	setLogin(a);
	setNombre(a);
	setApellido(a);
	setPerfil(a);

	a->v_fotos = 0;
	a->dim_vfotos = 0;
	a->totalFotosUsuario = 0;




}

string getLogin(const Usuario *a){
	return a->login;
}
string getNombre(const Usuario *a){
	return a->nombre;
}
string getApellido(const Usuario *a){
	return a->apellido;
}
string getPerfil(const Usuario *a){
	return a->perfil_usuario;
}


void getUsuario(Usuario *a){
	
	cout << getLogin(a) << endl;
	cout << getNombre(a) << endl;
	cout << getApellido(a) << endl;
	cout << getPerfil(a) << endl;



}



void resize(Usuario **p, int &tuplas){

	int nuevaDim = tuplas + 1;

	Usuario **a;
	a = new Usuario*[nuevaDim];

	if (a == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        //exit(-1);
    }

	for(int i = 0; i < tuplas; i++){
		a[i] = p[i];
	}

	delete [] p;

	p = a;

	a = 0;



}



 Usuario* iniciaPersona(Usuario *a){

	a = new Usuario;

	//cout << a << endl;
	return a;
	
	
}



Usuario** insertarUsuarioEnTablaUsuarios(Usuario **a, int dimension, int &util){

	cout << "entra I  " << endl;
	a[util] = iniciaPersona(a[util]);
	cout << "sale  " << endl;

	cout << "entra SU  " << endl;
	setUsuario(a[util]);
	cout << "sale " << endl;


	util++;
	cout << util << endl;
	//a = resize(a, dimension);

	return a;
	
	
}


/**

* @ brief Inicializa la Tabla Usuarios para poder comenzar a introducir Usuarios.
* @ param 
* @ pre Debe haber sido escogida esta opción y no debe escogerse una vez inicializada esta Tabla.
* @ return devuelve un puntero que apunta a punteros de Usuarios ya que este puntero;
* @ post TablaUsuarios será inicializada para que se puedan a empezar a introducir usuarios.

**/
TablaUsuarios* inicializarTabla(){

	TablaUsuarios *q = 0;
	q = new TablaUsuarios;

	if (q == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    //cout << "debug totalTuplas: " << q->totalTuplas << endl;
    q->totalTuplas = 8;

    Usuario **a = 0;
    a = new Usuario*[q->totalTuplas];

    //cout << "debug " << a << endl;

    q->punteroapuntero = a;

    //cout << "debug " << q->punteroapuntero << endl;

    cout << "Su tabla ha sido inicializada." << endl;;

    return  q;

}

/**
*
*/

void imprimirTabla(Usuario **a, int util){


	for(int i = 0; i < util; i++){
		getUsuario(a[i]);
	}	

}


/**

* @brief Menu que se le mostrará al usuario por pantalla.

*/
void menu(){


	unsigned short int opcion;
	TablaUsuarios *miTabla;
	int util = 0;

	do{

	 cout << "\t BIENVENIDO AL PROGRAMA DE LA PRACTICA FINAL DEL 2º TRIMESTRE." << endl;
	 cout << "\t* Elija una de las siguientes opciones: " << endl;
	 cout << "\t* Para Crear Tabla Usuarios ---------------------------[1]" << endl;
	 cout << "\t * Para Imprimir Tabla Usuarios ------------------------[3]" << endl;
	 cout << "\t * Para Insertar Usuario en Tabla Usuarios -------------[4]" << endl;
	 cout << "\t * Para Eliminar Usuario en Tabla Usuarios -------------[5]" << endl;
	 cout << "\t * Buscar Usuarios por Login ---------------------------[6]" << endl;
	 cout << "\t * Ordenar Tabla Usuarios por totalFotosUsuario o Login-[7]" << endl;
	 cout << "\t * Añadir Fotografia a Usuario -------------------------[8]" << endl;
	 cout << "\t * Eliminar Fotografia a Usuario -----------------------[9]" << endl;
	 cout << "\t * Imprimir Fotografias de un Usuario ------------------[10]" << endl;
	 cout << "\t * Usuarios con Determinada Foto -----------------------[11]" << endl;
	 cout << "\t * SALIR -----------------------------------------------[12]" << endl;


	do{

		cin >> opcion;
		//cout << DEBUG << "debug: " << opcion << RESTORE << endl;

	}while(opcion < 1 || opcion > 12);

	switch(opcion){

		

		case 1:
				//cout << miTabla << endl;
				//cout << miTabla->punteroapuntero << endl;
				miTabla = inicializarTabla();
				//cout << miTabla << endl;
				//cout << miTabla->punteroapuntero << endl;
		 		break;
		/*case 2: //eliminarTabla(); break;*/

		case 3: 
		cout << "util "<< util << endl;
		imprimirTabla(miTabla->punteroapuntero, util); 
				cout << "sale " << endl;
				break;

		case 4: 
		cout << "entra " << endl;
		miTabla->punteroapuntero = insertarUsuarioEnTablaUsuarios(miTabla->punteroapuntero, miTabla->totalTuplas, util); 
				cout << "sale " << endl;
				break;
		/*case 5: //eliminarUsuario(); break;
		case 6: //buscarUsuarioPorLogin(); break;
		case 7: //ordenarTabla(); break;
		case 8: //aniadirFotoAUsuario(); break;
		case 9: //eliminarFotoAUsuario(); break;
		case 10: //imprimirFotosUsuario(); break;
		case 11: //busquedaDeterminada(); break;*/

	}


	}while(opcion != 12);

}


int main(){

	menu();
}