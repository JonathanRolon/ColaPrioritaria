# include <iostream>

#include "ColaConPrioridad.h"

using namespace std;

int main(){

	ColaConPrioridad CCP;

   //paso prioridad y clave en este caso un string(se puede cambiar en el tipo de dato en la
   //clase elemento)
	Elemento * E1 = new Elemento(40,"San Juan");
	Elemento * E2 = new Elemento(100,"Mendoza");
	Elemento * E3 = new Elemento(2,"San Luis");
	Elemento * E4 = new Elemento(50,"Catamarca");
	Elemento * E5 = new Elemento(100,"Jujuy");
	Elemento * E6 = new Elemento(1,"tu vieja");

	CCP.acolar(E1);
	CCP.acolar(E2);
	CCP.acolar(E3);
	CCP.acolar(E4);
	CCP.acolar(E5);
	CCP.acolar(E6);

	cout<<"La raiz es : "<<CCP.desacolar()<<endl;
	cout<<"La raiz es : "<<CCP.desacolar()<<endl;
	cout<<"La raiz es : "<<CCP.desacolar()<<endl;
	cout<<"La raiz es : "<<CCP.desacolar()<<endl;
	cout<<"La raiz es : "<<CCP.desacolar()<<endl;
	cout<<"La raiz es : "<<CCP.desacolar()<<endl;

	return 0;
}
