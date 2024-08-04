
/*
 * DeTraduccion.cpp
 *
 *  Created on: Jun 17, 2024
 *      Author: mat
 */

#include "DeTraduccion.h"

DeTraduccion::DeTraduccion() {
	this->idEjercicio = ++(this->cantInstancias);
}

DeTraduccion::DeTraduccion(std::string descripcionEj, std::string frase, std::string sol) {
	this->descripcion = descripcionEj;
	this->fraseATraducir = frase;
	this->solucion = sol;
	this->idEjercicio = ++(this->cantInstancias);
}


DeTraduccion::~DeTraduccion() {
	// TODO Auto-generated destructor stub
}

std::string DeTraduccion::getProblema() {
	return this->fraseATraducir;
}

std::string DeTraduccion::getSolucion() {
	return this->solucion;
}

bool DeTraduccion::resolver(std::string sol) {
	return (this->getSolucion() == sol);
}

DT_DataDeTraduccion* DeTraduccion::getDataDeTraduccion() {
	DT_DataDeTraduccion* dataDeTraduccion = new DT_DataDeTraduccion(
		this->getDescripcion(),
		this->getProblema(),
		this->getSolucion());
	
	return dataDeTraduccion;
}





