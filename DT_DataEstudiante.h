#ifndef DT_DATAESTUDIANTE_H
#define DT_DATAESTUDIANTE_H
#include<iostream>
#include "DT_Date.h"

class DT_DataEstudiante {
private:
	std::string nombre;
	std::string descripcion;
	std::string nickname;
	std::string paisResidencia;
	DT_Date* fechaNacimiento;
public:
	DT_DataEstudiante();
	DT_DataEstudiante(std::string nombre,
					  std::string nickname,
					  std::string descripcion,
					  DT_Date* fechaNacimiento,
					  std::string paisResidencia);
	~DT_DataEstudiante();
	
	std::string getNickname();
	std::string getNombre();
	std::string getDescripcion();
	DT_Date* getFechaNacimiento();
	std::string getFechaNacToString();
	std::string getPaisResidencia();
	friend std::ostream& operator<<(std::ostream& os, DT_DataEstudiante* dataEst);
};

#endif
