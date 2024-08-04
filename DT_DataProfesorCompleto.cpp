#include "DT_DataProfesorCompleto.h"

DT_DataProfesorCompleto::DT_DataProfesorCompleto(
		std::string nombreProf,
		std::string nicknameProf,
		std::string instituto,
		std::set<std::string> idiomasEspecializacion) {
	this->nombre = nombreProf;
	this->nickname = nicknameProf;
	this->instituto = instituto;
	this->idiomas = idiomasEspecializacion;
}

DT_DataProfesorCompleto::~DT_DataProfesorCompleto() {
	
}

std::string DT_DataProfesorCompleto::getNombre() {
	return this->nombre;
}

std::string DT_DataProfesorCompleto::getNickname() {
	return this->nickname;
}

std::string DT_DataProfesorCompleto::getInstituto() {
	return this->instituto;
}

std::set<std::string> DT_DataProfesorCompleto::getIdiomasEspecializacion() {
	return this->idiomas;
}

std::string DT_DataProfesorCompleto::getIdiomasToString() {
	std::string idiomas = "";
	for (std::string st : this->idiomas) {
		idiomas = idiomas + "|" + st;
	}
	return idiomas;
}

std::ostream& operator<<(std::ostream& os, DT_DataProfesorCompleto* dataProf) {
	os << "\nNickname: " << dataProf->getNickname()
		<< "\nInstituto: " << dataProf->getInstituto()
		<< "\nIdiomas dictados: " << dataProf->getIdiomasToString();

	return os;
}
