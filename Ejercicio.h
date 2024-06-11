#ifndef EJERCICIO_H
#define EJERCICIO_H
#include<iostream>

using namespace std;

class Ejercicio {
public:
	Ejercicio();
	Ejercicio(const Ejercicio &arg);
	~Ejercicio();
private:
	string descripcion;
	int idEjerccio;
};

#endif

