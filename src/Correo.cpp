#include "Correo.h"
#include <iostream>
using namespace std;

Correo::Correo(CatalogoDe<Destino*>* destinos, Cultivo* cultivoAEnviar)
{
	this->destinos=destinos;
	this->costoEnvio=0;
	this->cultivoAEnviar=cultivoAEnviar;
}

Cultivo* Correo::cultivoParaEnviar()
{
	return cultivoAEnviar;
}

void Correo::enviarCultivo(Almacen* almacen)
{
	for(unsigned int i=1; i<=almacen->cultivos->contarElementos(); i++)
	{
		if(almacen->cultivos->obtener(i) == cultivoAEnviar)
			almacen->quitarCultivo(i);
	}
}

void Correo::cobrar(Almacen* almacen, Destino* destino, Monedero* monedero)
{
	unsigned int rentabilidad=obtenerRentabilidad(almacen, destino);
	int ganancia=costoEnvio+rentabilidad;
	monedero->sumarDinero(ganancia);
}

unsigned int Correo::obtenerRentabilidad(Almacen* almacen, Destino* destino)
{
	unsigned int rentabilidad=0;
	costoEnvio=calcularCostoEnvio(destino);
	for(unsigned int i=1; i<=almacen->cultivos->contarElementos(); i++)
	{
		if(cultivoAEnviar==almacen->cultivos->obtener(i))
			rentabilidad=cultivoAEnviar->obtenerRentabilidad();
	}
	return rentabilidad;
}

int Correo::calcularCostoEnvio(Destino* destino)
{
	int costoEnvio=0;
	for(unsigned int i=1; i<=destinos->obtenerCantidadDisponible(); i++)
	{
		if(destino==destinos->obtenerPosicion(i))
			costoEnvio=(destino->obtenerPrecio()*destino->obtenerDistancia());
	}
	return costoEnvio;
}