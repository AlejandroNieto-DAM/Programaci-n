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
void buscarUsuarioPorLogin(Usuario **q, int util);
void ordenarTablaPorTotalFotos(Usuario **q, int &util);
void ordenarTablaPorLogin(Usuario **q, int &util);
void ordenarTotalFotosoLogin(Usuario **q, int &util);
void fotoAUsuario(Usuario *a);
void aniadirFotoAUsuario(Usuario **q, int &dimension, int &util);
void imprimirFotosUsuario(Usuario **q, int &dimension, int &util);
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

/**

* @ brief Asigna a una foto una ruta que se le introduce.

*/
void setRuta(Foto &a){

	cout << "Introduce la ruta (Ejem: home/cristorey/Escritorio/imagen.png) : ";
	cin >> a.ruta;

}

/**

* @ brief Asigna a una foto su tipo que se le introduce.

*/
void setTipo(Foto &a){

	cout << "Introduce el tipo (Ejem: png, jpeg...): ";
	cin >> a.tipo;

}

/**

* @brief Asigna a una foto su tamaño que se le introduce.

*/
void setTamanio(Foto &a){

	cout << "Introduce el tamaño: ";
	cin >> a.tamanio;
}

/**

* @ brief Módulo que asigna a una posicion del vector de fotos sus correspondientes miembros.

*/
void setFoto(Foto *a, int util){

	setRuta(a[util]);
	setTipo(a[util]);
	setTamanio(a[util]);

 
}

/**

* @brief Aumenta la dimension y los utiles del vector de fotos de un usuario conforme se van introduciendo más fotos.
* @param *p que es el vector de fotos de un usuario que vamos a aumentar.
* @param dimension que es la dimension que tiene el vector de fotos del usuario.
* @param util que es el numero de fotos que hay guardadas en el vector en el momento.
* @pre Debe de haber un vector de fotos inicializado en el usuario con fotos adentro.
* @return devuelve una direccion de memoria de tipo Foto.
* @post La dimension y el util habrán crecido a la misma vez dejando asi un espacio para introducir otra foto.

*/
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

/**

* @brief Aumenta la dimension y los utiles del vector de fotos de un usuario conforme se van introduciendo más fotos.
* @param *p que es el vector de fotos de un usuario que vamos a aumentar.
* @param dimension que es la dimension que tiene el vector de fotos del usuario.
* @param util que es el numero de fotos que hay guardadas en el vector en el momento.
* @pre Debe de haber un vector de fotos inicializado en el usuario con fotos adentro.
* @return devuelve una direccion de memoria de tipo Foto.
* @post La dimension y el util habrán crecido a la misma vez dejando asi un espacio para introducir otra foto.

*/
Foto* resizeFotoDisminuir(Foto *p, int &dimension, int &util){

	int nuevaDim = dimension - 1;

	Foto *a = 0;
	a = new Foto[nuevaDim];

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

	dimension--;
	util--;

	p = a;

	a = 0;

	return p;

}

/**

* @brief Módulo que inicializa el miembro v_fotos del usuario si este tiene fotos y las introduce dentro del vector.
* @param *a que es el usuario al que le vamos a inicializar su miembro v_fotos
* @pre la direccion de memoria de este usuario debe de estar en alguna posicion del miembro punteroapuntero de miTabla tipo TablaUsuarios.
* @return no devuelve nada.
* @post El miembro v_fotos del Usuario quedara inicializado si este tiene fotos y tendra la opcion de introducir o no las fotos en este momento.

*/
void setVectorFotos(Usuario *a){

	int opcion = 0;

	cout << "Este usuario tiene fotos? [1]Si, [2]No. " << endl;
	cin >> opcion;

	
	if(opcion == 1){
		Foto *v = 0;
		v = new Foto [1];

		a->v_fotos = v;

		a->totalFotosUsuario = 0;
		a->dim_vfotos = 1;

	} else {

		a->v_fotos = 0;

		a->totalFotosUsuario = 0;
		a->dim_vfotos = -1;

	}

}

/**

* @brief Módulo que llama a otros modulos para asignar al usuario cada uno de sus miembros.
* @param *a que es el usuario al que queremos introducir valores.
* @pre Este usuario debe de haberse inicializado con anterioridad.
* @return no devuelve nada.
* @post cada uno de los miembros del usuario tomara el valor introducido.

*/
void setUsuario(Usuario *a){

	setLogin(a);
	setNombre(a);
	setApellido(a);
	setPerfil(a);
	setVectorFotos(a);
	

}

/**

* @brief Devuelve el login de un usuario.
* @return Devuelve un string que es el login.

*/
string getLogin(const Usuario *a){
	return a->login;
}

/**

* @brief Devuelve el nombre de un usuario.
* @return Devuelve un string que es el nombre.

*/
string getNombre(const Usuario *a){
	return a->nombre;
}

/**

* @brief Devuelve el apellido de un usuario.
* @return Devuelve un string que es el apellido.

*/
string getApellido(const Usuario *a){
	return a->apellido;
}

/**

* @brief Devuelve el perfil de un usuario.
* @return Devuelve un string que es el perfil del usuario.

*/
string getPerfil(const Usuario *a){
	return a->perfil_usuario;
}

/**

* @brief Devuelve la ruta de una foto.
* @return Devuelve un string que es la ruta de una foto.

*/
string getRuta(Foto &a){
	return a.ruta;
}

/**

* @brief Devuelve el tipo de una foto.
* @return Devuelve un string que es el tipo de una foto.

*/
string getTipo(Foto &a){
	return a.tipo;
}

/**

* @brief Devuelve el tamaño de una foto.
* @return Devuelve un string que es el tamaño de una foto.

*/
unsigned long int getTamanio(Foto &a){
	return a.tamanio;
}

/**

* @ brief Modulo que devuelve las fotos de un usuario.
* @ param *a que es el vector de fotos del usuario.
* @ param util que es el numero de componentes utilizadas en el vector (totalFotosUsuario)
* @ pre *a debe de haber sido inicializado previamente
* @ pre totalFotosUsuario > 0 && < DIM
* @ return no devuelve nada.
* @ post se mostrará por pantalla cada una de las fotos del usuario.  

*/
void getFoto(Foto *a, int util){

	for(int i = 0; i < util; i++){
		cout << "Foto: " << i + 1 << endl;
		cout << "Ruta: " << getRuta(a[i]) << endl;
		cout << "Tipo: " << getTipo(a[i]) << endl;
		cout << "Tamaño que ocupa: " << getTamanio(a[i]) << endl;
		cout << endl;
	}
}


/**

* @ brief Permite ver si se desea las fotos del usuario.
* @ param *a que es el usuario del que queremos ver las fotos.
* @ pre *a debe de tener su vector de fotos inicializado y al menos mantener 1 en su interior.
* @ return no devuelve nada.
* @ post Si se desea se veran todas las fotos de usuario  y si no seguirá con la ejecución de programa.

*/
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

* @ brief Imprime un usuario al completo.
* @ param *a que es el usuario que queremos mostrar por pantalla.
* @ pre *a debe de ser un usuario en una posicion existente de punteroapuntero.
* @ return no devuelve nada.
* @ post Se mostrará el usuario por pantalla. 

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

* @ brief Imprime un usuario sin las fotos.
* @ param *a que es el usuario que queremos mostrar por pantalla.
* @ pre *a debe de ser un usuario en una posicion existente de punteroapuntero.
* @ return no devuelve nada.
* @ post Se mostrará el usuario por pantalla. 

*/
void getUsuarioSinFotos(Usuario *a){

	cout << "USUARIO" << endl;
	cout << "Login: " << getLogin(a) << endl;
	cout << "Nombre: " << getNombre(a) << endl;
	cout << "Apellido: " << getApellido(a) << endl;
	cout << "Perfil del Usuario: " << getPerfil(a) << endl; 
	cout << endl;



}

/**

* @ brief Muestra el login del usuario y sus fotos.
* @ param *a que es el usuario del que queremos mostrar su login y fotos.
* @ pre *a debe de ser un usuario en una posicion existente de punteroapuntero.
* @ return no devuelve nada.
* @ param se mostrará por pantalla el login y las fotos.

*/
void getFotosUsuario(Usuario *a){
	
	cout << "USUARIO" << endl;
	cout << "Login: " << getLogin(a) << endl;
	getFotos(a); 

}

/**

* @ brief Aumenta la dimension y el util del vector de punteros **p.
* @ param **p que es el vector de punteros al que cambiaremos su dimension.
* @ param tuplas que es la dimension de **p
* @ param util que es el numero de posiciones que hay ocupadas dentro del vector de punteros.
* @ pre **p debe de tener algo en su interior para acceder a este modulo.
* @ pre tuplas > 0
* @ pre util > 0 
* @ return no devuelve nada.
* @ post el numero de tuplas y utiles de **p será aumentado en 1.

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

* @ brief Disminuye la dimension y el util del vector de punteros **p.
* @ param **p que es el vector de punteros al que cambiaremos su dimension.
* @ param tuplas que es la dimension de **p
* @ param util que es el numero de posiciones que hay ocupadas dentro del vector de punteros.
* @ pre **p debe de tener algo en su interior para acceder a este modulo.
* @ pre tuplas > 0
* @ pre util > 0 
* @ return no devuelve nada.
* @ post el numero de tuplas y utiles de **p será disminuido en 1.

*/
Usuario** resizeDisminuir(Usuario **p, int &tuplas, int &util){

	int nuevaDim = tuplas - 1;

	Usuario **a;
	a = new Usuario*[nuevaDim];

	if (a == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

	for(int i = 0; i < util; i++){
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

* @ brief Inicia un puntero de tipo usuario al que se le asigna una dirección de memoria.
* @ param *a que es el usuario al que asignaremos la posicion.
* @ pre *a debe de ser una posicion en un vector de punteros.
* @ return devuelve un puntero a usuario.
* @ post la direccion de memoria que se retorna se guarda en un vector de punteros a punteros.

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

* @ brief Inserta un usuario en el puntero a puntero de una variable tipo TablaUsuarios y hace un resize del mismo.
* @ param **a que es el miembro punteroapuntero de una varible de tipo TablaUsuarios
* @ param dimension que es el miembro totalTuplas de una variable de tipo TablaUsuarios.
* @ param util que es el numero de componentes ocupados en el miembro **a
* @ pre todos estos componentes deben de haber sidos inicializados anteriormente.
* @ return devuelve una direccion de memoria de tipo puntero a puntero 
* @ post **a cambiará su dirección de memoria por una nueva después del resize.


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

* @ brief Muestra todos los usuarios guardados en la tabla.
* @ param **a que es el vector que guarda los usuarios.
* @ param util que es el numero de usuarios total en el vector.
* @ pre util > 0.
* @ return no devuelve nada.
* @ post Se mostrarán todos los usuarios al completo.

*/
void imprimirTabla(Usuario **a, int util){


	for(int i = 0; i < util; i++){
		getUsuario(a[i]);
	}	

}


/**

* @ brief Muestra todos los usuarios guardados en la tabla sin fotos.
* @ param **a que es el vector que guarda los usuarios.
* @ param util que es el numero de usuarios total en el vector.
* @ pre util > 0.
* @ return no devuelve nada.
* @ post Se mostrarán todos los usuarios sin fotos.

*/
void imprimirTablaSinFotos(Usuario **a, int util){


	for(int i = 0; i < util; i++){
		getUsuarioSinFotos(a[i]);
	}	

}


/**

* @ brief Muestra un usuario en concreto al completo.
* @ param **a que es el vector que guarda los usuarios.
* @ param pos que es la posicion del usuario en concreto que queremos ver.
* @ pre pos >= 0 && < totalTuplas.
* @ return no devuelve nada.
* @ post Se mostrará el usuario indicado al completo.

*/
void imprimirTablaUser(Usuario **a, int pos){

	getUsuario(a[pos]);

}

/**

* @ brief Busca el usuario que introduzcan mediante su login en toda la tabla y te lo muestra al completo.
* @ param **q que es el vector de usuarios donde vamos a buscar.
* @ param util que es el numero de usuarios dentro del vector.
* @ pre util > 0.
* @ return no devuelve nada.
* @ post Buscará un usuario en la tabla de usuarios y lo mostrará al completo.

*/
void buscarUsuarioPorLogin(Usuario **q, int util){

	string login;
	int opcion = 0;
	bool encontrado = false;
	int posicion = 0;

	imprimirTablaSinFotos(q, util);

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

/**

* @ brief Ordena la tabla por el numero total de fotos del usuario.
* @ param **q que es el vector que vamos a ordenar.
* @ param util que es el numero de usuarios total.
* @ pre util > 0
* @ return no devuelve nada
* @ post el vector quedará ordenado por el numero total de fotos.

*/
void ordenarTablaPorTotalFotos(Usuario **q, int &util){

	Usuario *auxiliar;

	auxiliar = new Usuario;


	for(int i = 0; i < util; i++){
		for(int j = 0; j < util; j++){

			if(q[i]->totalFotosUsuario > q[j]->totalFotosUsuario){

				auxiliar = q[i];
				q[i] = q[j];
				q[j] = auxiliar;

			}

		}
	}

	cout << "Ya se ha ordenado correctamente. " << endl;
	cout << "********************************" << endl;

	imprimirTablaSinFotos(q, util);



}

/**

* @ brief Ordena la tabla alfabeticamente segun el login.
* @ param **q que es el vector que vamos a ordenar.
* @ param util que es el numero de usuarios total.
* @ pre util > 0
* @ return no devuelve nada
* @ post el vector quedará ordenado alfabeticamente.

*/
void ordenarTablaPorLogin(Usuario **q, int &util){

	Usuario *auxiliar;

	auxiliar = new Usuario;

	char cadena[20];
	char cadena2[20];


	for(int i = 0; i < util; i++){
		for(int j = 0; j < util; j++){

			strcpy(cadena, (q[i]->login).c_str());
			strcpy(cadena2, (q[j]->login).c_str());

			if(strcmp(cadena, cadena2) < 0){

				auxiliar = q[i];
				q[i] = q[j];
				q[j] = auxiliar;

			}

		}
	}

	cout << "Ya se ha ordenado correctamente. " << endl;
	cout << "********************************" << endl;

	imprimirTablaSinFotos(q, util);

}

/**

* @ brief Módulo que muestra las opciones de ordenar que hay.
* @ param **q que es vector de usuarios que ordenaremos por su total de fotos o alfabeticamente.
* @ param util que es el numero de usuarios en el interior del vector de usuarios.
* @ pre util > 0
* @ return no devuelve nada.
* @ post el vector quedará ordenado segun el parametro indicado.

*/
void ordenarTotalFotosoLogin(Usuario **q, int &util){

	int opcion = 0;

	cout << "Se procederá a ordenar su tabla: " << endl;
	cout << "********************************" << endl;
	cout << "[1] Ordenar por numero total de fotos. " << endl;
	cout << "[2] Ordenar alfabeticamente. " << endl;

	do{
		cin >> opcion;
	}while(opcion != 2 && opcion != 1);

	if(opcion == 1){
		ordenarTablaPorTotalFotos(q, util);
	} else {
		ordenarTablaPorLogin(q, util);
	}


}


/**

* @ brief Añade una foto al usuario y hace un resize del vector de fotos.
* @ param *a que es el usuario al que le queremos añadir las fotos.
* @ pre *a debe de ser un usuario que esté dentro del puntero a puntero.
* @ return no devuelve nada.
* @ post el usuario tendrá fotos añadidas y su vector de fotos aumentará tantas como se le añadan.

*/
void fotoAUsuario(Usuario *a){
			
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

/**

* @ brief Añade una foto al vector de fotos del usuario.
* @ param **q que es el vector donde estan todos los usuarios.
* @ param dimension que nos servirá para ver que usuario tiene fotos y se le pueden añadir y cual no.
* @ param util que es el numero de usuarios total que hay.
* @ pre util > 0
* @ return no devuelve nada.
* @ post al usuario escogido se le añadiran las fotos que se quieran si es que tiene.

*/
void aniadirFotoAUsuario(Usuario **q, int &dimension, int &util){

	int posicion = 0;
	int opcion = 0;
	string login;
	bool encontrado = false;

	imprimirTablaSinFotos(q, util);
	do{
		cout << "A que usuario quieres introducirle la foto? Introduce su login: "; 
		cin >> login;

		for(int i = 0; i < util || encontrado == false; i++){

				//cout << "iteracion: " << i << endl;

				if(login == q[i]->login){
					encontrado = true;
					posicion = i;
				}

		}

	}while(encontrado == false);

	if(q[posicion]->dim_vfotos != -1){
		do{

			fotoAUsuario(q[posicion]);

			cout << "Quiere introducir otra foto? [1]Si, [2]No..."; cin >> opcion;

		}while(opcion == 1);
	} else {
		cout << "Este usuario no tiene fotos :(( " << endl;
	}


}

/**

* @ brief Muestra las fotos de un usuario en concreto.
* @ param **q que es el vector donde estan todos los usuarios.
* @ param dimension que nos servirá para ver que usuario tiene fotos y cual no.
* @ param util que es el numero de usuarios total que hay.
* @ pre util > 0
* @ return no devuelve nada.
* @ post Imprimirá las fotos del usuario escogido si tiene.

*/
void imprimirFotosUsuario(Usuario **q, int &dimension, int &util){

	
	int posicion = 0;
	bool encontrado = false;
	string login;

	imprimirTablaSinFotos(q, util);

	do{
		cout << "De que usuario quieres ver la/s foto/s? Introduce su login: "; 
		cin >> login;

	
		for(int i = 0; i < util || encontrado == false; i++){

				//cout << "iteracion: " << i << endl;

				if(login == q[i]->login){
					encontrado = true;
					posicion = i;
				}

		}
	}while(encontrado == false);

	if(q[posicion]->dim_vfotos != -1 && q[posicion]->dim_vfotos > 1){
		imprimirTablaUser(q, posicion);
	} else {
		cout << "Este usuario no tiene fotos :(( " << endl;
	}

}

void intercambiarFotos(Foto *a, int posicion, int util){

	//cout << "pos " << posicion << endl;
	//cout << "totalFotos" << util << endl;

	a[posicion] = a[util];

}

void borrarFoto(Foto *a, int posicion){


	a[posicion].ruta = "";
	a[posicion].tipo = "";
	a[posicion].tamanio = 0;
	


}

void borrarfotoAUsuario(Usuario *a){

	int posicion = 0;
	
	cout << "Que foto quiere borrar? Introduce su posicion: "; cin >> posicion;
	intercambiarFotos(a->v_fotos, posicion, a->totalFotosUsuario);
	borrarFoto(a->v_fotos, a->totalFotosUsuario);
	
	//cout << "dim: " << a->dim_vfotos << endl;
	//cout << "totalf: " << a->totalFotosUsuario << endl;
	a->v_fotos = resizeFotoDisminuir(a->v_fotos, a->dim_vfotos, a->totalFotosUsuario);
	//cout << "dim: " << a->dim_vfotos << endl;
	//cout << "totalf: " << a->totalFotosUsuario << endl;
}

/**
*
*/
void eliminarFotoAUsuario(Usuario **q, int &dimension, int &util){

	int posicion = 0;
	int opcion = 0;
	string login;
	bool encontrado = false;

	imprimirTablaSinFotos(q, util);
	do{
		cout << "A que usuario quieres borrarle foto/s? Introduce su login: "; 
		cin >> login;

		for(int i = 0; i < util || encontrado == false; i++){

				//cout << "iteracion: " << i << endl;

				if(login == q[i]->login){
					encontrado = true;
					posicion = i;
				}

		}

	}while(encontrado == false);

	if(q[posicion]->dim_vfotos != -1){
		do{

			imprimirTablaUser(q, posicion);
			borrarfotoAUsuario(q[posicion]);
			if(q[posicion]->dim_vfotos > 1){
			cout << "Quiere borrar otra foto? [1]Si, [2]No..."; cin >> opcion;
			}

		}while(opcion == 1);
	} else {
		cout << "Este usuario no tiene fotos :(( " << endl;
	}

}


void setUsuarioCero(Usuario *a){

	a->login = "";
	a->nombre = "";
	a->apellido = "";
	a->perfil_usuario = "";

	for(int i = 0; i < a->totalFotosUsuario; i++){
		borrarFoto(a->v_fotos, i);
	}

	a->v_fotos = 0;
	a->dim_vfotos = 0;
	a->totalFotosUsuario = 0;



}

Usuario** eliminarUsuario(Usuario **q, int &dimension, int &util){

	int posicion = 0;
	string login;
	bool encontrado = false;

	imprimirTablaSinFotos(q, util);
	do{
		cout << "A que usuario quieres borrarle foto/s? Introduce su login: "; 
		cin >> login;

		for(int i = 0; i < util || encontrado == false; i++){

				//cout << "iteracion: " << i << endl;

				if(login == q[i]->login){
					encontrado = true;
					posicion = i;
				}

		}

	}while(encontrado == false);

	if(util > 1){

		q[posicion] = q[util-1];
		q[util - 1] = 0;
		

	}else{

		setUsuarioCero(q[posicion]);

	}


	//cout << "dim: " << dimension << endl;
	//cout << "util: "<< util << endl;
	q = resizeDisminuir(q, dimension, util);
	//cout << "dim: " << dimension <<endl;
	//cout << "util: "<< util << endl;

	return q;

	cout << "********* El usuario ha sido eliminado exitosamente. **********" << endl;;
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


    cout << "********* Su tabla ha sido inicializada. **********" << endl;

    return  q;

}

void eliminarUsuarios(Usuario **q, int &dimension, int &util){

	for(int i = 0; i < util; i++){
		setUsuarioCero(q[i]);
	}

}

void eliminarTabla(TablaUsuarios *a, int &util){

	eliminarUsuarios(a->punteroapuntero, a->totalTuplas, util);

	cout << "********* Su tabla ha sido eliminada exitosamente. **********" << endl;;

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
	 cout << "* Para Eliminar Tabla Usuarios ------------------------[2]" << endl;
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
				cout << "Primero debes crear la tabla O.o Pulsa [1]..." << endl;
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
		case 2: 

			eliminarTabla(miTabla, util); 
			delete miTabla;
			miTabla = 0;

			primeraOpcion = true;
			tablaCreada = false;

			break;

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
			miTabla->punteroapuntero = eliminarUsuario(miTabla->punteroapuntero, miTabla->totalTuplas, util); 
			//cout << "sale " << endl;
			break;

		case 6: buscarUsuarioPorLogin(miTabla->punteroapuntero, util); break;
		case 7: ordenarTotalFotosoLogin(miTabla->punteroapuntero, util); break;
		case 8: aniadirFotoAUsuario(miTabla->punteroapuntero, miTabla->totalTuplas, util); break;
		case 9: eliminarFotoAUsuario(miTabla->punteroapuntero, miTabla->totalTuplas, util); break;
		case 10: imprimirFotosUsuario(miTabla->punteroapuntero, miTabla->totalTuplas, util); break;
		//case 11: busquedaDeterminada(); break;
		case 12: cout << "******** Gracias por haber utilizado el programa :) *********" << endl; break;

	}


	}while(opcion != 12);

}


int main(){

	menu();
}