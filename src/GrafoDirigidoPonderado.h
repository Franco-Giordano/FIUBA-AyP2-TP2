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


/* LA CLASE T ELEGIDA DEBERA
 * TENER LOS METODOS PUBLICOS: -obtenerNombre(): devuelve std::string, representa el nombre del vertice
 * 							   -obtenerOrigen(): devuelve std::string, representa de quien es adyacente el vertice
 * 							   -obtenerPrecio(): devuelve unsigned int, representa ponderacion de la arista que une obtenerOrigen() con obtenerNombre()
 *
 * 	En nuestro caso, T = Destino.
 */
template <class T>
class GrafoDirigidoPonderado {
private:
	ListaNombrada<ListaNombrada<unsigned int>*>* listaAdyacencia;

public:
	/*
	* POST: Crea el grafo, recibiendo como parámetros un puntero a un catálogo de Destino y un nombre de un cultivo (cultivoBuscado).
	* Se crea una lista de adyacencia, y se hace un recorrido desde 0 hasta la cantidad disponible de destinos en el catálogo, en donde, 
	* si el cultivo del catálogo en la posición i es el cultivoBuscado, va modificando la lista de adyacencias dependiendo de la existencia 
	* del origen del Destino en la misma.
	*/
	GrafoDirigidoPonderado<T>(CatalogoDe<T>* catalogo, std::string cultivoBuscado) {
		listaAdyacencia = new ListaNombrada<ListaNombrada<unsigned int>*>();

		for (unsigned int i=0; i < catalogo->obtenerCantidadDisponible(); i++){

			if (catalogo->obtenerPosicion(i)->obtenerNombreCultivo() == cultivoBuscado) {
				T* actual = catalogo->obtenerPosicion(i);
				std::string origenDeActual = catalogo->obtenerPosicion(i)->obtenerOrigen();

				if (listaAdyacencia->yaExisteNombre(origenDeActual)) {

					ListaNombrada<unsigned int>* listaDestinos = listaAdyacencia->obtenerDatoDeNombre(origenDeActual);

					listaDestinos->agregar(actual->obtenerNombre(), actual->obtenerPrecio());
				}

				else {
					ListaNombrada<unsigned int>* nuevosAdyacentes = new ListaNombrada<unsigned int>();

					nuevosAdyacentes->agregar(actual->obtenerNombre(), actual->obtenerPrecio());

					listaAdyacencia->agregar(origenDeActual, nuevosAdyacentes);
				}

				if (!listaAdyacencia->yaExisteNombre(actual->obtenerNombre())){
					ListaNombrada<unsigned int>* nuevosAdyacentes = new ListaNombrada<unsigned int>();

					listaAdyacencia->agregar(actual->obtenerNombre(), nuevosAdyacentes);
				}
			}

		}
	}

	/*
	* PRE: Que la lista no esté vacía
	* POST: Muestra la lista de adyacencias por pantalla
	*/
	void imprimirListaAdyacencia() {
		listaAdyacencia->iniciarCursor();
		while (listaAdyacencia->avanzarCursor()) {
			ListaNombrada<unsigned int>* actual = listaAdyacencia->obtenerDatoCursor();

			std::cout << listaAdyacencia->obtenerNombreCursor() << " |> ";

			actual->iniciarCursor();
			while (actual->avanzarCursor()) {
				std::cout << "[" << actual->obtenerNombreCursor() << " $" << actual->obtenerDatoCursor()<<"] ";
			}
			std::cout<<std::endl;

		}
	}

	/*
	* POST: Devuelve la lista de adyacencias
	*/
	ListaNombrada<ListaNombrada<unsigned int>*>* obtenerListaAdyacencia() {
		return listaAdyacencia;
	}

	/*
	* POST: Libera la memoria utilizada
	*/
	~GrafoDirigidoPonderado<T>() {
		listaAdyacencia->iniciarCursor();
		while (listaAdyacencia->avanzarCursor()) {
			ListaNombrada<unsigned int>* adyActual = listaAdyacencia->obtenerDatoCursor();
			delete adyActual;
		}
		delete listaAdyacencia;
	}
};



#endif /* SRC_GRAFODIRIGIDOPONDERADO_H_ */
