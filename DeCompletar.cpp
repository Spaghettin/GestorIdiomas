/*
 * DeCompletar.cpp
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#include "DeCompletar.h"

DeCompletar::DeCompletar() {
	this->idEjercicio = ++(this->cantInstancias);
}

DeCompletar::DeCompletar(std::string descripcionEj, std::string frase, std::vector<std::string> sol) {
	this->descripcion = descripcionEj;
	this->fraseIncompleta = frase;
	this->solucion = sol;
	this->idEjercicio = ++(this->cantInstancias);
}


DeCompletar::~DeCompletar() {
	// TODO Auto-generated destructor stub
}

std::vector<std::string> DeCompletar::getSolucion() {
	return this->solucion;
}

std::string DeCompletar::getProblema() {
	return this->fraseIncompleta;
}

bool DeCompletar::resolver(std::vector<std::string> sol) {

	if (sol.size() != (this->getSolucion().size())) {
		return false;
	}

	std::vector<std::string>::iterator it_1, it_2;
	std::vector<std::string> solucion = this->getSolucion();
	it_1 = sol.begin();

	for (it_2 = solucion.begin(); it_2 != solucion.end(); it_2++) {
		if (*it_1 != *it_2) {
			return false;
		}
		it_1++;
	}

	return true;
}


DT_DataDeCompletar* DeCompletar::getDataDeCompletar() {
	DT_DataDeCompletar* dataDeComp = new DT_DataDeCompletar(
		this->getDescripcion(),
		this->getProblema(),
		this->getSolucion()
	);
	
	return dataDeComp;
}
