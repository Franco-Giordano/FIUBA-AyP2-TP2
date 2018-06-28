/*
 * GrafoOrientado.h
 *
 *  Created on: 20 jun. 2018
 *      Author: frank
 */

#ifndef SRC_GRAFODIRIGIDOPONDERADO_H_
#define SRC_GRAFODIRIGIDOPONDERADO_H_

#include "ListaNombrada.h"
#include "Catalogo.h"

class GrafoDirigidoPonderado {
private:
	ListaNombrada<ListaNombrada<unsigned int>*>* listaAdyacencia;

public:
	/*
	 * POST: Crea el grafo, recibiendo como parámetros un puntero a un catálogo de Destino y un nombre de un cultivo (cultivoBuscado).
	 */
	GrafoDirigidoPonderado(CatalogoDe<Destino>* catalogo, std::string cultivoBuscado);

	/*
	 * PRE: Que la lista no esté vacía
	 * POST: Muestra la lista de adyacencias por pantalla
	 */
	void imprimirListaAdyacencia();

	/*
	 * POST: Devuelve la lista de adyacencias
	 */
	ListaNombrada<ListaNombrada<unsigned int>*>* obtenerListaAdyacencia();

	/*
	 * POST: Libera la memoria utilizada
	 */
	~GrafoDirigidoPonderado();
};

#endif /* SRC_GRAFODIRIGIDOPONDERADO_H_ */
