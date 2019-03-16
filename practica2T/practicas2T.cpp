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





void setRuta(Foto *a){

	cout << "Introduce la ruta: ";
	cin >> a->ruta;

}

void setTipo(Foto *a){

	cout << "Introduce el tipo: ";
	cin >> a->tipo;

}
void setTamanio(Foto *a){

	cout << "Introduce el tamaño: ";
	cin >> a->tamanio;
}

void setFoto(Foto *a){

	Foto *b;
	b = new Foto;

	setRuta(b);
	setTipo(b);
	setTamanio(b);

	a = b;

	delete b;
	b = 0;
 
}

void resizeFoto(Foto *p, int &dimension, int &util){

	int nuevaDim = dimension + 1;

	Foto *a = 0;
	a = new Foto [nuevaDim];

	if (a == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }


	for(int i = 0; i < util; i++){
		a[i] = p[i];
	}


	//cout << "del: " << endl;
	delete [] p;
	//cout << "asig: " << endl;

	dimension = nuevaDim;
	util++;

	p = a;

	a = 0;

}

/**
*
*/

void inicializarVectorFotos(Foto *a, int &dimension, int &util){

	Foto *v = 0;
	v = new Foto [1];

	dimension = 1;
	util = 0;

	if (v == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }



    delete [] a;

    //cout << a << endl;
    //cout << v << endl;
	a = v;

	v = 0;
	//cout << a << endl;


}

void aniadirFotoAUsuario(Foto *p, int &dimension, int &util){


	setFoto(&(p[util]));
	//cout << "sale " << endl;
	
	cout << "dim: " << dimension << endl;
	cout << "util: " << util << endl;
	resizeFoto(p, dimension, util);
	cout << "dim: " << dimension << endl;
	cout << "util: " << util << endl;


}

void setVectorFotos(Usuario *a){

	unsigned short int opcion = 0;
	unsigned short int opcion2 = 0;

	cout << "Este usuario tiene fotos? [1]Si, [2]No. " << endl;
	cin >> opcion;

	if(opcion == 1){
		inicializarVectorFotos(a->v_fotos, a->dim_vfotos, a->totalFotosUsuario);

	}


	if(opcion == 1){

		do{

			cout << "Quiere añadir foto? [1]Si, [2]No: ";
			cin >> opcion2;
			cout << endl;

			if(opcion2 == 1)
				aniadirFotoAUsuario(a->v_fotos, a->dim_vfotos, a->totalFotosUsuario);

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


string getRuta(Foto *a){
	return a->ruta;
}
string getTipo(Foto *a){
	return a->tipo;
}
unsigned long int getTamanio(Foto *a){
	return a->tamanio;
}

void getFoto(Foto *a, int util){

	for(int i = 0; i < util; i++){
		cout << "Foto: " << i + 1 << endl;
		cout << "Ruta: " << getRuta(&(a[i])) << endl;
		cout << "Tipo: " << getTipo(&(a[i])) << endl;
		cout << "Tamaño que ocupa: " << getTamanio(&(a[i])) << endl;
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
		getFoto(a->v_fotos, a->dim_vfotos);

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
void resizeAumentar(Usuario **p, int &tuplas, int &util){

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



}


/**
*
*/
void resizeDisminuir(Usuario **p, int &tuplas, int &util){

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

	//cout << "entra I  " << endl;
	a[util] = iniciaPersona(a[util]);
	//cout << "sale  " << endl;

	//cout << "entra SU  " << endl;
	setUsuario(a[util]);
	//cout << "sale " << endl;


	cout << "dim: " << dimension << endl;
	cout << "util: "<< util << endl;
	resizeAumentar(a, dimension, util);
	cout << "dim: " << dimension <<endl;
	cout << "util: "<< util << endl;

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

void resizeVector(int *a, int &util){

	int nuevaDim = util + 1;

	int *b = 0;
	b = new int [nuevaDim];

	for(int i = 0; i < util; i++){
		b[i] = a[i];
	}

	delete [] a;

	util = nuevaDim;

	a = b;

	b = 0;

}

void buscarUsuarioPorLogin(Usuario **q, int dimension, int util){

	string login;
	int opcion = 0;
	bool encontrado = false;

	int util_v = 0;
	int *v = 0;
	v = new int [util_v];	

	imprimirTabla(q, util);

	cout << "Que usuario quiere buscar? Escriba su login a continuacion: "; cin >> login;

	for(int i = 0; i < util; i++){

			if(login == q[i]->login){
				v[i] = i;
				//cout << "util_v " << util_v << endl;
				resizeVector(v, util_v);
				//cout << "util_v " << util_v << endl;
			}

	}

	if(util_v != 0){

		for(int i = 0; i < util_v; i++){
			getUsuario(q[v[i]]);
		}

	} else {

		 cout << "No hemos encontrado el usuario introducido :( " << endl;
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


    cout << "Su tabla ha sido inicializada." << endl;;

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

	 cout << "\t BIENVENIDO AL PROGRAMA DE LA PRACTICA FINAL DEL 2º TRIMESTRE." << endl;
	 cout << "\t * Elija una de las siguientes opciones: " << endl;
	 cout << "\t * Para Crear Tabla Usuarios ---------------------------[1]" << endl;
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
			//cout << "util "<< util << endl;
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