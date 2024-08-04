#include "DT_DataInfoEstudiante.h"

DT_DataInfoEstudiante::DT_DataInfoEstudiante(std::string paisRes, DT_Date* fechaNac) {
	this->fechaNacimiento = fechaNac;
	this->paisResidencia = paisRes;
}

DT_DataInfoEstudiante::~DT_DataInfoEstudiante() {
	
}

std::string DT_DataInfoEstudiante::getPaisResidencia() {
	return this->paisResidencia;
}



std::string DT_DataInfoEstudiante::getFechaNacimientoToString() {
	
	std::string dia = std::to_string(this->getFechaNacimiento()->getDia());
	std::string mes = std::to_string(this->getFechaNacimiento()->getMes());
	std::string ano = std::to_string(this->getFechaNacimiento()->getAno());
	
	return (dia + "/" + mes + "/" + ano);
}

DT_Date* DT_DataInfoEstudiante::getFechaNacimiento() {
	return this->fechaNacimiento;
}

std::ostream& operator<<(std::ostream& os, DT_DataInfoEstudiante* dataInfo) {
	os << "\nPais de residencia: " << dataInfo->getPaisResidencia()
		<< "\nFecha de nacimiento: " << dataInfo->getFechaNacimientoToString();
	
	return os;
}
