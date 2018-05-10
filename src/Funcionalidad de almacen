#include <iostream>
#include "Almacen.h"

using namespace std;

int main(){

	int filas=5;
	int columnas= 5;
	int dificultad;

	cout << "Ingrese la dificultad: " << endl;
	cin >> dificultad;

	Cultivo c1;
	Cultivo c2;
	Cultivo c3;
	Cultivo c4;

	c1.modificarCultivo("PAPA", 3, 3, 30, 10, 1);
	c2.modificarCultivo("CEBOLLA", 3, 3, 40, 10, 2);
	c3.modificarCultivo("AJO", 3, 3, 110, 10, 3);
	c4.modificarCultivo("LECHUGA", 3, 3, 20, 10, 1);


	Almacen almacen(filas, columnas, dificultad);

	almacen.agregarCultivo(c1);
	almacen.agregarCultivo(c2);
	almacen.agregarCultivo(c3);
	almacen.agregarCultivo(c4);

	almacen.mostrarNombresDeCultivosEnElAlmacen();
}