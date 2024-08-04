#include "DT_DataEstudiante.h"

DT_DataEstudiante::DT_DataEstudiante(std::string nickname,
									 std::string nombre,
									 std::string descripcion,
									 DT_Date* fechaNacimiento,
									 std::string paisResidencia){
	this->nickname = nickname;
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->paisResidencia = paisResidencia;
	this->fechaNacimiento = fechaNacimiento;
}

DT_DataEstudiante::~DT_DataEstudiante() {
	
}

std::string DT_DataEstudiante::getNickname() {
	return this->nickname;
}

std::string DT_DataEstudiante::getNombre() {
	return this->nombre;
}

std::string DT_DataEstudiante::getDescripcion() {
	return this->descripcion;
}

DT_Date* DT_DataEstudiante::getFechaNacimiento() {
	return this->fechaNacimiento;
}

std::string DT_DataEstudiante::getPaisResidencia() {
	return this->paisResidencia;
}

std::string DT_DataEstudiante::getFechaNacToString() {
	DT_Date* fechaNac = this->fechaNacimiento;
	std::string fechaString = (
			std::to_string(fechaNac->getDia()) + "/"
			+ std::to_string(fechaNac->getMes()) + "/"
			+ std::to_string(fechaNac->getAno())
			);
	return fechaString;
}

std::ostream& operator<<(std::ostream& os, DT_DataEstudiante* dataEst) {
	os << "\nNickname: " << dataEst->getNickname()
		<< "\nNombre: " << dataEst->getNombre()
		<< "\nDescripcion: " << dataEst->getDescripcion()
		<< "\nFecha de nacimiento: " << dataEst->getFechaNacToString()
		<< "\nPais de residencia: " << dataEst->getPaisResidencia();

	return os;
}
