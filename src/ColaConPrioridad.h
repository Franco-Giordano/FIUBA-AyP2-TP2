/*
 * Heap.h
 *
 *  Created on: 21 jun. 2018
 *      Author: frank
 */

#ifndef SRC_COLACONPRIORIDAD_H_
#define SRC_COLACONPRIORIDAD_H_

#ifndef INFINITO
#define INFINITO 99999999
#endif

#include <string>
#include "ListaNombrada.h"
#include "Candidato.h"
#include <iostream>

class ColaConPrioridad {
private:
	unsigned int maximaCantidad;

	Candidato<std::string>** candidatos; //se identificaran los vertices con strings (sus nombres) pero se ordenaran por peso minimo

	unsigned int posUltima;

	void copiarListaEnCandidatos(ListaNombrada<ListaNombrada<unsigned int>*>* listaOriginal, unsigned int origen) {

		ListaNombrada<unsigned int>* adyacentesOrigen = listaOriginal->obtenerDato(origen);

		std::string nombreOrigen = listaOriginal->obtenerNombre(origen);

		//copio todos los elementos con peso infinito
		listaOriginal->iniciarCursor();
		unsigned int i = 0;
		while (listaOriginal->avanzarCursor()) {

			if (listaOriginal->obtenerNombreCursor() != nombreOrigen) {
				Candidato<std::string>* nuevoElem = new Candidato<std::string>(listaOriginal->obtenerNombreCursor(), INFINITO);

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

    void subir(int pos) {
    	int padre;
    	if (pos != 0) {
    		padre = (pos - 1)/2;

    		if (candidatos[padre]->obtenerPeso() > candidatos[pos]->obtenerPeso()) {
    			intercambiar(padre,pos);

    			subir(padre);
    		}
    	}
    }

public:
	ColaConPrioridad(ListaNombrada<ListaNombrada<unsigned int>*>* listaAdyacencia, unsigned int origen) {

		maximaCantidad = listaAdyacencia->contarElementos() - 1; //no se debe contar el origen

		this -> posUltima = maximaCantidad - 1;

		candidatos = new Candidato<std::string>*[maximaCantidad];
		this->copiarListaEnCandidatos(listaAdyacencia, origen);

		//Inicio Algoritmo de Floyd para construir HEAP desde array
		for (int i = maximaCantidad/2 - 1; i>= 0 ; i--) {
			bajar(i, maximaCantidad - 1);
		}


	}

	void imprimirHeap() {
		for (unsigned int i=0; i < this->posUltima + 1; i++) {
			std::cout << "[" << candidatos[i]->obtenerIdentificador() << " | $" << candidatos[i]->obtenerPeso() << "] ";
		}
	}

	bool estaVacia() {
		return candidatos[0] == NULL;
	}

	Candidato<std::string> removerRaiz() {

		Candidato<std::string> raiz (candidatos [0]->obtenerIdentificador(), candidatos[0]->obtenerPeso());

		delete candidatos[0];

		candidatos[0] = NULL;

		if (posUltima != 0) {
			candidatos[0] = candidatos [posUltima];

			candidatos[posUltima] = NULL;

			posUltima--;

			this -> bajar(0,posUltima);
		}

		return raiz;
	}

	void mejorarPeso(std::string nombreRecibido, unsigned int pesoRecibido){

		unsigned int i = 0;

		bool encontrado = false;

		while (!encontrado && i < posUltima + 1){

			if (nombreRecibido == candidatos[i]->obtenerIdentificador()){

				candidatos[i]->modificarPeso(pesoRecibido);

				encontrado = true;

				this -> subir(i);
			}
			i++;
		}
	}

	bool estaNombre(std::string nombre) {
		bool esta = false;
		unsigned int i = 0;
		while (i < posUltima + 1 && !esta) {
			if (candidatos[i]->obtenerIdentificador() == nombre) {
				esta = true;
			}
			i++;
		}

		return esta;
	}

	~ColaConPrioridad() {
		for (unsigned int i = 0; i < maximaCantidad; i++) {
			delete candidatos[i];
		}

		delete[] candidatos;
	}

	ListaNombrada<unsigned int>* convertirColaAlistaNombrada() {
		ListaNombrada<unsigned int>* resultado = new ListaNombrada<unsigned int>();

		for (unsigned int i = 0; i < this->maximaCantidad; i++) {
			resultado->agregar(candidatos[i]->obtenerIdentificador(), candidatos[i]->obtenerPeso());
		}

		return resultado;
	}

};

#endif /* SRC_ColaConPrioridad_H_ */
