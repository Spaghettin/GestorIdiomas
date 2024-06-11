#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include<iostream>

using namespace std;

class Inscripcion {
public:
	Inscripcion();
	Inscripcion(const Inscripcion &arg);
	~Inscripcion();
private:
	// fechaInsc;
	float progresoCurso;
	float progresoLeccion;
};

#endif

