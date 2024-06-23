#ifndef DT_DATACURSOCOMPLETO_H
#define DT_DATACURSOCOMPLETO_H
#include<iostream>
#include <set>
#include "DT_DataLeccionConEjercicio.h"
#include "DT_DataCurso.h"
#include "DT_DataEstudianteCurso.h"
using namespace std;

class DT_DataCursoCompleto {
public:
	DT_DataCursoCompleto();
	DT_DataCursoCompleto(const DT_DataCursoCompleto &arg);
	~DT_DataCursoCompleto();
private:
	DT_DataCurso curso;
	std::string nombreIdioma;
	std::string nombreUsuario;
	set<DT_DataLeccionConEjercicio> leccion;
	set<DT_DataEstudianteCurso> estudianteCurso;
	bool habilitado;
};

#endif

