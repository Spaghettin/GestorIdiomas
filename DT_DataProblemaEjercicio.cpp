/*
 * DT_DataProblemaEjercicio.cpp
 *
 *  Created on: Jun 18, 2024
 *      Author: mat
 */

#include "DT_DataProblemaEjercicio.h"

#include "DeCompletar.h"

DT_DataProblemaEjercicio::DT_DataProblemaEjercicio(Ejercicio* ej) {

	this->descripcion = ej->getDescripcion();
	this->fraseProblema = ej->getProblema();

	if (dynamic_cast<DeCompletar*>(ej) != nullptr) {
		this->tipoEj = Completar;
		} else {
		this->tipoEj = Traduccion;
	}
}

std::string DT_DataProblemaEjercicio::getTipoEjercicioToString() {
	if (this->tipoEj == Traduccion) {
		return "De Traduccion";
	} else {
		return "De Completar";
	}
}

std::string DT_DataProblemaEjercicio::getDescripcionEjercicio() {
	return this->descripcion;
}

std::string DT_DataProblemaEjercicio::getFraseProblema() {
	return this->fraseProblema;
}

std::ostream& operator<<(std::ostream& os, DT_DataProblemaEjercicio* dtPE) {
	os << "\nDescripcion: " << dtPE->getDescripcionEjercicio()
		<< "\nTipo de ejercicio: " << dtPE->getTipoEjercicioToString()
		<< "\nProblema: " << dtPE->getFraseProblema();

	return os;
}

DT_DataProblemaEjercicio::~DT_DataProblemaEjercicio() {
	// TODO Auto-generated destructor stub
}

