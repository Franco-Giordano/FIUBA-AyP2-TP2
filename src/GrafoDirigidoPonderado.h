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
 */
template <class T>
class GrafoDirigidoPonderado { //todo metodos para interactuar con el grafo
private:
	ListaNombrada<ListaNombrada<unsigned int>*>* listaAdyacencia;

//	ListaNombrada<unsigned int>* adyacentesAlVerticeInteresante;	-------------originalmente pensado para acceder a 'Almacen' mas rapido pero provoca errores mas adelante.

public:
	GrafoDirigidoPonderado<T>(CatalogoDe<T>* catalogo /*, std::string verticeInteresante*/) {
		listaAdyacencia = new ListaNombrada<ListaNombrada<unsigned int>*>();

		for (unsigned int i=0; i < catalogo->obtenerCantidadDisponible(); i++){

			T* actual = catalogo->obtenerPosicion(i);
			std::string origenDeActual = catalogo->obtenerPosicion(i)->obtenerOrigen();

			if (listaAdyacencia->yaExisteNombre(origenDeActual)){

				ListaNombrada<unsigned int>* listaDestinos = listaAdyacencia->obtenerDatoDeNombre(origenDeActual);

				listaDestinos->agregar(actual->obtenerNombre(), actual->obtenerPrecio());
			}

			else {
				ListaNombrada<unsigned int>* nuevosAdyacentes = new ListaNombrada<unsigned int>();

				nuevosAdyacentes->agregar(actual->obtenerNombre(), actual->obtenerPrecio());

				listaAdyacencia->agregar(origenDeActual, nuevosAdyacentes);
			}
		}

//		adyacentesAlVerticeInteresante = listaAdyacencia->obtenerDatoDeNombre(verticeInteresante);
	}


	void imprimirListaAdyacencia() { //todo DE MOMENTO SOLO UTILIZADO PARA PRUEBAS
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

	ListaNombrada<ListaNombrada<unsigned int>*>* obtenerListaAdyacencia() {
		return listaAdyacencia;
	}

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
