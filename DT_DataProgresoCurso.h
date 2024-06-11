#ifndef DT_DATAPROGRESOCURSO_H
#define DT_DATAPROGRESOCURSO_H
#include<iostream>
#include "date.h"
using namespace std;

class DT_DataProgresoCurso {
public:
	DT_DataProgresoCurso();
	DT_DataProgresoCurso(const DT_DataProgresoCurso &arg);
	~DT_DataProgresoCurso();
private:
	string nombreCurso;
	string nombreEstudiante;
	date fechaIns;
	bool aprobado;
	float progresoCurso;
	float progresoLeccion;
};

#endif

