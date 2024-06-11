#ifndef DETRADUCCION_H
#define DETRADUCCION_H
#include "Ejercicio.h"
#include<iostream>

using namespace std;

class DeTraduccion : protected Ejercicio {
public:
	DeTraduccion();
	DeTraduccion(const DeTraduccion &arg);
	~DeTraduccion();
private:
	string solucion;
	string fraseATraducir;
};

#endif

