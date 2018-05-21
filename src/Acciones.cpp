#include "Acciones.h"
#include <limits>
using namespace std;

Acciones::Acciones(Jugador* pJugador){
	opcionElegida=0;
	jugador = pJugador;
}

unsigned int Acciones::obtenerAccionDeJugador(){
	unsigned int opcion;
	cout<<"Estas son las acciones que puede realizar, elija la que desea:"<<endl;
	cout<<"1. Sembrar"<<endl;
	cout<<"2. Cosechar"<<endl;
	cout<<"3. Regar"<<endl;
	cout<<"4. Enviar una cosecha"<<endl;
	cout<<"5. Comprar un terreno"<<endl;
	cout<<"6. Vender un terreno"<<endl;
	cout<<"7. Comprar capacidad del tanque de agua"<<endl;
	cout<<"8. Comprar capacidad del almacen"<<endl;
	cout<<"9. Pasar de turno"<<endl;
	cin>>opcion;
	while (!opcionValida(1,9,opcion))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Opcion invalida, ingrese otra: "<<endl;
		cin>>opcion;
	}
	opcionElegida=opcion;
	return opcionElegida;
}

bool Acciones::opcionValida(unsigned int minimo,unsigned int maximo, unsigned int opcion)
{
	return (opcion>=minimo && opcion<=maximo);
}

bool Acciones::esSiembraValida(Parcela* parcelaElegida, Cultivo* cultivoElegido) {

	bool puedeComprarSemilla = jugador->obtenerMonedero()->dineroSuficiente(cultivoElegido->obtenerCostoSemilla());
	return parcelaElegida->sePuedeSembrar() && puedeComprarSemilla;
}


bool Acciones::esRiegoValido(Parcela* parcelaElegida) {
	bool hayAguaSuficiente = jugador->obtenerTanqueDeAgua()->obtenerCantidadDeAguaActual() >= parcelaElegida->obtenerCultivo()->obtenerConsumoAgua();
	return !parcelaElegida->estaRegada() && hayAguaSuficiente;
}













