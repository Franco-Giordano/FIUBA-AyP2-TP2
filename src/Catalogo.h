/*
 * CatalogoDeTemplate.h
 *
 *  Created on: 20 may. 2018
 *      Author: frank
 */

#ifndef SRC_CATALOGO_H_
#define SRC_CATALOGO_H_


#include "Lista.h"
#include "ConversorDeDatos.h"


//Representa TODOS los tipos de <objetos> disponibles en el juego. (Ej: Papa, Zanahoria, Soja, etc...)
template <class T>
class CatalogoDe {
private:
	unsigned int cantidadDisponible;
	T* catalogo;

public:


	CatalogoDe(Lista<std::string*>* datosCSV) {
		cantidadDisponible = datosCSV->contarElementos();
		catalogo = new T[cantidadDisponible];

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


	T* obtenerPosicion(ui pos) {
		return &catalogo[pos];
	}


	unsigned int obtenerCantidadDisponible() {
		return cantidadDisponible;
	}


	~CatalogoDe() {
		delete[] catalogo;
	}


};


#endif /* SRC_CATALOGO_H_ */
