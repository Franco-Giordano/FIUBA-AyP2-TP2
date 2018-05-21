/*
 * Secretario.cpp
 *
 *  Created on: 21 may. 2018
 *      Author: frank
 */

#include "Secretario.h"

Secretario::Secretario(CatalogoDe<Cultivo>* pCatalogoSemillas, CatalogoDe<Destino>* pCatalogoDestinos) {

	turnos = obtenerNumero(1, "Determine la cantidad de turnos totales. ");

	numeroDeJugadores = obtenerNumero(1, "Determine la cantidad de jugadores. ");

	filas = obtenerNumero(1,"Determine la cantidad de filas del terreno. ");
	columnas = obtenerNumero(1,"Determine la cantidad de columnas del terreno. ");

	dificultad = obtenerNumero(1, 3, "Determine la dificultad, siendo 1 la mas facil y 3 la mas dificil. ");

    catalogoSemillas = pCatalogoSemillas;
    catalogoDestinos = pCatalogoDestinos;
}



int Secretario::obtenerNumero(int minimo, int maximo, std::string textoOpcional = "") {
	std::string input;
	int numero;

	do {
		std::cout << textoOpcional <<  "Ingrese un numero entre "<< minimo << " y "<<maximo<<": ";
		std::cin >> input;
		std::istringstream(input) >> numero;

	}
	while (numero < minimo || numero > maximo);

	std::cout<< std::endl;

	return numero;
}


int Secretario::obtenerNumero(int minimo, std::string textoOpcional = "") {
	std::string input;
	int numero;

	do {
		std::cout << textoOpcional << "Ingrese un numero mayor a " << minimo <<": ";
		std::cin >> input;
		std::istringstream(input) >> numero;
	}
	while (numero < minimo);
	std::cout<< std::endl;

	return numero;
}


int Secretario::obtenerCantidadTurnos() {
	return turnos;
}


int Secretario::obtenerFilas() {
	return filas;
}


int Secretario::obtenerColumnas() {
	return columnas;
}


int Secretario::obtenerNumeroDeJugadores() {
	return numeroDeJugadores;
}


int Secretario::obtenerDificultad() {
	return dificultad;
}


void Secretario::atenderJugador(Jugador* jugador) {
	Peon peon;
	Acciones acciones(jugador);
	bool pasarTurno = false;

	while (!pasarTurno) {
		unsigned int eleccion = acciones.obtenerAccionDeJugador();

		Parcela* parcelaElegida;

		if (eleccion >= 1 && eleccion <= 3) { //Si la eleccion es sembrar, cosechar o regar.

			Terreno* terreno = jugador-> obtenerListaTerreno() -> obtener(obtenerTerrenoDeJugador(jugador)) ;
			unsigned int fila = obtenerNumero(1, this->filas,"Determine numero de fila. ");
			unsigned int columna = obtenerNumero(1, this->columnas,"Determine numero de columna. ");
            parcelaElegida = terreno->obtenerParcela(fila-1,columna-1);
		}



		switch (eleccion) {
			case 1: {
				Cultivo* cultivoElegido = seleccionarCultivoDeCatalogo();
                if (acciones.esSiembraValida(parcelaElegida, cultivoElegido)) {
                	peon.sembrar(parcelaElegida, jugador->obtenerMonedero(), cultivoElegido);
                }
				break; }

			case 2:
				if (parcelaElegida->sePuedeCosechar()){
					peon.cosechar(parcelaElegida, jugador->obtenerAlmacen());
				}
			break;
			case 3:
				if (acciones.esRiegoValido(parcelaElegida)) {
					peon.regar(parcelaElegida, jugador->obtenerTanqueDeAgua());
				}
			break;
			case 4:
				//enviarCosecha();
			break;
			case 5:
				//comprarTerreno();
			break;
			case 6:
				//venderTerreno();
			break;
			case 7:
				//comprarCapacidadTanque(dificultad);
			break;
			case 8:
				//comprarCapacidadAlmacen(dificultad);
			break;
			case 9:
				pasarTurno = true;
			break;
		}
	}
}





unsigned int Secretario::obtenerTerrenoDeJugador(Jugador* jugador) {
	return obtenerNumero(1, jugador->obtenerListaTerreno()->contarElementos(), "Cual de sus terrenos desea trabajar? ");
}





Cultivo* Secretario::seleccionarCultivoDeCatalogo() {
	std::cout << "Seleccione un cultivo a sembrar: "<<std::endl;
	for (unsigned int i =0; i < catalogoSemillas->obtenerCantidadDisponible(); i++) {
		std::cout<< i+1 << ". " << catalogoSemillas->obtenerPosicion(i)->obtenerNombre()<<std::endl;
	}

	return catalogoSemillas->obtenerPosicion(obtenerNumero(1, catalogoSemillas->obtenerCantidadDisponible() - 1));
}
