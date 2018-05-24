#ifndef CORREO_H_
#define CORREO_H_
#include "Destino.h"
#include "Cultivo.h"
#include "Almacen.h"
#include "Catalogo.h"

class Correo{
private:
	CatalogoDe<Destino*>* destinos;
	int costoEnvio;
	Cultivo* cultivoAEnviar;
public:

	Correo(CatalogoDe<Destino*>* destinos, Cultivo* cultivoAEnviar);

	Cultivo* cultivoParaEnviar();

	void enviarCultivo(Almacen* almacen);

	void cobrar(Almacen* almacen, Destino* destino, Monedero* monedero);

	unsigned int obtenerRentabilidad(Almacen* almacen, Destino* destino);

	int calcularCostoEnvio(Destino* destino);
};


#endif /* CORREO_H_ */
