/*
 * Heap.h
 *
 *  Created on: 21 jun. 2018
 *      Author: frank
 */

#ifndef SRC_MINHEAP_H_
#define SRC_MINHEAP_H_

#ifndef INFINITO
#define INFINITO 99999999999999999999999999
#endif

#include <string>
#include "ListaNombrada.h"
#include "Candidato.h"
#include <iostream>

class MinHeap { //TODO esto xd
private:
	unsigned int maximaCantidad;

	Candidato<std::string>** candidatos; //se identificaran los vertices con strings (sus nombres) pero se ordenaran por peso minimo

	void copiarListaEnArray(ListaNombrada<ListaNombrada<unsigned int>*>* listaOriginal, Candidato<std::string>** arrayDondeCopiar, unsigned int origen) {
		ListaNombrada<unsigned int>* adyacentesOrigen = listaOriginal->obtenerDato(origen);

		adyacentesOrigen->iniciarCursor();
		unsigned int i = 0;
		while (adyacentesOrigen->avanzarCursor()) {

			Candidato<std::string>* nuevoElem = new Candidato<std::string>(adyacentesOrigen->obtenerNombreCursor(), adyacentesOrigen->obtenerDatoCursor());

			arrayDondeCopiar[i] = nuevoElem;

			i++;
		}
	}

	void bajar(unsigned int primero, unsigned int ultimo) {

		unsigned int minimo = 2*primero + 1; //el minimo de los dos hijos

		while (minimo <= ultimo) {
			if (minimo > ultimo && candidatos[ultimo]->obtenerPeso() > candidatos[ultimo+1]->obtenerPeso()) {
				//chequeo si realmente elegi al hijo mas chico, sino cambio al otro
				minimo++;
			}

			if (candidatos[primero]->obtenerPeso() > candidatos[minimo]->obtenerPeso()) { //si el hijo es mas chico que el padre...
				intercambiar(primero, minimo);

				//ahora me fijo los hijos del hijo que recien movi, a ver si hay que seguir intercambiando
				primero = minimo;
				minimo = 2*primero +1;
			}
			else {
				minimo = ultimo + 1; //si no se ejecuto lo de arriba, entonces ya puedo salir del loop
			}


		}
	}


	//intercambia los punteros almacenados en candidatos[posA] y candidatos[posB]
	void intercambiar(unsigned int posA, unsigned int posB) {
		Candidato<std::string>* aux = candidatos[posA];
		candidatos[posA] = candidatos[posB];
		candidatos[posB] = aux;
	}

public:
	MinHeap(ListaNombrada<ListaNombrada<unsigned int>*>* listaAdyacencia, unsigned int origen) {
		//TODO hace el HEAP solo con los adyacentes al origen, no tiene implementado manejar los de peso infinito

		maximaCantidad = listaAdyacencia->obtenerDato(origen)->contarElementos(); //TODO TA MAL AAAAAAAAAAAAAAAAAAAAAAAAAAA

		candidatos = new Candidato<std::string>*[maximaCantidad];
		this->copiarListaEnArray(listaAdyacencia, candidatos, origen); //TODO ARREGLAR QUE AGREGUE VERTICES NO APUNTADOS POR EL ORIGEN


		//Inicio Algoritmo de Floyd para construir HEAP desde array
		for (int i = maximaCantidad/2 - 1; i>= 0 ; i--) {
			bajar(i, maximaCantidad - 1);
		}
	}

	void imprimirHeap() {
		for (unsigned int i=0; i < this->maximaCantidad; i++) {
			std::cout << "[" << candidatos[i]->obtenerIdentificador() << " | $" << candidatos[i]->obtenerPeso() << "] ";
		}
	}


	//TODO destructor xd
	~MinHeap() {
		for (unsigned int i = 0; i < maximaCantidad; i++) {
			delete candidatos[i];
		}

		delete[] candidatos;
	}

};

#endif /* SRC_HEAP_H_ */
