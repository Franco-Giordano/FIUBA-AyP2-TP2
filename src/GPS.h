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

	GrafoDirigidoPonderado<Destino>** grafos;

	unsigned int cantidadGrafos;

	ListaNombrada<unsigned int>** mejoresCostos;

	unsigned int minimoEntre(unsigned int elemento1, unsigned int elemento2);

	unsigned int obtenerPosicionDeNombre(std::string nombre);

	void removerInfinitos(ListaNombrada<unsigned int>*& lista);

public:

	GPS(std::string origenRecibido, CatalogoDe<Cultivo>* catalogoSemillas, CatalogoDe<Destino>* catalogoDestinos);

	ListaNombrada<unsigned int>* hallarCaminoMinConDijkstra(GrafoDirigidoPonderado<Destino>* grafo);

	ListaNombrada<unsigned int>* obtenerMejoresCostosPara(std::string nombreCultivo);

	~GPS();
};


#endif /* GPS_H_ */
