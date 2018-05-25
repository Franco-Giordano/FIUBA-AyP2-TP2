/*
 * Secretario.cpp
 *
 *  Created on: 21 may. 2018
 *      Author: frank
 */

#include "Secretario.h"
#include <sstream>
#include "Correo.h"

using namespace std;

Secretario::Secretario(Jugador* jugador, CatalogoDe<Cultivo>* pCatalogoSemillas, CatalogoDe<Destino>* pCatalogoDestinos) {

	this -> turnos = obtenerNumero(1, "Determine la cantidad de turnos totales. ");
	this -> numeroDeJugadores = obtenerNumero(1, "Determine la cantidad de jugadores. ");
	this -> filas = obtenerNumero(1,"Determine la cantidad de filas del terreno. ");
	this -> columnas = obtenerNumero(1,"Determine la cantidad de columnas del terreno. ");
	this -> dificultad = obtenerNumero(1, 3, "Determine la dificultad, siendo 1 la mas facil y 3 la mas dificil. ");

	this -> jugador = jugador;
	this -> catalogoSemillas = pCatalogoSemillas;
	this -> catalogoDestinos = pCatalogoDestinos;
}



int Secretario::obtenerNumero(int minimo, int maximo, std::string textoOpcional /*= ""*/) {
	std::string input;
	int numero;

	do {
		std::cout << textoOpcional <<  "Ingrese un numero entre "<< minimo << " y "<<maximo<<": ";
		std::cin >> input;
		std::istringstream(input) >> numero;

	}
	while (numero < minimo || numero > maximo);

	std::cout<< std::endl;

	return numero;
}


int Secretario::obtenerNumero(int minimo, std::string textoOpcional /*= ""*/) {
	std::string input;
	int numero;

	do {
		std::cout << textoOpcional << "Ingrese un numero mayor a " << minimo <<": ";
		std::cin >> input;
		std::istringstream(input) >> numero;
	}
	while (numero < minimo);
	std::cout<< std::endl;

	return numero;
}


int Secretario::obtenerCantidadTurnos() {
	return this -> turnos;
}


int Secretario::obtenerFilas() {
	return this -> filas;
}


int Secretario::obtenerColumnas() {
	return this -> columnas;
}


int Secretario::obtenerNumeroDeJugadores() {
	return this -> numeroDeJugadores;
}


int Secretario::obtenerDificultad() {
	return this -> dificultad;
}


void Secretario::atenderJugador() {

	Acciones acciones(this->jugador);
	bool pasarTurno = false;

	while (!pasarTurno) {
		unsigned int eleccion = acciones.obtenerAccionDeJugador();
		pasarTurno = this->administrarEleccion(eleccion, acciones);

	}
}


bool Secretario::administrarEleccion(unsigned int eleccion, Acciones acciones) {

	bool pasarTurno = false;

	unsigned int fila;
	unsigned int columna;
	Terreno* terreno;

	if (eleccion >= 1 && eleccion <= 3) { //Si la eleccion es sembrar, cosechar o regar.

		terreno = jugador-> obtenerListaTerreno() -> obtener(this->obtenerTerrenoDeJugador()) ;
		fila = this->obtenerNumero(1, this->filas,"Determine numero de fila. ");
		columna = this->obtenerNumero(1, this->columnas,"Determine numero de columna. ");
	}


	switch (eleccion) {
		case 1: {
			this->gestionarSiembra(terreno, fila, columna);
		break; }
		case 2:
			this->gestionarCosecha(terreno, fila, columna);
		break;
		case 3:
			this->gestionarRiego(terreno, fila, columna);
		break;
		case 4:
			this->gestionarEnvioCosecha(acciones);
		break;
		case 5: {
			this->gestionarCompraTerreno();
		break; }
		case 6: {
			this->gestionarVentaTerreno();
		break; }
		case 7: {
			this->gestionarAmpliarTanque();
		break; }
		case 8: {
			this->gestionarAmpliarAlmacen();
		break; }
		case 9:
			pasarTurno = true;
		break;

	}

	return pasarTurno;
}



void Secretario::gestionarSiembra(Terreno* terreno, unsigned int fila, unsigned int columna) {
	Acciones acciones(this->jugador);
	Peon peon;
	Cultivo* cultivoElegido = seleccionarCultivoDeCatalogo();
	if (acciones.esSiembraValida(terreno, fila, columna,cultivoElegido)) {
		peon.sembrar(terreno->obtenerParcela(fila, columna), this->jugador->obtenerMonedero(), cultivoElegido);
		cout << "**Siembra correcta**"<<endl<<endl;
	}
	else {
		cout << "**Creditos insuficientes o parcela ya ocupada.**" <<endl<<endl;
	}
}

void Secretario::gestionarCosecha(Terreno* terreno, unsigned int fila, unsigned int columna) {
	Peon peon;
	Acciones acciones(this->jugador);
	if (acciones.esCosechaValida(terreno, fila, columna)){
		peon.cosechar(terreno->obtenerParcela(fila, columna), jugador->obtenerAlmacen());
		cout << "**Cosecha exitosa**" <<endl<<endl;
	}
	else {
		cout << "**La parcela no puede cosecharse o no hay espacio en el almacen**"<<endl<<endl;
	}
}

void Secretario::gestionarRiego(Terreno* terreno, unsigned int fila, unsigned int columna) {
	Peon peon;
	Acciones acciones(jugador);
	if (acciones.esRiegoValido(terreno,fila,columna)) {
		peon.regar(terreno->obtenerParcela(fila,columna), this->jugador->obtenerTanqueDeAgua());
		cout<< "**Riego exitoso**"<<endl<<endl;
	}
	else {
		cout<< "**La parcela no esta plantada, ya esta regada o no posees agua suficiente**"<<endl<<endl;
	}
}

void Secretario::gestionarEnvioCosecha(Acciones acciones) {

	if (this->jugador->obtenerAlmacen()->contarCultivos() > 0) {
		cout << "Escoja cual de sus cultivos quiere vender: "<<endl;
		this->jugador->obtenerAlmacen()->mostrarNombresDeCultivosEnElAlmacen();
		int numCultivoAEnviar=this->obtenerNumero(1,this->jugador->obtenerAlmacen()->contarCultivos(),"");
		Lista<Destino*>* destinosValidos = new Lista<Destino*>;
		acciones.obtenerDestinosValidos(destinosValidos, this->jugador->obtenerAlmacen()->
										obtenerCultivoEnPosicion(numCultivoAEnviar),this->catalogoDestinos);
		if (destinosValidos->contarElementos()!=0)
		{
			cout<<"�A cual de estos destinos quiere enviar la cosecha?"<<endl;
			acciones.imprimirListaDestinos(destinosValidos);
			unsigned int destinoEscojido=this->obtenerNumero(1,destinosValidos->contarElementos(),"");
			Correo correo(destinosValidos, this->jugador->obtenerAlmacen()->obtenerCultivoEnPosicion(numCultivoAEnviar));
			correo.enviarCultivo(numCultivoAEnviar, this->jugador->obtenerAlmacen());
			correo.cobrar(destinosValidos->obtener(destinoEscojido), this->jugador->obtenerMonedero());
		}
		else {
			cout<<"No hay ningun comprador que acepte su cosecha."<<endl;
		}
	}
	else
		cout<<"No posee cultivos en el almacen."<<endl;
}

void Secretario::gestionarCompraTerreno() {
	Mercado mercado(this->dificultad);
	Acciones acciones(this->jugador);

	unsigned int costoNuevoTerreno = filas*columnas*dificultad*jugador->obtenerListaTerreno()->contarElementos();

	string costoSTR = this->convertirIntAString(costoNuevoTerreno);

	bool quiereContinuar = this->obtenerNumero(0, 1, "El precio es de "+costoSTR+" creditos, escoja 0 para CANCELAR, 1 para CONTINUAR. ");

	if (quiereContinuar && acciones.puedeComprarTerreno(this->dificultad, this->filas, this->columnas)){
		mercado.venderTerrenoAJugador(jugador, this->filas, this->columnas);
		cout<<"**Compra exitosa**"<<endl<<endl;
	}
	else {
		cout<<"**Creditos insuficientes**"<<endl<<endl;
	}

}

void Secretario::gestionarVentaTerreno() {
	Acciones acciones(this->jugador);
	Mercado mercado(this->dificultad);

	if (acciones.tieneMasDeUnTerreno()) {
		unsigned int posicionT = obtenerNumero(1, jugador->obtenerListaTerreno()->contarElementos(),
				"Cual de sus terrenos desea vender? ");
		bool aceptaPerderCosechas = this->advertirQuePuedePerderCosechas(posicionT);

		if (aceptaPerderCosechas){
			unsigned int costoActual = filas*columnas*dificultad*jugador->obtenerListaTerreno()->contarElementos() / 2;
			string costoSTR = this->convertirIntAString(costoActual);
			bool aceptaPrecio = this->obtenerNumero(0, 1, "Se lo recompensara con "+costoSTR+" creditos, escoja 0 para CANCELAR, 1 para CONTINUAR. ");

			if (aceptaPrecio){
				mercado.comprarTerrenoDeJugador(jugador, posicionT, costoActual);
			}
		}
	}
	else {
		cout << "**Debe poseer al menos dos terrenos para continuar la venta**";
	}
}

void Secretario::gestionarAmpliarTanque() {
	Acciones acciones(this->jugador);
	Mercado mercado(this->dificultad);

	unsigned int ampliacionElegida = this->obtenerNumero(1, "Determine en cuantas unidades desea ampliar su tanque. ");
	if (acciones.compraCapacidadTanqueValida(columnas, this->dificultad)) {
		mercado.venderCapacidadDeTanque(this->jugador, ampliacionElegida);
		cout << "**Ampliacion exitosa**"<<endl<<endl;
	}
	else {
		cout<<"**Dinero insuficiente**"<<endl<<endl;
	}
}

void Secretario::gestionarAmpliarAlmacen(){
	Acciones acciones(jugador);
	Mercado mercado(this->dificultad);

	unsigned int capacidadElegida = this->obtenerNumero(1, "Determine en cuantas unidades desea ampliar su almacen. ");
	if (acciones.compraCapacidadAlmacenValida(capacidadElegida, this->dificultad)) {
		mercado.venderCapacidadDeTanque(jugador, capacidadElegida);
		cout << "**Ampliacion exitosa**"<<endl<<endl;
	}
	else {
		cout<<"**Dinero insuficiente**"<<endl<<endl;
	}
}


unsigned int Secretario::obtenerTerrenoDeJugador() {
	return obtenerNumero(1, this->jugador->obtenerListaTerreno()->contarElementos(), "Cual de sus terrenos desea trabajar? ");
}



Cultivo* Secretario::seleccionarCultivoDeCatalogo() {
	cout << "Seleccione un cultivo a sembrar: "<<std::endl;
	for (unsigned int i =0; i < catalogoSemillas->obtenerCantidadDisponible(); i++) {
		cout<< i+1 << ". " << catalogoSemillas->obtenerPosicion(i)->obtenerNombre() << " //";
		cout << " Precio: " << catalogoSemillas->obtenerPosicion(i)->obtenerCostoSemilla() << " //";
		cout << " Rentabilidad: "<<catalogoSemillas->obtenerPosicion(i)->obtenerRentabilidad() << " //";
		cout << " Tiempo hasta cosecha: " << catalogoSemillas->obtenerPosicion(i)->obtenerTiempoCosecha() << "."<<endl;

		cout << endl;
	}

	return catalogoSemillas->obtenerPosicion(this->obtenerNumero(1, catalogoSemillas->obtenerCantidadDisponible()) - 1);
}


bool Secretario::advertirQuePuedePerderCosechas(unsigned int posicionTerreno) {
	bool deseaContinuar = true;
	if (!jugador->obtenerListaTerreno()->obtener(posicionTerreno)->estaTodoVacio()) {
		string posicionSTR = this->convertirIntAString(posicionTerreno);
		deseaContinuar = this->obtenerNumero(0, 1, "Advertencia! El terreno "+posicionSTR+" NO esta vacio."+
				" Esto significa que cualquier cultivo y potencial ganancia seran perdidas."
				" Escoja 0 para CANCELAR, 1 para CONTINUAR. ");
	}

	return deseaContinuar;
}

void Secretario::cambiarJugador(Jugador* jugador){
	this->jugador= jugador;
}


string Secretario::convertirIntAString(int i) {
	string resultado;
	stringstream convertidor;
	convertidor << i;
	resultado = convertidor.str();
	return resultado;
}


