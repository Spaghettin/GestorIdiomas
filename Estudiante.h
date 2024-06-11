#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Usuario.h"
#include<iostream>

using namespace std;

class Estudiante {
public:
	Estudiante();
	Estudiante(const Estudiante &arg);
	~Estudiante();
private:
	string paisResidencia;
	// fechaNacimiento;
};

#endif

