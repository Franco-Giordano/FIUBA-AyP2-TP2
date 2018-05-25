/*
 * ConversorDeDatos.cpp
 *
 *  Created on: 19 may. 2018
 *      Author: frank
 */

#include "ConversorDeDatos.h"

void ConversorDeDatos::convertirAobjeto(std::string* datos, Cultivo &cultivoAmodificar) {
	std::string nombre = datos[0];

	ui precio, rentabilidad, tiempoCosecha, tiempoRecuperacion, consumoAgua;
	std::istringstream(datos[1]) >> precio;
	std::istringstream(datos[2]) >> tiempoCosecha;
	std::istringstream(datos[3]) >> rentabilidad;
	std::istringstream(datos[4]) >> tiempoRecuperacion;
	std::istringstream(datos[5]) >> consumoAgua;

	cultivoAmodificar.modificarCultivo(nombre, precio, tiempoCosecha, rentabilidad, tiempoRecuperacion, consumoAgua);
}

void ConversorDeDatos::convertirAobjeto(std::string* datos, Destino &destinoAmodificar) {
	std::string nombre = datos[0];
	ui distancia, precio;
	std::istringstream(datos[1]) >> distancia;
	std::istringstream(datos[2]) >> precio;
	std::string cultivo = datos[3];

	destinoAmodificar.modificarDestino(nombre, distancia, precio, cultivo);
}

