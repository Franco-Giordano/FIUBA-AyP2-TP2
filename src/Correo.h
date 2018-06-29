#ifndef CORREO_H_
#define CORREO_H_
#include "Destino.h"
#include "Cultivo.h"
#include "Almacen.h"
#include "Catalogo.h"
#include "ListaNombrada.h"

class Correo {
private:
	int costoEnvio;
	Cultivo* cultivoAEnviar;
public:

	//Pre: recibe una lista de destinos validos y el cultivo a enviar.
	// Post: crea el objeto correo, el cual se encargara de los envios que desee realizar el jugador durante el juego
	Correo(Cultivo* cultivoAEnviar);

	// Post: devuelve el cultivo a enviar.
	Cultivo* cultivoParaEnviar();

	//Pre: recibe la posicion en la lista del cultivo que se desea enviar.
	//Post: quita el cultivo que va a ser enviado de la lista de cultivos.
	void enviarCultivo(unsigned int posicionCultivoAEnviar, Almacen* almacen);

	//Post: suma en el monedero del jugador que vende el cultivo la rentabilidad, que se calcula como la resta
	// entre lo que cuesta el envio y del valor del cultivo.
	void cobrar(unsigned int precio, Monedero* monedero);

	// Post: devuelve la rentabilidad del cultivo.
	unsigned int obtenerRentabilidad();
};

#endif /* CORREO_H_ */
