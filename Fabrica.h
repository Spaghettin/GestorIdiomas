#ifndef FABRICA_H
#define FABRICA_H

#include "ICtrl.h"
#include "Ctrl.h"


class Fabrica {
public:
	Fabrica();
	~Fabrica();
	ICtrl* getControlador();
};

#endif

