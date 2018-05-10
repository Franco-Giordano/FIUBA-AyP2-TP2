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
	Monedero monedero(5,5,1);
	TanqueDeAgua tanqueAgua(5,5,1);

	cout << "Ingrese cantidad de filas: ";
	cin >> cantidadFilas;
	cout << "Ingrese cantidad de columnas: ";
	cin >> cantidadColumnas;
	Terreno terreno(cantidadFilas,cantidadColumnas);

	tanqueAgua.agregarAgua(50);

	cout << "CREDITOS: " << monedero.obtenerDineroActual() << endl;
	cout << "TANQUE: " << tanqueAgua.obtenerCantidadDeAguaActual() << endl;
	terreno.obtenerParcela(0,0).sembrarCultivo("Papa",1,1,1,1,monedero,1);
	terreno.obtenerParcela(1,1).sembrarCultivo("Zanahoria",2,3,1,4,monedero,1);
	terreno.obtenerParcela(0,0).regarParcela(tanqueAgua,1);
	cout << "Sembrados 2 terrenos y regados 1." << endl;
	cout << "CREDITOS: " << monedero.obtenerDineroActual() << endl;
	cout << "TANQUE: "<< tanqueAgua.obtenerCantidadDeAguaActual() << endl <<endl ;

	for (int i = 0; i < terreno.obtenerFilas(); i ++){
		for (int j = 0; j < terreno.obtenerColumnas(); j++){
			cout << "Nombre: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerNombre() << endl;
			cout << "Costo semilla: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerCostoSemilla() << endl;
			cout << "Rentabilidad: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerRentabilidad() << endl;
			cout << "Tiempo cosecha: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerTiempoCosecha() << endl;
			cout << "Tiempo recuperacion: " << terreno.obtenerParcela(i,j).obtenerCultivo().obtenerTiempoRecuperacion() << endl;
			cout << "Regada: " << terreno.obtenerParcela(i,j).estaRegada()<< endl << endl;
		}
	}


}
