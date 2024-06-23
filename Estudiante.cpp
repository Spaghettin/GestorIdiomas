#include "Estudiante.h"


Estudiante::Estudiante() {
	
}

Estudiante::Estudiante(DT_DataEstudiante* datosEst){
	this->nombre = datosEst->getNombre();
	this->nickname = datosEst->getNickname();
	this->contrasena = datosEst->getContrasena();
	this->descripcion = datosEst->getDescripcion();
	this->fechaNacimiento = datosEst->getFechaNacimiento();
	this->paisResidencia = datosEst->getPaisResidencia();
}

Estudiante::Estudiante(const Estudiante &arg) {
	
}

Estudiante::~Estudiante() {
	
}

date* Estudiante::getFechaNacimiento() const {
	return this->fechaNacimiento;
}

std::string Estudiante::getPaisResidencia() const {
	return this->paisResidencia;
}

Estudiante* Estudiante::crearE(DT_DataEstudiante* datosEst){
	return new Estudiante(datosEst);
}

std::ostream& operator<<(std::ostream& os, Estudiante* est) {
	os  << "\nNickname: " << est->getNickname()
		<< "\nNombre: " << est->getNombre()
		<< "\nContrasena: " << est->getContrasena()
		<< "\nDescripcion: " << est->getDescripcion()
		<< "\nFecha Nacimiento: " << est->getFechaNacimiento()
		<< "\nPaisResidencia: " << est->getPaisResidencia();
	
	return os;
}
