#ifndef DT_DATAESTUDIANTECURSO_H
#define DT_DATAESTUDIANTECURSO_H

#include<iostream>
#include "DT_Date.h"

class DT_DataEstudianteCurso {
public:
	DT_DataEstudianteCurso(std::string nombreEst, DT_Date* fechaIns);
	~DT_DataEstudianteCurso();
	DT_Date* getFechaInscripcion();
	std::string getFechaInscripcionToString();
	std::string getNombreEstudiante();
	friend std::ostream& operator<<(std::ostream& os, DT_DataEstudianteCurso* dataEst);
private:
	std::string nombreEstudiante;
	DT_Date* fechaIns;
};

#endif

