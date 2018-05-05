/*
 * Implementacion.cpp
 *
 *  Created on: 4 may. 2018
 *      Author: federico
 */


#include "Terreno.h"
#include <iostream>

using namespace std;

int main(){

	int cantidadFilas,cantidadColumnas;

	cout << "Ingrese cantidad de filas: ";
	cin >> cantidadFilas;
	cout << "Ingrese cantdidad de columnas: ";
	cin >> cantidadColumnas;
	Terreno terreno(cantidadFilas,cantidadColumnas);

	terreno.obtenerParcela(0,0).obtenerCultivo().modificarCultivo("Papa",1,1,1,1);
	terreno.obtenerParcela(1,1).obtenerCultivo().modificarCultivo("Zanahoria",2,3,1,4);

	for (int i = 0; i < terreno.obtenerFilas(); i ++){
		for (int j = 0; j < terreno.obtenerColumnas(); j++){
			cout << "Nombre: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerNombre() << endl;
			cout << "Costo semilla: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerCostoSemilla() << endl;
			cout << "Rentabilidad: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerRentabilidad() << endl;
			cout << "Tiempo cosecha: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerTiempoCosecha() << endl;
			cout << "Tiempo recuperacion: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerTiempoRecuperacion() << endl << endl;
		}
	}


}
