#ifndef COLACONPRIORIDAD_H_
#define COLACONPRIORIDAD_H_

#include <string>

#include "ArbolHeapDeMinimo.h"

/*
 *  Cada elemento es un par ordenado (clave, prioridad).
 *  Las claves pueden repetirse y también las prioridades.
 *  Los elementos se almacenan de forma secuencial, como en una cola común,
 *  pero cada nuevo elemento al ser acolado se ubica delante de aquellos de prioridad menor,
 *  si es que hay elementos con estas características.
 *  Si no, se ubicará al final. La operación desacolar elimina el
 *  primer elemento de la cola, al igual que en las colas habituales.
 *
 */

class ColaConPrioridad {

	private:

     	 ArbolHeapDeMinimo * heap;

    public:

        /*
         * post: instancia de Cola vacía y lista para ser usada.
         */
        ColaConPrioridad();

        /*
         * post: devuelve si la Cola no tiene ningún elemento.
         */
        bool estaVacia();

        /*
         * post: agrega 'elemento' en el lugar prioritario de la Cola.
         */
        void acolar(Elemento * elemento);

        /*
         * pre : la Cola no está vacía.
         * post: remueve el minimo de la Cola(elemento de prioridad mas alta = menor valor)
         *       y lo devuelve (devuelve la clave guardada no la prioridad).
         */
        std:: string desacolar();

        /*
         * post: remueve todos los elementos y libera
         *       los recursos tomados por la estructura de datos.
         */
        ~ColaConPrioridad();
};


ColaConPrioridad::ColaConPrioridad() {

	heap = new ArbolHeapDeMinimo;
}

bool ColaConPrioridad::estaVacia() {

    return (this->heap->obtenerTamanio() == 0);
}


void ColaConPrioridad::acolar(Elemento * elemento) {

	heap->agregarElemento(elemento);

}

std::string ColaConPrioridad::desacolar() {

    if (this->estaVacia()) {
        throw std::string("No se puede desacolar, la cola está vacía.");
    }

    std:: string minimo;

    Elemento * aBorrar=heap->extraerRaiz();

    minimo=aBorrar->obtenerClave();

    delete aBorrar;

    return minimo;
}

ColaConPrioridad::~ColaConPrioridad() {

    delete heap;
}



#endif /* COLACONPRIORIDAD_H_ */
