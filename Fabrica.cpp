#include "Fabrica.h"

Fabrica::Fabrica() {

}

Fabrica::~Fabrica() {

}

ICtrl* Fabrica::getControlador(){
	return (Ctrl::getInstance());
}

