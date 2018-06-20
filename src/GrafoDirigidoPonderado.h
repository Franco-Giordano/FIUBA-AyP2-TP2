/*
 * GrafoOrientado.h
 *
 *  Created on: 20 jun. 2018
 *      Author: frank
 */

#ifndef SRC_GRAFODIRIGIDOPONDERADO_H_
#define SRC_GRAFODIRIGIDOPONDERADO_H_

#include "ListaNombrada.h"

template <class T>
class GrafoDirigidoPonderado { //todo lograr representar los destinos con este grafo
private:
	ListaNombrada<ListaNombrada<unsigned int>*>* listaAdyacencia;

public:
	GrafoDirigidoPonderado<T>() {
		listaAdyacencia = new ListaNombrada<ListaNombrada<unsigned int>*>();
	}

	~GrafoDirigidoPonderado<T>() {
		delete listaAdyacencia;
	}
};



#endif /* SRC_GRAFODIRIGIDOPONDERADO_H_ */
