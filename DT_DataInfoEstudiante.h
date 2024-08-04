#ifndef DT_DATAINFOESTUDIANTE_H
#define DT_DATAINFOESTUDIANTE_H
#include<iostream>
#include "DT_Date.h"

class DT_DataInfoEstudiante {
public:
	DT_DataInfoEstudiante(std::string paisRes, DT_Date* fechaNac);
	~DT_DataInfoEstudiante();
	std::string getPaisResidencia();
	std::string getFechaNacimientoToString();
	DT_Date* getFechaNacimiento();
	friend std::ostream& operator<<(std::ostream& os, DT_DataInfoEstudiante* dataInfo);
private:
	std::string paisResidencia;
	DT_Date* fechaNacimiento;
};

#endif

