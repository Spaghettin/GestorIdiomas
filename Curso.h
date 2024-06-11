#ifndef CURSO_H
#define CURSO_H
#include<iostream>

using namespace std;

class Curso {
public:
	Curso();
	Curso(const Curso &arg);
	~Curso();
private:
	string nombreCurso;
	string descripcion;
	// dificultad;
	bool habilitado;
	int cantidadEjercicios;
	int cantidadLecciones;
};

#endif

