#ifndef DT_DATAINFOESTUDIANTE_H
#define DT_DATAINFOESTUDIANTE_H
#include<iostream>
#include "date.h"
using namespace std;

class DT_DataInfoEstudiante {
public:
	DT_DataInfoEstudiante();
	DT_DataInfoEstudiante(const DT_DataInfoEstudiante &arg);
	~DT_DataInfoEstudiante();
private:
	string paisResidencia;
	date fechaNacimiento;
};

#endif

