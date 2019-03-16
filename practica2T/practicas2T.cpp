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

/********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Foto **
 ********************************************************/
void setRuta(Foto &a);
void setTipo(Foto &a);
void setTamanio(Foto &a);
void setFoto(Foto *a, int util);
string getRuta(Foto &a);
string getTipo(Foto &a);
unsigned long int getTamanio(Foto &a);
void getFoto(Foto *a, int util);





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

/***********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Usuario **
 ***********************************************************/
void setNombre(Usuario *a);
void setApellido(Usuario *a);
void setLogin(Usuario *a);
void setPerfil(Usuario *a);
Foto* resizeFoto(Foto *p, int &dimension, int &util);
void setVectorFotos(Usuario *a);
void setUsuario(Usuario *a);
string getLogin(const Usuario *a);
string getNombre(const Usuario *a);
string getPerfil(const Usuario *a);
string getApellido(const Usuario *a);
void getFotos(Usuario *a);
void getUsuario(Usuario *a);
Usuario* iniciaPersona(Usuario *a);




/**********************************************
** Definición del TIPO DE DATO TablaUsuarios **
***********************************************/

struct TablaUsuarios{

    Usuario **punteroapuntero;//Vector dinámico de punteros.
    int totalTuplas; 
    
};

/*****************************************************************
 ** Definición de sus Prototipos del Tipo de Dato TablaUsuarios **
 *****************************************************************/
Usuario** resizeAumentar(Usuario **p, int &tuplas, int &util);
Usuario** resizeDisminuir(Usuario **p, int &tuplas, int &util);
Usuario** insertarUsuarioEnTablaUsuarios(Usuario **a, int &dimension, int &util);
void imprimirTabla(Usuario **a, int util);
void buscarUsuarioPorLogin(Usuario **q, int dimension, int util);
TablaUsuarios* inicializarTabla();
void menu();

/**

* @brief Asigna un nombre que se introduce a un usuario.

*/
void setNombre(Usuario *a){
	cout << "Introduce el nombre: ";
	cin >> a->nombre;
	cout << endl;
}

/**

* @brief Asigna un apellido que se introduce a un usuario.

*/
void setApellido(Usuario *a){
	cout << "Introduce el apellido: ";
	cin >> a->apellido;
	cout << endl;
}

/**

* @brief Asigna un Login único que se introduce a un usuario.

*/
void setLogin(Usuario *a){
	cout << "Introduce el login: ";
	cin >> a->login;
	cout << endl;
}

/**

* @brief Asigna un perfil_usuario que se introduce al usuario filtrandolo ya que solo puede ser Admin o User.

*/
void setPerfil(Usuario *a){
	string admin = "Admin";
	string user = "User";
	bool correcto = true;
	do{

		correcto = true;

		cout << "Introduce el perfil_usuario [Admin] o [User]: ";
		cin >> a->perfil_usuario;
		cout << endl;

		if(a->perfil_usuario != admin && a->perfil_usuario != user){
			correcto = false;
			cout << "El perfil_usuario solo puede ser [Admin] o [User], Try again...";
		}

	}while(correcto == false);
	
}



void setNombre0(Usuario *a){
	a->nombre = "0";

}
void setApellido0(Usuario *a){
	a->apellido = "0";
}
void setLogin0(Usuario *a){
	
	a->login = "0";
	
}
void setPerfil0(Usuario *a){

	
	a->perfil_usuario = "0";
	
}



/**

* @ brief Asigna a una foto una ruta que se le introduce.

*/
void setRuta(Foto &a){

	cout << "Introduce la ruta (Ejem: home/cristorey/Escritorio/imagen.png) : ";
	cin >> a.ruta;

}

void setTipo(Foto &a){

	cout << "Introduce el tipo: ";
	cin >> a.tipo;

}
void setTamanio(Foto &a){

	cout << "Introduce el tamaño: ";
	cin >> a.tamanio;
}

void setFoto(Foto *a, int util){

	setRuta(a[util]);
	setTipo(a[util]);
	setTamanio(a[util]);

 
}

Foto* resizeFoto(Foto *p, int &dimension, int &util){

	int nuevaDim = dimension + 1;

	Foto *a = 0;
	a = new Foto[nuevaDim];

	if (a == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }


	for(int i = 0; i < dimension; i++){
		a[i] = p[i];
	}


	//cout << "del: " << endl;
	delete [] p;
	//cout << "asig: " << endl;

	dimension++;
	util++;

	p = a;

	a = 0;

	return p;

}


void setVectorFotos(Usuario *a){

	unsigned short int opcion = 0;
	unsigned short int opcion2 = 0;

	cout << "Este usuario tiene fotos? [1]Si, [2]No. " << endl;
	cin >> opcion;

	if(opcion == 1){

		Foto *v = 0;
		v = new Foto [1];

		a->v_fotos = v;

		a->totalFotosUsuario = 0;
		a->dim_vfotos = 1;

		//a->v_fotos = inicializarVectorFotos(a->v_fotos, a->dim_vfotos, a->totalFotosUsuario);

	}


	if(opcion == 1){

		do{

			cout << "Quiere añadir foto? [1]Si, [2]No: ";
			cin >> opcion2;
			cout << endl;

			if(opcion2 == 1){
				//cout << "util fuera: " << a->totalFotosUsuario << endl;
				//cout << "dim fuera: " << a->dim_vfotos << endl;
				setFoto(a->v_fotos, a->totalFotosUsuario);
				//cout << "sale " << endl;

				//cout << "dim: " << a->dim_vfotos << endl;
				//cout << "totalf: " << a->totalFotosUsuario << endl;
				a->v_fotos = resizeFoto(a->v_fotos, a->dim_vfotos, a->totalFotosUsuario);
				//cout << "dim: " << a->dim_vfotos << endl;
				//cout << "totalf: " << a->totalFotosUsuario << endl;
			}

		}while(opcion2 != 2);

	}

}


void setUsuario(Usuario *a){

	setLogin(a);
	setNombre(a);
	setApellido(a);
	setPerfil(a);
	setVectorFotos(a);
	

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


string getRuta(Foto &a){
	return a.ruta;
}
string getTipo(Foto &a){
	return a.tipo;
}
unsigned long int getTamanio(Foto &a){
	return a.tamanio;
}

void getFoto(Foto *a, int util){

	for(int i = 0; i < util; i++){
		cout << "Foto: " << i + 1 << endl;
		cout << "Ruta: " << getRuta(a[i]) << endl;
		cout << "Tipo: " << getTipo(a[i]) << endl;
		cout << "Tamaño que ocupa: " << getTamanio(a[i]) << endl;
		cout << endl;
	}
}




void getFotos(Usuario *a){

	int opcion = 0;

	if(a->totalFotosUsuario > 0){
		cout << "Quieres ver las fotos que guarda el usuario? [1]Si, [Press any int key]No: ";
		cin >> opcion;
	}

	if(opcion == 1)
		getFoto(a->v_fotos, a->totalFotosUsuario);

}

/**
*
*/
void getUsuario(Usuario *a){

	cout << "USUARIO" << endl;
	cout << "Login: " << getLogin(a) << endl;
	cout << "Nombre: " << getNombre(a) << endl;
	cout << "Apellido: " << getApellido(a) << endl;
	cout << "Perfil del Usuario: " << getPerfil(a) << endl;
	getFotos(a); 
	cout << endl;



}

/**
*
*/
Usuario** resizeAumentar(Usuario **p, int &tuplas, int &util){

	int nuevaDim = tuplas + 1;

	Usuario **a;
	a = new Usuario *[nuevaDim];

	if (a == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

	for(int i = 0; i < tuplas; i++){
		a[i] = p[i];
	}

	delete [] p;

	tuplas = nuevaDim;
	util++;


	p = a;

	a = 0;

	return p;



}


/**
*
*/
Usuario** resizeDisminuir(Usuario **p, int &tuplas, int &util){

	int nuevaDim = tuplas - 1;

	Usuario **a;
	a = new Usuario*[nuevaDim];

	if (a == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

	for(int i = 0; i < tuplas; i++){
		a[i] = p[i];
	}

	delete [] p;

	tuplas = nuevaDim;
	util--;

	p = a;

	a = 0;

	return p;

}


/**
*
*/
 Usuario* iniciaPersona(Usuario *a){

	a = new Usuario;


	if (a == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

	//cout << a << endl;
	return a;
	
	
}

/**
*
*/
Usuario** insertarUsuarioEnTablaUsuarios(Usuario **a, int &dimension, int &util){

	bool repetido = false;

	do{

		repetido = false;
		//cout << "entra I  " << endl;
		a[util] = iniciaPersona(a[util]);
		//cout << "sale  " << endl;

		//cout << "entra SU  " << endl;
		setUsuario(a[util]);
			//cout << "sale " << endl;
		for(int i = 0; i < util; i++){
			if(a[util]->login == a[i]->login){
				repetido = true;
				cout << "Ese login ya está en uso :( Try again... " << endl;
			}

		}

	}while(repetido == true);


	//cout << "dim: " << dimension << endl;
	//cout << "util: "<< util << endl;
	a = resizeAumentar(a, dimension, util);
	//cout << "dim: " << dimension <<endl;
	//cout << "util: "<< util << endl;

	return a;
	
	
}

/**
*
*/

void imprimirTabla(Usuario **a, int util){


	for(int i = 0; i < util; i++){
		getUsuario(a[i]);
	}	

}

void asignarACero(Usuario *a){

	

	if(a->dim_vfotos > 0){

		for(int i = 0; i < a->dim_vfotos; i++){
			a->v_fotos = 0;
			//resizeFoto(a->v_fotos);
		}

	}
	
	setLogin0(a);
	setNombre0(a);
	setApellido0(a);
	setPerfil0(a);

}



/**
*
*/
void cambiarPosicionUsuario(Usuario *a, Usuario *b){

	a->login = b->login;
	a->nombre = b->nombre;
	a->apellido = b->apellido;
	a->perfil_usuario = b->perfil_usuario;
	a->v_fotos = b->v_fotos;
	a->dim_vfotos = b->dim_vfotos;
	a->totalFotosUsuario = b->totalFotosUsuario;


}

void intercambiarUsuarios(Usuario *a, Usuario *b){

	Usuario *auxiliar = 0;
	auxiliar = new Usuario;

	Foto *auxiliar2 = 0;
	auxiliar2 = new Foto [b->dim_vfotos];

	auxiliar->v_fotos = auxiliar2;

	cambiarPosicionUsuario(auxiliar, b);
	cambiarPosicionUsuario(b, a);
	cambiarPosicionUsuario(a, auxiliar);

	delete auxiliar;
	delete [] auxiliar2;

	auxiliar = 0;
	auxiliar2 = 0;

}

/**
*
*/
void eliminarUsuario(Usuario **a, int &dimension, int &util){

	string login;
	int opcion = 0;
	bool encontrado = false;

	imprimirTabla(a, util);

	cout << "Que usuario quiere eliminar? Escriba su login a continuacion: "; cin >> login;

	for(int i = 0; i < util; i++){

			if(login == a[i]->login){
				getUsuario(a[i]);
				
				
				cout << "Quieres eliminarlo? [1]Si, [Press any int key]No: "; cin >> opcion;
				if(opcion == 1){	
					asignarACero(a[i]);
					intercambiarUsuarios(a[i], a[util]);
					//resizeDisminuir(a, dimension, util);
				}


			}

	}


}


void buscarUsuarioPorLogin(Usuario **q, int dimension, int util){

	string login;
	int opcion = 0;
	bool encontrado = false;
	int posicion = 0;

	imprimirTabla(q, util);

	cout << "Que usuario quiere buscar? Escriba su login a continuacion: "; cin >> login;

	for(int i = 0; i < util || encontrado == false; i++){

			//cout << "iteracion: " << i << endl;

			if(login == q[i]->login){
				encontrado = true;
				posicion = i;
			}


	}

	if(encontrado == true){
		getUsuario(q[posicion]);
	} else {
		cout << "No se ha encontrado el usuario con el login especificado :( " << endl;
	}


}

void ordenarTablaPorTotalFotos(Usuario **q, int &dimension, int &util){

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
    q->totalTuplas = 5;

    Usuario **a = 0;
    a = new Usuario*[q->totalTuplas];

    //cout << "debug " << a << endl;

    q->punteroapuntero = a;

    //cout << "debug " << q->punteroapuntero << endl;


    cout << "********* Su tabla ha sido inicializada. **********" << endl;;

    return  q;

}




/**

* @brief Menu que se le mostrará al usuario por pantalla.

*/
void menu(){


	unsigned short int opcion;
	TablaUsuarios *miTabla;
	int util = 0;
	bool tablaCreada = false;
	bool primeraOpcion = true;

	do{

	 cout << "\nBIENVENIDO AL PROGRAMA DE LA PRACTICA FINAL DEL 2º TRIMESTRE." << endl;
	 cout << "*************************************************************" << endl;
	 cout << "* Elija una de las siguientes opciones: " << endl;
	 cout << "* Para Crear Tabla Usuarios ---------------------------[1]" << endl;
	 cout << "* Para Imprimir Tabla Usuarios ------------------------[3]" << endl;
	 cout << "* Para Insertar Usuario en Tabla Usuarios -------------[4]" << endl;
	 cout << "* Para Eliminar Usuario en Tabla Usuarios -------------[5]" << endl;
	 cout << "* Buscar Usuarios por Login ---------------------------[6]" << endl;
	 cout << "* Ordenar Tabla Usuarios por totalFotosUsuario o Login-[7]" << endl;
	 cout << "* Añadir Fotografia a Usuario -------------------------[8]" << endl;
	 cout << "* Eliminar Fotografia a Usuario -----------------------[9]" << endl;
	 cout << "* Imprimir Fotografias de un Usuario ------------------[10]" << endl;
	 cout << "* Usuarios con Determinada Foto -----------------------[11]" << endl;
	 cout << "* SALIR -----------------------------------------------[12]" << endl;


	if(primeraOpcion == true){

		do{

			cin >> opcion;

			if(opcion == 1 || opcion == 12){
				tablaCreada = true;
			} else {
				cout << "Primero debes crear la tabla O.o" << endl;
			}

		}while(tablaCreada == false);

		primeraOpcion = false;

	} else {

		do{

			cin >> opcion;
			//cout << DEBUG << "debug: " << opcion << RESTORE << endl;
		}while(opcion < 2 || opcion > 12);

	}



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
			//cout << "dim "<< miTabla->punteroapuntero[0]->totalFotosUsuario << endl;
			imprimirTabla(miTabla->punteroapuntero, util); 
			//cout << "sale " << endl;
			break;

		case 4: 
			
			miTabla->punteroapuntero = insertarUsuarioEnTablaUsuarios(miTabla->punteroapuntero, miTabla->totalTuplas, util); 
			
			break;

		case 5: 
			//cout << "entra " << endl;
			eliminarUsuario(miTabla->punteroapuntero, miTabla->totalTuplas, util); 
			//cout << "sale " << endl;
			break;

		case 6: buscarUsuarioPorLogin(miTabla->punteroapuntero, miTabla->totalTuplas, util); break;
		case 7: ordenarTablaPorTotalFotos(miTabla->punteroapuntero, miTabla->totalTuplas, util); break;
		//case 8: aniadirFotoAUsuario(); break;
		//case 9: eliminarFotoAUsuario(); break;
		//case 10: imprimirFotosUsuario(); break;
		//case 11: busquedaDeterminada(); break;
		case 12: cout << "******** Gracias por haber utilizado el programa :) *********" << endl; break;

	}


	}while(opcion != 12);

}


int main(){

	menu();
}