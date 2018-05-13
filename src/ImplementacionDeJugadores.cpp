
#include <iostream>
#include "Jugador.h"
#include "Jugadores.h"

using namespace std;

int main ()
{
	int numeroDeJugadores;
	cout << "Cuantos jugadores van a jugar ? " << endl;
	cin >> numeroDeJugadores;

	Jugadores jugadores(numeroDeJugadores);

	cout << "Jugadores:" << jugadores.obtenerListaJugadores()->contarElementos() << endl;

	Cultivo* c1= new Cultivo();
	c1->modificarCultivo("Zanahoria",2,2,2,2,2);
	Cultivo* c2= new Cultivo();
	c2->modificarCultivo("Papa", 3,4,3,3,3);

	jugadores.obtenerListaJugadores()->obtener(1)->sembrar(1, 3, 4, c1);
	jugadores.obtenerListaJugadores()->obtener(1)->sembrar(1, 3, 3, c2);

	cout << "Nombre: " << jugadores.obtenerListaJugadores()->obtener(1)->obtenerListaTerreno()->obtener(1)->
			obtenerParcela(3,4).obtenerCultivo()->obtenerNombre() << endl;

	cout << "Nombre: " << jugadores.obtenerListaJugadores()->obtener(1)->obtenerListaTerreno()->obtener(1)->
				obtenerParcela(3,3).obtenerCultivo()->obtenerNombre() << endl;

	cout << "Terrenos antes de comprar: "<< jugadores.obtenerListaJugadores()->obtener(1)->
			obtenerListaTerreno()->contarElementos()<< endl;

	jugadores.obtenerListaJugadores()->obtener(1)->comprarTerreno(5,5);

	cout << "Terrenos despues de comprar: "<< jugadores.obtenerListaJugadores()->obtener(1)->
			obtenerListaTerreno()->contarElementos()<< endl;

	jugadores.obtenerListaJugadores()->obtener(1)->sembrar(2, 3, 2, c1);

	cout << "Nombre: " << jugadores.obtenerListaJugadores()->obtener(1)->obtenerListaTerreno()->obtener(2)->
					obtenerParcela(3,2).obtenerCultivo()->obtenerNombre() << endl;


	jugadores.obtenerListaJugadores()->obtener(1)->venderTerreno(2);

	cout << "Terrenos despues de vender: "<< jugadores.obtenerListaJugadores()->obtener(1)->
				obtenerListaTerreno()->contarElementos()<< endl;

	int dificultad=2;

	cout << "Capacidad del almacen: " << jugadores.obtenerListaJugadores()->obtener(1)->obtenerAlmacen()->
			obtenerCapacidad()<< endl;

	jugadores.obtenerListaJugadores()->obtener(1)->agrandarAlmacen(5, dificultad);

	cout << "Capacidad del almacen: " << jugadores.obtenerListaJugadores()->obtener(1)->obtenerAlmacen()->
			obtenerCapacidad()<< endl;



	delete c1;
	delete c2;

return 0;
}