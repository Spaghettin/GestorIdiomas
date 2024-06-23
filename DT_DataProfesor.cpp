#include "DT_DataProfesor.h"

DT_DataProfesor::DT_DataProfesor() {
	
}

DT_DataProfesor::DT_DataProfesor(std::string nickname,
								 std::string nombre,
								 std::string contrasena,
								 std::string descripcion){
	this->nickname = nickname;
	this->nombre = nombre;
	this->contrasena = contrasena;
	this->descripcion = descripcion;
}

DT_DataProfesor::DT_DataProfesor(const DT_DataProfesor &arg) {
	
}

DT_DataProfesor::~DT_DataProfesor() {
	
}

std::string DT_DataProfesor::getNombre() const {
	return this->nombre;
}

std::string DT_DataProfesor::getNickname() const {
	return this->nickname;
}

std::string DT_DataProfesor::getContrasena() const {
	return this->contrasena;
}

std::string DT_DataProfesor::getDescripcion() const {
	return this->descripcion;
}
