/*
 * Heap.h
 *
 *  Created on: 21 jun. 2018
 *      Author: frank
 */

#ifndef SRC_MINHEAP_H_
#define SRC_MINHEAP_H_

#ifndef INFINITO
#define INFINITO 99999999
#endif

#include <string>
#include "ListaNombrada.h"
#include "Candidato.h"
#include <iostream>

class MinHeap { //TODO esto xd
private:
	unsigned int maximaCantidad;

	Candidato<std::string>** candidatos; //se identificaran los vertices con strings (sus nombres) pero se ordenaran por peso minimo

	void copiarListaEnCandidatos(ListaNombrada<ListaNombrada<unsigned int>*>* listaOriginal, unsigned int origen) {

		ListaNombrada<unsigned int>* adyacentesOrigen = listaOriginal->obtenerDato(origen);

		std::string nombreOrigen = listaOriginal->obtenerNombre(origen);

		//copio todos los elementos con peso infinito
		listaOriginal->iniciarCursor();
		unsigned int i = 0;
		while (listaOriginal->avanzarCursor()) {

			if (listaOriginal->obtenerNombreCursor() != nombreOrigen) {
				Candidato<std::string>* nuevoElem = new Candidato<std::string>(listaOriginal->obtenerNombreCursor(),
																			   INFINITO);

				candidatos[i] = nuevoElem;
				i++;
			}
		}

		//me fijo cuales son adyacentes a mi origen y corrijo su respectivo peso en el array
		adyacentesOrigen->iniciarCursor();
		while (adyacentesOrigen->avanzarCursor()) {

			unsigned int posAdy = this->hallarPosicionConNombre(adyacentesOrigen->obtenerNombreCursor());

			candidatos[posAdy]->modificarPeso(adyacentesOrigen->obtenerDatoCursor());
		}
	}

	//PRE: el nombre esta en el array
	unsigned int hallarPosicionConNombre(std::string nombre) {
		unsigned int posicion = 0;
		bool encontrado = false;

		unsigned int i = 0;
		while (i < maximaCantidad && !encontrado) {
			if (candidatos[i]->obtenerIdentificador() == nombre) {
				posicion = i;
				encontrado = true;
			}
			i++;
		}
		return posicion;
	}

	void bajar(unsigned int primero, unsigned int ultimo) {

		unsigned int minimo = 2*primero + 1; //el minimo de los dos hijos

		while (minimo <= ultimo) {
			if (minimo < ultimo && candidatos[minimo]->obtenerPeso() > candidatos[minimo+1]->obtenerPeso()) {
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

		maximaCantidad = listaAdyacencia->contarElementos() - 1; //no se debe contar el origen

		candidatos = new Candidato<std::string>*[maximaCantidad];
		this->copiarListaEnCandidatos(listaAdyacencia, origen); //TODO ARREGLAR QUE AGREGUE VERTICES NO APUNTADOS POR EL ORIGEN

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


	~MinHeap() {
		for (unsigned int i = 0; i < maximaCantidad; i++) {
			delete candidatos[i];
		}

		delete[] candidatos;
	}

};

#endif /* SRC_HEAP_H_ */
