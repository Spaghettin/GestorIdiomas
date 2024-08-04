#ifndef DT_DATACURSOCOMPLETO_H
#define DT_DATACURSOCOMPLETO_H

#include<iostream>
#include <set>
#include "DT_DataLeccionConEjercicio.h"
#include "DT_DataCurso.h"
#include "DT_DataEstudianteCurso.h"

class DT_DataCursoCompleto {
public:
	DT_DataCursoCompleto(
		 DT_DataCurso* dataC,
		 std::string nombreIdioma,
		 std::string nombreUsuario,
		 std::set<DT_DataLeccionConEjercicio*> leccionesDeCurso,
		 std::set<DT_DataEstudianteCurso*> estudiantesDeCurso
		 );
	~DT_DataCursoCompleto();
	friend std::ostream& operator<<(std::ostream& os, DT_DataCursoCompleto* dataCC);
	DT_DataCurso* getDataCurso();
	std::string getNombreIdioma();
	std::string getNombreUsuario();
	std::set<DT_DataLeccionConEjercicio*> getLeccionesDeCurso();
	std::set<DT_DataEstudianteCurso*> getDataEstudiantes();
private:
	DT_DataCurso* dataCurso;
	std::string nombreIdioma;
	std::string nombreUsuario;
	std::set<DT_DataLeccionConEjercicio*> leccionesDeCurso;
	std::set<DT_DataEstudianteCurso*> estudiantesDeCurso;
};

#endif
