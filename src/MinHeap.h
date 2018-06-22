/*
 * Heap.h
 *
 *  Created on: 21 jun. 2018
 *      Author: frank
 */

#ifndef SRC_MINHEAP_H_
#define SRC_MINHEAP_H_

#include <string>
#include "ListaNombrada.h"
#include "Candidato.h"

class MinHeap { //TODO esto xd
private:
	unsigned int maximaCantidad;

	Candidato<std::string>* candidatos; //se identificaran los vertices con strings (sus nombres) pero se ordenaran por peso minimo

	void copiarListaEnArray(ListaNombrada<unsigned int>* listaOriginal, Candidato<std::string>* arrayDondeCopiar) {
		listaOriginal->iniciarCursor();
		unsigned int i = 0;
		while (listaOriginal->avanzarCursor()) {

			Candidato<std::string>* nuevoElem = new Candidato<std::string>(listaOriginal->obtenerNombreCursor(), listaOriginal->obtenerDatoCursor());

			arrayDondeCopiar[i] = nuevoElem;

			i++;
		}
	}

public:
	MinHeap(ListaNombrada<unsigned int>* elementos, unsigned int cantidad) {

		maximaCantidad = cantidad;

		candidatos = new Candidato<std::string>[maximaCantidad];
		this->copiarListaEnArray(elementos, candidatos);


		//Inicio Algoritmo de Floyd para construir HEAP desde array
		for (unsigned int i = maximaCantidad/2; i>= 0 ; i--) {
			if () {

			}
		}


	}


	~MinHeap();
};

#endif /* SRC_HEAP_H_ */
