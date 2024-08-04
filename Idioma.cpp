/*
 * Idioma.cpp
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#include "Idioma.h"

Idioma::Idioma(std::string nombreIdioma) {
	this->nombreIdioma = nombreIdioma;
}

Idioma::~Idioma() {
	// TODO Auto-generated destructor stub
}

std::string Idioma::getNombre() {
	return this->nombreIdioma;
}
