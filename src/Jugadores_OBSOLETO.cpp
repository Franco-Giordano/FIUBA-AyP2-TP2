#include "Jugadores_OBSOLETO.h"

Jugadores::Jugadores(unsigned int numeroDeJugadores) {
	this->jugadores= new Lista<Jugador*>;

	for(int i =	1 ; i <= numeroDeJugadores; i++){
		Monedero* monedero= new Monedero(5,5,3);
		TanqueDeAgua* tanque= new TanqueDeAgua(5,5,3);
		Almacen* almacen= new Almacen(5,5,3);
		Jugador* jugador= new Jugador (monedero, tanque, almacen, 5, 5);
		jugadores->agregar(jugador);
	}

}

Lista<Jugador*>* Jugadores::obtenerListaJugadores(){
	return this->jugadores;
}

Jugadores::~Jugadores() {
	delete jugadores;
}
