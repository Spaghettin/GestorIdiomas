#include "DT_DataUsuarioGenerico.h"

DT_DataUsuarioGenerico::DT_DataUsuarioGenerico(
	   std::string nickname, 
	   std::string descripcion,
	   DT_DataInfoEstudiante* dataEst,
	   DT_DataInfoProfesor* dataProf
	   ) {
	this->nickname = nickname;
	this->descripcion = descripcion;
	this->datosEstudiante = dataEst;
	this->datosProfesor = dataProf;
}

DT_DataUsuarioGenerico::~DT_DataUsuarioGenerico() {
	
}

std::string DT_DataUsuarioGenerico::getNickname() {
	return this->nickname;
}

std::string DT_DataUsuarioGenerico::getDescripcion() {
	return this->descripcion;
}

DT_DataInfoEstudiante* DT_DataUsuarioGenerico::getDataInfoEstudiante() {
	return this->datosEstudiante;
}

DT_DataInfoProfesor* DT_DataUsuarioGenerico::getDataInfoProfesor() {
	return this->datosProfesor;
}

std::ostream& operator<<(std::ostream& os, DT_DataUsuarioGenerico* dataUsr) {
	
	os << "\nNickname: " << dataUsr->getNickname()
		<< "\nDescripcion: " << dataUsr->getDescripcion();
	
	if (dataUsr->getDataInfoEstudiante() == nullptr) {
		os << "\n" << dataUsr->getDataInfoProfesor();
	}
	
	if (dataUsr->getDataInfoProfesor() == nullptr) {
		os << "\n" << dataUsr->getDataInfoEstudiante();
	}
	
	return os;
}
