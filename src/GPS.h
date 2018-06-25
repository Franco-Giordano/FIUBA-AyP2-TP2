/*
 * GPS.h
 *
 *  Created on: 25 jun. 2018
 *      Author: franco
 */

#ifndef SRC_GPS_H_
#define SRC_GPS_H_

#include <string>
#include "GrafoDirigidoPonderado.h"

class GPS {
private:
	std::string origen;

	GrafoDirigidoPonderado<Destino>** grafos;

	unsigned int cantidadGrafos;

	ListaNombrada<unsigned int>** mejoresCostos;

	unsigned int minimoEntre(unsigned int elemento1, unsigned int elemento2){

		unsigned int minimo;

		if (elemento1 < elemento2){
			minimo = elemento1;
		}
		else {
			minimo = elemento2;
		}

		return minimo;
	}

public:
	GPS(std::string origenRecibido, CatalogoDe<Cultivo>* catalogoSemillas, CatalogoDe<Destino>* catalogoDestinos) {

		this->cantidadGrafos = catalogoSemillas->obtenerCantidadDisponible();

		this->origen = origenRecibido;

		this->grafos = new GrafoDirigidoPonderado<Destino>*[cantidadGrafos];

		this->mejoresCostos = new ListaNombrada<unsigned int>*[cantidadGrafos];

		for (unsigned int i = 0; i < cantidadGrafos; i++) {
			grafos[i] = new GrafoDirigidoPonderado<Destino>(catalogoDestinos,
															catalogoSemillas->obtenerPosicion(i)->obtenerNombre());

			ListaNombrada<unsigned int>* mejoresCostosCultivoActual = this->hallarCaminoMinConDijkstra(this->grafos[i]); //grafo en la posicion i

			mejoresCostos[i] = mejoresCostosCultivoActual;
		}
	}

	ListaNombrada<unsigned int>* hallarCaminoMinConDijkstra(GrafoDirigidoPonderado<Destino>* grafo) {

		ListaNombrada<ListaNombrada<unsigned int>*>* listaAdyacentes= grafo->obtenerListaAdyacencia();

		ListaNombrada<unsigned int>* mejoresCaminos;

		if (listaAdyacentes->yaExisteNombre(this->origen)) {
			unsigned int posOrigen = listaAdyacentes -> obtenerPosicionConNombre(this->origen);

			ColaConPrioridad cola(listaAdyacentes, posOrigen);

			mejoresCaminos = cola.convertirColaAlistaNombrada();

			while (!cola.estaVacia()) {

				Candidato<std::string> raizRemovida = cola.removerRaiz();

				ListaNombrada<unsigned int>* adyacentesActual = listaAdyacentes->obtenerDatoDeNombre(raizRemovida.obtenerIdentificador());

				adyacentesActual->iniciarCursor();

				while (adyacentesActual->avanzarCursor()){

					std::string nombreAdyacenteActual = adyacentesActual->obtenerNombreCursor();

					unsigned int pesoAnterior = mejoresCaminos->obtenerDatoDeNombre(nombreAdyacenteActual);

					unsigned int pesoNuevo = raizRemovida.obtenerPeso() + adyacentesActual->obtenerDatoCursor();

					if (pesoNuevo < pesoAnterior){

						mejoresCaminos->modificarDatoConNombre(nombreAdyacenteActual, pesoNuevo);

						if (cola.estaNombre(nombreAdyacenteActual)) {
							cola.mejorarPeso(nombreAdyacenteActual, pesoNuevo);
						}
					}
				}
			}
		}
		else {
			mejoresCaminos = new ListaNombrada<unsigned int>();
		}

		return mejoresCaminos;
	}

	~GPS() {
		for (unsigned int i = 0; i < cantidadGrafos; i++) {
			delete grafos[i];
			delete mejoresCostos[i];
		}
		delete[] grafos;
		delete[] mejoresCostos;
	}
};

#endif /* SRC_GPS_H_ */
