#include "DT_DataEstudiante.h"

DT_DataEstudiante::DT_DataEstudiante() {
	
}

DT_DataEstudiante::DT_DataEstudiante(std::string nickname,
									 std::string nombre,
									 std::string contrasena,
									 std::string descripcion,
									 date* fechaNacimiento,
									 std::string paisResidencia){
	this->nickname = nickname;
	this->nombre = nombre;
	this->contrasena = contrasena;
	this->descripcion = descripcion;
	this->paisResidencia = paisResidencia;
	this->fechaNacimiento = fechaNacimiento;
}

DT_DataEstudiante::DT_DataEstudiante(const DT_DataEstudiante &arg) {
	
}

DT_DataEstudiante::~DT_DataEstudiante() {
	
}

std::string DT_DataEstudiante::getNickname() const {
	return this->nickname;
}

std::string DT_DataEstudiante::getContrasena() const {
	return this->contrasena;
}

std::string DT_DataEstudiante::getNombre() const {
	return this->nombre;
}

std::string DT_DataEstudiante::getDescripcion() const {
	return this->descripcion;
}

date* DT_DataEstudiante::getFechaNacimiento() const {
	return this->fechaNacimiento;
}

std::string DT_DataEstudiante::getPaisResidencia() const {
	return this->paisResidencia;
}
