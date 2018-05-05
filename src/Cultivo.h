/*
 * Cultivo.h
 *
 *  Created on: 4 may. 2018
 *      Author: federico
 */

#ifndef Cultivo_H_
#define Cultivo_H_

#include <string>

class Cultivo{

private:

	std::string nombre;
	int costoSemilla;
	int tiempoCosecha;
	int rentabilidad;
	int tiempoRecuperacion;

public:

	//Post: Crea un Cultivo inicializado con sus valores numéricos en 0 y con nombre "VACIO".
	Cultivo();

	//Pre:  Los datos deben de ser validos.
	//Post:  Modifica las propiedades del Cultivo con los datos recibidos por parámetro.
	void modificarCultivo(std::string nombreRecibido, int costoSemillaRecibido, int tiempoCosechaRecibido, int rentabilidadRecibida, int tiempoRecuperacionRecibido);

	//Post: Devuelve el nombre.
	std::string obtenerNombre();

	//Post: Devuelve el costo de la semilla.
	int obtenerCostoSemilla();

	//Post: Devuelve la rentabilidad.
	int obtenerRentabilidad();

	//Post: Devuelve el tiempo de cosecha.
	int obtenerTiempoCosecha();

	//Post: Devuelve el tiempo de recuperación.
	int obtenerTiempoRecuperacion();


};

#endif /* Cultivo_H_ */

