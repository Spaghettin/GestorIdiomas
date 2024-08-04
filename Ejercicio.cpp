/*
 * Ejercicio.cpp
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#include "Ejercicio.h"

int Ejercicio::cantInstancias = 0;

Ejercicio::Ejercicio() {}

Ejercicio::~Ejercicio() {
	// TODO Auto-generated destructor stub
}

int Ejercicio::getID() {
	return this->idEjercicio;
}

std::string Ejercicio::getDescripcion() {
	return this->descripcion;
}

DT_DataProblemaEjercicio* Ejercicio::getDataProblema() {
	DT_DataProblemaEjercicio* dtPE = new DT_DataProblemaEjercicio(this);
	return dtPE;
}
