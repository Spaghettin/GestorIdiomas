/*
* DataProblemaEjercicio.cpp
*
*  Created on: Jun 18, 2024
*      Author: mat
*/

#include "DeCompletar.h"
#include "DT_DataProblemaEjercicio.h"

DT_DataProblemaEjercicio::DT_DataProblemaEjercicio() {}

DT_DataProblemaEjercicio::DT_DataProblemaEjercicio(Ejercicio* ej) {
	
	this->descripcion = ej->getDescripcion();
	this->fraseProblema = ej->getProblema();
	
	if (dynamic_cast<DeCompletar*>(ej) != nullptr) {
		this->tipoEj = Completar;
	} else {
		this->tipoEj = Traduccion;
	}
}

std::string DT_DataProblemaEjercicio::getDescripcion() {
	return this->descripcion;
}

std::string DT_DataProblemaEjercicio::getProblema() {
	return this->fraseProblema;
}

std::string DT_DataProblemaEjercicio::getTipoEjercicio() {
	if (this->tipoEj == Traduccion) {
		return "De Traduccion";
	} else {
		return "De Completar";
	}
}

std::ostream& operator<<(std::ostream& os, DT_DataProblemaEjercicio* dtPE) {
	os << "\nDescripcion: " << dtPE->getDescripcion()
		<< "\nTipo de ejercicio: " << dtPE->getTipoEjercicio()
		<< "\nProblema: " << dtPE->getProblema();
	
	return os;
}

DT_DataProblemaEjercicio::~DT_DataProblemaEjercicio() {
	// TODO Auto-generated destructor stub
}
