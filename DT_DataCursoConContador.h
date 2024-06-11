#ifndef DT_DATACURSOCONCONTADOR_H
#define DT_DATACURSOCONCONTADOR_H
#include<iostream>
#include "DT_DataCurso.h"

using namespace std;

class DT_DataCursoConContador {
public:
	DT_DataCursoConContador();
	DT_DataCursoConContador(const DT_DataCursoConContador &arg);
	~DT_DataCursoConContador();
private:
	string nombre;
	string descripcion;
	dificultad dificultad;
	int cantidadLecciones;
	int cantidadEjercicios;
};

#endif

