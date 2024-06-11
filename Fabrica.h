#ifndef FABRICA_H
#define FABRICA_H
#include "I_Ctrl.h"
#include "Ctrl.h"
class Fabrica {
public:
	Fabrica();
	Fabrica(const Fabrica &arg);
	~Fabrica();
	
	I_Ctrl* getControlador();
private:
};

#endif

