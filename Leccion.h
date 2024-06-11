#ifndef LECCION_H
#define LECCION_H
#include<iostream>

using namespace std;

class Leccion {
public:
	Leccion();
	Leccion(const Leccion &arg);
	~Leccion();
private:
	string tema;
	string objetivo;
	int idLeccion;
};

#endif

