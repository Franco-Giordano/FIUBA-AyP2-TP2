/*
 * DirectorDeJuego.h
 *
 *  Created on: 25 may. 2018
 *      Author: frank
 */

#ifndef SRC_DIRECTORDEJUEGO_H_
#define SRC_DIRECTORDEJUEGO_H_

#include "Jugador.h"
#include "Catalogo.h"

class DirectorDeJuego {
private:
	unsigned int turnos, numeroDeJugadores, filas, columnas, dificultad;
	CatalogoDe<Cultivo>* catalogoSemillas;
	CatalogoDe<Destino>* catalogoDestinos;

	Lista<Jugador*>* jugadores;

	int obtenerNumero(int minimo, int maximo, std::string textoOpcional = "");

	int obtenerNumero(int minimo, std::string textoOpcional = "");

public:

	/* Pre: Recibe un puntero a un CatalogoDe<Cultivo> y un puntero a un CatalogoDe<Destino> que seran todos los cultivos y destinos disponibles, respectivamente
	 * Post: Crea DirectorDeJuego con estos datos, y ademas PREGUNTA POR CONSOLA cuantos turnos, numero de jugadores, filas y columnas maximas, y dificultad integraran el juego.
	 */
	DirectorDeJuego(CatalogoDe<Cultivo>* pCatalogoSemillas, CatalogoDe<Destino>* pCatalogoDestinos);

	/* Pre: Recibe un puntero a una lista de punteros a jugadores, cada uno inicializado.
	 * Post: ahora Director podra coordinar el Juego con estos jugadores.
	 */
	void invitarJugadoresApartida(Lista<Jugador*>* jugadores);

	/* Post: Devuelve la cantidad de jugadores que estan jugando
	 */
	int obtenerNumeroDeJugadores();

	/* Post: Devuelve la cantidad de turnos totales.
	 */
	int obtenerCantidadTurnos();

	/* Post: Devuelve la cantidad de filas de cualquier terreno en este juego
	 */
	int obtenerFilas();

	/* Post: Devuelve la cantidad de columnas de cualquier terreno en este juego
	 */
	int obtenerColumnas();

	/* Post: Devuelve la dificultad en este juego
	 */
	int obtenerDificultad();

	/* Pre: Ya se agregaron correctamente jugadores con invitarJugadoresApartida()
	 *  Post: Itera por CantidadTurnos y NumeroDeJugadores, imprimiendo, tomando y ejecutando acciones en su turno
	 */
	void coordinarJuego();

	/* Pre: numeroJugador esta en el rango [1, obtenerNumeroDeJugadores()], y que ya se agregaron correctamente jugadores con invitarJugadoresApartida()
	 * Post: Imprime el numero del jugador, y regala agua utilizando Dado.
	 */
	void anunciarJugadorYregalarAgua(unsigned int numeroJugador);

};

#endif /* SRC_DIRECTORDEJUEGO_H_ */
