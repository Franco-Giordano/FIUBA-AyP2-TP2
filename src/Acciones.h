#ifndef ACCIONES_H_
#define ACCIONES_H_

#include <iostream>
#include "Jugador.h"
#include "Destino.h"
#include "Catalogo.h"
#include "Correo.h"
#include "ListaNombrada.h"
#include "Candidato.h"


class Acciones {
private:
	unsigned int opcionElegida;
	Jugador* jugador;
public:

	 //Post: inicializa la opcionElegida en 0.
	Acciones(Jugador* pJugador);

	//Post: le muestra por pantalla a cada jugador las acciones que puede realizar durante el juego.
	unsigned int obtenerAccionDeJugador();

	//Post: devuelve true si es posible sembrar en la parcela.
	bool esSiembraValida(Terreno* terreno, unsigned int fila, unsigned int columna, Cultivo* cultivoElegido);

	//Post: devuelve true si es posible cosechar en la parcela.
	bool esCosechaValida(Terreno* terreno, unsigned int fila, unsigned int columna);

	//Post: devuelve true si es posible regar en la parcela.
	bool esRiegoValido(Terreno* terreno, unsigned int fila, unsigned int columna);

	//Post: devuelve true si el jugador posee el dinero suficiente para comprar la ampliacion elegida.
	bool compraCapacidadTanqueValida(unsigned int ampliacionElegida, unsigned int dificultad);

	//Post: devuelve true si el jugador posee el dinero suficiente para comprar la ampliacion elegida.
	bool compraCapacidadAlmacenValida(unsigned int ampliacionElegida, unsigned int dificultad);

	//Post: devuelve true si el jugador posee el dinero suficiente para comprar un terreno.
	bool puedeComprarTerreno(unsigned int dificultad, unsigned int filas, unsigned int columnas);

	//Post: devuelve true si el jugador posee mas de un terreno.
	bool tieneMasDeUnTerreno();

	//Pre: recibe una lista de destinos validos, el catalogo y el cultivo.
	//Post: aniade a la lista los posibles destinos para el cultivo recibido.
	void obtenerDestinosValidos(Lista<Destino*>* listaDestinos, Cultivo* cultivo, CatalogoDe<Destino>* catalogoDestinos);

	//Post: muestra por pantalla la lista de destinos validos.
	void imprimirListaDestinos(ListaNombrada<unsigned int>* destinosValidos, Candidato<std::string>* previos, unsigned int cantVertices) ;

	//Post: devuelve true si la rentabilidad del cultivo es mayor al coste de envio.
	bool esEnvioValido(unsigned int precio, Correo correo);

private:

	void imprimirCaminoPara(std::string nombreLlegada, Candidato<std::string>* previos, unsigned int cantVertices);

	bool opcionValida(unsigned int minimo, unsigned int maximo, unsigned int opcion);
};

#endif /* ACCIONES_H_ */
