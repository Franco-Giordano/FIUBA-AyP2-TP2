

#include <iostream>
#include "LectorCSV.h"
#include "ConversorDeDatos.h"
#include "CatalogoDeSemillas.h"

typedef unsigned int ui;

using namespace std;



int main(){

	LectorCSV lectorDeCosas("RUTA_ARCHIVO_SEMILLAS", 6);

	Lista<std::string*>* datos = lectorDeCosas.obtenerLista();

	CatalogoDeSemillas todasLasSemillas(datos);

	Cultivo* actual;
	for (unsigned int i = 0; i < todasLasSemillas.obtenerCantidadDisponible(); i++) {
		actual = todasLasSemillas.obtenerPosicion(i);

		cout << actual->obtenerNombre() <<" " << actual->obtenerCostoSemilla() << " " << actual->obtenerTiempoCosecha() << " " <<
				actual->obtenerRentabilidad() << " "<< actual->obtenerTiempoRecuperacion()
				<< " "<<actual->obtenerConsumoAgua() << endl << "--------------------------"<< endl;
	}

	return 0;

}

