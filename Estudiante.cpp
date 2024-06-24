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

