/*
 * ConversorDeDatos.cpp
 *
 *  Created on: 19 may. 2018
 *      Author: frank
 */

#include "ConversorDeDatos.h"
#include <algorithm>

void ConversorDeDatos::convertirAobjeto(std::string* datos, Cultivo &cultivoAmodificar) {
	std::string nombre = datos[0];
	hacerTodoMinusculas(nombre);

	ui precio, rentabilidad, tiempoCosecha, tiempoRecuperacion, consumoAgua;
	std::istringstream(datos[1]) >> precio;
	std::istringstream(datos[2]) >> tiempoCosecha;
	std::istringstream(datos[3]) >> rentabilidad;
	std::istringstream(datos[4]) >> tiempoRecuperacion;
	std::istringstream(datos[5]) >> consumoAgua;

	cultivoAmodificar.modificarCultivo(nombre, precio, tiempoCosecha, rentabilidad, tiempoRecuperacion, consumoAgua);
}

void ConversorDeDatos::convertirAobjeto(std::string* datos, Destino &destinoAmodificar) {
	std::string nombre = datos[1];
	hacerTodoMinusculas(nombre);

	ui distancia, precio;
	std::istringstream(datos[2]) >> distancia;
	std::istringstream(datos[3]) >> precio;

	std::string cultivo = datos[4];
	hacerTodoMinusculas(cultivo);

	if (nombre[0] == ' '){ //quitar posible espacio (' ') al principio
		nombre = nombre.substr(1, nombre.size());
	}

	if (cultivo[0] == ' '){ //quitar posible espacio (' ') al principio
		cultivo = cultivo.substr(1, cultivo.size());
	}

	std::string origen = datos[0];
	hacerTodoMinusculas(origen);

	destinoAmodificar.modificarDestino(origen, nombre, distancia, precio, cultivo);
}

void ConversorDeDatos::hacerTodoMinusculas(std::string& cadena) {
	std::transform(cadena.begin(), cadena.end(), cadena.begin(), ::tolower);
}

