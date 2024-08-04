#include "DT_DataInfoProfesor.h"

DT_DataInfoProfesor::DT_DataInfoProfesor(std::string instituto, std::set<std::string> idiomas) {
	this->idiomas = idiomas;
	this->instituto = instituto;
}

DT_DataInfoProfesor::~DT_DataInfoProfesor() {
	
}

std::string DT_DataInfoProfesor::getInstituto() {
	return this->instituto;
}

std::set<std::string> DT_DataInfoProfesor::getIdiomas() {
	return this->idiomas;
}

std::string DT_DataInfoProfesor::getIdiomasToString() {
	std::string idiomas = "";
	for (std::string idm : this->getIdiomas()) {
		idiomas += (idm + " | ");
	}
	return idiomas;
}

std::ostream& operator<<(std::ostream& os, DT_DataInfoProfesor* dataInfo) {
	os << "\nInstituto: " << dataInfo->getInstituto() 
		<< "\nIdiomas: " << dataInfo->getIdiomasToString();
	
	return os;
}
