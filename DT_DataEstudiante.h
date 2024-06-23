#ifndef DT_DATAESTUDIANTE_H
#define DT_DATAESTUDIANTE_H
#include<iostream>
#include "date.h"

class DT_DataEstudiante {
private:
	std::string nombre;
	std::string descripcion;
	std::string contrasena;
	std::string nickname;
	std::string paisResidencia;
	date* fechaNacimiento;
public:
	DT_DataEstudiante();
	DT_DataEstudiante(std::string nombre,
					  std::string nickname,
					  std::string contrasena,
					  std::string descripcion,
					  date* fechaNacimiento,
					  std::string paisResidencia);
	DT_DataEstudiante(const DT_DataEstudiante &arg);
	~DT_DataEstudiante();
	
	std::string getNickname() const;
	std::string getContrasena() const;
	std::string getNombre() const;
	std::string getDescripcion() const;
	date* getFechaNacimiento() const;
	std::string getPaisResidencia() const;
};

#endif
