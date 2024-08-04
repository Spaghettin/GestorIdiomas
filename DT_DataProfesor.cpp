#include "DT_DataProfesor.h"

DT_DataProfesor::DT_DataProfesor(std::string nickname,
								 std::string nombre){
	this->nickname = nickname;
	this->nombre = nombre;
}

DT_DataProfesor::~DT_DataProfesor() {
	
}

std::string DT_DataProfesor::getNombre() {
	return this->nombre;
}

std::string DT_DataProfesor::getNickname() {
	return this->nickname;
}

std::ostream& operator<<(std::ostream& os, DT_DataProfesor* dataProf) {
	os << "\nNombre: " << dataProf->getNombre()
		<< "\nNickname: " << dataProf->getNickname();

	return os;
}
