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

class Terreno
{
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

	void prepararParcela(int fila, int columna);

	ListaCoordenada<ListaCoordenada<Parcela*>*>* obtenerListaFilas();

	bool estaTodoVacio();

	//Post: Libera la memoria utilizada por Terreno.
	~Terreno();
};

#endif /* TERRENO_H_ */
