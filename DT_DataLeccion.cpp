/*
* DataLeccion.cpp
*
*  Created on: Jun 17, 2024
*      Author: mat
*/

#include "DT_DataLeccion.h"

DT_DataLeccion::DT_DataLeccion() {}

DT_DataLeccion::DT_DataLeccion(int id, std::string temaL, std::string objL) {
	this->idLeccion = id;
	this->tema = temaL;
	this->objetivo = objL;
}

DT_DataLeccion::~DT_DataLeccion() {
	// TODO Auto-generated destructor stub
}

int DT_DataLeccion::getID() {
	return this->idLeccion;
}

std::string DT_DataLeccion::getTema() {
	return this->tema;
}

std::string DT_DataLeccion::getObjetivo() {
	return this->objetivo;
}

std::ostream& operator<<(std::ostream& os, DT_DataLeccion* lec) {
	os << "\nLeccion: " << lec->getID()
		<< "\nTema: " << lec->getTema()
		<< "\nObjetivo: " << lec->getObjetivo();
	
	return os;
}

