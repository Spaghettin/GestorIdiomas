/*
 * Usuario.cpp
 *
 *  Created on: Jun 20, 2024
 *      Author: mat
 */

#include "Usuario.h"

Usuario::Usuario() {
	// TODO Auto-generated constructor stub

}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

std::string Usuario::getNickname() {
	return this->nickname;
}

std::string Usuario::getNombreUsuario() {
	return this->nombreUsuario;
}

std::string Usuario::getDescripcionUsuario() {
	return this->descripcionUsuario;
}
