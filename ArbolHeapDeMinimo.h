/*
 * ArbolHeapDeMinimo:
 *
 * Un árbol heap  conceptualmente es un árbol binario completo o casi completo
 * y parcialmente ordenado.
 *
 * Completo significa que tiene ‘aspecto triangular’, es decir que contiene un nodo en la raíz,
 * dos en el nivel siguiente,  y así sucesivamente teniendo todos los niveles ocupados
 * totalmente con una cantidad de nodos que debe ser  2.
 *
 * Casi completo significa que tiene todos los niveles menos el de las hojas
 * ‘saturados’, ocupados  con 1,2,4,8,16, etc. nodos; en el nivel de las hojas
 * puede no cumplirse esta condición, pero los nodos existentes deben estar ubicados ‘a izquierda’
 *
 *‘Parcialmente ordenado’ significa que para cada nodo se cumple que los valores de sus hijos
 * son ambos mayores o iguales que los de su nodo padre (y se llama árbol heap de mínimo).
 */

#ifndef ARBOLHEAPDEMINIMO_H_
#define ARBOLHEAPDEMINIMO_H_

#include "Lista.h"

#include "Elemento.h"

class ArbolHeapDeMinimo{

	private:

		Lista <Elemento*> * arbol;

	public:

		/*
		 * Post: la instancia de arbol queda sin nodos con altura 0 lista para ser usada
		 */
		ArbolHeapDeMinimo();

		/*
		 * Post:libera los recursos asociados al arbol
		 */
		~ArbolHeapDeMinimo();

		/* pre: el arbol debe tener altura al menos 1
		 * post: remueve la raiz y la devuelve, el arbol queda reordenado con un elemento menos
		 */
		Elemento  * extraerRaiz();

		/*
		 * post: se agrega el elemento en la posicion correspondiente, el arbol queda modificado
		 */
		void agregarElemento(Elemento * elemento);

		/*
		 * post: devuelve el tamanio(# de nodos) del arbol
		 */
		unsigned obtenerTamanio();

	private:

		/*
		 * post:el arbol queda ordenado (en valor prioritario) ascendentemente
		 *      desde la raiz hacia las hojas
		 */
		void ordenamientoHeap(Lista <Elemento*> * arbol, unsigned tope);

		/* pre:recibe el arbol a ordenar, tope>0 es la cantidad de nodos del arbol, posicionRaiz=1
		 * post: arbol armado y ordenado de acuerdo al principio de arbol de heap de minimo
		 */
		void armarHeap(Lista <Elemento*>* arbol, unsigned tope, unsigned posicionRaiz);

		/*
		 * post: intercambio realizado entre el elemento de la raiz con el de 'mayor' valor
		 */
		void swap(Lista <Elemento*> * arbol,unsigned raiz,unsigned mayor);

};


ArbolHeapDeMinimo :: ArbolHeapDeMinimo(){

	arbol= new Lista <Elemento*>;
}

void ArbolHeapDeMinimo :: agregarElemento(Elemento * elemento){

	//agrego el elemento como ultima hoja
	arbol->agregar(elemento,arbol->contarElementos()+1);

	//reordeno el arbol
	ordenamientoHeap(arbol, arbol->contarElementos());

}

Elemento  * ArbolHeapDeMinimo :: extraerRaiz(){

	Elemento * raiz=NULL;

	if(!arbol->estaVacia()){

		raiz = arbol->obtener(1);

		Elemento  *  ultimaHoja =  arbol->obtener(arbol->contarElementos());

		arbol->asignar(ultimaHoja,1);

		//borro la ultima hoja
		arbol->remover(arbol->contarElementos());

		//reordeno el arbol
		ordenamientoHeap(arbol,arbol->contarElementos());


	}else{
		throw std:: string("Imposible remover raiz, arbol sin nodos");
	}

	return raiz;
}

unsigned ArbolHeapDeMinimo :: obtenerTamanio(){

	return arbol->contarElementos();
}

void ArbolHeapDeMinimo :: ordenamientoHeap(Lista <Elemento*> * arbol, unsigned tope){

	// Construcción del heap o Build_heap
	for(int i = tope / 2; i > 0; i--){
		armarHeap(arbol, tope, i);
	}

	// extraemos de a uno los elementos del heap
	for(int i=tope; i > 0; i--){

		// se intercambia el valor de la raíz con el de
		//la última hoja
		swap(arbol, 1, i);

		// restauramos el heap en una zona que se redujo en una posición
		armarHeap(arbol, i-1, 1);
	}

}

void ArbolHeapDeMinimo ::armarHeap(Lista <Elemento*>* arbol, unsigned tope, unsigned posicionRaiz)
{

	unsigned posicionMayor = posicionRaiz;

	// raíz del subárbol a analizar
	unsigned posicionHijoIzquierdo = 2*posicionRaiz ;

	// posición hijo izquierdo = 2*posicionRaiz
	unsigned posicionHijoDerecho = 2*posicionRaiz + 1;

	// posición hijo derecho = 2*posicionRaiz + 1
	// si hijo izquierdo es mayor que la raíz
	if (posicionHijoIzquierdo <= tope &&
		arbol->obtener(posicionHijoIzquierdo)->verPrioridad() >
	    arbol->obtener(posicionMayor)->verPrioridad()){

		posicionMayor = posicionHijoIzquierdo;
	}

	// si el hijo derecho es más
	//grande que el mayor hasta aquí
	if (posicionHijoDerecho <= tope &&
		arbol->obtener(posicionHijoDerecho)->verPrioridad() >
	    arbol->obtener(posicionMayor)->verPrioridad()){

		posicionMayor = posicionHijoDerecho;
	}

	// si el mayor no es la raíz
	if (posicionMayor != posicionRaiz)
	{
		swap(arbol,posicionRaiz, posicionMayor);

		armarHeap(arbol, tope, posicionMayor);
	}
}

void ArbolHeapDeMinimo ::swap(Lista <Elemento*> * arbol,unsigned raiz,unsigned mayor){

	Elemento * elemento = NULL;
	elemento = arbol->obtener(raiz);
	arbol->asignar(arbol->obtener(mayor),raiz);
	arbol->asignar(elemento,mayor);

}

ArbolHeapDeMinimo:: ~ ArbolHeapDeMinimo(){

	arbol->iniciarCursor();
	while(arbol->avanzarCursor()){
		delete arbol->obtenerCursor();
	}
	delete arbol;
}

#endif /* ARBOLHEAPDEMINIMO_H_ */
