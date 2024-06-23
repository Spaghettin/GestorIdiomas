#include "Usuario.h"
#include "iostream"

Usuario::Usuario() {
	
}

Usuario::Usuario(const Usuario &arg) {
	
}

Usuario::~Usuario() {
	
}

std::string Usuario::getNickname() const {
	return this->nickname;
}

std::string Usuario::getContrasena() const {
	return this->contrasena;
}

std::string Usuario::getNombre() const {
	return this->nombre;
}

std::string Usuario::getDescripcion() const {
	return this->descripcion;
}

