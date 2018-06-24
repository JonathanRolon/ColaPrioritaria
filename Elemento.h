#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>

typedef std::string T;
/* Un elemento consta de una clave y una prioridad de utilizacion */

class Elemento{

	private:

		unsigned prioridad;

		T clave;

	public:

		/*
		 * post: el elemento esta creado con una prioridad y una clave, listo para su uso
		 */
		Elemento(unsigned prioridadInicial, T clave);

		/*
		 * post: devuelve la prioridad o turno del elemento actual
		 */
		unsigned verPrioridad();

		/*
		 * post: devuelve la clave del elemento actual;
		 */
		T obtenerClave();
};

Elemento::Elemento(unsigned prioridadInicial, T clave){

	this->prioridad=prioridadInicial;
	this->clave=clave;
}

unsigned Elemento::verPrioridad(){

	return this->prioridad;
}

T Elemento::obtenerClave(){
	return this->clave;
}

#endif
