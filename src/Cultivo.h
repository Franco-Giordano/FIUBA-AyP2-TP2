/*
 * Cultivo.h
 *
 *  Created on: 4 may. 2018
 *      Author: federico
 */

#ifndef Cultivo_H_
#define Cultivo_H_

#include <string>

class Cultivo {

private:

	std::string nombre;
	unsigned int costoSemilla;
	unsigned int tiempoCosecha;
	unsigned int rentabilidad;
	unsigned int tiempoRecuperacion;
	unsigned int consumoAgua;

public:

	//Post: Crea un Cultivo inicializado con sus valores numericos en 0 y nombre vacio.
	Cultivo();

	//Pre:  Los parametros numericos deben de ser mayores a 0.
	//Post:  Modifica las propiedades del Cultivo con los datos recibidos por parametro.
	void modificarCultivo(std::string nombreRecibido, unsigned int costoSemillaRecibido, unsigned int tiempoCosechaRecibido,
												unsigned int rentabilidadRecibida, unsigned int tiempoRecuperacionRecibido, unsigned int consumoAguaRecibido);

	//Post: Devuelve el nombre.
	std::string obtenerNombre();

	//Post: Devuelve el costo de la semilla.
	unsigned int obtenerCostoSemilla();

	//Post: Devuelve la rentabilidad.
	unsigned int obtenerRentabilidad();

	//Post: Devuelve el tiempo de cosecha.
	unsigned int obtenerTiempoCosecha();

	//Post: Devuelve el tiempo de recuperacion.
	unsigned int obtenerTiempoRecuperacion();

	//Post: Devuelve el consumo de agua del cultivo.
	unsigned int obtenerConsumoAgua();

};

#endif /* Cultivo_H_ */

