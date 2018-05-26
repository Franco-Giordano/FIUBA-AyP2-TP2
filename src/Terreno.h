/*
 * Terreno.h
 *
 *  Created on: 4 may. 2018
 *      Author: Federico
 */

#ifndef TERRENO_H_
#define TERRENO_H_

#include "Parcela.h"
#include "ListaCoordenada.h"

class Terreno {
private:

	unsigned int limiteFilas;
	unsigned int limiteColumnas;
	ListaCoordenada<ListaCoordenada<Parcela*>*>* filas;

public:

	//Post: Crea el terreno.
	Terreno(unsigned int cantidadFilasRecibidas, unsigned int cantidadColumnasRecibidas);

	//Post: Devuelve la cantidad de filas que tiene la matriz.
	unsigned int obtenerFilas();

	//Post: Devuelve la cantidad de columnas que tiene la matriz.
	unsigned int obtenerColumnas();

	//Pre: La parcela a obtener existe.
	//Post: Devuelve un puntero a la parcela en fila y columna elegidas.
	Parcela* obtenerParcela(unsigned int filaElegida, unsigned int columnaElegida);

	//Post: Devuelve como booleano indicando si la parcela esta ocupada (no vacia).
	bool estaOcupada(unsigned int filaRecibida, unsigned int columnaRecibida);

	//Pre: recibe la fila y la columna de donde se desea crear la parcela.
	//Post: crea una parcela, en la posicion pedida, para poder ser usada.
	void prepararParcela(unsigned int fila, unsigned int columna);

	//Post: devuelve la lista de filas la cual contiene listas de columnas.
	ListaCoordenada<ListaCoordenada<Parcela*>*>* obtenerListaFilas();

	//Post: devuelve true si no hay ningun elemento creado en el terreno.
	bool estaTodoVacio();

	//Post: Libera la memoria utilizada por Terreno.
	virtual ~Terreno();
};

#endif /* TERRENO_H_ */
