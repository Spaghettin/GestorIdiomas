#include "Fabrica.h"

Fabrica::Fabrica() {
	
}

Fabrica::Fabrica(const Fabrica &arg) {
	
}

Fabrica::~Fabrica() {
	
}

I_Ctrl* Fabrica::getControlador(){
	return (new Ctrl());
}

