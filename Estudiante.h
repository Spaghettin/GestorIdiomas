#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Usuario.h"
#include "date.h"
#include "iostream"
#include "DT_DataEstudiante.h"


class Estudiante : public Usuario {
private:
	std::string paisResidencia;
	date* fechaNacimiento;
public:
	Estudiante();
	Estudiante(DT_DataEstudiante* datosEst);
	Estudiante(const Estudiante &arg);
	~Estudiante();
	
	date* getFechaNacimiento() const;
	std::string getPaisResidencia() const;
	
};

#endif
	

