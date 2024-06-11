#ifndef DT_DATAESTUDIANTE_H
#define DT_DATAESTUDIANTE_H
#include<iostream>
#include "date.h"
using namespace std;

class DT_DataEstudiante {
public:
	DT_DataEstudiante();
	DT_DataEstudiante(string nombre,
					  string descripcion,
					  string nickname,
					  string paisResidencia,
					  date* fechaNacimiento);
	DT_DataEstudiante(const DT_DataEstudiante &arg);
	~DT_DataEstudiante();
private:
	string nombre;
	string descripcion;
	string nickname;
	string paisResidencia;
	date* fechaNacimiento;
};

#endif

