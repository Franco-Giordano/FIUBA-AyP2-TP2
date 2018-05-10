#include "Almacen.h"
#include <iostream>
using namespace std;

Almacen::Almacen(int N, int M, int dificultad) {
	this->capacidad= (2*(N+M))/dificultad;
	Lista<Cultivo> cultivos;
}

int Almacen::obtenerCapacidad(){
	return this->capacidad;
}

bool Almacen:: capacidadValida(){
	return (cultivos.contarElementos() <= capacidad);
}

void Almacen::agrandarAlmacen(Monedero& monedero, unsigned int capacidadAAgregar, int dificultad){

	int precio= (capacidadAAgregar + dificultad) *10;

	if (monedero.dineroSuficiente(precio)){
		monedero.gastarDinero(precio);
		this->capacidad += capacidadAAgregar;
	}


}

void Almacen::agregarCultivo(Cultivo cultivo){
	if( capacidadValida())
		cultivos.agregar(cultivo);
	else
		cout << "Se llego a la capacidad maxima del almacen." << endl;
}


void Almacen::quitarCultivo(int posicion){
	cultivos.remover(posicion);
}

void Almacen:: mostrarNombresDeCultivosEnElAlmacen(){
	cultivos.iniciarCursor();
	int i=1;
	while ( cultivos.avanzarCursor()){
		cout << "Elemento " << i << "en la lista: " << cultivos.obtener(i).obtenerNombre() << endl;
		i++;
	}

}


Almacen::~Almacen() {
}
