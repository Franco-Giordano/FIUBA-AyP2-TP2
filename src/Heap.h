/*
 * Heap.h
 *
 *  Created on: 21 jun. 2018
 *      Author: frank
 */

#ifndef SRC_HEAP_H_
#define SRC_HEAP_H_

#include <string>
#include "ListaNombrada.h"


class Heap {
private:
	unsigned int maximaCantidad;

	unsigned int * pesos;

	std::string* nombres;

public:
	Heap(ListaNombrada<unsigned int>* elementos, unsigned int cantidad) {
		pesos = new unsigned int[cantidad];
		nombres = new std::string[cantidad];
		maximaCantidad = cantidad;

	}


	~Heap();
};

#endif /* SRC_HEAP_H_ */
