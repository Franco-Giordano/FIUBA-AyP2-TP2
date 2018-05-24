#ifndef CORREO_H_
#define CORREO_H_
#include "Destino.h"
#include "Cultivo.h"
#include "Almacen.h"
#include "Catalogo.h"

class Correo{
private:
	Lista<Destino*>* destinosValidos;
	int costoEnvio;
	Cultivo* cultivoAEnviar;
public:

	Correo(Lista<Destino*>* destinosValidos, Cultivo* cultivoAEnviar);

	Cultivo* cultivoParaEnviar();

	void enviarCultivo(unsigned int posicionCultivoAEnviar, Almacen* almacen);

	void cobrar(Destino* destino, Monedero* monedero);

	unsigned int obtenerRentabilidad();

	int calcularCostoEnvio(Destino* destino);
};


#endif /* CORREO_H_ */
