/*
 * DirectorDeJuego.cpp
 *
 *  Created on: 25 may. 2018
 *      Author: frank
 */

#include "DirectorDeJuego.h"
#include "DronAereo.h"
#include "Marcador.h"
#include "Tiempo.h"
#include "Secretario.h"
#include <iostream>

using namespace std;

DirectorDeJuego::DirectorDeJuego(CatalogoDe<Cultivo>* pCatalogoSemillas, CatalogoDe<Destino>* pCatalogoDestinos) {
	this->turnos = obtenerNumero(1, "Determine la cantidad de turnos totales. ");

	this->jugadores = NULL;

	this->numeroDeJugadores = obtenerNumero(1, "Determine la cantidad de jugadores. ");

	this->filas = obtenerNumero(1, "Determine la cantidad de filas del terreno. ");
	this->columnas = obtenerNumero(1, "Determine la cantidad de columnas del terreno. ");

	this->dificultad = obtenerNumero(1, 3, "Determine la dificultad, siendo 1 la mas facil y 3 la mas dificil. ");

	this->catalogoSemillas = pCatalogoSemillas;
	this->catalogoDestinos = pCatalogoDestinos;

}

void DirectorDeJuego::invitarJugadoresApartida(Lista<Jugador*>* jugadores) {
	this->jugadores = jugadores;
}

int DirectorDeJuego::obtenerNumeroDeJugadores() {
	return this -> numeroDeJugadores;
}


int DirectorDeJuego::obtenerCantidadTurnos() {
	return this -> turnos;
}


int DirectorDeJuego::obtenerFilas() {
	return this -> filas;
}


int DirectorDeJuego::obtenerColumnas() {
	return this -> columnas;
}


int DirectorDeJuego::obtenerDificultad() {
	return this -> dificultad;
}


int DirectorDeJuego::obtenerNumero(int minimo, int maximo, std::string textoOpcional /*= ""*/) {
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

int DirectorDeJuego::obtenerNumero(int minimo, std::string textoOpcional /*= ""*/) {
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



void DirectorDeJuego::coordinarJuego() {

	cout << "Mandando a volar el dron, estara listo en unos momentos..." << endl<<endl;
	DronAereo dron(this->filas, this->columnas);

	Secretario secretario(catalogoSemillas, catalogoDestinos, filas, columnas, dificultad);

	unsigned int numeroJugador = 1;
	for (unsigned int i = 1; i <= this->turnos; i++) {

		cout << "-----------------------TURNO " << i<< "-----------------------" << endl;

		jugadores->iniciarCursor();

		Jugador* jugadorActual;
		while (jugadores->avanzarCursor()) {
			jugadorActual = jugadores->obtenerCursor();

			secretario.cambiarJugador(jugadorActual);

			Tiempo tiempo(jugadorActual);
			tiempo.madurarTodosLosTerrenosDelJugador();

			this->anunciarJugadorYregalarAgua(numeroJugador);

			cout <<endl<<"++Tomando fotos de  sus terrenos al principio de turno, aguarde un momento...++"<< endl<<endl;
			dron.tomarFoto(jugadorActual, numeroJugador, i);

			secretario.atenderJugador();

			cout << "++Tomando fotos de sus terrenos al final de turno, aguarde un momento...++"<< endl<<endl;
			dron.tomarFoto(jugadorActual, numeroJugador, i);

			numeroJugador++;
		}
		numeroJugador = 1;

	}
}

void DirectorDeJuego::anunciarJugadorYregalarAgua(unsigned int numeroJugador) {

	Jugador* jugadorActual = this->jugadores->obtener(numeroJugador);

	Dado dado;

	cout << "/////Jugador " << numeroJugador << "/////" << endl;

	unsigned int resultadoDado = dado.obtenerNumeroRandom();
	cout << "// Obtuviste " << resultadoDado << " en tu dado! Ganaste "<< resultadoDado * 5 << " de agua." << endl;

	unsigned int aguaPerdida = jugadorActual->obtenerTanqueDeAgua()->agregarAgua(resultadoDado * 5);
	if (aguaPerdida != 0) {
		std::cout << "// ****Perdiste " << aguaPerdida<< " unidad(es) de riego!****" << endl;
	}
}

