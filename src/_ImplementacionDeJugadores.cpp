
/* 
*principal.cpp
* Created by:Alvaro
*28 abr. 2018
*20:27:02
*/


#include <iostream>
#include "Jugador.h"


using namespace std;

int main ()
{
	int numeroDeJugadores;
	cout << "Cuantos jugadores van a jugar ? " << endl;
	cin >> numeroDeJugadores;

	int N=5;
	int M=6;
	int dificultad=1;

	Lista<Jugador*>* jugadores= new Lista<Jugador*>;

	for (unsigned int i=1; i<= numeroDeJugadores; i++){
		Jugador* jugador= new Jugador(N, M,dificultad);
		jugadores->agregar(jugador);

	}

	cout << "Jugadores:" << jugadores->contarElementos() << endl;

	Cultivo* c1= new Cultivo();
	c1->modificarCultivo("Zanahoria",2,2,2,2,2);
	Cultivo* c2= new Cultivo();
	c2->modificarCultivo("Papa", 3,4,3,3,3);

	jugadores->obtener(1)->sembrar(1, 3, 4, c1);
	jugadores->obtener(1)->sembrar(1, 3, 3, c2);

	cout << "Nombre: " << jugadores->obtener(1)->obtenerListaTerreno()->obtener(1)->
			obtenerParcela(3,4).obtenerCultivo()->obtenerNombre() << endl;

	cout << "Nombre: " << jugadores->obtener(1)->obtenerListaTerreno()->obtener(1)->
				obtenerParcela(3,3).obtenerCultivo()->obtenerNombre() << endl;

	cout << "Terrenos antes de comprar: "<< jugadores->obtener(1)->
			obtenerListaTerreno()->contarElementos()<< endl;

	jugadores->obtener(1)->comprarTerreno(5,5);

	cout << "Terrenos despues de comprar: "<< jugadores->obtener(1)->
			obtenerListaTerreno()->contarElementos()<< endl;

	jugadores->obtener(1)->sembrar(2, 3, 2, c1);

	cout << "Nombre: " << jugadores->obtener(1)->obtenerListaTerreno()->obtener(2)->
					obtenerParcela(3,2).obtenerCultivo()->obtenerNombre() << endl;


	jugadores->obtener(1)->venderTerreno(2);

	cout << "Terrenos despues de vender: "<< jugadores->obtener(1)->
				obtenerListaTerreno()->contarElementos()<< endl;



	cout << "Capacidad del almacen: " << jugadores->obtener(1)->obtenerAlmacen()->
			obtenerCapacidad()<< endl;

	jugadores->obtener(1)->agrandarAlmacen(5, dificultad);

	cout << "Capacidad del almacen: " << jugadores->obtener(1)->obtenerAlmacen()->
			obtenerCapacidad()<< endl;



	delete c1;
	delete c2;

return 0;
}

