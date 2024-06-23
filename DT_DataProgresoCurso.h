#ifndef DT_DATAPROGRESOCURSO_H
#define DT_DATAPROGRESOCURSO_H
#include<iostream>
#include "date.h"


class DT_DataProgresoCurso {
public:
	DT_DataProgresoCurso();
	DT_DataProgresoCurso(const DT_DataProgresoCurso &arg);
	~DT_DataProgresoCurso();
private:
	std::string nombreCurso;
	std::string nombreEstudiante;
	date fechaIns;
	bool aprobado;
	float progresoCurso;
	float progresoLeccion;
};

#endif

