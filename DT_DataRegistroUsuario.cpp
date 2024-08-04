#include "DT_DataRegistroUsuario.h"

DT_DataRegistroUsuario::DT_DataRegistroUsuario(
		std::string nickname,
		std::string nombre,
		std::string descripcion,
		std::string contrasena) {
	this->nickname = nickname;
	this->nombre = nombre;
	this->contrasena = contrasena;
	this->descripcion = descripcion;
}


DT_DataRegistroUsuario::~DT_DataRegistroUsuario() {
	
}


std::string DT_DataRegistroUsuario::getNombre() {
	return this->nombre;
}

std::string DT_DataRegistroUsuario::getNickname() {
	return this->nickname;
}

std::string DT_DataRegistroUsuario::getContrasena() {
	return this->contrasena;
}

std::string DT_DataRegistroUsuario::getDescripcion() {
	return this->descripcion;
}
