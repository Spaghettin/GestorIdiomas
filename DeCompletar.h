#ifndef DECOMPLETAR_H
#define DECOMPLETAR_H
#include "Ejercicio.h"
#include<iostream>

using namespace std;

class DeCompletar : protected Ejercicio {
public:
	DeCompletar();
	DeCompletar(const DeCompletar &arg);
	~DeCompletar();
private:
	string solucion;
	string fraseIncompleta;
	//Hacer el set de soluciones
};

#endif

