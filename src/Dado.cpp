#include "Dado.h"
#include <cstdlib>
#include <ctime>

Dado::Dado() {
	this->numeroRandom=0;

}

void Dado::tirarDado(){
	srand (time(0));
	this->numeroRandom= (1 + rand() % 6);
}

int Dado::obtenerNumeroRandom(){
	tirarDado();
	return this->numeroRandom;
}

Dado::~Dado() {
}

