#ifndef CATALOGO_H_
#define CATALOGO_H_

#include "Lista.h"
#include "ConversorDeDatos.h"

template<class T>
class CatalogoDe {
private:

	unsigned int cantidadDisponible;
	T* catalogo;

public:

	/*
	 * Pre: recibe una lista de arrays strings que cada elemento de la lista representa una fila, y cada
	 * posicion del arrays representa su respectiva columna.
	 * Post: crea un catalogo generico con una clase "T", la cual recibe en el momento en que se crea.
	 *  Este catalogo es un vector dinamico implementado para aprovechar la forma de obtencion de la posicion
	 *  de este mismo.
	 */
	CatalogoDe(Lista<std::string*>* datosCSV);

	// Pre: recibe la posicion que se desea obtener del catalogo.
	// Post: devuelve la referencia a la posicion en el catalogo.
	T* obtenerPosicion(unsigned int pos);

	// Post: devuelve el numero de parametros que posee el catalogo.
	unsigned int obtenerCantidadDisponible();

	// Post: libera la memoria que uso el catalogo.
	~CatalogoDe();
};

template<class T>
CatalogoDe<T>::CatalogoDe(Lista<std::string*>* datosCSV) {

	this->cantidadDisponible = datosCSV->contarElementos();
	this->catalogo = new T[cantidadDisponible];

	ConversorDeDatos conversor;

	datosCSV->iniciarCursor();
	std::string* datosObjActual;

	int posicion = 0;
	while (datosCSV->avanzarCursor()) {
		datosObjActual = datosCSV->obtenerCursor();

		T objActual;
		conversor.convertirAobjeto(datosObjActual, objActual);

		catalogo[posicion] = objActual;
		posicion++;
	}
}

template<class T>
T* CatalogoDe<T>::obtenerPosicion(unsigned int pos) {

	return &catalogo[pos];
}

template<class T>
unsigned int CatalogoDe<T>::obtenerCantidadDisponible() {

	return cantidadDisponible;
}

template<class T>
CatalogoDe<T>::~CatalogoDe() {

	delete[] catalogo;
}

#endif /* CATALOGO_H_ */
