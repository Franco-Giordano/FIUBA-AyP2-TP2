/*
 * GPS.h
 *
 *  Created on: 26 jun. 2018
 *      Author: ailen-magali
 */

#ifndef GPS_H_
#define GPS_H_

#include <string>
#include "GrafoDirigidoPonderado.h"
#include "ColaConPrioridad.h"

class GPS {
private:

	CatalogoDe<Cultivo>* catalogoSemillas;

	std::string origen;

	GrafoDirigidoPonderado** grafos;

	unsigned int cantidadGrafos;

	ListaNombrada<unsigned int>** mejoresCostos;

	Candidato<std::string>** previosCadaCultivoCadaDestino;

	/*
	 * POST: Recibe dos unsigned int y devuelve el menor de ellos.
	 */
	unsigned int minimoEntre(unsigned int elemento1, unsigned int elemento2);

	/*
	 * POST: Devuelve la posición en la que se encuentra el Destino de nombre "nombre" en el catálogoSemillas.
	 * Si no lo encuentra, devuelve -1.
	 */
	unsigned int obtenerPosicionDeNombre(std::string nombre);

	/*
	 * POST: Guarda en la lista "lista" aquellos datos que tengan un peso menor a INFINITO
	 */
	void removerInfinitos(ListaNombrada<unsigned int>*& lista);

	void inicializarPrevios(Candidato<std::string>* array, ListaNombrada<ListaNombrada<unsigned int>*>* listaAdy);

public:

	/*
	 * POST: Inicializa catalogoSemillas y origen con los parámetros recibidos, cantidadGrafos
	 * con la cantidad de semillas disponibles en el catálogo, grafos con un array dinámico
	 * de GrafoDirigidoPonderado<Destino> de tamaño cantidadGrafos, mejores costos con una ListaNombrada
	 * de tamaño CantidadGrafos, en donde para cada posicion del array grafos se calculará el camino
	 * mínimo con Dijkstra y se agregará a mejoresCostos en la posición de ese grafo.
	 */
	GPS(std::string origenRecibido, CatalogoDe<Cultivo>* catalogoSemillas, CatalogoDe<Destino>* catalogoDestinos);

	/*
	 * POST: Devuelve los caminos de menor costo de grafo calculado con el método de Dijkstra basado en una lista de adyacencias y una cola con
	 * prioridad
	 */
	ListaNombrada<unsigned int>* hallarCaminoMinConDijkstra(unsigned int i);

	/*
	 * POST: Devuelve los mejores costos para un cultivo dado
	 */
	ListaNombrada<unsigned int>* obtenerMejoresCostosPara(std::string nombreCultivo);

	/*
	 * POST: Devuelve la cantidad de vertices del grafo correspondiente a 'nombreCultivo'
	 */
	unsigned int cantVertices(std::string nombreCultivo);


	/*
	 * POST: Devuelve un puntero al array de previos, que representa el mejor camino segun Dijkstra.
	 */
	Candidato<std::string>* obtenerPreviosPara(std::string nombreCultivo);

	/*
	 * POST: Libera la memoria utilizada
	 */
	~GPS();
};

#endif /* GPS_H_ */
