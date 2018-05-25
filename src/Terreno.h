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

	int limiteFilas;
	int limiteColumnas;
	ListaCoordenada<ListaCoordenada<Parcela*>*>* filas;

public:

	//Post: Crea el terreno.
	Terreno(int cantidadFilasRecibidas, int cantidadColumnasRecibidas);

	//Post: Devuelve la cantidad de filas que tiene la matriz.
	int obtenerFilas();

	//Post: Devuelve la cantidad de columnas que tiene la matriz.
	int obtenerColumnas();

	//Pre: La parcela a obtener esta ocupada.
	//Post: Devuelve el objeto parcela como referencia para su modifición.
	Parcela* obtenerParcela(int filaElegida, int columnaElegida);

	//Post: Devuelve como booleano indicando si la parcela esta ocupada (no vacia).
	bool estaOcupada(int filaRecibida, int columnaRecibida);

	//Pre: recibe la fila y la columna de donde se desea crear la parcela.
	//Post: crea una parcela, en la posicion pedida, para poder ser usada.
	void prepararParcela(int fila, int columna);

	//Post: devuelve la lista de filas la cual contiene listas de columnas.
	ListaCoordenada<ListaCoordenada<Parcela*>*>* obtenerListaFilas();

	//Post: devuelve true si no hay ningun elemento creado en el terreno (osea en la lista de listas).
	bool estaTodoVacio();

	//Post: Libera la memoria utilizada por Terreno.
	~Terreno();
};

#endif /* TERRENO_H_ */
