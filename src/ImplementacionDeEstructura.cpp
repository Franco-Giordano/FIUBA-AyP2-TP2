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

	//Declaro variables que voy a utilizar.
	int cantidadFilas,cantidadColumnas;
	Monedero monedero(5,5,1);
	TanqueDeAgua tanqueAgua(5,5,1);

	//Creo cultivos (estos son los que van a estar en la lista).
	Cultivo papa;
	Cultivo zanahoria;

	//Le asigno datos (esto saldría de los archivos de texto).
	papa.modificarCultivo("papa",1,1,1,1,1);
	zanahoria.modificarCultivo("zanahoria",2,2,2,2,2);

	//Creo los punteros para poder implementar parcela.
	Cultivo* punteroPapa = &papa;
	Cultivo* punteroZanahoria = &zanahoria;

	//Pido cantidad de filas y columnas para crear el terreno.
	cout << "Ingrese cantidad de filas: ";
	cin >> cantidadFilas;
	cout << "Ingrese cantidad de columnas: ";
	cin >> cantidadColumnas;
	Terreno terreno(cantidadFilas,cantidadColumnas);

	//Fuerzo la inicializacion del tanque de agua.
	tanqueAgua.agregarAgua(50);

	/*Muestro por pantalla los creditos y la cantidad de agua del tanque, tanto antes de comprar semillas como despues de
	hacerlo*/
	cout << "CREDITOS: " << monedero.obtenerDineroActual() << endl;
	cout << "TANQUE: " << tanqueAgua.obtenerCantidadDeAguaActual() << endl;
	terreno.obtenerParcela(0,0).sembrarCultivo(punteroPapa,monedero);
	terreno.obtenerParcela(1,1).sembrarCultivo(punteroZanahoria,monedero);
	terreno.obtenerParcela(0,0).regarParcela(tanqueAgua,1);
	cout << "Sembrados 2 terrenos y regados 1." << endl;
	cout << "CREDITOS: " << monedero.obtenerDineroActual() << endl;
	cout << "TANQUE: "<< tanqueAgua.obtenerCantidadDeAguaActual() << endl <<endl ;

	//Muestro por pantalla aquellas parcelas que no estén vacías.
	for (int i = 0; i < terreno.obtenerFilas(); i ++){
		for (int j = 0; j < terreno.obtenerColumnas(); j++){
			if (terreno.obtenerParcela(i,j).obtenerCultivo() != NULL){
				cout << "Nombre: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerNombre() << endl;
				cout << "Costo semilla: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerCostoSemilla() << endl;
				cout << "Rentabilidad: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerRentabilidad() << endl;
				cout << "Tiempo cosecha: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerTiempoCosecha() << endl;
				cout << "Tiempo recuperacion: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerTiempoRecuperacion() << endl;
				cout << "Regada: " << terreno.obtenerParcela(i,j).estaRegada()<< endl << endl;
			}
		}
	}

	//Cultivo las parcelas que sembré.
	terreno.obtenerParcela(0,0).cultivarParcela(monedero);
	terreno.obtenerParcela(1,1).cultivarParcela(monedero);

	//Muestro por pantalla para ver si se suman bien los creditos. Que si lo hacen.
	cout << "CREDITOS: " << monedero.obtenerDineroActual() << endl;
	cout << "TANQUE: "<< tanqueAgua.obtenerCantidadDeAguaActual() << endl <<endl ;

	//Muestro de vuelta las parcelas que no están libres. En este caso no queda ninguna NO vacía. Ya que se liberan bien.
	for (int i = 0; i < terreno.obtenerFilas(); i ++){
		for (int j = 0; j < terreno.obtenerColumnas(); j++){
			if (terreno.obtenerParcela(i,j).obtenerCultivo() != NULL){
				cout << "Nombre: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerNombre() << endl;
				cout << "Costo semilla: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerCostoSemilla() << endl;
				cout << "Rentabilidad: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerRentabilidad() << endl;
				cout << "Tiempo cosecha: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerTiempoCosecha() << endl;
				cout << "Tiempo recuperacion: " << terreno.obtenerParcela(i,j).obtenerCultivo()->obtenerTiempoRecuperacion() << endl;
				cout << "Regada: " << terreno.obtenerParcela(i,j).estaRegada()<< endl << endl;
			}
		}
	}

}
