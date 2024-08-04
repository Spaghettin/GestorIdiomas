#ifndef DT_DATAPROGRESOCURSO_H
#define DT_DATAPROGRESOCURSO_H

#include<iostream>
#include "DT_Date.h"

class DT_DataProgresoCurso {
private:
std::string nombreCurso;
std::string nombreEstudiante;
DT_Date* fechaIns;
bool aprobado;
float progresoCurso;
float progresoLeccion;
public:
	DT_DataProgresoCurso(
			std::string nombreCurso,
			std::string nombreEstudiante,
			DT_Date* fechaIns,
			float progresoCurso,
			float progresoLeccion
			);
	~DT_DataProgresoCurso();
	std::string getNombreCurso();
	std::string getNombreEstudiante();
	std::string getFechaInscripcionToString();
	bool getAprobado();
	std::string getAprobadoToString();
	float getProgresoCurso();
	float getProgresoLeccion();
	friend std::ostream& operator<<(std::ostream& os, DT_DataProgresoCurso* dataPC);
};

#endif

